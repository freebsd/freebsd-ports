diff --git Source/CPack/cmCPackFreeBSDGenerator.cxx Source/CPack/cmCPackFreeBSDGenerator.cxx
index 162dfc7346..206f2d06a0 100644
--- Source/CPack/cmCPackFreeBSDGenerator.cxx
+++ Source/CPack/cmCPackFreeBSDGenerator.cxx
@@ -245,8 +245,15 @@ public:
   void write_value(cmGeneratedFileStream& s) const override
   {
     s << "{\n";
-    for (std::string const& elem : value) {
-      s << "  \"" << elem << R"(": {"origin": ")" << elem << "\"},\n";
+    for (std::string const& origin : value) {
+      // Split the origin into its category and name components.
+      // Treat it like a path (which it sort-of is, in the ports tree).
+      // Because it is a "cat/name" style relative path, it gets split
+      // into "" "cat" and "name" parts.
+      std::vector<std::string> originComponents;
+      cmSystemTools::SplitPath(origin, originComponents);
+      const std::string name = (originComponents.size() == 3) ? originComponents[2] : origin;
+      s << "  \"" << name << R"(": {"origin": ")" << origin << "\"},\n";
     }
     s << '}';
   }
