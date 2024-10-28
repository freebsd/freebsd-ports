--- src/slic3r/GUI/Field.cpp.orig	2024-09-18 13:39:04 UTC
+++ src/slic3r/GUI/Field.cpp
@@ -222,7 +222,7 @@ static wxString na_value(bool for_spin_ctrl = false)
 
 static wxString na_value(bool for_spin_ctrl = false)
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     if (for_spin_ctrl)
         return "";
 #endif
