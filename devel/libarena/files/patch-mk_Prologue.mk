--- mk/Prologue.mk.orig	2011-03-13 13:59:37.000000000 +0100
+++ mk/Prologue.mk	2011-03-13 14:00:08.000000000 +0100
@@ -9,5 +9,5 @@ d		:= $(dir)
 
 # Our parent directory
 $(d)/..		?= $(shell dirname "$(d)")
-$(d)/..		!= dirname "$(d)"
+#$(d)/..		!= dirname "$(d)"
 
