--- /home/tg/.BACKUP/!home!tg!work!FreeBSD!ports!local!freedoko!work!FreeDoko_0.6.3!src!misc!setting.cpp~	Wed May  5 12:31:09 2004
+++ misc/setting.cpp	Fri Jun  4 09:59:07 2004
@@ -399,8 +399,9 @@
       break;
     case LANGUAGE:
 #ifdef LINUX
-      if (string(getenv("LANG"), 0, 2) == string("de"))
-	value = "de";
+      if (getenv("LANG"))
+        if (string(getenv("LANG"), 0, 2) == string("de"))
+          value = "de";
 #endif
 #ifdef WINDOWS
       value = DK::Utils::Windows::Reg_read(HKEY_LOCAL_MACHINE,
