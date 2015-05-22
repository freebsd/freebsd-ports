--- README.md.orig
+++ README.md
@@ -25,7 +25,7 @@
 
 Installing Globally
 ===================
-_Note that this install currently clobbers any previous /etc/phpsh/rc.php_  
+_Note that this install currently clobbers any previous %%ETCDIR%%/rc.php_  
 * `python setup.py build`  
 * `sudo python setup.py install`  
 * `phpsh`  
@@ -56,7 +56,7 @@
 
 Autoloading
 -----------
-* Modify /etc/phpsh/rc.php. Then:
+* Modify %%ETCDIR%%/rc.php. Then:
   * `cd ~/www`  
   * `phpsh`  
 * And for times when you just want vanilla php:
