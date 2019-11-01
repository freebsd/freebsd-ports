--- pdf-unicode.hh.orig	2019-10-27 19:18:36.768779000 +0000
+++ pdf-unicode.hh	2019-10-27 19:19:00.052652000 +0000
@@ -58,7 +58,7 @@
         Unicode* data;
         int length_;
     public:
-        explicit FullNFKC(Unicode *, int length);
+        explicit FullNFKC(const Unicode *, int length);
         ~FullNFKC();
         int length() const
         {
@@ -79,7 +79,7 @@
     protected:
         std::basic_string<Unicode> string;
     public:
-        explicit MinimalNFKC(Unicode *, int length);
+        explicit MinimalNFKC(const Unicode *, int length);
         int length() const;
         operator const Unicode*() const;
     };
