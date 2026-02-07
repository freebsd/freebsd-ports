--- support/pop/popser.c.orig	1999-02-09 11:30:00 UTC
+++ support/pop/popser.c
@@ -259,7 +259,7 @@ static		p_cmatch(), p_isdate(), p_ishead
 extern	int	mbx_read ();
 
 static int	setup(), setupaux(), read_map(), read_file(), pmbx_size();
-static int	quitaux(), quitfile(), respond(), getline();
+static int	quitaux(), quitfile(), respond(), get_line();
 static	m_gMsgs(), multiline(), multiend(), putline();
 /*  */
 
@@ -410,7 +410,7 @@ char   *rhost;
     (void) respond (OK, "%s ready %s", server, timestamp);
 
     for (mystate = auth1; mystate != halt && mystate != error;)
-	switch (getline (buffer, sizeof buffer, input)) {
+	switch (get_line (buffer, sizeof buffer, input)) {
 	    case OK: 
 		if ((v = getvector (buffer, vec)) == NULL)
 		    continue;
@@ -1850,7 +1850,7 @@ static  multiend () {
 
 /*  */
 
-static int  getline (s, n, iop)
+static int  get_line (s, n, iop)
 register char  *s;
 register int	n;
 register FILE  *iop;
