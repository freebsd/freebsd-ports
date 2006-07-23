--- code/qcommon/vm.c.orig	Wed May 31 23:18:41 2006
+++ code/qcommon/vm.c	Wed May 31 23:19:43 2006
@@ -225,7 +225,7 @@
 		return;
 	}
 
-	COM_StripExtension( vm->name, name );
+	COM_StripExtension( vm->name, name, sizeof(name) );
 	Com_sprintf( symbols, sizeof( symbols ), "vm/%s.map", name );
 	len = FS_ReadFile( symbols, (void **)&mapfile );
 	if ( !mapfile ) {
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
