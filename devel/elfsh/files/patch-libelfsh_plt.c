--- libelfsh/plt.c.orig	2003-08-21 01:11:03 UTC
+++ libelfsh/plt.c
@@ -47,7 +47,7 @@ int		elfsh_copy_plt(elfshobj_t *file)
 			  0, 0, plt->shdr->sh_size, 0, 0, 0, 0);
 
   /* FreeBSD is incompatible with pre-interp injection */
-#ifdef __FreeBSD__
+#if defined __FreeBSD__ || defined __DragonFly__
   mode = ELFSH_DATA_INJECTION;
 #else
   mode = ELFSH_CODE_INJECTION;
