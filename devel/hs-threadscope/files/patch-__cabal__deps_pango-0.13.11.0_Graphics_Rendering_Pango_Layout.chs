--- _cabal_deps/pango-0.13.11.0/Graphics/Rendering/Pango/Layout.chs.orig	2001-09-09 01:46:40 UTC
+++ _cabal_deps/pango-0.13.11.0/Graphics/Rendering/Pango/Layout.chs
@@ -356,11 +356,20 @@ --
 --   a word if it is the only one on this line and it exceeds the
 --   specified width.
 --
+#if PANGO_VERSION_CHECK(1,56,0)
 {#enum PangoWrapMode as LayoutWrapMode
   {underscoreToCase,
   PANGO_WRAP_WORD as WrapWholeWords,
   PANGO_WRAP_CHAR as WrapAnywhere,
+  PANGO_WRAP_WORD_CHAR as WrapPartialWords,
+  PANGO_WRAP_NONE as WrapNowhere}#}
+#else
+{#enum PangoWrapMode as LayoutWrapMode
+  {underscoreToCase,
+  PANGO_WRAP_WORD as WrapWholeWords,
+  PANGO_WRAP_CHAR as WrapAnywhere,
   PANGO_WRAP_WORD_CHAR as WrapPartialWords}#}
+#endif
 
 -- | Set how this paragraph is wrapped.
 --
