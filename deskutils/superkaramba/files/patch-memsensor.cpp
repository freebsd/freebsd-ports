--- src/memsensor.cpp.orig     Mon Apr 21 15:17:03 2003
+++ src/memsensor.cpp  Fri Sep  5 12:07:36 2003
@@ -12,63 +12,202 @@
 #include <qtextstream.h>
 #include <qstring.h>
 #include <qregexp.h>
+
+#ifdef __FreeBSD__
+#include <sys/time.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/resource.h>
+#include <unistd.h>
+#include <kvm.h>
+#include <sys/file.h>
+#include <osreldate.h>
+
+/* define pagetok in terms of pageshift */
+#define pagetok(size) ((size) << pageshift)
+#endif
+
 MemSensor::MemSensor(int msec) : Sensor(msec)
 {
+#ifdef __FreeBSD__
+   /* get the page size with "getpagesize" and calculate pageshift from it */
+    int pagesize = getpagesize();
+    pageshift = 0;
+    while (pagesize > 1)
+    {
+        pageshift++;
+        pagesize >>= 1;
+    }
+
+    /* we only need the amount of log(2)1024 for our conversion */
+    pageshift -= 10;
+
+# if __FreeBSD_version < 500018
+    connect(&ksp, SIGNAL(receivedStdout(KProcess *, char *, int )),
+            this,SLOT(receivedStdout(KProcess *, char *, int )));
+    connect(&ksp, SIGNAL(processExited(KProcess *)),
+            this,SLOT(processExited( KProcess * )));
+
+    swapTotal = swapUsed = 0;
+
+    MaxSet = false;
+
     readValues();
+# else
+    kd = kvm_open("/dev/null", "/dev/null", "/dev/null", O_RDONLY, "kvm_open");
+# endif
+#else
+    readValues();
+#endif
 }
+
 MemSensor::~MemSensor()
 {}
 
+#ifdef __FreeBSD__
+void MemSensor::receivedStdout(KProcess *, char *buffer, int len )
+{
+    buffer[len] = 0;
+    sensorResult += QString( QCString(buffer) );
+}
+
+void MemSensor::processExited(KProcess *)
+{
+    QStringList stringList = QStringList::split('\n',sensorResult);
+    sensorResult = "";
+    QStringList itemsList = QStringList::split(' ', stringList[1]);
+
+    swapUsed = itemsList[2].toInt();
+    swapTotal = itemsList[1].toInt();
+}
+#endif
 
 int MemSensor::getMemTotal()
 {
+#ifdef __FreeBSD__
+    static int mem = 0;
+    size_t size = sizeof(mem);
+
+    sysctlbyname("hw.physmem", &mem, &size, NULL, 0);
+    return (mem / 1024);
+#else
     QRegExp rx( "MemTotal:\\s*(\\d+)" );
     rx.search( meminfo );
     return ( rx.cap(1).toInt() );
+#endif
 }
 
 int MemSensor::getMemFree()
 {
+#ifdef __FreeBSD__
+    static int mem = 0;
+    size_t size = sizeof(mem);
+
+    sysctlbyname("vm.stats.vm.v_free_count", &mem, &size, NULL, 0);
+    return (pagetok(mem));
+#else
     QRegExp rx( "MemFree:\\s*(\\d+)" );
     rx.search( meminfo );
     return ( rx.cap(1).toInt() );
+#endif
 }
 
 
 int MemSensor::getBuffers()
 {
+#ifdef __FreeBSD__
+    static int mem = 0;
+    size_t size = sizeof(mem);
+
+    sysctlbyname("vfs.bufspace", &mem, &size, NULL, 0);
+    return (mem / 1024);
+#else
     QRegExp rx( "Buffers:\\s*(\\d+)" );
     rx.search( meminfo );
     return ( rx.cap(1).toInt() );
+#endif
 }
 
 int MemSensor::getCached()
 {
+#ifdef __FreeBSD__
+    static int mem = 0;
+    size_t size = sizeof(mem);
+
+    sysctlbyname("vm.stats.vm.v_cache_count", &mem, &size, NULL, 0);
+    return (pagetok(mem));
+#else
     QRegExp rx1( "Cached:\\s*(\\d+)" );
     QRegExp rx2( "SwapCached:\\s*(\\d+)" );
     rx1.search( meminfo );
     rx2.search( meminfo );
     return ( rx1.cap(1).toInt() + rx2.cap(1).toInt() );
+#endif
 }
 
 
 int MemSensor::getSwapTotal()
 {
+#ifdef __FreeBSD__
+# if __FreeBSD_version < 500018
+    return(swapTotal);
+# else
+    int n = -1;
+    int pagesize = getpagesize();
+    int retavail = 0;
+
+    if (kd != NULL)
+        n = kvm_getswapinfo(kd, &swapinfo, 1, 0);
+
+    if (n < 0 || swapinfo.ksw_total == 0)
+        return(0);
+
+    retavail = swapinfo.ksw_total * pagesize / 1024;
+
+    return(retavail);
+# endif
+#else
     QRegExp rx( "SwapTotal:\\s*(\\d+)" );
     rx.search( meminfo );
     return ( rx.cap(1).toInt() );
+#endif
 }
 
 int MemSensor::getSwapFree()
 {
+#ifdef __FreeBSD__
+# if __FreeBSD_version < 500018
+    return(swapTotal - swapUsed);
+# else
+    int n = -1;
+    int pagesize = getpagesize();
+    int retfree = 0;
+
+    if (kd != NULL)
+        n = kvm_getswapinfo(kd, &swapinfo, 1, 0);
+    if (n < 0 || swapinfo.ksw_total == 0)
+        return(0);
+
+    retfree = (swapinfo.ksw_total - swapinfo.ksw_used) * pagesize / 1024;
+
+    return(retfree);
+# endif
+#else
     QRegExp rx( "SwapFree:\\s*(\\d+)" );
     rx.search( meminfo );
     return ( rx.cap(1).toInt() );
+#endif
 }
 
