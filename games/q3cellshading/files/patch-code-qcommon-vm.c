--- ./code/qcommon/vm.c.orig	Wed May 31 18:55:11 2006
+++ ./code/qcommon/vm.c	Wed May 31 19:08:19 2006
@@ -225,7 +225,7 @@
 		return;
 	}
 
-	COM_StripExtension( vm->name, name );
+	COM_StripExtension( vm->name, name, sizeof(name) );
 	Com_sprintf( symbols, sizeof( symbols ), "vm/%s.map", name );
 	len = FS_ReadFile( symbols, (void **)&mapfile );
 	if ( !mapfile ) {
@@ -826,7 +826,7 @@
 
 
 
-#ifdef oDLL_ONLY // bk010215 - for DLL_ONLY dedicated servers/builds w/o VM
+#ifdef DLL_ONLY // bk010215 - for DLL_ONLY dedicated servers/builds w/o VM
 int	VM_CallCompiled( vm_t *vm, int *args ) {
   return(0); 
 }
