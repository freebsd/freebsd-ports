--- common/components/audio/sample_data.cpp.orig	Thu Sep 16 18:34:33 2004
+++ common/components/audio/sample_data.cpp	Thu Sep 16 18:40:05 2004
@@ -325,7 +325,7 @@
 
 	if (is_16bits) {
 
-		(void*)new_sample_8bits=malloc(size);
+		new_sample_8bits=(Sint8*)malloc(size);
 		if (new_sample_8bits==NULL) {
 
 			ERROR("Cannot convert sample! not enough memory?");
@@ -339,7 +339,7 @@
 	} else {
 
 		Sint8 *sample_8bits_ptr=(Sint8*)data_ptr;
-		(void*)new_sample_16bits=malloc(size*2);
+		new_sample_16bits=(Sint16*)malloc(size*2);
 		if (new_sample_16bits==NULL) {
 
 			ERROR("Cannot convert sample! not enough memory?");
