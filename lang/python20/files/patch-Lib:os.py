*** Lib/os.py.orig	Thu Sep 28 14:10:56 2000
--- Lib/os.py	Mon Nov 11 15:18:05 2002
***************
*** 234,241 ****
      args may be a list or tuple of strings. """    
      _execvpe(file, args, env)
  
- _notfound = None
  def _execvpe(file, args, env=None):
      if env is not None:
          func = execve
          argrest = (args, env)
--- 234,242 ----
      args may be a list or tuple of strings. """    
      _execvpe(file, args, env)
  
  def _execvpe(file, args, env=None):
+     from errno import ENOENT, ENOTDIR
+ 
      if env is not None:
          func = execve
          argrest = (args, env)
***************
*** 243,249 ****
          func = execv
          argrest = (args,)
          env = environ
-     global _notfound
      head, tail = path.split(file)
      if head:
          apply(func, (file,) + argrest)
--- 244,249 ----
***************
*** 253,272 ****
      else:
          envpath = defpath
      PATH = envpath.split(pathsep)
!     if not _notfound:
!         import tempfile
!         # Exec a file that is guaranteed not to exist
!         try: execv(tempfile.mktemp(), ('blah',))
!         except error, _notfound: pass
!     exc, arg = error, _notfound
      for dir in PATH:
          fullname = path.join(dir, file)
          try:
              apply(func, (fullname,) + argrest)
!         except error, (errno, msg):
!             if errno != arg[0]:
!                 exc, arg = error, (errno, msg)
!     raise exc, arg
  
  # Change environ to automatically call putenv() if it exists
  try:
--- 253,273 ----
      else:
          envpath = defpath
      PATH = envpath.split(pathsep)
!     saved_exc = None
!     saved_tb = None
      for dir in PATH:
          fullname = path.join(dir, file)
          try:
              apply(func, (fullname,) + argrest)
!         except error, e:
!             tb = sys.exc_info()[2]
!             if (e.errno != ENOENT and e.errno != ENOTDIR
!                 and saved_exc is None):
!                 saved_exc = e
!                 saved_tb = tb
!     if saved_exc:
!         raise error, saved_exc, saved_tb
!     raise error, e, tb
  
  # Change environ to automatically call putenv() if it exists
  try:
