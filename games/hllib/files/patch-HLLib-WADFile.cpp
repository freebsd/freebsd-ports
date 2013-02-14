--- ../orig/HLLib/WADFile.cpp	2010-10-31 22:56:14.000000000 -0200
+++ ./HLLib/WADFile.cpp	2013-02-11 17:56:51.300216459 -0200
@@ -200,9 +200,13 @@
 					hlAttributeSetUnsignedInteger(&Attribute, this->lpItemAttributeNames[eAttribute], (hlUInt)pLump->iType, hlTrue);
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
Only in ./HLLib: WADFile.cpp.orig
diff -ru ../orig/HLLib/XZPFile.cpp ./HLLib/XZPFile.cpp
