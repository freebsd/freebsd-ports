--- src/aprsString.h.orig	2008-01-12 18:11:00.000000000 -0500
+++ src/aprsString.h	2008-01-12 18:11:35.000000000 -0500
@@ -196,7 +196,8 @@
    void parseLogon(void);
    bool parseCommand(void);
    bool parsePortFilter(void);
-   void aprsString::getMsgText(string& msg);
+//   void aprsString::getMsgText(string& msg);
+   void getMsgText(string& msg);
    void print(ostream& os);
    string getAX25Source(void);
    string getAX25Dest(void);
