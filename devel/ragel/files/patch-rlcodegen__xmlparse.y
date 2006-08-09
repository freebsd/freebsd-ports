--- rlcodegen/xmlparse.y.orig	Sun Jul 30 22:41:37 2006
+++ rlcodegen/xmlparse.y	Wed Aug  9 01:05:51 2006
@@ -474,7 +474,7 @@
 			cgd->initStateCondList( curState, length );
 			curStateCond = 0;
 		}
-	}
+	};
 
 StateCondList:
 	StateCondList StateCond |
@@ -488,7 +488,7 @@
 		Key highKey = readKey( td, &td );
 		long condId = readOffsetPtr( td, &td );
 		cgd->addStateCond( curState, lowKey, highKey, condId );
-	}
+	};
 	
 TagTransList:
 	TagTransListHead
