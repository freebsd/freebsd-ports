--- qsstv/sstvtx.cpp.orig	Sat Aug 28 20:14:15 2004
+++ qsstv/sstvtx.cpp	Sat Aug 28 20:14:16 2004
@@ -187,7 +187,7 @@
 						{
 		  				struct tm *ltm=localtime(&t); //  to calculate timezone
 		  				ltzone="UTC";
-		  				if(daylight && ltm->tm_isdst)
+		  				if(/*daylight &&*/ ltm->tm_isdst)
 		    				{
 							    dt=dt.addSecs((int)timezone-3600);
 		    				}
@@ -199,7 +199,7 @@
 	      	else
 						{
 		  				struct tm *ltm=gmtime(&t); // to set tzname correctly
-		  				if(daylight && ltm->tm_isdst)
+		  				if(/*daylight &&*/ ltm->tm_isdst)
 		    				{
 		      				ltzone=tzname[2];
 		    				}
