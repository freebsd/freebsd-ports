--- lib/inc/hocon/config_origin.hpp.orig	2016-09-23 20:45:10 UTC
+++ lib/inc/hocon/config_origin.hpp
@@ -36,7 +36,7 @@ namespace hocon {
          *
          * @return string describing the origin
          */
-        LIBCPP_HOCON_EXPORT virtual std::string const& description() const = 0;
+        CPP_HOCON_EXPORT virtual std::string const& description() const = 0;
 
         /**
          * Returns a {@code ConfigOrigin} based on this one, but with the given
@@ -55,7 +55,7 @@ namespace hocon {
          * @param lineNumber the new line number
          * @return the created ConfigOrigin
          */
-        LIBCPP_HOCON_EXPORT virtual shared_origin with_line_number(int line_number) const = 0;
+        CPP_HOCON_EXPORT virtual shared_origin with_line_number(int line_number) const = 0;
 
         /**
          * Returns a line number where the value or exception originated. This will
@@ -63,7 +63,7 @@ namespace hocon {
          *
          * @return line number or -1 if none is available
          */
-        LIBCPP_HOCON_EXPORT virtual int line_number() const = 0;
+        CPP_HOCON_EXPORT virtual int line_number() const = 0;
 
         /**
          * Returns any comments that appeared to "go with" this place in the file.
@@ -75,7 +75,7 @@ namespace hocon {
          * @return any comments that seemed to "go with" this origin, empty list if
          *         none
          */
-        LIBCPP_HOCON_EXPORT virtual std::vector<std::string> const& comments() const = 0;
+        CPP_HOCON_EXPORT virtual std::vector<std::string> const& comments() const = 0;
 
         /**
          * Returns a {@code config_origin} based on this one, but with the given
@@ -92,7 +92,7 @@ namespace hocon {
          * @param comments the comments used on the returned origin
          * @return the config_origin with the given comments
          */
-        LIBCPP_HOCON_EXPORT virtual shared_origin with_comments(std::vector<std::string> comments) const = 0;
+        CPP_HOCON_EXPORT virtual shared_origin with_comments(std::vector<std::string> comments) const = 0;
     };
 
 }  // namespace hocon
