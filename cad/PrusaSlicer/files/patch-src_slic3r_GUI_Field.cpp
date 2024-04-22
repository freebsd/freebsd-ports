--- src/slic3r/GUI/Field.cpp.orig	2023-12-12 14:21:21 UTC
+++ src/slic3r/GUI/Field.cpp
@@ -221,7 +221,7 @@ bool Field::is_matched(const std::string& string, cons
 
 static wxString na_value(bool for_spin_ctrl = false)
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     if (for_spin_ctrl)
         return "";
 #endif
