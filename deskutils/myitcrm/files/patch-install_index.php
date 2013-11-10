--- ./install/indexold.php	2013-11-06 11:05:07.000000000 -0900
+++ ./install/index.php	2013-11-06 11:07:16.000000000 -0900
@@ -1260,9 +1260,8 @@
 #####################################
 #		Set Path					#
 #####################################
-function set_path($_POST) 
+function set_path() 
 {
-	
 	$install_date = date("M d Y h:i:s A" ,time());
 	$filename = '../conf.php';
 	$path2 = 'default_site_name';
