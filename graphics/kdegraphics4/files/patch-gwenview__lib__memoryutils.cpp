--- ./gwenview/lib/memoryutils.cpp.orig	2010-12-13 02:03:56.937466810 +0100
+++ ./gwenview/lib/memoryutils.cpp	2010-12-13 02:10:42.437502217 +0100
@@ -32,6 +32,10 @@
 #ifdef Q_OS_WIN
 #define _WIN32_WINNT 0x0500
 #include <windows.h>
+#elif defined(Q_OS_FREEBSD)
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <vm/vm_param.h>
 #endif
 
 namespace Gwenview {
@@ -61,6 +64,12 @@
         if ( entry.startsWith( "MemTotal:" ) )
             return (cachedValue = (Q_UINT64_C(1024) * entry.section( ' ', -2, -2 ).toULongLong()));
     }
+#elif defined(Q_OS_FREEBSD)
+    qulonglong physmem;
+    int mib[] = {CTL_HW, HW_PHYSMEM};
+    size_t len = sizeof( physmem );
+    if ( sysctl( mib, 2, &physmem, &len, NULL, 0 ) == 0 )
+        return (cachedValue = physmem);
 #elif defined(Q_OS_WIN)
     MEMORYSTATUSEX stat;
     stat.dwLength = sizeof(stat);
@@ -107,6 +116,26 @@
     lastUpdate = QTime::currentTime();
 
     return ( cachedValue = (Q_UINT64_C(1024) * memoryFree) );
+#elif defined(Q_OS_FREEBSD)
+    qulonglong cache, inact, free, psize;
+    size_t cachelen, inactlen, freelen, psizelen;
+    cachelen = sizeof( cache );
+    inactlen = sizeof( inact );
+    freelen = sizeof( free );
+    psizelen = sizeof( psize );
+    // sum up inactive, cached and free memory
+    if ( sysctlbyname( "vm.stats.vm.v_cache_count", &cache, &cachelen, NULL, 0 ) == 0 &&
+            sysctlbyname( "vm.stats.vm.v_inactive_count", &inact, &inactlen, NULL, 0 ) == 0 &&
+            sysctlbyname( "vm.stats.vm.v_free_count", &free, &freelen, NULL, 0 ) == 0 &&
+            sysctlbyname( "vm.stats.vm.v_page_size", &psize, &psizelen, NULL, 0 ) == 0 )
+    {
+        lastUpdate = QTime::currentTime();
+        return (cachedValue = (cache + inact + free) * psize);
+    }
+    else
+    {
+        return 0;
+    }
 #elif defined(Q_OS_WIN)
     MEMORYSTATUSEX stat;
     stat.dwLength = sizeof(stat);
