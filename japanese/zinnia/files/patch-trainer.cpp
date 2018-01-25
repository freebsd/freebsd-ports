--- trainer.cpp.orig	2010-05-09 05:34:08 UTC
+++ trainer.cpp
@@ -93,7 +93,7 @@ class TrainerImpl: public Trainer {
 
  public:
   bool add(const Character &character) {
-    const std::string y = character.value();
+    std::string y = character.value();
     CHECK_FALSE(!y.empty()) << "input character is empty";
     Features features;
     CHECK_FALSE(features.read(character)) << "cannot read character: " << y;
@@ -103,7 +103,7 @@ class TrainerImpl: public Trainer {
     if (!fn) {
       return false;
     }
-    x_.push_back(std::make_pair<std::string, FeatureNode *>(y, fn));
+    x_.push_back(std::make_pair(y, fn));
     return true;
   }
 
