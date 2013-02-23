--- ../orig/HLLib/DirectoryFolder.cpp	2012-09-17 20:16:52.000000000 -0300
+++ ./HLLib/DirectoryFolder.cpp	2013-02-11 17:56:51.275211034 -0200
@@ -517,6 +517,8 @@
 		case HL_ITEM_FILE:
 			uiSize += static_cast<const CDirectoryFile *>(pItem)->GetSize();
 			break;
+		default:
+			;
 		}
 	}
 
@@ -541,6 +543,8 @@
 		case HL_ITEM_FILE:
 			uiSize += static_cast<hlULongLong>(static_cast<const CDirectoryFile *>(pItem)->GetSize());
 			break;
+		default:
+			;
 		}
 	}
 
@@ -565,6 +569,8 @@
 		case HL_ITEM_FILE:
 			uiSize += static_cast<const CDirectoryFile *>(pItem)->GetSizeOnDisk();
 			break;
+		default:
+			;
 		}
 	}
 
@@ -589,6 +595,8 @@
 		case HL_ITEM_FILE:
 			uiSize += static_cast<hlULongLong>(static_cast<const CDirectoryFile *>(pItem)->GetSizeOnDisk());
 			break;
+		default:
+			;
 		}
 	}
 
@@ -611,6 +619,8 @@
 				uiCount += static_cast<const CDirectoryFolder *>(pItem)->GetFolderCount(bRecurse);
 			}
 			break;
+		default:
+			;
 		}
 	}
 
@@ -635,6 +645,8 @@
 		case HL_ITEM_FILE:
 			uiCount++;
 			break;
+		default:
+			;
 		}
 	}
 
Only in ./HLLib: DirectoryFolder.cpp.orig
diff -ru ../orig/HLLib/Error.cpp ./HLLib/Error.cpp
