--- avida-core/source/main/cPopulationInterface.cc.orig	2026-09-06 13:22:43 UTC
+++ avida-core/source/main/cPopulationInterface.cc
@@ -903,8 +903,8 @@ void cPopulationInterface::CreateLinkByXY(int x, int y
 	// cell coordinate.  the problem is that a 2s-complement int can hold a negative
 	// number whose absolute value is too large for the int to hold.  when this happens,
 	// abs returns the value unmodified.
-	int cellx = std::abs(static_cast<long long int>(x)) % deme->GetWidth();
-	int celly = std::abs(static_cast<long long int>(y)) % deme->GetHeight();
+	int cellx = llabs(static_cast<long long int>(x)) % deme->GetWidth();
+	int celly = llabs(static_cast<long long int>(y)) % deme->GetHeight();
 	assert(cellx >= 0);
 	assert(cellx < deme->GetWidth());
 	assert(celly >= 0);
@@ -921,7 +921,7 @@ void cPopulationInterface::CreateLinkByIndex(int idx, 
 	// cell coordinate.  the problem is that a 2s-complement int can hold a negative
 	// number whose absolute value is too large for the int to hold.  when this happens,
 	// abs returns the value unmodified.
-	int that_cell = std::abs(static_cast<long long int>(idx)) % deme->GetSize();
+	int that_cell = llabs(static_cast<long long int>(idx)) % deme->GetSize();
 	assert(that_cell >= 0);
 	assert(that_cell < deme->GetSize());
 	deme->GetNetwork().Connect(*this_cell, deme->GetCell(that_cell), weight);
