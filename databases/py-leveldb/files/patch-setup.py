--- setup.py.orig	2016-12-27 23:05:34 UTC
+++ setup.py
@@ -14,15 +14,11 @@ from setuptools import setup, Extension
 
 system, node, release, version, machine, processor = platform.uname()
 common_flags = [
-    '-I./leveldb/include',
-    '-I./leveldb',
-    '-I./snappy',
+    '-I%%LOCALBASE%%/include',
     '-I.',
     '-fno-builtin-memcmp',
     '-O2',
     '-fPIC',
-    '-DNDEBUG',
-    '-DSNAPPY',
 ]
 
 if system == 'Darwin':
@@ -31,11 +27,11 @@ if system == 'Darwin':
         '-DLEVELDB_PLATFORM_POSIX',
         '-Wno-error=unused-command-line-argument-hard-error-in-future',
     ]
-elif system == 'Linux':
+elif system == 'FreeBSD':
     extra_compile_args = common_flags + [
         '-pthread',
         '-Wall',
-        '-DOS_LINUX',
+        '-DOS_FREEBSD',
         '-DLEVELDB_PLATFORM_POSIX',
     ]
 else:
@@ -74,57 +70,11 @@ setup(
     ext_modules = [
         Extension('leveldb',
             sources = [
-                # snappy
-                './snappy/snappy.cc',
-                './snappy/snappy-stubs-internal.cc',
-                './snappy/snappy-sinksource.cc',
-                './snappy/snappy-c.cc',
-
-                #leveldb
-                'leveldb/db/builder.cc',
-                'leveldb/db/c.cc',
-                'leveldb/db/db_impl.cc',
-                'leveldb/db/db_iter.cc',
-                'leveldb/db/dbformat.cc',
-                'leveldb/db/filename.cc',
-                'leveldb/db/log_reader.cc',
-                'leveldb/db/log_writer.cc',
-                'leveldb/db/memtable.cc',
-                'leveldb/db/repair.cc',
-                'leveldb/db/table_cache.cc',
-                'leveldb/db/version_edit.cc',
-                'leveldb/db/version_set.cc',
-                'leveldb/db/write_batch.cc',
-                'leveldb/table/block.cc',
-                'leveldb/table/block_builder.cc',
-                'leveldb/table/filter_block.cc',
-                'leveldb/table/format.cc',
-                'leveldb/table/iterator.cc',
-                'leveldb/table/merger.cc',
-                'leveldb/table/table.cc',
-                'leveldb/table/table_builder.cc',
-                'leveldb/table/two_level_iterator.cc',
-                'leveldb/util/arena.cc',
-                'leveldb/util/bloom.cc',
-                'leveldb/util/cache.cc',
-                'leveldb/util/coding.cc',
-                'leveldb/util/comparator.cc',
-                'leveldb/util/crc32c.cc',
-                'leveldb/util/env.cc',
-                'leveldb/util/env_posix.cc',
-                'leveldb/util/filter_policy.cc',
-                'leveldb/util/hash.cc',
-                'leveldb/util/histogram.cc',
-                'leveldb/util/logging.cc',
-                'leveldb/util/options.cc',
-                'leveldb/util/status.cc',
-                'leveldb/port/port_posix.cc',
-
                 # python stuff
                 'leveldb_ext.cc',
                 'leveldb_object.cc',
             ],
-            libraries = ['stdc++'],
+            libraries = ['leveldb'],
             extra_compile_args = extra_compile_args,
         )
     ]
