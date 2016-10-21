--- cpp/test/IceGrid/deployer/AllTests.cpp.orig	2016-10-05 16:59:08.000000000 +0200
+++ cpp/test/IceGrid/deployer/AllTests.cpp	2016-10-11 23:09:05.053078910 +0200
@@ -126,21 +126,21 @@
         //
         // Test with empty file.
         //
-        string path = testDir + "/log1.txt";
+        string path = testDir + "/db/log1.txt";
         ofstream os(path.c_str());
         os.close();
 
-        it = session->openServerLog("LogServer", testDir + "/log1.txt", -1);
+        it = session->openServerLog("LogServer", testDir + "/db/log1.txt", -1);
         test(it->read(1024, lines) && lines.empty());
         test(it->read(1024, lines) && lines.empty());
         it->destroy();
 
-        it = session->openServerLog("LogServer", testDir + "/log1.txt", 0);
+        it = session->openServerLog("LogServer", testDir + "/db/log1.txt", 0);
         test(it->read(1024, lines) && lines.empty());
         test(it->read(1024, lines) && lines.empty());
         it->destroy();
 
-        it = session->openServerLog("LogServer", testDir + "/log1.txt", 100);
+        it = session->openServerLog("LogServer", testDir + "/db/log1.txt", 100);
         test(it->read(1024, lines) && lines.empty());
         test(it->read(1024, lines) && lines.empty());
         it->destroy();
@@ -156,29 +156,29 @@
         //
         // Test with log file with one line with no EOL on last line.
         //
-        string path = testDir + "/log2.txt";
+        string path = testDir + "/db/log2.txt";
         ofstream os(path.c_str());
         os << "one line file with no EOL on last line";
         os.close();
 
-        it = session->openServerLog("LogServer", testDir + "/log2.txt", -1);
+        it = session->openServerLog("LogServer", testDir + "/db/log2.txt", -1);
         test(it->read(1024, lines) && lines.size() == 1);
         test(lines[0] == "one line file with no EOL on last line");
         test(it->read(1024, lines) && lines.empty());
         it->destroy();
 
-        it = session->openServerLog("LogServer", testDir + "/log2.txt", 0);
+        it = session->openServerLog("LogServer", testDir + "/db/log2.txt", 0);
         test(it->read(1024, lines) && lines.empty());
         test(it->read(1024, lines) && lines.empty());
         it->destroy();
 
-        it = session->openServerLog("LogServer", testDir + "/log2.txt", 1);
+        it = session->openServerLog("LogServer", testDir + "/db/log2.txt", 1);
         test(it->read(1024, lines) && lines.size() == 1);
         test(lines[0] == "one line file with no EOL on last line");
         test(it->read(1024, lines) && lines.empty());
         it->destroy();
 
-        it = session->openServerLog("LogServer", testDir + "/log2.txt", 100);
+        it = session->openServerLog("LogServer", testDir + "/db/log2.txt", 100);
         test(it->read(1024, lines) && lines.size() == 1);
         test(lines[0] == "one line file with no EOL on last line");
         test(it->read(1024, lines) && lines.empty());
@@ -195,37 +195,37 @@
         //
         // Test with log file with one line with EOL on last line.
         //
-        string path = testDir + "/log3.txt";
+        string path = testDir + "/db/log3.txt";
         ofstream os(path.c_str());
         os << "one line file with EOL on last line" << endl;
         os.close();
 
-        it = session->openServerLog("LogServer", testDir + "/log3.txt", -1);
+        it = session->openServerLog("LogServer", testDir + "/db/log3.txt", -1);
         test(it->read(1024, lines) && lines.size() == 2);
         test(lines[0] == "one line file with EOL on last line");
         test(lines[1].empty());
         test(it->read(1024, lines) && lines.empty());
         it->destroy();
 
-        it = session->openServerLog("LogServer", testDir + "/log3.txt", 0);
+        it = session->openServerLog("LogServer", testDir + "/db/log3.txt", 0);
         test(it->read(1024, lines) && lines.empty());
         test(it->read(1024, lines) && lines.empty());
         it->destroy();
 
-        it = session->openServerLog("LogServer", testDir + "/log3.txt", 1);
+        it = session->openServerLog("LogServer", testDir + "/db/log3.txt", 1);
         test(it->read(1024, lines) && lines.size() == 2);
         test(lines[0] == "one line file with EOL on last line");
         test(lines[1].empty());
         test(it->read(1024, lines) && lines.empty());
         it->destroy();
 
