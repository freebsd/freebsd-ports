--- mimelib/mimelib/string.h.bak	2011-01-20 11:10:01.000000000 +0100
+++ mimelib/mimelib/string.h	2011-01-20 11:12:06.000000000 +0100
@@ -504,7 +504,7 @@
     //. {\tt DwString} object.  White space characters include ASCII HT,
     //. LF, and SPACE.
 
-    void WriteTo(ostream& aStrm) const;
+    void WriteTo(std::ostream& aStrm) const;
     //. Writes the contents of this {\tt DwString} object to the stream
     //. {\tt aStrm}.
 
@@ -569,7 +569,7 @@
 
 public:
 
-    virtual void PrintDebugInfo(ostream& aStrm) const;
+    virtual void PrintDebugInfo(std::ostream& aStrm) const;
     //. Prints debugging information about the object to {\tt aStrm}.
     //.
     //. This member function is available only in the debug version of
@@ -736,11 +736,11 @@
 DW_EXPORT DwBool operator >= (const DwString& aStr1, const char* aCstr);
 DW_EXPORT DwBool operator >= (const char* aCstr, const DwString& aStr2);
 
-DW_EXPORT ostream& operator << (ostream& aOstrm, const DwString& aStr);
+DW_EXPORT std::ostream& operator << (std::ostream& aOstrm, const DwString& aStr);
 //. Writes the contents of {\tt aStr} to the stream {\tt aOstrm}.
 
-DW_EXPORT istream& getline (istream& aIstrm, DwString& aStr, char aDelim);
-DW_EXPORT istream& getline (istream& aIstrm, DwString& aStr);
+DW_EXPORT std::istream& getline (std::istream& aIstrm, DwString& aStr, char aDelim);
+DW_EXPORT std::istream& getline (std::istream& aIstrm, DwString& aStr);
 
 DW_EXPORT int DwStrcasecmp(const DwString& aStr1, const DwString& aStr2);
 DW_EXPORT int DwStrcasecmp(const DwString& aStr1, const char* aCstr);
