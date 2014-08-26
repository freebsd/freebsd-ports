--- ./bugz/cli.py.orig	2012-05-06 20:37:35.000000000 +0000
+++ ./bugz/cli.py	2014-08-02 20:38:22.976386635 +0000
@@ -29,6 +29,7 @@
 """
 
 DEFAULT_COOKIE_FILE = '.bugz_cookie'
+DEFAULT_TOKEN_FILE = '.bugz_token'
 DEFAULT_NUM_COLS = 80
 
 #
@@ -143,6 +144,12 @@
 		except IOError:
 			pass
 
+		self.token_file = os.path.join(os.environ['HOME'], DEFAULT_TOKEN_FILE)
+		try:
+			self.token = open(self.token_file).read().strip()
+		except IOError:
+			self.token = None
+
 		if getattr(args, 'encoding'):
 			self.enc = args.encoding
 		else:
@@ -170,16 +177,21 @@
 	def get_input(self, prompt):
 		return raw_input(prompt)
 
+	def set_token(self, *args):
+		if args and self.token:
+			args[0]['Bugzilla_token'] = self.token
+		return args
+
 	def bzcall(self, method, *args):
 		"""Attempt to call method with args. Log in if authentication is required.
 		"""
 		try:
-			return method(*args)
+			return method(*self.set_token(*args))
 		except xmlrpclib.Fault, fault:
 			# Fault code 410 means login required
 			if fault.faultCode == 410 and not self.skip_auth:
 				self.login()
-				return method(*args)
+				return method(*self.set_token(*args))
 			raise
 
 	def login(self, args=None):
@@ -208,10 +220,21 @@
 			params['remember'] = True
 		self.log('Logging in')
 		self.bz.User.login(params)
+		log_info('Logging in')
+		result = self.bz.User.login(params)
+		if 'token' in result:
+			self.token = result['token']
 
 		if args is not None:
-			self.cookiejar.save()
-			os.chmod(self.cookiejar.filename, 0600)
+			if self.token:
+				fd = open(self.token_file, 'w')
+				fd.write(self.token)
+				fd.write('\n')
+				fd.close()
+				os.chmod(self.token_file, 0600)
+			else:
+				self.cookiejar.save()
+				os.chmod(self.cookiejar.filename, 0600)
 
 	def logout(self, args):
 		self.log('logging out')
