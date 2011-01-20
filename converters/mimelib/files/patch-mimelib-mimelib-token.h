--- mimelib/mimelib/token.h.bak	1997-09-27 13:55:37.000000000 +0200
+++ mimelib/mimelib/token.h	2011-01-20 11:20:25.000000000 +0100
@@ -74,12 +74,12 @@
     const DwString& Token() const { return mToken; }
     int Type() const              { return mTkType; }
     void StripDelimiters();
-    static ostream* mDebugOut;
+    static std::ostream* mDebugOut;
 protected:
     DwTokenizer(const DwString& aStr);
     DwTokenizer(const char* aCStr);
     virtual ~DwTokenizer();
-    void PrintToken(ostream*);
+    void PrintToken(std::ostream*);
     // Quoted strings, comments, and domain literals are parsed
     // identically in RFC822 and RFC1521
     void ParseQuotedString();
