--- libevmasm/Assembly.cpp.orig	2018-05-16 14:30:44 UTC
+++ libevmasm/Assembly.cpp
@@ -264,7 +264,7 @@ Json::Value Assembly::assemblyJSON(Strin
 					createJsonValue("PUSH [ErrorTag]", i.location().start, i.location().end, ""));
 			else
 				collection.append(
-					createJsonValue("PUSH [tag]", i.location().start, i.location().end, string(i.data())));
+					createJsonValue("PUSH [tag]", i.location().start, i.location().end, dev::toString(i.data())));
 			break;
 		case PushSub:
 			collection.append(
@@ -290,7 +290,7 @@ Json::Value Assembly::assemblyJSON(Strin
 			break;
 		case Tag:
 			collection.append(
-				createJsonValue("tag", i.location().start, i.location().end, string(i.data())));
+				createJsonValue("tag", i.location().start, i.location().end, dev::toString(i.data())));
 			collection.append(
 				createJsonValue("JUMPDEST", i.location().start, i.location().end));
 			break;
