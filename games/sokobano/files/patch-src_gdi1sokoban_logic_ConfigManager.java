--- src/gdi1sokoban/logic/ConfigManager.java.orig	2009-03-26 21:46:24 UTC
+++ src/gdi1sokoban/logic/ConfigManager.java
@@ -10,7 +10,9 @@ import java.io.ObjectOutputStream;
 
 public class ConfigManager {
 
-	private static final String GL_CONFIG_PATH ="res"+File.separator+"config"+File.separator+"global.cfg";
+	private static final String GL_CONFIG_PATH =
+	    System.getProperty("user.home") + File.separator + ".config" +
+	    File.separator + "sokobano" + File.separator + "global.cfg";
 
 	private static ConfigManager _instance;
 
