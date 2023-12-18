--- boost/boost_1_77_0/boost/move/detail/type_traits.hpp.orig	2021-08-05 09:42:11 UTC
+++ boost/boost_1_77_0/boost/move/detail/type_traits.hpp
@@ -1104,7 +1104,7 @@ struct alignment_struct
 typedef int (alignment_dummy::*member_ptr);
 typedef int (alignment_dummy::*member_function_ptr)();
 struct alignment_struct
-{  long double dummy[4];  };
+{  double XXXdummy[4];  };
 
 /////////////////////////////
 //    max_align_t
@@ -1122,7 +1122,7 @@ union max_align
    float       float_;
    double      double_;
    void *      void_ptr_;
-   long double long_double_[4];
+   double XXXlong_double_[4];
    alignment_dummy *unknown_class_ptr_;
    function_ptr function_ptr_;
    member_function_ptr member_function_ptr_;
