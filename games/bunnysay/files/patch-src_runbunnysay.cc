--- src/runbunnysay.cc.orig	2017-02-28 03:26:39 UTC
+++ src/runbunnysay.cc
@@ -20,7 +20,6 @@
 */
 #include "bunnysay.h"
 #include <iostream>
-#include <iterator>
 #include <string>
 
 void usage(char *prog) {
@@ -33,9 +32,10 @@ void usage(char *prog) {
 int main(int argc, char **argv) {
   std::string buff;
   if (argc >= 2 && std::string(argv[1]) == "--") {
-    std::istream_iterator<char> it(std::cin);
-    std::istream_iterator<char> end;
-    buff = std::string(it, end);
+    std::string line;
+    while (std::getline(std::cin, line)) {
+      buff += std::string(line);
+    }
   } else if (argc >= 2) {
     for (int i = 1; i < argc; i++) {
       if (i != 1) {
