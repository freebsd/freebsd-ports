--- vm/include/elfsh.h.orig	2003-08-21 01:11:02 UTC
+++ vm/include/elfsh.h
@@ -471,7 +471,7 @@ int		vm_getdisasm(u_int index, u_int arg
 int		vm_gethexa(u_int index, u_int argc, char **argv);
 int		vm_getvarparams(u_int index, u_int argc, char **argv);
 
-int		dprintf(int fd, char *format, ...);
+int		_dprintf(int fd, char *format, ...);
 
 /* Libasm resolve handler */
 void		do_resolve(void *data, u_int vaddr, char *, u_int);
