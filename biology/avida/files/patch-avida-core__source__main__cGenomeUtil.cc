--- avida-core/source/main/cGenomeUtil.cc.orig
+++ avida-core/source/main/cGenomeUtil.cc
@@ -214,7 +214,14 @@
  */
 void cGenomeUtil::RandomShuffle(cAvidaContext& ctx, Sequence& genome) {
 	std::vector<int> idx(static_cast<std::size_t>(genome.GetSize()));
-	std::iota(idx.begin(), idx.end(), 0);
+
+	std::vector<int>::iterator idx_it = idx.begin();
+	int value = 0;
+	while (idx_it != idx.end()) {
+		*idx_it++ = value;
+		++value;
+	}
+
 	cRandomStdAdaptor rng(ctx.GetRandom());
 	std::random_shuffle(idx.begin(), idx.end(), rng);
 	Sequence shuffled(genome.GetSize());
