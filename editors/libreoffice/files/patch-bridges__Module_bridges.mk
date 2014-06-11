--- bridges/Module_bridges.mk.orig	2014-06-10 16:26:56.078373584 +0200
+++ bridges/Module_bridges.mk	2014-06-10 16:26:26.759413474 +0200
@@ -19,7 +19,7 @@
 	$(if $(filter ARM,$(CPUNAME)),\
 		$(if $(filter IOS,$(OS)),\
 			CustomTarget_gcc3_ios_arm) \
-		$(if $(filter ANDROID LINUX,$(OS)),\
+		$(if $(filter ANDROID FREEBSD LINUX,$(OS)),\
 			CustomTarget_gcc3_linux_arm) \
 	) \
 ))
