--- files.h	Fri Oct 25 21:22:08 2002
+++ files.h	Fri Oct 25 21:21:48 2002
@@ -1,4 +1,4 @@
-#include <fstream.h>
+#include <fstream>
 
 #ifdef __WIN32__
 	char file_path[50] = "C:\\Program Files\\Pengpong\\";
@@ -17,7 +17,7 @@
 
 void read_config_file()
 {
-	ifstream a_file;
+	std::ifstream a_file;
 	char *temp_string1, *temp_string2;
 	char *temp_config_path;
 	temp_string1 = new char[50];
@@ -75,7 +75,7 @@
 
 void write_config_file()
 {
-	ofstream b_file;
+	std::ofstream b_file;
 	char *temp_config_path;
 	char *temp_config_data;
 	temp_config_data = new char[80];
@@ -90,7 +90,7 @@
 	strcpy(temp_config_path, config_file_path);
 	#endif
 	
-	b_file.open(temp_config_path, ios::trunc);
+	b_file.open(temp_config_path, std::ios::trunc);
 	
 	sprintf(temp_config_data, "player1_name:%s\n", adam.name);
 	b_file<<temp_config_data;
