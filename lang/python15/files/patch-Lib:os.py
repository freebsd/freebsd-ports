*** Lib/os.py.orig	Mon Feb 22 09:40:34 1999
--- Lib/os.py	Mon Nov 11 15:08:52 2002
***************
*** 185,192 ****
  def execvpe(file, args, env):
      _execvpe(file, args, env)
  
- _notfound = None
  def _execvpe(file, args, env = None):
      if env:
          func = execve
          argrest = (args, env)
--- 185,193 ----
  def execvpe(file, args, env):
      _execvpe(file, args, env)
  
  def _execvpe(file, args, env = None):
+     from errno import ENOENT, ENOTDIR
+ 
      if env:
          func = execve
          argrest = (args, env)
***************
*** 194,200 ****
          func = execv
          argrest = (args,)
          env = environ
-     global _notfound
      head, tail = path.split(file)
      if head:
          apply(func, (file,) + argrest)
--- 195,200 ----
***************
*** 205,224 ****
          envpath = defpath
      import string
      PATH = string.splitfields(envpath, pathsep)
!     if not _notfound:
!         import tempfile
!         # Exec a file that is guaranteed not to exist
!         try: execv(tempfile.mktemp(), ())
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
--- 205,225 ----
          envpath = defpath
      import string
      PATH = string.splitfields(envpath, pathsep)
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
