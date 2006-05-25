--- code/qcommon/vm.c.orig	Thu May 25 16:59:36 2006
+++ code/qcommon/vm.c	Thu May 25 17:08:51 2006
@@ -478,7 +478,7 @@
 		}
 	}
 
-	if ( interpret == VMI_NATIVE ) {
+	if ( 1 ) {
 		// try to load as a system dll
 		Com_Printf( "Loading dll file %s.\n", vm->name );
 		vm->dllHandle = Sys_LoadDll( module, vm->fqpath , &vm->entryPoint, VM_DllSyscall );
@@ -826,7 +826,7 @@
 
 
 
-#ifdef oDLL_ONLY // bk010215 - for DLL_ONLY dedicated servers/builds w/o VM
+#ifdef DLL_ONLY // bk010215 - for DLL_ONLY dedicated servers/builds w/o VM
 int	VM_CallCompiled( vm_t *vm, int *args ) {
   return(0); 
 }
