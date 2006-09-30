*** examples/infoReader/Date.cpp.orig	Thu Sep 28 13:23:25 2006
--- examples/infoReader/Date.cpp	Thu Sep 28 13:23:36 2006
***************
*** 39,45 ****
    return "\"" + m + "/" + d + "/" + y + "\"";
  }
  
! std::ostream& X3DTK::operator<<(std::ostream& o, const Date &date)
  {
    return o << date.month << "/" << date.day << "/" << date.year;
  }
--- 39,45 ----
    return "\"" + m + "/" + d + "/" + y + "\"";
  }
  
! std::ostream& operator<<(std::ostream& o, const Date &date)
  {
    return o << date.month << "/" << date.day << "/" << date.year;
  }
