--- uri.c.orig	2024-06-13 16:34:21 UTC
+++ uri.c
@@ -149,7 +149,7 @@ uri_host_inet(PG_FUNCTION_ARGS)
 		char *tmp = palloc(16);
 		snprintf(tmp, 16, "%u.%u.%u.%u", data[0], data[1], data[2], data[3]);
 		uriFreeUriMembersA(&uri);
-		PG_RETURN_INET_P(DirectFunctionCall1(inet_in, CStringGetDatum(tmp)));
+		PG_RETURN_INET_P((inet *) (DirectFunctionCall1(inet_in, CStringGetDatum(tmp))));
 	}
 	else if (uri.hostData.ip6)
 	{
@@ -161,7 +161,7 @@ uri_host_inet(PG_FUNCTION_ARGS)
 				 data[8], data[9], data[10], data[11],
 				 data[12], data[13], data[14], data[15]);
 		uriFreeUriMembersA(&uri);
-		PG_RETURN_INET_P(DirectFunctionCall1(inet_in, CStringGetDatum(tmp)));
+		PG_RETURN_INET_P((inet *) (DirectFunctionCall1(inet_in, CStringGetDatum(tmp))));
 	}
 	else
 	{
@@ -299,7 +299,7 @@ uri_path_array(PG_FUNCTION_ARGS)
 	uriFreeUriMembersA(&uri);
 
 	if (astate)
-		PG_RETURN_ARRAYTYPE_P(makeArrayResult(astate, CurrentMemoryContext));
+		PG_RETURN_ARRAYTYPE_P((Pointer)(makeArrayResult(astate, CurrentMemoryContext)));
 	else
 		PG_RETURN_ARRAYTYPE_P(construct_empty_array(TEXTOID));
 }
