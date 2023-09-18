--- source/network/NetMessage.cpp.orig	2023-09-17 08:35:54 UTC
+++ source/network/NetMessage.cpp
@@ -1,4 +1,4 @@
-/* Copyright (C) 2017 Wildfire Games.
+/* Copyright (C) 2023 Wildfire Games.
  * This file is part of 0 A.D.
  *
  * 0 A.D. is free software: you can redistribute it and/or modify
@@ -216,7 +216,8 @@ CNetMessage* CNetMessageFactory::CreateMessage(const v
 		break;
 
 	default:
-		LOGERROR("CNetMessageFactory::CreateMessage(): Unknown message type '%d' received", header.GetType());
+		LOGERROR("CNetMessageFactory::CreateMessage(): Unknown message type '%d' received",
+			static_cast<int>(header.GetType()));
 		break;
 	}
 
