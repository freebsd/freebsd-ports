--- src/Tokenizer.cc.orig	2019-06-23 12:39:20 UTC
+++ src/Tokenizer.cc
@@ -755,10 +755,10 @@ enum { MAX_TOKENIZE_DIGITS_1 = 20,                    
        MAX_TOKENIZE_DIGITS = MAX_TOKENIZE_DIGITS_1 - 1   // excl. rounding digit
      };
 
-#define exp_0_9(x) x ## 0L, x ## 1L, x ## 2L, x ## 3L, x ## 4L,  \
-                           x ## 5L, x ## 6L, x ## 7L, x ## 8L, x ## 9L, 
+#define exp_0_9(x) x ## 0, x ## 1, x ## 2, x ## 3, x ## 4,  \
+                           x ## 5, x ## 6, x ## 7, x ## 8, x ## 9,
 
-static const long double expo_tab[310] = 
+static const long double expo_tab[309] = 
 {
    exp_0_9(1E)   exp_0_9(1E1)  exp_0_9(1E2)  exp_0_9(1E3)  exp_0_9(1E4)
    exp_0_9(1E5)  exp_0_9(1E6)  exp_0_9(1E7)  exp_0_9(1E8)  exp_0_9(1E9)
@@ -766,7 +766,7 @@ static const long double expo_tab[310] = 
    exp_0_9(1E15) exp_0_9(1E16) exp_0_9(1E17) exp_0_9(1E18) exp_0_9(1E19)
    exp_0_9(1E20) exp_0_9(1E21) exp_0_9(1E22) exp_0_9(1E23) exp_0_9(1E24)
    exp_0_9(1E25) exp_0_9(1E26) exp_0_9(1E27) exp_0_9(1E28) exp_0_9(1E29)
-   exp_0_9(1E30)
+   1E300, 1E301, 1E302, 1E303, 1E304, 1E305, 1E306, 1E307, 1E308
 };
 
 static const long double nexpo_tab[310] = 
@@ -960,6 +960,7 @@ UTF8_string digits = int_digits;
 
         if (expo > 0)
            {
+             if (expo > 308)   return false;
              if (negative)   flt_val = - v * expo_tab[expo];
              else            flt_val =   v * expo_tab[expo];
              return true;   // OK
