--- mk/Epilogue.mk.orig	2011-03-13 13:59:37.000000000 +0100
+++ mk/Epilogue.mk	2011-03-13 13:59:59.000000000 +0100
@@ -5,5 +5,5 @@
 d	:= $(dirstack_$(sp))
 
 sp	?= $(shell basename "$(sp)")
-sp	!= basename "$(sp)"
+#sp	!= basename "$(sp)"
 
