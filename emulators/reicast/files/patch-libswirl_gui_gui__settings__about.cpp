--- libswirl/gui/gui_settings_about.cpp.orig	2020-08-21 20:26:50 UTC
+++ libswirl/gui/gui_settings_about.cpp
@@ -40,13 +40,13 @@ void gui_settings_about()
 	    {
 	    	ImGui::Text("CPU: %s",
 #if HOST_CPU == CPU_X86
-				"x86"
+				"i386"
 #elif HOST_CPU == CPU_ARM
 				"ARM"
 #elif HOST_CPU == CPU_MIPS
 				"MIPS"
 #elif HOST_CPU == CPU_X64
-				"x86/64"
+				"amd64"
 #elif HOST_CPU == CPU_GENERIC
 				"Generic"
 #elif HOST_CPU == CPU_ARM64
@@ -88,4 +88,4 @@ void gui_settings_about()
 		ImGui::PopStyleVar();
 		ImGui::EndTabItem();
 	}
-}
\ No newline at end of file
+}
