--- vcl/unx/generic/app/geninst.cxx.orig	2019-12-18 18:16:42.000000000 +0800
+++ vcl/unx/generic/app/geninst.cxx	2020-01-03 16:10:17.974216000 +0800
@@ -18,6 +18,7 @@
  */
 
 #include <sal/config.h>
+#include <sys/utsname.h>
 
 #if defined(LINUX)
 #  include <stdio.h>
@@ -48,30 +49,22 @@
 
 OUString SalGenericInstance::getOSVersion()
 {
-    OUString aKernelVer = "unknown";
+    struct utsname stName;
 
-// not so generic, but at least shared between all unix backend
-#if defined(LINUX)
-    FILE* pVersion = fopen( "/proc/version", "r" );
-    if ( pVersion )
+    if ( uname( &stName ) != 0 )
+        return "unknown";
+
+    sal_Int32 nDots = 0;
+    sal_Int32 nIndex = 0;
+    OUString aVers = OUString::createFromAscii( stName.release );
+    while ( nIndex++ < aVers.getLength() )
     {
-        char aVerBuffer[512];
-        if ( fgets ( aVerBuffer, 511, pVersion ) )
-        {
-            aKernelVer = OUString::createFromAscii( aVerBuffer );
-            // "Linux version 3.16.7-29-desktop ..."
-            OUString aVers = aKernelVer.getToken( 2, ' ' );
-            // "3.16.7-29-desktop ..."
-            sal_Int32 nTooDetailed = aVers.indexOf( '.', 2);
-            if (nTooDetailed < 1 || nTooDetailed > 8)
-                aKernelVer = "Linux (misparsed version)";
-            else // "3.16.7-29-desktop ..."
-                aKernelVer = "Linux " + aVers.copy(0, nTooDetailed);
-        }
-        fclose( pVersion );
+        const char c = stName.release[ nIndex ];
+        if ( c == ' ' || c == '-' || ( c == '.' && nDots++ > 0 ) )
+            break;
     }
-#endif
-    return aKernelVer;
+    return OUString::createFromAscii( stName.sysname ) + " " +
+        aVers.copy( 0, nIndex );
 }
 
 /* vim:set shiftwidth=4 softtabstop=4 expandtab: */
