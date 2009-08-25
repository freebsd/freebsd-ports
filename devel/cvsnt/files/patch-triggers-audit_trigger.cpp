*** triggers/audit_trigger.cpp.orig	Wed Jul 15 14:08:34 2009
--- triggers/audit_trigger.cpp	Wed Jul 15 14:09:10 2009
***************
*** 226,231 ****
--- 226,232 ----
  		return 0;
  	}
  
+ 	rs->Close();
  
  	g_nSessionId = 0;
  	if(g_AuditLogSessions)