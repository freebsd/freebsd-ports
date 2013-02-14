--- ../orig/HLLib/VBSPFile.cpp	2011-05-22 07:53:42.000000000 -0300
+++ ./HLLib/VBSPFile.cpp	2013-02-11 17:56:51.294217852 -0200
@@ -422,6 +422,8 @@
 						delete []lpComment;
 						return hlTrue;
 					}
+					default:
+						;
 				}
 			}
 			else
@@ -444,6 +446,8 @@
 						hlAttributeSetUnsignedInteger(&Attribute, this->lpItemAttributeNames[eAttribute], *(hlUInt *)this->pHeader->lpLumps[uiID].lpFourCC, hlTrue);
 						return hlTrue;
 					}
+					default:
+						;
 				}
 
 				if(this->pEndOfCentralDirectoryRecord != 0 && pItem->GetID() == HL_VBSP_LUMP_PAKFILE)
@@ -466,11 +470,15 @@
 							delete []lpComment;
 							return hlTrue;
 						}
+						default:
+							;
 					}
 				}
 			}
 			break;
 		}
+		default:
+			;
 	}
 
 	return hlFalse;
Only in ./HLLib: VBSPFile.cpp.orig
diff -ru ../orig/HLLib/VPKFile.cpp ./HLLib/VPKFile.cpp
