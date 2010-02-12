--- src/MEDMEM/MEDMEM_define.hxx.orig	2009-03-18 20:52:30.000000000 +0600
+++ src/MEDMEM/MEDMEM_define.hxx	2009-06-04 14:59:23.000000000 +0700
@@ -24,7 +24,7 @@
 
 #include <stdio.h>
 #include <iostream>
-#include <string>
+#include <cstring>
 #include <assert.h>
 
 // UTILE AUX DEUX NAMESPACES
@@ -117,7 +117,7 @@
 //   //#define MED_ALL    0 !!!!! NB: WARNING MED_ALL deja utilise dans l'enum medGeometryElement !!!!!!!!
 // #define MED_ALL    0
 
-#if defined(SUN4SOL2) || defined(PCLINUX) || defined(PCLINUX64_32) || defined(OSF1_32) || defined(IRIX64_32) || defined(RS6000)
+#if defined(SUN4SOL2) || defined(PCLINUX) || defined(PCLINUX64_32) || defined(OSF1_32) || defined(IRIX64_32) || defined(RS6000) || defined(FREEBSD)
 /* interface C/FORTRAN */
 /* this true only with g77 and gcc : we must change it to use directly NOMF_... and INT32 or INT64 - it will be more simple to understand and to use ! */
 // #define NOMF_POST_UNDERSCORE
