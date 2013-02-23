--- ../orig/HLLib/BSPFile.cpp	2010-10-31 22:48:46.000000000 -0200
+++ ./HLLib/BSPFile.cpp	2013-02-11 17:56:51.271215107 -0200
@@ -203,10 +203,14 @@
 						hlAttributeSetUnsignedInteger(&Attribute, this->lpItemAttributeNames[eAttribute], uiPaletteSize, hlFalse);
 						return hlTrue;
 					}
+					default:
+						;
 				}
 			}
 			break;
 		}
+		default:
+			;
 	}
 
 	return hlFalse;
Only in ./HLLib: BSPFile.cpp.orig
diff -ru ../orig/HLLib/DirectoryFolder.cpp ./HLLib/DirectoryFolder.cpp
