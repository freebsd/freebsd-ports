From: Gerald Pfeifer <gerald@pfeifer.com>
To: wine-devel@winehq.org, Austin English <austinenglish@gmail.com>
Date: Sat, 25 Nov 2017 15:43:13 +0100 (CET)
Subject: [PATCH] advapi32: Include <stdarg.h> since winbase.h expects va_list

The addition of dlls/advapi32/perf.c about a week ago broke my nightly 
FreeBSD builder as follows:

  In file included from perf.c:24:
  ../../include/windef.h:106:24: error: unknown type name ‘va_list’
   #  define __ms_va_list va_list
                          ^~~~~~~
  ../../include/winbase.h:2002:84: note: in expansion of macro ‘__ms_va_list’ in
  WINBASEAPI DWORD WINAPI FormatMessageA(DWORD,LPCVOID,DWORD,DWORD,LPSTR,DWORD,__ms_va_list*);

This is a typical failure mode I've seen on FreeBSD, which is more 
parsimonious than GNU/Linux when it comes to include files pulling 
in others, though our peak with Wine running into this was more than 
a decade ago. ;-)

Investigating this case a little I found that indeed winbase.h and 
in turn windef.h assume va_list is known and indeed many other files 
in dlls/advapi32 already include stdarg.h.

Gerald

Signed-off-by: Gerald Pfeifer <gerald@pfeifer.com>
---
 dlls/advapi32/perf.c | 1 +
 1 file changed, 1 insertion(+)

--- UTC
--- dlls/advapi32/perf.c
+++ dlls/advapi32/perf.c
@@ -18,6 +18,7 @@
  * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
  */
 
+#include <stdarg.h>
 #include <stdio.h>
 
 #include "windef.h"
-- 
2.15.0
