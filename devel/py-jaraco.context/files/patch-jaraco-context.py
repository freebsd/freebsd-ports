--- jaraco/context.py.orig	2020-01-10 08:37:17 UTC
+++ jaraco/context.py
@@ -13,10 +13,7 @@ try:
 except Exception:
     import contextlib as contextlib2
 
-import jaraco.apt
-import yg.lockfile
 
-
 __metaclass__ = type
 
 
@@ -58,111 +55,11 @@ def data_lines_from_file(filename):
     return filter(None, strip_comments(file_lines_if_exists(filename)))
 
 
-def run():
-    """
-    Run a command in the context of the system dependencies.
-    """
-    parser = argparse.ArgumentParser()
-    parser.add_argument(
-        '--deps-def',
-        default=data_lines_from_file("system deps.txt")
-        + data_lines_from_file("build deps.txt"),
-        help="A file specifying the dependencies (one per line)",
-        type=data_lines_from_file,
-        dest="spec_deps",
-    )
-    parser.add_argument(
-        '--dep',
-        action="append",
-        default=[],
-        help="A specific dependency (multiple allowed)",
-        dest="deps",
-    )
-    parser.add_argument(
-        'command',
-        type=shlex.split,
-        default=shlex.split("python2.7 setup.py test"),
-        help="Command to invoke in the context of the dependencies",
-    )
-    parser.add_argument(
-        '--do-not-remove',
-        default=False,
-        action="store_true",
-        help="Keep any installed packages",
-    )
-    parser.add_argument(
-        '--aggressively-remove',
-        default=False,
-        action="store_true",
-        help="When removing packages, also remove those automatically installed"
-        " as dependencies",
-    )
-    parser.add_argument(
-        '-l',
-        '--log-level',
-        default=logging.INFO,
-        type=log_level,
-        help="Set log level (DEBUG, INFO, WARNING, ERROR)",
-    )
-    args = parser.parse_args()
-    logging.basicConfig(level=args.log_level)
-    context = dependency_context(
-        args.spec_deps + args.deps, aggressively_remove=args.aggressively_remove
-    )
-    with context as to_remove:
-        if args.do_not_remove:
-            del to_remove[:]
-        raise SystemExit(subprocess.Popen(args.command).wait())
-
-
 def log_level(level_string):
     """
     Return a log level for a string
     """
     return getattr(logging, level_string.upper())
-
-
-@contextlib.contextmanager
-def dependency_context(package_names, aggressively_remove=False):
-    """
-    Install the supplied packages and yield. Finally, remove all packages
-    that were installed.
-    Currently assumes 'aptitude' is available.
-    """
-    installed_packages = []
-    log = logging.getLogger(__name__)
-    try:
-        if not package_names:
-            logging.debug('No packages requested')
-        if package_names:
-            lock = yg.lockfile.FileLock('/tmp/.pkg-context-lock', timeout=30 * 60)
-            log.info('Acquiring lock to perform install')
-            lock.acquire()
-            log.info('Installing ' + ', '.join(package_names))
-            output = subprocess.check_output(
-                ['sudo', 'aptitude', 'install', '-y'] + package_names,
-                stderr=subprocess.STDOUT,
-            )
-            log.debug('Aptitude output:\n%s', output)
-            installed_packages = jaraco.apt.parse_new_packages(
-                output, include_automatic=aggressively_remove
-            )
-            if not installed_packages:
-                lock.release()
-            log.info('Installed ' + ', '.join(installed_packages))
-        yield installed_packages
-    except subprocess.CalledProcessError:
-        log.error("Error occurred installing packages")
-        raise
-    finally:
-        if installed_packages:
-            log.info('Removing ' + ','.join(installed_packages))
-            subprocess.check_call(
-                ['sudo', 'aptitude', 'remove', '-y'] + installed_packages,
-                stdout=subprocess.PIPE,
-                stderr=subprocess.STDOUT,
-            )
-            lock.release()
 
 
 @contextlib.contextmanager
