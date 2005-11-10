--- Tomboy/Trie.cs.orig	Thu May  5 14:11:16 2005
+++ Tomboy/Trie.cs	Sat Sep 10 20:01:33 2005
@@ -132,7 +132,7 @@
 					while (m != null) {
 						TrieState q1 = m.State;
 						TrieState r = q.Fail;
-						TrieMatch n;
+						TrieMatch n = null;
 
 						while (r != null) {
 							n = FindMatchAtState (r, m.Value);
