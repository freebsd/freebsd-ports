--- binutils/ld/emulparams/zpuelf.sh.orig	2012-10-12 15:43:08.000000000 -0500
+++ binutils/ld/emulparams/zpuelf.sh	2012-10-12 15:43:55.000000000 -0500
@@ -27,4 +27,5 @@
 DTOR_START='___dtors = .;'
 DTOR_END='___dtors_end = .;'
 
-STACK_ADDR=(0x1000000-0x10000)
+STACK_ADDR=0x1000000-0x10000
+#STACK_ADDR=(0x1000000-0x10000)
