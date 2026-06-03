--- navi2ch-multibbs.el.orig	2024-03-27 06:06:19 UTC
+++ navi2ch-multibbs.el
@@ -393,6 +393,8 @@ START $B$,(B non-nil $B$J$i$P%l%9HV9f(B START $B$
 	  ((or (string-match
 		"http://\\(.+\\)/\\([^/]+\\)/kako/[0-9]+/" url)
 	       (string-match
+		"http://\\(.+\\)/\\([^/]+\\)/oyster/[0-9]+/" url)
+	       (string-match
 		"http://\\(.+\\)/\\([^/]+\\)/i/" url)
 	       (string-match
 		"http://\\(.+\\)/\\([^/]+\\)" url))
@@ -421,6 +423,8 @@ START $B$,(B non-nil $B$J$i$P%l%9HV9f(B START $B$
 	  ;; "http://pc.2ch.net/unix/kako/1009/10093/1009340234.html" $B$H$+!#(B
 	  ((or (string-match
 		"http://.+/kako/[0-9]+/\\([0-9]+\\)\\.\\(dat\\|html\\)" url)
+	       (string-match
+		"http://.+/oyster/[0-9]+/\\([0-9]+\\)\\.dat" url)
 	       (string-match
 		"http://.+/kako/[0-9]+/[0-9]+/\\([0-9]+\\)\\.\\(dat\\|html\\)" url))
 	   (setq artid (match-string 1 url))
