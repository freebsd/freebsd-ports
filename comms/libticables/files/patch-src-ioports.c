--- src/ioports.c.orig	Wed Aug 27 11:34:39 2003
+++ src/ioports.c	Wed May 12 17:56:00 2004
@@ -41,7 +41,7 @@
 #if defined(__I386__) && defined(HAVE_ASM_IO_H) && defined(HAVE_SYS_PERM_H)
 #  include <sys/perm.h>
 #  include <asm/io.h>
-#elif defined(__BSD__)
+#elif defined(__BSD__) && defined(__I386__)
 #  include <machine/sysarch.h>
 #  include <machine/cpufunc.h>
 #elif defined(__WIN32__)
@@ -107,7 +107,7 @@
 }
 #endif /* 0 */ /* __MACOSX__ */
 
-#if defined(__I386__) && defined(HAVE_ASM_IO_H) && defined(HAVE_SYS_PERM_H) || defined(__ALPHA__) || defined(__BSD__)
+#if defined(__I386__) && defined(HAVE_ASM_IO_H) && defined(HAVE_SYS_PERM_H) || defined(__ALPHA__) || (defined(__BSD__) && defined(__I386__))
 static int linux_asm_read_io(unsigned int addr)
 {
   return inb(addr);
@@ -208,7 +208,7 @@
 {
 #if defined(__I386__) && defined(HAVE_ASM_IO_H) && defined(HAVE_SYS_PERM_H) || defined(__ALPHA__) || defined(__BSD__) || defined(__MACOSX__)
 
-#ifndef __MACOSX__
+#if !(defined(__MACOSX__) || (defined(__BSD__) && !defined(__I386__)))
   if (method & IOM_ASM) {
     io_rd = linux_asm_read_io;
     io_wr = linux_asm_write_io;
@@ -417,7 +417,7 @@
 int io_close(unsigned long from, unsigned long num)
 {
 #if defined(__I386__) && defined(HAVE_ASM_IO_H) && defined(HAVE_SYS_PERM_H) || defined(__ALPHA__) || defined(__BSD__) || defined(__MACOSX__)
-#ifndef __MACOSX__
+#if !(defined(__MACOSX__) || (defined(__BSD__) && !defined(__I386__)))
   if (method & IOM_ASM)
 #ifndef __BSD__
     return (ioperm(from, num, 0) ? ERR_ROOT : 0);
