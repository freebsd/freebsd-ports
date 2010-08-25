--- daemon/pidlockfile.py.orig	2010-08-24 16:57:37.753374406 +0000
+++ daemon/pidlockfile.py	2010-08-24 16:58:57.825989360 +0000
@@ -22,6 +22,7 @@
     NotLocked, NotMyLock,
     )
 
+from lockfile.pidlockfile import PIDLockFile
 
 class PIDFileError(Exception):
     """ Abstract base class for errors specific to PID files. """
@@ -30,61 +31,6 @@
     """ Raised when parsing contents of PID file fails. """
 
 
-class PIDLockFile(LinkFileLock, object):
-    """ Lockfile implemented as a Unix PID file.
-
-        The PID file is named by the attribute `path`. When locked,
-        the file will be created with a single line of text,
-        containing the process ID (PID) of the process that acquired
-        the lock.
-
-        The lock is acquired and maintained as per `LinkFileLock`.
-
-        """
-
-    def read_pid(self):
-        """ Get the PID from the lock file.
-            """
-        result = read_pid_from_pidfile(self.path)
-        return result
-
-    def acquire(self, *args, **kwargs):
-        """ Acquire the lock.
-
-            Locks the PID file then creates the PID file for this
-            lock. The `timeout` parameter is used as for the
-            `LinkFileLock` class.
-
-            """
-        super(PIDLockFile, self).acquire(*args, **kwargs)
-        try:
-            write_pid_to_pidfile(self.path)
-        except OSError, exc:
-            error = LockFailed("%(exc)s" % vars())
-            raise error
-
-    def release(self):
-        """ Release the lock.
-
-            Removes the PID file then releases the lock, or raises an
-            error if the current process does not hold the lock.
-
-            """
-        if self.i_am_locking():
-            remove_existing_pidfile(self.path)
-        super(PIDLockFile, self).release()
-
-    def break_lock(self):
-        """ Break an existing lock.
-
-            If the lock is held, breaks the lock and removes the PID
-            file.
-
-            """
-        super(PIDLockFile, self).break_lock()
-        remove_existing_pidfile(self.path)
-
-
 class TimeoutPIDLockFile(PIDLockFile):
     """ Lockfile with default timeout, implemented as a Unix PID file.
 
