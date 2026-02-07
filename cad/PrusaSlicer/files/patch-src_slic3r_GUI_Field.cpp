--- src/slic3r/GUI/Field.cpp.orig	2024-12-20 11:54:34 UTC
+++ src/slic3r/GUI/Field.cpp
@@ -222,7 +222,7 @@ static wxString na_value(bool for_spin_ctrl = false)
 
 static wxString na_value(bool for_spin_ctrl = false)
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     if (for_spin_ctrl)
         return "";
 #endif
