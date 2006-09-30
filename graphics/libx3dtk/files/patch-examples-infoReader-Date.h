*** examples/infoReader/Date.h.orig	Thu Sep 28 13:22:51 2006
--- examples/infoReader/Date.h	Thu Sep 28 13:23:03 2006
***************
*** 17,23 ****
    int year;    
  };
  
! std::ostream& X3DTK::operator<<(std::ostream& o, const Date &date);
  
  }
  
--- 17,23 ----
    int year;    
  };
  
! std::ostream& operator<<(std::ostream& o, const Date &date);
  
  }
  
