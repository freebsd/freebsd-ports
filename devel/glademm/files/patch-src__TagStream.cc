--- src/TagStream.cc.orig	2013-09-24 21:52:55.000000000 +0900
+++ src/TagStream.cc	2013-09-24 21:55:38.000000000 +0900
@@ -20,7 +20,8 @@
 #include "TagStream.hh"
 #include <cstring>
 #include <unistd.h>
-#include <algo.h>
+#include <algorithm>
+#include <iostream>
 
 //#define REMEMBER_EMPTY_SPACE
 
@@ -73,10 +74,10 @@
 {  std::string ret;
    std::string::const_iterator i(cont.begin());
    while (i!=cont.end())
-   {  std::string::const_iterator verbatim(::find(i,cont.end(),'&'));
+   {  std::string::const_iterator verbatim(std::find(i,cont.end(),'&'));
       ret+=std::string(i,verbatim);
       if (verbatim!=cont.end())
-      {  std::string::const_iterator endtag(::find(verbatim,cont.end(),';'));
+      {  std::string::const_iterator endtag(std::find(verbatim,cont.end(),';'));
          if (endtag!=cont.end()) ++endtag;
          std::string tag(verbatim,endtag);
          if (tag[1]=='#' && tag[2]=='x')
