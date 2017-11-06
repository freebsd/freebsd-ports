--- src/i_tcp.c.orig	2017-03-03 19:49:10 UTC
+++ src/i_tcp.c
@@ -411,8 +411,12 @@ byte  IPX_hashaddr(mysockaddr_t *a)
     // Not allowed to be 0.
     // Big endian, want final addr byte.
 #ifdef LINUX
+# ifdef FREEBSD
+    return ((byte)(a->ipx.sipx_addr.x_host.c_host[5])) | 0x80;
+# else
     // Linux: IPX address hash
     return ((byte)(a->ipx.sipx_node[5])) | 0x80;
+# endif
 #else
     // Windows, OS2, DJGPP: IPX address hash
     return ((byte)(a->ipx.sa_nodenum[5])) | 0x80;
