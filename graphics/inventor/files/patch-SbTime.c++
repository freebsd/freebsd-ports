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
