--- ../orig/HLLib/FileStream.cpp	2010-10-28 20:41:26.000000000 -0200
+++ ./HLLib/FileStream.cpp	2013-02-11 17:56:51.278212203 -0200
@@ -216,6 +216,8 @@
 	case HL_SEEK_END:
 		iMode = SEEK_END;
 		break;
+	default:
+		;
 	}
 
 	return (hlUInt)lseek(this->iFile, iOffset, iMode);
Only in ./HLLib: FileStream.cpp.orig
diff -ru ../orig/HLLib/GCFFile.cpp ./HLLib/GCFFile.cpp
