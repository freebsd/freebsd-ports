
$FreeBSD$

--- util/src/Yagol.h.orig	Tue Aug 10 16:42:48 2004
+++ util/src/Yagol.h	Tue Aug 10 16:43:29 2004
@@ -298,6 +298,8 @@
     template < class Type >
     string AboveRangeException<Type>::message() const
     {
+	Type value;
+	Type limit;
         return "value " + doctorj::StringUtilities::toString(value()) + 
             " is above the upper bound " + doctorj::StringUtilities::toString(limit());
     }
@@ -339,6 +341,8 @@
     template < class Type >
     string BelowRangeException<Type>::message() const
     {
+	Type value;
+	Type limit;
         return "value " + doctorj::StringUtilities::toString(value()) + 
             " is below the lower bound " + doctorj::StringUtilities::toString(limit());
     }
@@ -1991,7 +1995,7 @@
                                 vector<typename Container::value_type>* const values)
         {
             ArgCallback<vector< typename Container::value_type > >* validator = 
-                new GroupValidator<vector< typename Container::value_type > >(value, valids, nValids);
+                new GroupValidator<vector< typename Container::value_type > >(values, valids, nValids);
             return addOption(new OptionMultiValues<Container>(name, description, validator, strictArgs_));
         }
 
