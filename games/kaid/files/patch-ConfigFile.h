--- ConfigFile.h	Sun Feb  6 10:40:17 2005
--- ConfigFile.h	Sun Feb 27 06:50:15 2005
@@ -20,6 +20,9 @@
     int             OrbPort;
 	int				Verbosity;
     bool            UseIPv6;
+#ifdef PLATFORM_freebsd
+    string	    User;
+#endif
     
     string			UIBind;
     string			UIIP;
