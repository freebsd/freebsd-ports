--- ./boost/boost_1_77_0/boost/move/detail/type_traits.hpp.ORIG	2021-08-05 11:42:11.000000000 +0200
+++ ./boost/boost_1_77_0/boost/move/detail/type_traits.hpp	2023-11-04 13:09:44.198320000 +0100
@@ -1104,7 +1104,7 @@
 typedef int (alignment_dummy::*member_ptr);
 typedef int (alignment_dummy::*member_function_ptr)();
 struct alignment_struct
-{  long double dummy[4];  };
+{  double XXXdummy[4];  };
 
 /////////////////////////////
 //    max_align_t
@@ -1122,7 +1122,7 @@
    float       float_;
    double      double_;
    void *      void_ptr_;
-   long double long_double_[4];
+   double XXXlong_double_[4];
    alignment_dummy *unknown_class_ptr_;
    function_ptr function_ptr_;
    member_function_ptr member_function_ptr_;
