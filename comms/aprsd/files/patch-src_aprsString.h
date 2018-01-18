--- src/aprsString.h.orig	2003-10-01 16:58:27 UTC
+++ src/aprsString.h
@@ -196,7 +196,8 @@ class aprsString: public string (public)
    void parseLogon(void);
    bool parseCommand(void);
    bool parsePortFilter(void);
-   void aprsString::getMsgText(string& msg);
+//   void aprsString::getMsgText(string& msg);
+   void getMsgText(string& msg);
    void print(ostream& os);
    string getAX25Source(void);
    string getAX25Dest(void);
