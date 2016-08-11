--- overlay/overlay.h.orig	2014-08-08 15:51:59 UTC
+++ overlay/overlay.h
@@ -42,6 +42,25 @@ struct OverlayMsgHeader {
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
 
