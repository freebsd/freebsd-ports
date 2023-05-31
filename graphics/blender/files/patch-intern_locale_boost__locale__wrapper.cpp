https://bugs.gentoo.org/887059

Adding include as suggested by the compiler:

"intern/locale/boost_locale_wrapper.cpp:12:1: note: ‘std::cout’ is defined 
in header ‘<iostream>’; did you forget to ‘#include <iostream>’?"

--- intern/locale/boost_locale_wrapper.cpp.orig	2023-02-15 14:56:19 UTC
+++ intern/locale/boost_locale_wrapper.cpp
@@ -10,6 +10,7 @@
 #include <stdio.h>
 
 #include "boost_locale_wrapper.h"
+#include <iostream>
 
 static std::string messages_path;
 static std::string default_domain;
