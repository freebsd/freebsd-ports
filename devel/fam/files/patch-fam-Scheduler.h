--- fam/Scheduler.h~	Tue Jul 16 02:14:41 2002
+++ fam/Scheduler.h	Fri Sep  6 03:46:29 2002
@@ -105,7 +105,11 @@
     //  for the corresponding I/O type.
 
     struct IOTypeInfo {
+#if defined(__FreeBSD__) && defined(__GNUC__) && (__GNUC__ > 2)
+	FDInfo::FDIOHandler FDInfo::*iotype;
+#else
 	FDInfo::FDIOHandler FDInfo::*const iotype;
+#endif
 	unsigned int nbitsset;		// number of bits set in fds
 	fd_set fds;
 	IOTypeInfo(FDInfo::FDIOHandler FDInfo::* a_iotype) :