-        it = session->openServerLog("LogServer", testDir + "/log3.txt", 100);
+        it = session->openServerLog("LogServer", testDir + "/db/log3.txt", 100);
         test(it->read(1024, lines) && lines.size() == 2);
         test(lines[0] == "one line file with EOL on last line");
         test(lines[1].empty());
         it->destroy();
 
-        it = session->openServerLog("LogServer", testDir + "/log3.txt", 2);
+        it = session->openServerLog("LogServer", testDir + "/db/log3.txt", 2);
         test(it->read(1024, lines) && lines.size() == 2);
         test(lines[0] == "one line file with EOL on last line");
         test(lines[1].empty());
@@ -242,14 +242,14 @@
         //
         // Test with log file with multiple lines
         //
-        string path = testDir + "/log4.txt";
+        string path = testDir + "/db/log4.txt";
         ofstream os(path.c_str());
         os << "line 1" << endl;
         os << "line 2" << endl;
         os << "line 3" << endl;
         os.close();
 
-        it = session->openServerLog("LogServer", testDir + "/log4.txt", -1);
+        it = session->openServerLog("LogServer", testDir + "/db/log4.txt", -1);
         test(it->read(1024, lines) && lines.size() == 4);
         test(lines[0] == "line 1");
         test(lines[1] == "line 2");
@@ -258,25 +258,25 @@
         test(it->read(1024, lines) && lines.empty());
         it->destroy();
 
-        it = session->openServerLog("LogServer", testDir + "/log4.txt", 0);
+        it = session->openServerLog("LogServer", testDir + "/db/log4.txt", 0);
         test(it->read(1024, lines) && lines.empty());
         test(it->read(1024, lines) && lines.empty());
         it->destroy();
 
-        it = session->openServerLog("LogServer", testDir + "/log4.txt", 1);
+        it = session->openServerLog("LogServer", testDir + "/db/log4.txt", 1);
         test(it->read(1024, lines) && lines.size() == 2);
         test(lines[0] == "line 3");
         test(lines[1].empty());
         it->destroy();
 
-        it = session->openServerLog("LogServer", testDir + "/log4.txt", 2);
+        it = session->openServerLog("LogServer", testDir + "/db/log4.txt", 2);
         test(it->read(1024, lines) && lines.size() == 3);
         test(lines[0] == "line 2");
         test(lines[1] == "line 3");
         test(lines[2].empty());
         it->destroy();
 
-        it = session->openServerLog("LogServer", testDir + "/log4.txt", 100);
+        it = session->openServerLog("LogServer", testDir + "/db/log4.txt", 100);
         test(it->read(1024, lines) && lines.size() == 4);
         test(lines[0] == "line 1");
         test(lines[1] == "line 2");
@@ -292,11 +292,11 @@
 
     try
     {
-        string path = testDir + "/log1.txt";
+        string path = testDir + "/db/log1.txt";
         ofstream os(path.c_str(), ios_base::out | ios_base::trunc);
         os << flush;
 
-        it = session->openServerLog("LogServer", testDir + "/log1.txt", -1);
+        it = session->openServerLog("LogServer", testDir + "/db/log1.txt", -1);
         test(it->read(1024, lines) && lines.empty());
 
         os << "started a line" << flush;
@@ -347,18 +347,18 @@
 
         it->destroy();
 
-        it = session->openServerLog("LogServer", testDir + "/log1.txt", 0);
+        it = session->openServerLog("LogServer", testDir + "/db/log1.txt", 0);
         test(it->read(1024, lines) && lines.empty());
         it->destroy();
 
-        it = session->openServerLog("LogServer", testDir + "/log1.txt", 1);
+        it = session->openServerLog("LogServer", testDir + "/db/log1.txt", 1);
         test(!it->read(1024, lines) && lines.size() == 1 && isLongLineStart(lines[0]));
         test(!it->read(1024, lines) && lines.size() == 1 && isLongLineContent(lines[0]));
         test(it->read(1024, lines) && lines.size() == 2 && isLongLineEnd(lines[0]) && lines[1].empty());
         test(it->read(1024, lines) && lines.empty());
         it->destroy();
 
-        it = session->openServerLog("LogServer", testDir + "/log1.txt", 2);
+        it = session->openServerLog("LogServer", testDir + "/db/log1.txt", 2);
         test(!it->read(1024, lines) && lines.size() == 1 && isLongLineStart(lines[0]));
         test(!it->read(1024, lines) && lines.size() == 1 && isLongLineContent(lines[0]));
         test(!it->read(1024, lines) && lines.size() == 2 && isLongLineEnd(lines[0]) && isLongLineStart(lines[1]));
