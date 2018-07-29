--- src/XESCore/AptIO.cpp.orig	2018-07-04 20:00:56 UTC
+++ src/XESCore/AptIO.cpp
@@ -707,7 +707,7 @@ printf("read open_poly %i elements\n",in
 						{
 							//If we've loop through the whole array of ramp_ai_opperation_types
 							//we have a problem
-							if(ramp_operation_type_strings[i] == '\0')
+							if(ramp_operation_type_strings[i] == NULL)
 							{
 								ok = string("Error: ") + ramp_op_type_human_string + "is not a real Ramp Operation Type";
 								break;
@@ -990,7 +990,7 @@ printf("read open_poly %i elements\n",in
 				}
 
 				const char** str = truck_type_strings;
-				while(*str != '\0')
+				while(*str != NULL)
 				{
 					if (strcmp(truck_type_str.c_str(),*str)==0)
 					{
@@ -998,7 +998,7 @@ printf("read open_poly %i elements\n",in
 						break;
 					}
 					++str;
-					if (*str == '\0')
+					if (*str == NULL)
 					{
 						ok = ("Error: Truck type " + truck_type_str + " is not supported.");
 					}
@@ -1036,7 +1036,7 @@ printf("read open_poly %i elements\n",in
 				for (vector<string>::iterator itr = tokenized.begin(); itr != tokenized.end(); ++itr)
 				{
 					const char** str = truck_type_strings;
-					while (*str != '\0')
+					while (*str != NULL)
 					{
 						if (strcmp(itr->c_str(), *str) == 0)
 						{
@@ -1044,7 +1044,7 @@ printf("read open_poly %i elements\n",in
 							break;
 						}
 						++str;
-						if (*str == '\0')
+						if (*str == NULL)
 						{
 							ok = ("Error: Truck type " + *itr + " is not supported.");
 						}
