--- src/gtimelapse.cpp.orig
+++ src/gtimelapse.cpp
@@ -155,7 +155,11 @@
 					//cout << "type: RADIO" << endl;
 					//cout << "current: " << current << endl;
 
+#ifdef __clang__
+					wxString *choices = new wxString[cnt];
+#else
 					wxString choices[cnt];
+#endif
 					
 					for ( i=0; i<cnt; i++) {
 						const char *choice;
@@ -165,6 +169,10 @@
 						choices[i] = mystring;
 					}
 			
+#ifdef __clang__
+					delete [] choices;
+#endif
+
 					wxString title(label, wxConvUTF8);
 					wxString default_choice(current, wxConvUTF8);
 					wxString choice_label(uselabel, wxConvUTF8);
