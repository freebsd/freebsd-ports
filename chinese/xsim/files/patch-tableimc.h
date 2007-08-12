--- plugins/IMs/table/tableimc.h.orig	2007-08-12 15:38:33.000000000 +0200
+++ plugins/IMs/table/tableimc.h	2007-08-12 15:38:58.000000000 +0200
@@ -23,7 +23,7 @@
 	uint8_t sort_index;
 	wchar_t w[MAX_WORD_LEN + 1];
 
-	size_t si_size() { return (uint32_t) w - (uint32_t)&sort_index; }
+	size_t si_size() { return (uintptr_t) w - (uintptr_t)&sort_index; }
 	size_t size(){ return si_size() + (wcslen(w) + 1) * sizeof(wchar_t); }
 	void copy(struct Word_Rec_tag * val) { memcpy(this, val, sizeof(Word_Rec_tag));}
 }Word_Rec;
