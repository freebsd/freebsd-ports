--- src/emucore/Props.hxx.orig	Tue Feb 18 10:19:44 2003
+++ src/emucore/Props.hxx	Wed Sep 17 00:42:29 2003
@@ -79,14 +79,14 @@
 
       @param in The input stream to use
     */
-    void load(istream& in);
+    void load(std::istream& in);
  
     /**
       Save properties to the specified output stream
 
       @param out The output stream to use
     */
-    void save(ostream& out);
+    void save(std::ostream& out);
 
     /**
       Merge the given properties into this properties object
@@ -103,7 +103,7 @@
       @param in The input stream to use
       @return The string inside the quotes
     */ 
-    static string readQuotedString(istream& in);
+    static string readQuotedString(std::istream& in);
      
     /**
       Write the specified string to the given output stream as a 
@@ -112,7 +112,7 @@
       @param out The output stream to use
       @param s The string to output
     */ 
-    static void writeQuotedString(ostream& out, const string& s);
+    static void writeQuotedString(std::ostream& out, const string& s);
 
   public:
     /**
