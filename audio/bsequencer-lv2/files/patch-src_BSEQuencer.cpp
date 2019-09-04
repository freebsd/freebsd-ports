--- src/BSEQuencer.cpp.orig	2019-09-04 08:30:06 UTC
+++ src/BSEQuencer.cpp
@@ -626,7 +626,7 @@ void BSEQuencer::run (uint32_t n_samples)
 						PadMessage* pMes = (PadMessage*) (&vec->body + 1);
 
 						// Copy PadMessages to pads
-						for (uint i = 0; i < size; ++i)
+						for (unsigned i = 0; i < size; ++i)
 						{
 							int row = (int) pMes[i].row;
 							int step = (int) pMes[i].step;
