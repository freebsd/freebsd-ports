--- ftpd/extern.h.orig	2004-04-18 12:20:14 UTC
+++ ftpd/extern.h
@@ -47,7 +47,7 @@ void	feat(void);
 void    ftpd_logwtmp(char *, char *, struct sockaddr *addr);
 int	ftpd_pclose(FILE *);
 FILE   *ftpd_popen(char *, char *);
-char   *getline(char *, int, FILE *);
+char   *get_line(char *, int, FILE *);
 void	lreply(int, const char *, ...);
 void	makedir(char *);
 void	nack(char *);
