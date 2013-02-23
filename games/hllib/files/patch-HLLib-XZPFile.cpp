--- ../orig/HLLib/XZPFile.cpp	2010-10-31 22:49:18.000000000 -0200
+++ ./HLLib/XZPFile.cpp	2013-02-11 17:56:51.302217604 -0200
@@ -197,7 +197,7 @@
 		for(hlUInt i = 0; i < this->pHeader->uiDirectoryEntryCount; i++)
 		{
 			hlChar lpTemp[16] = "";
-			hlChar *lpLookup[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f" };
+			const hlChar *lpLookup[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f" };
 			for(hlByte *lpCRC = (hlByte *)&this->lpDirectoryEntries[i].uiFileNameCRC; lpCRC < (hlByte *)&this->lpDirectoryEntries[i].uiFileNameCRC + sizeof(hlUInt); lpCRC++)
 			{
 				strcat(lpTemp, lpLookup[(hlByte)(*lpCRC >> 4)]);
@@ -299,9 +299,13 @@
 					hlAttributeSetUnsignedInteger(&Attribute, this->lpItemAttributeNames[eAttribute], uiSize, hlFalse);
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
Only in ./HLLib: XZPFile.cpp.orig
diff -ru ../orig/HLLib/ZIPFile.cpp ./HLLib/ZIPFile.cpp
