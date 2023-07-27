--- src/slic3r/GUI/Field.cpp.orig	2023-07-25 09:29:18 UTC
+++ src/slic3r/GUI/Field.cpp
@@ -199,7 +199,7 @@ static wxString na_value(bool for_spin_ctrl = false)
 
 static wxString na_value(bool for_spin_ctrl = false)
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     if (for_spin_ctrl)
         return "";
 #endif
