*** Lib/os.py.orig	Mon Nov 11 15:04:17 2002
--- Lib/os.py	Mon Nov 11 15:05:36 2002
***************
*** 301,308 ****
  
  __all__.extend(["execl","execle","execlp","execlpe","execvp","execvpe"])
  
- _notfound = None
  def _execvpe(file, args, env=None):
      if env is not None:
          func = execve
          argrest = (args, env)
--- 301,309 ----
  
  __all__.extend(["execl","execle","execlp","execlpe","execvp","execvpe"])
  
  def _execvpe(file, args, env=None):
+     from errno import ENOENT, ENOTDIR
+ 
      if env is not None:
          func = execve
          argrest = (args, env)
***************
*** 310,316 ****
          func = execv
          argrest = (args,)
          env = environ
!     global _notfound
      head, tail = path.split(file)
      if head:
          apply(func, (file,) + argrest)
--- 311,317 ----
          func = execv
          argrest = (args,)
          env = environ
! 
      head, tail = path.split(file)
      if head:
          apply(func, (file,) + argrest)
***************
*** 320,349 ****
      else:
          envpath = defpath
      PATH = envpath.split(pathsep)
!     if not _notfound:
!         if sys.platform[:4] == 'beos':
!             #  Process handling (fork, wait) under BeOS (up to 5.0)
!             #  doesn't interoperate reliably with the thread interlocking
!             #  that happens during an import.  The actual error we need
!             #  is the same on BeOS for posix.open() et al., ENOENT.
!             try: unlink('/_#.# ## #.#')
!             except error, _notfound: pass
!         else:
!             import tempfile
!             t = tempfile.mktemp()
!             # Exec a file that is guaranteed not to exist
!             try: execv(t, ('blah',))
!             except error, _notfound: pass
!     exc, arg = error, _notfound
      for dir in PATH:
          fullname = path.join(dir, file)
          try:
              apply(func, (fullname,) + argrest)
!         except error, (errno, msg):
!             if errno != arg[0]:
!                 exc, arg = error, (errno, msg)
!     raise exc, arg
! 
  
  # Change environ to automatically call putenv() if it exists
  try:
--- 321,341 ----
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
