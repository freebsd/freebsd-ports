--- code/game/q_shared.h.orig	Tue Aug 16 02:10:07 2005
+++ code/game/q_shared.h	Tue Aug 23 14:16:34 2005
@@ -452,13 +452,9 @@
 void *Hunk_Alloc( int size, ha_pref preference );
 #endif
 
-#ifdef __linux__
 // https://zerowing.idsoftware.com/bugzilla/show_bug.cgi?id=371
 // custom Snd_Memset implementation for glibc memset bug workaround
 void Snd_Memset (void* dest, const int val, const size_t count);
-#else
-#define Snd_Memset Com_Memset
-#endif
 
 #if !( defined __VECTORC )
 void Com_Memset (void* dest, const int val, const size_t count);
