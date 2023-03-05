--- cmake/modules/SMTG_AddVST3AuV2.cmake.orig	2023-03-05 18:19:05 UTC
+++ cmake/modules/SMTG_AddVST3AuV2.cmake
@@ -107,7 +107,7 @@ if (XCODE AND SMTG_COREAUDIO_SDK_PATH)
 		add_custom_command(TARGET ${target} POST_BUILD 
 			COMMAND /bin/mkdir "-p" ${outputdir}/${ARG_BUNDLE_NAME}.component/Contents/Resources
 			COMMAND /bin/rm "-f" "${outputdir}/${ARG_BUNDLE_NAME}.component/Contents/Resources/plugin.vst3"
-			COMMAND /bin/ln "-svfF" "${outputdir}/$<TARGET_FILE_NAME:${ARG_VST3_PLUGIN_TARGET}>.vst3" "${outputdir}/${ARG_BUNDLE_NAME}.component/Contents/Resources/plugin.vst3"
+			COMMAND /bin/ln "-sv" "${outputdir}/$<TARGET_FILE_NAME:${ARG_VST3_PLUGIN_TARGET}>.vst3" "${outputdir}/${ARG_BUNDLE_NAME}.component/Contents/Resources/plugin.vst3"
 			COMMAND /bin/cp "-rpf" "${outputdir}/${ARG_BUNDLE_NAME}.component" "~/Library/Audio/Plug-Ins/Components/"
 		)
 
