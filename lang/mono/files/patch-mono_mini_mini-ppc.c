--- mono/mini/mini-ppc.c.orig	2018-08-24 15:17:13 UTC
+++ mono/mini/mini-ppc.c
@@ -4650,7 +4650,7 @@ mono_arch_register_lowlevel_calls (void)
 }
 
 #ifdef __mono_ppc64__
-#ifdef _LITTLE_ENDIAN
+#if G_BYTE_ORDER == G_LITTLE_ENDIAN
 #define patch_load_sequence(ip,val) do {\
 		guint16 *__load = (guint16*)(ip);	\
 		g_assert (sizeof (val) == sizeof (gsize)); \
@@ -4659,7 +4659,7 @@ mono_arch_register_lowlevel_calls (void)
 		__load [6] = (((guint64)(gsize)(val)) >> 16) & 0xffff;	\
 		__load [8] =  ((guint64)(gsize)(val))        & 0xffff;	\
 	} while (0)
-#elif defined _BIG_ENDIAN
+#elif G_BYTE_ORDER == G_BIG_ENDIAN
 #define patch_load_sequence(ip,val) do {\
 		guint16 *__load = (guint16*)(ip);	\
 		g_assert (sizeof (val) == sizeof (gsize)); \
