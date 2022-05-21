--- src/Rack/plugin.mk.orig	2022-05-21 05:37:01 UTC
+++ src/Rack/plugin.mk
@@ -26,7 +26,7 @@ include $(RACK_DIR)/arch.mk
 ifdef ARCH_LIN
 	TARGET := plugin.so
 	# This prevents static variables in the DSO (dynamic shared object) from being preserved after dlclose().
-	FLAGS += -fno-gnu-unique
+	#FLAGS += -fno-gnu-unique
 	# When Rack loads a plugin, it symlinks /tmp/Rack2 to its system dir, so the plugin can link to libRack.
 	LDFLAGS += -Wl,-rpath=/tmp/Rack2
 	# Since the plugin's compiler could be a different version than Rack's compiler, link libstdc++ and libgcc statically to avoid ABI issues.
