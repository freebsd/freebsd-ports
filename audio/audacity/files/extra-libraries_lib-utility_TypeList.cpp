--- libraries/lib-utility/TypeList.cpp.orig	2023-11-16 11:58:21 UTC
+++ libraries/lib-utility/TypeList.cpp
@@ -118,16 +118,16 @@ static_assert(Is_v<NullOrStartsWithInt, Nil>);
 static_assert(Is_v<NullOrStartsWithInt, Example>);
 
 static_assert(Every_v<Fn<is_arithmetic>, Example>);
-static_assert(is_base_of_v<true_type, Every<Fn<is_arithmetic>, Example>>);
+static_assert(TypeList::is_base_of_v<true_type, Every<Fn<is_arithmetic>, Example>>);
 static_assert(!Every_v<Fn<is_integral>, Example>);
-static_assert(is_base_of_v<is_integral<double>,
+static_assert(TypeList::is_base_of_v<is_integral<double>,
    Every<Fn<is_integral>, Example>>);
 
 static_assert(Some_v<Fn<is_integral>, Example>);
-static_assert(is_base_of_v<is_integral<int>,
+static_assert(TypeList::is_base_of_v<is_integral<int>,
    Some<Fn<is_integral>, Example>>);
 static_assert(!Some_v<Fn<is_void>, Example>);
-static_assert(is_base_of_v<false_type, Some<Fn<is_void>, Example>>);
+static_assert(TypeList::is_base_of_v<false_type, Some<Fn<is_void>, Example>>);
 
 static_assert(NotEvery_v<Fn<is_floating_point>, Example>);
 static_assert(NotAny_v<Fn<is_void>, Example>);
