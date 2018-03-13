--- setup.py.orig	2018-03-12 17:25:11 UTC
+++ setup.py
@@ -27,12 +27,6 @@ if platform.system() in ['Linux', 'FreeB
     parser.add_argument('--root=', dest='root_path', metavar='dir', default='/')
     opts, _ = parser.parse_known_args(sys.argv[1:])
     usr_share = os.path.join(sys.prefix, "share")
-    if not os.access(opts.root_path + usr_share, os.W_OK) and \
-       not os.access(opts.root_path, os.W_OK):
-        if 'XDG_DATA_HOME' in os.environ.keys():
-            usr_share = os.environ['XDG_DATA_HOME']
-        else:
-            usr_share = os.path.expanduser('~/.local/share')
     data_files += [
         (os.path.join(usr_share, 'applications/'), ['electrum.desktop']),
         (os.path.join(usr_share, 'pixmaps/'), ['icons/electrum.png'])
@@ -86,8 +80,3 @@ setup(
     url="https://electrum.org",
     long_description="""Lightweight Bitcoin Wallet"""
 )
-
-# Optional modules (not required to run Electrum)
-import pip
-opt_modules = requirements_hw + ['pycryptodomex']
-[ pip.main(['install', m]) for m in opt_modules ]
