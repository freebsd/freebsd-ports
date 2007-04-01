--- ros/src/IncludeLibrary/IncludeLibrary_osd_dlopen.h.orig	Fri Dec  5 19:02:29 2003
+++ ros/src/IncludeLibrary/IncludeLibrary_osd_dlopen.h	Thu Aug 10 21:52:39 2006
@@ -83,7 +83,7 @@
 //   return cxxshl_load( Path , BIND_IMMEDIATE ,0L);
 // ===> findsym( &NULL ... for HP
 
-#elif defined(sun) || defined(SOLARIS)  || defined(IRIX) || defined(sgi) || defined(linux) || defined(LIN)
+#elif defined(sun) || defined(SOLARIS)  || defined(IRIX) || defined(sgi) || defined(linux) || defined(LIN) || defined(__FreeBSD__)
  if ( Path != NULL ) {
    if ( LazyMode )
      handle = dlopen( Path , RTLD_LAZY | RTLD_GLOBAL );
