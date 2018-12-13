--- imagepool/poolfindassociation.cpp.orig	2018-12-12 23:22:31 UTC
+++ imagepool/poolfindassociation.cpp
@@ -57,7 +57,10 @@ OFCondition FindAssociation::findSCU(T_A
 	req.Priority = DIMSE_PRIORITY_LOW;
 	strcpy(req.AffectedSOPClassUID, m_abstractSyntax);
 
+        int responseCount = 0;
+
 	cond = DIMSE_findUser(assoc, presId, &req, query, 
+			responseCount,
 			findCallback, (void*)this, 
 			(m_timeout == 0) ? DIMSE_BLOCKING : DIMSE_NONBLOCKING,
 			m_timeout, 