-
 void MemSensor::readValues()
 {
+#ifdef __FreeBSD__
+# if __FreeBSD_version < 500018
+    ksp.clearArguments();
+    ksp << "swapinfo";
+    ksp.start( KProcess::NotifyOnExit,KProcIO::Stdout);
+# endif
+#else
     QFile file("/proc/meminfo");
     QString line;
     if ( file.open(IO_ReadOnly | IO_Translate) )
@@ -77,15 +216,21 @@
         meminfo = t.read();
         file.close();
     }
+#endif
 }
 
 void MemSensor::update()
 {
+#if (defined(__FreeBSD__) && __FreeBSD_version < 500018) 
     readValues();
+#endif
     QString format;
     SensorParams *sp;
     Meter *meter;
     QObjectListIt it( *objList );
+#if (defined(__FreeBSD__) && __FreeBSD_version < 500018)
+    bool set = false;
+#endif
 
     int totalMem = getMemTotal();
     int usedMem = totalMem - getMemFree();
@@ -96,6 +241,12 @@
     while (it != 0)
     {
         sp = (SensorParams*)(*it);
+#if (defined(__FreeBSD__) && __FreeBSD_version < 500018)
+        if ( (!MaxSet) && (totalSwap > 0) ) {
+           setMaxValue(sp);
+           bool set = true;
+        }
+#endif 
         meter = sp->getMeter();
         format = sp->getParam("FORMAT");
         if (format.length() == 0 )
@@ -118,6 +269,11 @@
         meter->setValue(format);
         ++it;
     }
+#if (defined(__FreeBSD__) && __FreeBSD_version < 500018)
+    if (set)
+        MaxSet = true;
+#endif
+
 }
 
 void MemSensor::setMaxValue( SensorParams *sp )
@@ -133,7 +289,6 @@
     }
     if( f=="%fm" || f== "%um" || f=="%fmb" || f=="%umb" )
         meter->setMax( getMemTotal() / 1024 );
-
     if( f=="%fs" || f== "%us" )
         meter->setMax( getSwapTotal() / 1024 );
 }
