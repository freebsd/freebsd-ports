--- src/libtomcrypt/src/headers/tomcrypt_macros.h.orig	2015-06-20 16:57:25 UTC
+++ src/libtomcrypt/src/headers/tomcrypt_macros.h
@@ -262,21 +262,19 @@ static inline __attribute__((always_inli
 
 #ifndef LTC_NO_ROLC
 
-static inline __attribute__((always_inline)) unsigned ROLc(unsigned word, const int i)
-{
-   asm ("roll %2,%0"
-      :"=r" (word)
-      :"0" (word),"I" (i));
-   return word;
-}
+#define ROLc(word, i) ({     \
+   unsigned _word = word;    \
+   asm ("roll %2,%0"         \
+      :"=r" (_word)          \
+      :"0" (_word),"I" (i)); \
+   _word; })
 
-static inline __attribute__((always_inline)) unsigned RORc(unsigned word, const int i)
-{
-   asm ("rorl %2,%0"
-      :"=r" (word)
-      :"0" (word),"I" (i));
-   return word;
-}
+#define RORc(word, i) ({     \
+   unsigned _word = word;    \
+   asm ("rorl %2,%0"         \
+      :"=r" (_word)          \
+      :"0" (_word),"I" (i)); \
+   _word; })
 
 #else
 
@@ -305,21 +303,19 @@ static inline __attribute__((always_inli
 
 #ifndef LTC_NO_ROLC
 
-static inline __attribute__((always_inline)) unsigned ROLc(unsigned word, const int i)
-{
-   asm ("rotlwi %0,%0,%2"
-      :"=r" (word)
-      :"0" (word),"I" (i));
-   return word;
-}
+#define ROLc(word, i) ({     \
+   unsigned _word = word;    \
+   asm ("rotlwi %0,%0,%2"    \
+      :"=r" (_word)          \
+      :"0" (_word),"I" (i)); \
+   _word; })
 
-static inline __attribute__((always_inline)) unsigned RORc(unsigned word, const int i)
-{
-   asm ("rotrwi %0,%0,%2"
-      :"=r" (word)
-      :"0" (word),"I" (i));
-   return word;
-}
+#define RORc(word, i) ({     \
+   unsigned _word = word;    \
+   asm ("rotrwi %0,%0,%2"    \
+      :"=r" (_word)          \
+      :"0" (_word),"I" (i)); \
+   _word; })
 
 #else
 
@@ -361,21 +357,19 @@ static inline __attribute__((always_inli
 
 #ifndef LTC_NO_ROLC
 
-static inline __attribute__((always_inline)) unsigned long ROL64c(unsigned long word, const int i)
-{
-   asm("rolq %2,%0"
-      :"=r" (word)
-      :"0" (word),"J" (i));
-   return word;
-}
+#define ROL64c(word, i) ({     \
+   unsigned long _word = word; \
+   asm ("rolq %2,%0"           \
+      :"=r" (_word)            \
+      :"0" (_word),"J" (i));   \
+   _word; })
 
-static inline __attribute__((always_inline)) unsigned long ROR64c(unsigned long word, const int i)
-{
-   asm("rorq %2,%0"
-      :"=r" (word)
-      :"0" (word),"J" (i));
-   return word;
-}
+#define ROR64c(word, i) ({     \
+   unsigned long _word = word; \
+   asm ("rorq %2,%0"           \
+      :"=r" (_word)            \
+      :"0" (_word),"J" (i));   \
+   _word; })
 
 #else /* LTC_NO_ROLC */
 
