--- lib/markd/src/markd/rule.cr.orig	2026-10-29 18:48:14 UTC
+++ lib/markd/src/markd/rule.cr
@@ -70,8 +70,8 @@ module Markd
     # underscores may be present in the last two segments of the domain.
     #
     # Alphanumeric characters in this context include emojis.
-    LAST_DOMAIN_SEGMENT   = /(?:[a-zA-Z0-9\-\p{Emoji_Presentation}\-]+)/
-    OTHER_DOMAIN_SEGMENTS = /(?:[a-zA-Z0-9\p{Emoji_Presentation}\-_]+)/
+    LAST_DOMAIN_SEGMENT   = /(?:[a-zA-Z0-9\-\-]+)/
+    OTHER_DOMAIN_SEGMENTS = /(?:[a-zA-Z0-9\-_]+)/
     # The spec wants to capture greedily, even invalid domain names and then
     # reject the invalid ones later.
     # For example: www.xxx._yyy.zzz is never linked because of the
