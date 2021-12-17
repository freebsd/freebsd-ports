--- lib/src/mind/ai/autolinking/naive_autolinking_preprocessor.cpp.orig	2020-03-08 17:03:52 UTC
+++ lib/src/mind/ai/autolinking/naive_autolinking_preprocessor.cpp
@@ -60,6 +60,11 @@ bool NaiveAutolinkingPreprocessor::containsLinkCodeMat
     return false;
 }
 
+static bool aliasSizeComparator(const Thing* t1, const Thing* t2)
+{
+    return t1->getAutolinkingAlias().size() > t2->getAutolinkingAlias().size();
+}
+
 void NaiveAutolinkingPreprocessor::updateThingsIndex()
 {
     // IMPROVE update indices only if an O/N is modified (except writing read timestamps)
@@ -145,7 +150,7 @@ void NaiveAutolinkingPreprocessor::process(const vecto
                     // IMPROVE loop to be changed to Aho-Corasic trie
 
                     // inject Os, then Ns
-                    for(Thing* t:mind.autolink()->getThings()) {
+                    for(Thing* t:things) {
                         size_t found;
                         bool match, insensitiveMatch;
                         string lowerAlias{};
