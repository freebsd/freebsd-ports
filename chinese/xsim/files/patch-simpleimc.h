--- plugins/IMs/jianpin/simpleimc.h.orig	2007-08-12 15:33:23.000000000 +0200
+++ plugins/IMs/jianpin/simpleimc.h	2007-08-12 15:34:18.000000000 +0200
@@ -45,7 +45,7 @@
 	uint16_t access_count;
 	wchar_t w[MAX_WORD_LEN + 1];
 
-	size_t ac_size() { return (uint32_t) w - (uint32_t)&access_count; }
+	size_t ac_size() { return (uintptr_t) w - (uintptr_t)&access_count; }
 	size_t size(){ return ac_size() + wcslen(w) * sizeof(wchar_t); }
 	void copy(struct Word_Rec_tag * val) { memcpy(this, val, sizeof(Word_Rec_tag));}
 }Word_Rec;
