--- setup.py.orig	2017-03-23 01:56:41 UTC
+++ setup.py
@@ -21,12 +21,6 @@ if platform.system() in ['Linux', 'FreeB
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
