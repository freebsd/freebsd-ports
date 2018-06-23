--- src/common/gui/option.cpp.orig	2010-05-16 23:38:35 UTC
+++ src/common/gui/option.cpp
@@ -527,7 +527,7 @@ bool OptionBox::IsEnabled(uint32 index) 
 StillImage* OptionBox::GetEmbeddedImage(uint32 index) const {
 	if (index >= GetNumberOptions()) {
 		IF_PRINT_WARNING(VIDEO_DEBUG) << "argument index was invalid: " << index << endl;
-		return false;
+		return nullptr;
 	}
 
 	return _options[index].image;
