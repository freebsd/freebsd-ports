*** kmamerun/gamelist.h.orig	Tue Aug  6 09:15:28 2002
--- kmamerun/gamelist.h	Mon Feb 24 11:07:07 2003
***************
*** 54,60 ****
  		int size;
  		bool valid;
      };
!     typedef std::map<string, struct elem, greater<string> > GameListMap;
      
      GameListMap gamelist;
      bool modified;
--- 54,60 ----
  		int size;
  		bool valid;
      };
!     typedef std::map<std::string, struct elem, std::greater<std::string> > GameListMap;
      
      GameListMap gamelist;
      bool modified;
