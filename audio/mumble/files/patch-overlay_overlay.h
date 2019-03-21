--- overlay/overlay.h.orig	2019-03-13 18:38:10 UTC
+++ overlay/overlay.h
@@ -18,6 +18,25 @@ struct OverlayMsgHeader {
 #define OVERLAY_MSGTYPE_INIT 0
 struct OverlayMsgInit {
 	unsigned int uiWidth;
+/* BSD support */
+#ifndef ElfW
+# ifdef __FreeBSD__
+#  if __ELF_WORD_SIZE == 32
+#   define ElfW(type) Elf32_##type
+#  else
+#   define ElfW(type) Elf64_##type
+#  endif
+# else
+# ifdef __NetBSD__
+#  if ELFSIZE == 32
+#   define ElfW(type) Elf32_##type
+#  else 
+#   define ElfW(type) Elf64_##type
+#  endif
+# endif
+# endif
+#endif
+
 	unsigned int uiHeight;
 };
 
