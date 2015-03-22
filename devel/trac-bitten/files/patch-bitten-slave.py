diff -urN Bitten-0.6b3/bitten/slave.py Bitten-0.6b3.username/bitten/slave.py
--- Bitten-0.6b3/bitten/slave.py	2010-10-21 12:02:42.000000000 +0200
+++ Bitten-0.6b3.username/bitten/slave.py	2014-09-23 11:59:13.509163066 +0200
@@ -318,6 +318,7 @@
                                           "authentication" % url[:-7])
                                 raise ExitSlave(EX_NOPERM)
                             values = {'user': self.username, 
+                                      'username': self.username,
                                       'password':
                                           self.password_mgr.find_user_password(
                                                                 None, url)[1],
