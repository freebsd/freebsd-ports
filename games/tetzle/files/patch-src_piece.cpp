Fixes crash caused by invalidating m_neighbours iterator by
removing the very element we're currently itarating over in
attach(). Reported upstream.

--- src/piece.cpp.orig	2025-01-06 15:00:16 UTC
+++ src/piece.cpp
@@ -94,6 +94,7 @@ void Piece::attachSolutionNeighbors()
 		if (delta.manhattanLength() <= m_attach_margin) {
 			piece->moveBy(delta);
 			attach(piece);
+			return;
 		}
 	}
 }
