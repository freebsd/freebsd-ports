--- inc/extdefs.h.orig	2021-07-09 19:20:11 UTC
+++ inc/extdefs.h
@@ -0,0 +1,50 @@
+/*
+ * nlarn.h
+ * Copyright (C) 2009-2020 Joachim de Groot <jdegroot@web.de>
+ *
+ * NLarn is free software: you can redistribute it and/or modify it
+ * under the terms of the GNU General Public License as published by the
+ * Free Software Foundation, either version 3 of the License, or
+ * (at your option) any later version.
+ *
+ * NLarn is distributed in the hope that it will be useful, but
+ * WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
+ * See the GNU General Public License for more details.
+ *
+ * You should have received a copy of the GNU General Public License along
+ * with this program.  If not, see <http://www.gnu.org/licenses/>.
+ */
+
+#ifndef __EXTDEFS_H_
+#define __EXTDEFS_H_
+
+#include <setjmp.h>
+
+#include "game.h"
+#include "position.h"
+
+/* game version string */
+extern const char *nlarn_version;
+
+/* the entire game */
+extern game *nlarn;
+
+/* death jump buffer - used to return to the main loop when the player has died */
+extern jmp_buf nlarn_death_jump;
+
+/* file paths */
+extern const char *nlarn_libdir;
+extern const char *nlarn_mesgfile;
+extern const char *nlarn_helpfile;
+extern const char *nlarn_mazefile;
+extern const char *nlarn_fortunes;
+extern const char *nlarn_highscores;
+extern const char *nlarn_inifile;
+extern const char *nlarn_savefile;
+
+extern const position pos_invalid;
+
+/* textual representation of the player's gender */
+extern const char *player_sex_str[PS_MAX];
+#endif
