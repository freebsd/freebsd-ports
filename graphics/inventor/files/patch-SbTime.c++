--- lib/database/src/sb/SbTime.c++.orig	2018-11-05 18:10:14 UTC
+++ lib/database/src/sb/SbTime.c++
@@ -190,52 +190,52 @@ SbTime::format(const char *fmt) const
 
 	      case 'D':
 		if (negative) *s++ = '-';
-		s += sprintf(s, "%ld", tday);
+		s += sprintf(s, "%d", tday);
 		break;
 
 	      case 'H':
 		if (negative) *s++ = '-';
-		s += sprintf(s, "%ld", thour);
+		s += sprintf(s, "%d", thour);
 		break;
 
 	      case 'M':
 		if (negative) *s++ = '-';
-		s += sprintf(s, "%ld", tmin);
+		s += sprintf(s, "%d", tmin);
 		break;
 
 	      case 'S':
 		if (negative) *s++ = '-';
-		s += sprintf(s, "%ld", tsec);
+		s += sprintf(s, "%d", tsec);
 		break;
 
 	      case 'I':
 		if (negative) *s++ = '-';
-		s += sprintf(s, "%ld", tmilli);
+		s += sprintf(s, "%d", tmilli);
 		break;
 
 	      case 'U':
 		if (negative) *s++ = '-';
-		s += sprintf(s, "%ld", tmicro);
+		s += sprintf(s, "%d", tmicro);
 		break;
 
 	      case 'h':
-		s += sprintf(s, "%.2ld", rhour);
+		s += sprintf(s, "%.2d", rhour);
 		break;
 
 	      case 'm':
-		s += sprintf(s, "%.2ld", rmin);
+		s += sprintf(s, "%.2d", rmin);
 		break;
 
 	      case 's':
-		s += sprintf(s, "%.2ld", rsec);
+		s += sprintf(s, "%.2d", rsec);
 		break;
 
 	      case 'i':
-		s += sprintf(s, "%.3ld", rmilli);
+		s += sprintf(s, "%.3d", rmilli);
 		break;
 
 	      case 'u':
-		s += sprintf(s, "%.6ld", rmicro);
+		s += sprintf(s, "%.6d", rmicro);
 		break;
 
 	      default:

*** lib/database/src/sb/SbTime.c++	Sat Dec 14 18:06:53 2002
--- lib/database/src/sb/SbTime.c++.new	Sat Dec 14 17:15:06 2002
***************
*** 269,275 ****
      seconds = (int) t.tv_sec;
      strftime(buf, sizeof(buf), fmt, localtime((const time_t *) &seconds));
  #else
!     strftime(buf, sizeof(buf), fmt, localtime(&t.tv_sec));
  #endif
  
      return buf;
--- 269,275 ----
      seconds = (int) t.tv_sec;
      strftime(buf, sizeof(buf), fmt, localtime((const time_t *) &seconds));
  #else
!     strftime(buf, sizeof(buf), fmt, localtime((const time_t *) &t.tv_sec));
  #endif
  
      return buf;
