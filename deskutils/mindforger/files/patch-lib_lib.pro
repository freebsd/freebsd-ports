--- lib/lib.pro.orig	2020-03-08 17:03:52 UTC
+++ lib/lib.pro
@@ -136,9 +136,13 @@ SOURCES += \
     src/mind/ai/autolinking/naive_autolinking_preprocessor.cpp \
     src/representations/markdown/cmark_gfm_markdown_transcoder.cpp \
     src/mind/ai/autolinking/autolinking_mind.cpp \
-    src/mind/ai/autolinking/cmark_aho_corasick_block_autolinking_preprocessor.cpp \
     src/mind/limbo.cpp
 
+!mfnomd2html {
+    SOURCES += \
+    src/mind/ai/autolinking/cmark_aho_corasick_block_autolinking_preprocessor.cpp
+}
+
 mfner {
     SOURCES += \
     src/mind/ai/nlp/named_entity_recognition.cpp \
@@ -256,8 +260,12 @@ HEADERS += \
     src/config/config.h \
     src/representations/markdown/cmark_gfm_markdown_transcoder.h \
     src/mind/ai/autolinking/autolinking_mind.h \
-    src/mind/ai/autolinking/cmark_aho_corasick_block_autolinking_preprocessor.h \
     src/mind/limbo.h
+
+!mfnomd2html {
+    HEADERS += \
+    src/mind/ai/autolinking/cmark_aho_corasick_block_autolinking_preprocessor.h
+}
 
 mfner {
     HEADERS += \
