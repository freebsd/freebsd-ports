*** apps/converters/ivdowngrade/SoText3V2.c++.orig	Thu Jan  2 20:38:57 2003
--- apps/converters/ivdowngrade/SoText3V2.c++	Thu Jan  2 20:39:28 2003
***************
*** 50,55 ****
--- 50,57 ----
   */
  
  #include <Inventor/actions/SoWriteAction.h>
+ #include <Inventor/errors/SoDebugError.h>
+ 
  #include "SoText3V2.h"
  
  char* convToAscii(const SbString& str);
***************
*** 150,156 ****
  	}
      }
  #ifdef DEBUG
!     if (trunc) SoDebugWarning::post("SoText3V2", 
  	"Note that conversion modified an international text string");
  #endif /*DEBUG*/
      return newStr;            
--- 152,158 ----
  	}
      }
  #ifdef DEBUG
!     if (trunc) SoDebugError::post("SoText3V2", 
  	"Note that conversion modified an international text string");
  #endif /*DEBUG*/
      return newStr;            
