--- HLExtract/Main.c.orig	2016-07-26 11:59:22 UTC
+++ HLExtract/Main.c
@@ -52,7 +52,7 @@
 #	define WIN32_LEAN_AND_MEAN
 #	include <windows.h>
 #else
-#	include <linux/limits.h>
+#	include <sys/param.h>
 #	define MAX_PATH PATH_MAX
 
 #	define FOREGROUND_BLUE      0x0001
@@ -618,15 +618,15 @@ hlVoid PrintUsage()
 	printf("\n");
 	printf("Example HLExtract usage:\n");
 #ifdef _WIN32
-	printf("HLExtract.exe -p \"C:\\half-life.gcf\" -d \"C:\\backup\" -e \"root\\valve\\models\" -e \"root\\valve\\config.cfg\"\n");
-	printf("HLExtract.exe -p \"C:\\half-life.gcf\" -c -m -v\n");
-	printf("HLExtract.exe -p \"C:\\half-life.gcf\" -lf \"C:\\half-life.txt\" -m -s\n");
-	printf("HLExtract.exe -p \"C:\\half-life.gcf\" -m -f\n");
+	printf("hlextract -p \"C:\\half-life.gcf\" -d \"C:\\backup\" -e \"root\\valve\\models\" -e \"root\\valve\\config.cfg\"\n");
+	printf("hlextract -p \"C:\\half-life.gcf\" -c -m -v\n");
+	printf("hlextract -p \"C:\\half-life.gcf\" -lf \"C:\\half-life.txt\" -m -s\n");
+	printf("hlextract -p \"C:\\half-life.gcf\" -m -f\n");
 #else
-	printf("HLExtract.exe -p \"~/half-life.gcf\" -d \"~/backup\" -e \"root/valve/models\" -e \"root/valve/config.cfg\"\n");
-	printf("HLExtract.exe -p \"~/half-life.gcf\" -c -m -v\n");
-	printf("HLExtract.exe -p \"~/half-life.gcf\" -lf \"~/half-life.txt\" -m -s\n");
-	printf("HLExtract.exe -p \"~/half-life.gcf\" -m -f\n");
+	printf("hlextract -p \"~/half-life.gcf\" -d \"~/backup\" -e \"root/valve/models\" -e \"root/valve/config.cfg\"\n");
+	printf("hlextract -p \"~/half-life.gcf\" -c -m -v\n");
+	printf("hlextract -p \"~/half-life.gcf\" -lf \"~/half-life.txt\" -m -s\n");
+	printf("hlextract -p \"~/half-life.gcf\" -m -f\n");
 #endif
 }
 
@@ -657,6 +657,8 @@ hlVoid List(FILE *pFile, HLDirectoryItem
 			fprintf(pFile, "%s\n", lpPath);
 		}
 		break;
+	default:
+		;
 	}
 }
 
@@ -843,6 +845,8 @@ HLValidation Validate(HLDirectoryItem *p
 				PrintValidation(eValidation);
 				printf("\n");
 				break;
+			default:
+				;
 			}
 		}
 		else
@@ -851,6 +855,8 @@ HLValidation Validate(HLDirectoryItem *p
 			printf("  \n");
 		}
 		break;
+	default:
+		;
 	}
 
 	return eValidation;
@@ -882,6 +888,8 @@ hlVoid PrintAttribute(hlChar *lpPrefix, 
 	case HL_ATTRIBUTE_STRING:
 		printf("%s%s: %s%s\n", lpPrefix, pAttribute->lpName, pAttribute->Value.String.lpValue, lpPostfix);
 		break;
+	default:
+		;
 	}
 }
 
@@ -1151,6 +1159,8 @@ hlVoid EnterConsole(hlUInt uiPackage, hl
 						printf("  Size: %u B\n", hlFileGetSize(pSubItem));
 						printf("  Size On Disk: %u B\n", hlFileGetSizeOnDisk(pSubItem));
 						break;
+					default:
+						;
 					}
 
 					uiItemCount = hlPackageGetItemAttributeCount();
