--- dabreceiver-V2/gui.cpp.orig
+++ dabreceiver-V2/gui.cpp
@@ -646,6 +646,12 @@ QString a = ensemble. data (s, Qt::Displ
 	                break;
 	}
 
+#if 1
+	if (language < 0 || language > sizeof(table9)/sizeof(*table9))
+		language = 0;
+	if (type < 0 || type > sizeof(table12)/sizeof(*table12))
+		type = 0;
+#endif
 	nameofLanguage	-> setText (table9 [language]);
 	programType	-> setText (table12 [type]);
 }
