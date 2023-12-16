commit 642dc602f89b2c11d5d833a52f37b04427a27cab
Author: Marek Polacek <polacek@redhat.com>
Date:   2020-05-15T23:54:05+02:00

    c++: Regenerate cp/cfns.h.
    
    Current cfns.h includes register-qualified variables and that wouldn't
    play well when bootstrapping with GCC that uses the C++17 dialect,
    because 'register' was removed in C++17.  Regenerating it using the
    command specified in cfns.h luckily cleaned this up.
    
            * cfns.h: Regenerated.

--- gcc/cp/cfns.h.orig	2023-07-07 07:08:19 UTC
+++ gcc/cp/cfns.h
@@ -1,4 +1,4 @@
-/* C++ code produced by gperf version 3.0.4 */
+/* C++ code produced by gperf version 3.1 */
 /* Command-line: gperf -o -C -E -k '1-6,$' -j1 -D -N libc_name_p -L C++ --output-file cfns.h cfns.gperf  */
 
 #if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
@@ -25,7 +25,7 @@
       && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
       && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
 /* The character set is not based on ISO-646.  */
-#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
+#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gperf@gnu.org>."
 #endif
 
 #line 4 "cfns.gperf"
@@ -54,13 +54,13 @@ class libc_name (private)
 class libc_name
 {
 private:
-  static inline unsigned int hash (const char *str, unsigned int len);
+  static inline unsigned int hash (const char *str, size_t len);
 public:
-  static const struct libc_name_struct *libc_name_p (const char *str, unsigned int len);
+  static const struct libc_name_struct *libc_name_p (const char *str, size_t len);
 };
 
 inline unsigned int
-libc_name::hash (register const char *str, register unsigned int len)
+libc_name::hash (const char *str, size_t len)
 {
   static const unsigned short asso_values[] =
     {
@@ -91,34 +91,34 @@ libc_name::hash (register const char *str, register un
       1488, 1488, 1488, 1488, 1488, 1488, 1488, 1488, 1488, 1488,
       1488, 1488, 1488, 1488, 1488, 1488, 1488
     };
-  register int hval = len;
+  unsigned int hval = len;
 
   switch (hval)
     {
       default:
-        hval += asso_values[(unsigned char)str[5]+1];
+        hval += asso_values[static_cast<unsigned char>(str[5]+1)];
       /*FALLTHROUGH*/
       case 5:
-        hval += asso_values[(unsigned char)str[4]];
+        hval += asso_values[static_cast<unsigned char>(str[4])];
       /*FALLTHROUGH*/
       case 4:
-        hval += asso_values[(unsigned char)str[3]];
+        hval += asso_values[static_cast<unsigned char>(str[3])];
       /*FALLTHROUGH*/
       case 3:
-        hval += asso_values[(unsigned char)str[2]];
+        hval += asso_values[static_cast<unsigned char>(str[2])];
       /*FALLTHROUGH*/
       case 2:
-        hval += asso_values[(unsigned char)str[1]+1];
+        hval += asso_values[static_cast<unsigned char>(str[1]+1)];
       /*FALLTHROUGH*/
       case 1:
-        hval += asso_values[(unsigned char)str[0]];
+        hval += asso_values[static_cast<unsigned char>(str[0])];
         break;
     }
-  return hval + asso_values[(unsigned char)str[len - 1]];
+  return hval + asso_values[static_cast<unsigned char>(str[len - 1])];
 }
 
 const struct libc_name_struct *
-libc_name::libc_name_p (register const char *str, register unsigned int len)
+libc_name::libc_name_p (const char *str, size_t len)
 {
   enum
     {
@@ -1116,15 +1116,15 @@ libc_name::libc_name_p (register const char *str, regi
 
   if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
     {
-      register int key = hash (str, len);
+      unsigned int key = hash (str, len);
 
-      if (key <= MAX_HASH_VALUE && key >= 0)
+      if (key <= MAX_HASH_VALUE)
         {
-          register int index = lookup[key];
+          int index = lookup[key];
 
           if (index >= 0)
             {
-              register const char *s = wordlist[index].name;
+              const char *s = wordlist[index].name;
 
               if (*str == *s && !strcmp (str + 1, s + 1))
                 return &wordlist[index];
