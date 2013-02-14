--- ../orig/HLLib/NCFFile.cpp	2010-10-31 22:48:26.000000000 -0200
+++ ./HLLib/NCFFile.cpp	2013-02-11 17:56:51.287210992 -0200
@@ -347,6 +347,8 @@
 					hlAttributeSetUnsignedInteger(&Attribute, this->lpItemAttributeNames[eAttribute], this->lpDirectoryEntries[pFile->GetID()].uiDirectoryFlags, hlTrue);
 					return hlTrue;
 				}
+				default:
+					;
 			}
 			break;
 		}
@@ -360,9 +362,13 @@
 					hlAttributeSetUnsignedInteger(&Attribute, this->lpItemAttributeNames[eAttribute], this->lpDirectoryEntries[pFolder->GetID()].uiDirectoryFlags, hlTrue);
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
Only in ./HLLib: NCFFile.cpp.orig
diff -ru ../orig/HLLib/SGAFile.cpp ./HLLib/SGAFile.cpp
