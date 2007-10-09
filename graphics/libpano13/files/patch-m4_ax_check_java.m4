--- m4/ax_check_java.m4.orig	Wed Jan 17 11:23:05 2007
+++ m4/ax_check_java.m4	Wed Jan 17 11:25:08 2007
@@ -2,7 +2,7 @@
 dnl Usage:
 dnl AX_CHECK_JAVA
 dnl Test for java, and defines
-dnl - JAVA_CFLAGS (compiler flags)
+dnl - JAVA_FLAGS (compiler flags)
 dnl - LIB_JAVA (linker flags, stripping and path)
 dnl prerequisites:
 
@@ -78,6 +78,9 @@
   case "${target_os}" in
     linux*)
       java_extra_inc=linux
+      ;;
+    *freebsd*)
+      java_extra_inc=freebsd
       ;;
     darwin*)
       java_extra_inc=darwin
