--- midimountain/mvcMapperProperties.cpp	Wed Oct 24 09:47:34 2001
+++ midimountain/mvcMapperProperties.cpp	Wed Dec 11 03:23:50 2002
@@ -3,6 +3,8 @@
 //=============================================================================
 #include <mvcMapperProperties.h>
 #include <stdio.h>
+#include <iostream>
+using namespace std;
 
 void CloseClickedMapperProperties( GtkButton *button, gpointer user_data );
 void AddPresetClickedMapperProperties( GtkButton *button, gpointer user_data );
