--- __pkginfo__.py.orig	2021-11-07 21:37:38 UTC
+++ __pkginfo__.py
@@ -35,12 +35,12 @@ ftp_url = None
 author = "Rocky Bernstein"
 author_email = "rb@dustyfeet.com"
 ftp_url = None
-install_requires = [_six]
+install_requires = ["xdis >= 6.0.3"]
 license = "GPL-2.0"
 mailing_list = "python-debugger@googlegroups.com"
 modname = "xasm"
 py_modules = None
-setup_requires = ["pytest-runner", "xdis >= 6.0.3, < 6.1.0"]
+setup_requires = []
 # scripts            = ['bin/pydisasm']
 short_desc = "Python cross-version byte-code assembler"
 tests_require = ["pytest", _six]
