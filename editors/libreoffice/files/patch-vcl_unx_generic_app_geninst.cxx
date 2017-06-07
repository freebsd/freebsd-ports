--- vcl/unx/generic/app/geninst.cxx.orig	2017-05-03 16:46:29 UTC
+++ vcl/unx/generic/app/geninst.cxx
@@ -22,11 +22,8 @@
 #include <cassert>
 #include <string.h>
 #include <stdlib.h>
+#include <sys/utsname.h>
 
-#if defined(LINUX)
-#  include <stdio.h>
-#endif
-
 #include <osl/module.hxx>
 #include <comphelper/solarmutex.hxx>
 #include <config_features.h>
@@ -139,31 +136,22 @@ SalGenericInstance::~SalGenericInstance()
 
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
-            sal_Int32 nIndex = 0;
-            // "Linux version 3.16.7-29-desktop ..."
-            OUString aVers = aKernelVer.getToken( 2, ' ', nIndex );
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
