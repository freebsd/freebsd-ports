--- code/qcommon/vm.c.orig	Sat May 27 14:56:20 2006
+++ code/qcommon/vm.c	Sat May 27 15:40:59 2006
@@ -826,7 +826,7 @@
 
 
 
-#ifdef oDLL_ONLY // bk010215 - for DLL_ONLY dedicated servers/builds w/o VM
+#ifdef DLL_ONLY // bk010215 - for DLL_ONLY dedicated servers/builds w/o VM
 int	VM_CallCompiled( vm_t *vm, int *args ) {
   return(0); 
 }
