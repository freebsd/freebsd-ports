--- src/zhcon.cpp.orig	Sun Feb 17 02:12:17 2002
+++ src/zhcon.cpp	Sun Feb 24 14:31:41 2002
@@ -113,7 +113,7 @@
     string cfgfile = getenv("HOME");
     cfgfile += "/.zhconrc";
     if (access(cfgfile.c_str(), R_OK) != 0)
-        cfgfile = "/etc/zhcon.conf";
+        cfgfile = PREFIX"/etc/zhcon.conf";
 
 //    char c;cin>>c;
     ConfigFile f(cfgfile.c_str());
@@ -129,6 +129,7 @@
     InstallVtHandle();
     InstallSignal();
     ForkPty();
+    SetEncode(mDefaultEncode, mDefaultEncode);
     InitInputManager(f);
     if (f.GetOption("startupmsg",true))
         StartupMsg();
@@ -489,23 +490,23 @@
     string s;
     s = f.GetOption(string("defaultencode"), string("gb2312"));
     if (s == "gb2312") {
-        SetEncode(GB2312,GB2312);
+        //SetEncode(GB2312,GB2312);
         setenv("LC_ALL", "zh_CN.GB2312", 1);
         mDefaultEncode = GB2312;
     } else if (s == "gbk") {
-        SetEncode(GBK,GBK);
+        //SetEncode(GBK,GBK);
         setenv("LC_ALL", "zh_CN.GBK", 1);
         mDefaultEncode = GBK;
     } else if (s == "big5") {
-        SetEncode(BIG5,BIG5);
+        //SetEncode(BIG5,BIG5);
         setenv("LC_ALL", "zh_TW.Big5", 1);
         mDefaultEncode = BIG5;
     } else if (s == "jis") {
-        SetEncode(JIS,JIS);
+        //SetEncode(JIS,JIS);
         setenv("LC_ALL", "ja.JIS", 1);
         mDefaultEncode = JIS;
     } else if (s == "kscm") {
-        SetEncode(KSCM,KSCM);
+        //SetEncode(KSCM,KSCM);
         setenv("LC_ALL", "ko", 1);
         mDefaultEncode = GBK;
     } else {
