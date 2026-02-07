--- external/pufferfish/external/twopaco/graphconstructor/assemblyedgeconstructor.h.orig	2021-12-05 16:28:24 UTC
+++ external/pufferfish/external/twopaco/graphconstructor/assemblyedgeconstructor.h
@@ -30,10 +30,10 @@ namespace TwoPaCo
 				{
 					std::string vertex = chr.substr(i, vertexLength);
 					//Check if the Bloom filter contains an edge
-					assert(IsOutgoingEdgeInBloomFilter(hash, *bloomFilter, chr[i + edgeLength - 1]));
+					// assert(IsOutgoingEdgeInBloomFilter(hash, *bloomFilter, chr[i + edgeLength - 1]));
 					if (i > 0)
 					{
-						assert(IsIngoingEdgeInBloomFilter(hash, *bloomFilter, chr[i - 1]));
+						// assert(IsIngoingEdgeInBloomFilter(hash, *bloomFilter, chr[i - 1]));
 					}
 					
 					//Check the if the vertex is a junction
@@ -58,4 +58,4 @@ namespace TwoPaCo
 
 }
 
-#endif
\ No newline at end of file
+#endif
