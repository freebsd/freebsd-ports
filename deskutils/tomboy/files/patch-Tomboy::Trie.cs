--- Tomboy/Trie.cs.orig	Tue Jan 18 02:33:54 2005
+++ Tomboy/Trie.cs	Thu May 12 20:07:03 2005
@@ -186,7 +186,7 @@
 					 MatchHandler match_handler)
 		{
 			TrieState q = root;
-			TrieMatch m;
+			TrieMatch m = null;
 			int idx = 0, start_idx = 0, last_idx = 0;
 
 			while (idx < haystack.Length) {
