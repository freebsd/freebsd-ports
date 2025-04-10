--- poppler/FlateStream.h.orig	2025-04-09 19:14:40 UTC
+++ poppler/FlateStream.h
@@ -45,7 +45,7 @@ class FlateStream : public FilterStream (public)
     int lookChar() override;
     int getRawChar() override;
     void getRawChars(int nChars, int *buffer) override;
-    GooString *getPSFilter(int psLevel, const char *indent) override;
+    std::optional<std::string> getPSFilter(int psLevel, const char *indent) override;
     bool isBinary(bool last = true) const override;
 
 private:
