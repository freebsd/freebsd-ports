--- engine/SCons/Node/FS.py.orig	Wed Feb 16 03:12:10 2005
+++ engine/SCons/Node/FS.py	Tue Mar  8 19:08:43 2005
@@ -756,7 +756,7 @@
 
         The path argument must be a valid absolute path.
         """
-        if __debug__: logInstanceCreation(self)
+        if __debug__: logInstanceCreation(self, 'Node.FS')
         self.Top = None
         if path == None:
             self.pathTop = os.getcwd()
@@ -999,15 +999,11 @@
             self.__setTopLevelDir()
             self.Top.addRepository(d)
 
-    def do_Rsearch(self, path, func, clazz=_classEntry, cwd=None, verbose=lambda x: x):
+    def do_Rsearch(self, path, dir, func, clazz=_classEntry):
         """Search for something in a Repository.  Returns the first
         one found in the list, or None if there isn't one.
         __cacheable__
         """
-        if isinstance(path, SCons.Node.Node):
-            return path
-
-        path, dir = self.__transformPath(path, cwd)
         d, name = os.path.split(path)
         norm_name = _my_normcase(name)
         if d:
@@ -1021,8 +1017,7 @@
             if node:
                 dir = node.get_dir()
         if node:
-            verbose("... FOUND '%s' in '%s'\n" % (name, dir))
-            return node
+            return node, dir
         fname = '.'
         while dir:
             for rep in dir.getRepositories():
@@ -1034,19 +1029,21 @@
                 else:
                     node = func(node)
                 if node:
-                    verbose("... FOUND '%s' in '%s'\n" % (name, dir))
-                    return node
+                    return node, dir
             fname = dir.name + os.sep + fname
             dir = dir.get_dir()
-        return None
+        return None, None
 
     def Rsearch(self, path, clazz=_classEntry, cwd=None):
+        if isinstance(path, SCons.Node.Node):
+            return path
         def func(node):
             if node.exists() and \
                (isinstance(node, Dir) or not node.is_derived()):
                    return node
             return None
-        return self.do_Rsearch(path, func, clazz, cwd)
+        path, dir = self.__transformPath(path, cwd)
+        return self.do_Rsearch(path, dir, func, clazz)[0]
 
     def Rsearchall(self, pathlist, must_exist=1, clazz=_classEntry, cwd=None):
         """Search for a list of somethings in the Repository list.
@@ -1087,10 +1084,6 @@
             else:
                 if not must_exist or node.exists():
                     result.append(node)
-                if isinstance(node, Dir):
-                    result.extend(filter(select, node.getRepositories()))
-                if node:
-                    dir = node.get_dir()
             fname = '.'
             while dir:
                 for rep in dir.getRepositories():
@@ -1286,6 +1279,36 @@
         if not self.builder is MkdirBuilder:
             apply(SCons.Node.Node.build, [self,], kw)
 
+    def _create(self):
+        """Create this directory, silently and without worrying about
+        whether the builder is the default or not."""
+        listDirs = []
+        parent = self
+        while parent:
+            if parent.exists():
+                break
+            listDirs.append(parent)
+            p = parent.up()
+            if isinstance(p, ParentOfRoot):
+                raise SCons.Errors.StopError, parent.path
+            parent = p
+        listDirs.reverse()
+        for dirnode in listDirs:
+            try:
+                # Don't call dirnode.build(), call the base Node method
+                # directly because we definitely *must* create this
+                # directory.  The dirnode.build() method will suppress
+                # the build if it's the default builder.
+                SCons.Node.Node.build(dirnode)
+                dirnode.get_executor().nullify()
+                # The build() action may or may not have actually
+                # created the directory, depending on whether the -n
+                # option was used or not.  Delete the _exists and
+                # _rexists attributes so they can be reevaluated.
+                dirnode.clear()
+            except OSError:
+                pass
+
     def multiple_side_effect_has_builder(self):
         global MkdirBuilder
         return not self.builder is MkdirBuilder and self.has_builder()
@@ -1383,24 +1406,59 @@
         sccspath = 'SCCS' + os.sep + 's.'+name
         return self.entry_exists_on_disk(sccspath)
 
-    def srcdir_duplicate(self, name, clazz):
-        dname = '.'
+    def srcdir_list(self):
+        """__cacheable__"""
+        result = []
+
+        dirname = '.'
         dir = self
         while dir:
             if dir.srcdir:
-                srcdir = dir.srcdir.Dir(dname)
-                if srcdir.entry_exists_on_disk(name):
-                    srcnode = self.fs._doLookup(clazz, name, srcdir)
-                    if self.duplicate:
-                        node = self.fs._doLookup(clazz, name, self)
-                        node.do_duplicate(srcnode)
-                        return node
-                    else:
-                        return srcnode
-            dname = dir.name + os.sep + dname
+                d = dir.srcdir.Dir(dirname)
+                if d.is_under(dir):
+                    # Shouldn't source from something in the build path:
+                    # build_dir is probably under src_dir, in which case
+                    # we are reflecting.
+                    break
+                result.append(d)
+            dirname = dir.name + os.sep + dirname
             dir = dir.get_dir()
+
+        return result
+
+    def srcdir_duplicate(self, name, clazz):
+        for dir in self.srcdir_list():
+            if dir.entry_exists_on_disk(name):
+                srcnode = self.fs._doLookup(clazz, name, dir)
+                if self.duplicate:
+                    node = self.fs._doLookup(clazz, name, self)
+                    node.do_duplicate(srcnode)
+                    return node
+                else:
+                    return srcnode
         return None
 
+    def srcdir_find_file(self, filename):
+        """__cacheable__"""
+        fs = self.fs
+        do_Rsearch = fs.do_Rsearch
+
+        def func(node):
+            if isinstance(node, SCons.Node.FS.File) and \
+               (node.is_derived() or node.is_pseudo_derived() or node.exists()):
+                    return node
+            return None
+
+        node, d = do_Rsearch(filename, self, func, File)
+        if node:
+            return node, d
+
+        for dir in self.srcdir_list():
+            node, d = do_Rsearch(filename, dir, func, File)
+            if node:
+                return File(filename, self, fs), d
+        return None, None
+
     def node_on_disk(self, name, clazz):
         if self.entry_exists_on_disk(name) or \
            self.sccs_on_disk(name) or \
@@ -1542,33 +1600,7 @@
     def _createDir(self):
         # ensure that the directories for this node are
         # created.
-
-        listDirs = []
-        parent=self.dir
-        while parent:
-            if parent.exists():
-                break
-            listDirs.append(parent)
-            p = parent.up()
-            if isinstance(p, ParentOfRoot):
-                raise SCons.Errors.StopError, parent.path
-            parent = p
-        listDirs.reverse()
-        for dirnode in listDirs:
-            try:
-                # Don't call dirnode.build(), call the base Node method
-                # directly because we definitely *must* create this
-                # directory.  The dirnode.build() method will suppress
-                # the build if it's the default builder.
-                SCons.Node.Node.build(dirnode)
-                dirnode.get_executor().nullify()
-                # The build() action may or may not have actually
-                # created the directory, depending on whether the -n
-                # option was used or not.  Delete the _exists and
-                # _rexists attributes so they can be reevaluated.
-                dirnode.clear()
-            except OSError:
-                pass
+        self.dir._create()
 
     def retrieve_from_cache(self):
         """Try to retrieve the node's content from a cache
@@ -1844,7 +1876,7 @@
 
 default_fs = FS()
 
-def find_file(filename, paths, node_factory=default_fs.File, verbose=None):
+def find_file(filename, paths, verbose=None):
     """
     find_file(str, [Dir()]) -> [nodes]
 
@@ -1860,6 +1892,7 @@
 
     Only the first file found is returned, and none is returned
     if no file is found.
+    __cacheable__
     """
     if verbose:
         if not SCons.Util.is_String(verbose):
@@ -1870,49 +1903,32 @@
     else:
         verbose = lambda x: x
 
-    filedir, filename = os.path.split(filename)
-    if filedir:
-        lookup_dir = lambda d, fd=filedir: d.Dir(fd)
-    else:
-        lookup_dir = lambda d: d
-
     if callable(paths):
         paths = paths()
 
     # Give Entries a chance to morph into Dirs.
     paths = map(lambda p: p.must_be_a_Dir(), paths)
 
-    for pathdir in paths:
-        verbose("looking for '%s' in '%s' ...\n" % (filename, pathdir))
-        dir = lookup_dir(pathdir)
-        def func(node):
-            if isinstance(node, SCons.Node.FS.File) and \
-               (node.is_derived() or node.is_pseudo_derived() or node.exists()):
-                    return node
-            return None
-
-        node = default_fs.do_Rsearch(filename, func, File, dir, verbose)
+    filedir, filename = os.path.split(filename)
+    if filedir:
+        def filedir_lookup(p, fd=filedir):
+            try:
+                return p.Dir(fd)
+            except TypeError:
+                # We tried to look up a Dir, but it seems there's already
+                # a File (or something else) there.  No big.
+                return None
+        paths = filter(None, map(filedir_lookup, paths))
+
+    for dir in paths:
+        verbose("looking for '%s' in '%s' ...\n" % (filename, dir))
+        node, d = dir.srcdir_find_file(filename)
         if node:
+            verbose("... FOUND '%s' in '%s'\n" % (filename, d))
             return node
-
-        dirname = '.'
-        while dir:
-            if dir.srcdir:
-                d = dir.srcdir.Dir(dirname)
-                if d.is_under(dir):
-                    # Shouldn't source from something in the build path:
-                    # build_dir is probably under src_dir, in which case
-                    # we are reflecting.
-                    break
-                node = dir.fs.do_Rsearch(filename, func, File, d, verbose)
-                if node:
-                    return File(filename, dir.Dir(dirname), dir.fs)
-            dirname = dir.name + os.sep + dirname
-            dir = dir.get_dir()
-
     return None
 
-def find_files(filenames, paths, node_factory = default_fs.File):
+def find_files(filenames, paths):
     """
     find_files([str], [Dir()]) -> [nodes]
 
@@ -1927,7 +1943,5 @@
     Only the first file found is returned for each filename,
     and any files that aren't found are ignored.
     """
-    nodes = map(lambda x, paths=paths, node_factory=node_factory:
-                       find_file(x, paths, node_factory),
-                filenames)
-    return filter(lambda x: x != None, nodes)
+    nodes = map(lambda x, paths=paths: find_file(x, paths), filenames)
+    return filter(None, nodes)
