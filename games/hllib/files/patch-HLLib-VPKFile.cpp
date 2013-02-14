--- ../orig/HLLib/VPKFile.cpp	2013-01-27 14:13:28.000000000 -0200
+++ ./HLLib/VPKFile.cpp	2013-02-11 17:56:51.297217265 -0200
@@ -415,9 +415,13 @@
 					hlAttributeSetUnsignedInteger(&Attribute, this->lpItemAttributeNames[eAttribute], pDirectoryItem->pDirectoryEntry->uiCRC, hlTrue);
 					return hlTrue;
 				}
+				default:
+					;
 			}
 			break;
 		}
+		default:
+			;
 	}
 
 	return hlFalse;
Only in ./HLLib: VPKFile.cpp.orig
diff -ru ../orig/HLLib/WADFile.cpp ./HLLib/WADFile.cpp
