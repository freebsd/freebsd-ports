--- history.c	5 Apr 2003 16:04:21 -0000	1.28
+++ history.c	28 Mar 2004 21:01:11 -0000
@@ -155,7 +155,7 @@
     p->tm_year += p->tm_mon/12;
     p->tm_mon %= 12;
   }
-  isLeapYr = p->tm_year/4==0 && (p->tm_year/100!=0 || (p->tm_year+300)/400==0);
+  isLeapYr = p->tm_year%4==0 && (p->tm_year%100!=0 || p->tm_year%400==0);
   p->tm_yday = priorDays[p->tm_mon] + p->tm_mday - 1;
   if( isLeapYr && p->tm_mon>1 ) p->tm_yday++;
   nDay = (p->tm_year-70)*365 + (p->tm_year-69)/4 -p->tm_year/100 + 
