--- armoryengine/ArmoryUtils.py
+++ armoryengine/ArmoryUtils.py
@@ -208,6 +208,7 @@ class P2SHNotSupportedError(Exception): pass
 opsys = platform.system()
 OS_WINDOWS = 'win32'  in opsys.lower() or 'windows' in opsys.lower()
 OS_LINUX   = 'nix'    in opsys.lower() or 'nux'     in opsys.lower()
+OS_FREEBSD = 'freebsd' in opsys.lower()
 OS_MACOSX  = 'darwin' in opsys.lower() or 'osx'     in opsys.lower()
 
 
@@ -276,6 +277,14 @@ elif OS_LINUX:
    ARMORY_HOME_DIR = os.path.join(USER_HOME_DIR, '.armory', SUBDIR)
    BLKFILE_DIR     = os.path.join(BTC_HOME_DIR, 'blocks')
    BLKFILE_1stFILE = os.path.join(BLKFILE_DIR, 'blk00000.dat')
+elif OS_FREEBSD:
+   OS_NAME         = 'FreeBSD'
+   OS_VARIANT      = ('FreeBSD',platform.release(), '') # tuple (platform,version,id)
+   USER_HOME_DIR   = os.getenv('HOME')
+   BTC_HOME_DIR    = os.path.join(USER_HOME_DIR, '.bitcoin', SUBDIR)
+   ARMORY_HOME_DIR = os.path.join(USER_HOME_DIR, '.armory', SUBDIR)
+   BLKFILE_DIR     = os.path.join(BTC_HOME_DIR, 'blocks')
+   BLKFILE_1stFILE = os.path.join(BLKFILE_DIR, 'blk00000.dat')
 elif OS_MACOSX:
    platform.mac_ver()
    OS_NAME         = 'MacOSX'
@@ -293,6 +302,7 @@ else:
 opsys = platform.system()
 OS_WINDOWS = 'win32'  in opsys.lower() or 'windows' in opsys.lower()
 OS_LINUX   = 'nix'    in opsys.lower() or 'nux'     in opsys.lower()
+OS_FREEBSD = 'freebsd' in opsys.lower()
 OS_MACOSX  = 'darwin' in opsys.lower() or 'osx'     in opsys.lower()
 
 BLOCKCHAINS = {}
@@ -631,7 +641,7 @@ def killProcessTree(pid):
    # call, because have bundled a recent version of psutil.  Linux, however,
    # does not have that function call in earlier versions.
    from subprocess import Popen, PIPE
-   if not OS_LINUX:
+   if not OS_LINUX and not OS_FREEBSD:
       for child in psutil.Process(pid).get_children():
          killProcess(child.pid)
    else:
@@ -1007,7 +1017,7 @@ except:
    LOGCRIT('   in the current directory (or added to the PATH)')
    LOGCRIT('   Specifically, you need:')
    LOGCRIT('       CppBlockUtils.py     and')
-   if OS_LINUX or OS_MACOSX:
+   if OS_LINUX or OS_FREEBSD or OS_MACOSX:
       LOGCRIT('       _CppBlockUtils.so')
    elif OS_WINDOWS:
       LOGCRIT('       _CppBlockUtils.pyd')
@@ -1041,6 +1051,11 @@ def GetSystemDetails():
             out.CpuStr = line.split(':')[1].strip()
             break
 
+   elif OS_FREEBSD:
+      # Get total RAM
+      out.Memory = long(subprocess_check_output(['sysctl','-n','hw.physmem']))
+      ## Get CPU name
+      out.CpuStr = subprocess_check_output(['sysctl','-n','hw.model'])
 
    elif OS_WINDOWS:
       import ctypes
@@ -1542,7 +1557,7 @@ except:
    LOGCRIT('   in the current directory (or added to the PATH)')
    LOGCRIT('   Specifically, you need:')
    LOGCRIT('       CppBlockUtils.py     and')
-   if OS_LINUX or OS_MACOSX:
+   if OS_LINUX or OS_FREEBSD or OS_MACOSX:
       LOGCRIT('       _CppBlockUtils.so')
    elif OS_WINDOWS:
       LOGCRIT('       _CppBlockUtils.pyd')
