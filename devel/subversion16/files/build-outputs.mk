# DO NOT EDIT -- AUTOMATICALLY GENERATED

########################################
# Section 1: Global make variables
########################################

FS_BASE_DEPS = subversion/libsvn_fs_base/libsvn_fs_base-1.la subversion/libsvn_fs_util/libsvn_fs_util-1.la
FS_BASE_LINK = ../../subversion/libsvn_fs_base/libsvn_fs_base-1.la ../../subversion/libsvn_fs_util/libsvn_fs_util-1.la

FS_FS_DEPS = subversion/libsvn_fs_fs/libsvn_fs_fs-1.la subversion/libsvn_fs_util/libsvn_fs_util-1.la
FS_FS_LINK = ../../subversion/libsvn_fs_fs/libsvn_fs_fs-1.la ../../subversion/libsvn_fs_util/libsvn_fs_util-1.la

RA_LOCAL_DEPS = subversion/libsvn_ra_local/libsvn_ra_local-1.la
RA_LOCAL_LINK = ../../subversion/libsvn_ra_local/libsvn_ra_local-1.la

RA_NEON_DEPS = subversion/libsvn_ra_neon/libsvn_ra_neon-1.la
RA_NEON_LINK = ../../subversion/libsvn_ra_neon/libsvn_ra_neon-1.la

RA_SERF_DEPS = subversion/libsvn_ra_serf/libsvn_ra_serf-1.la
RA_SERF_LINK = ../../subversion/libsvn_ra_serf/libsvn_ra_serf-1.la

RA_SVN_DEPS = subversion/libsvn_ra_svn/libsvn_ra_svn-1.la
RA_SVN_LINK = ../../subversion/libsvn_ra_svn/libsvn_ra_svn-1.la

BUILD_DIRS = subversion/tests/libsvn_subr subversion/tests/libsvn_fs_base subversion/tests/libsvn_client tools/diff subversion/tests/libsvn_diff subversion/tests/libsvn_fs_fs subversion/tests/libsvn_fs subversion/bindings/javahl/src/org/tigris/subversion/javahl subversion/bindings/javahl/classes subversion/bindings/javahl/include subversion/bindings/javahl/tests/org/tigris/subversion/javahl subversion/libsvn_auth_gnome_keyring subversion/libsvn_auth_kwallet subversion/libsvn_client subversion/libsvn_delta subversion/libsvn_diff subversion/libsvn_fs subversion/libsvn_fs_base subversion/libsvn_fs_base/bdb subversion/libsvn_fs_base/util subversion/libsvn_fs_fs subversion/libsvn_fs_util subversion/libsvn_ra subversion/libsvn_ra_local subversion/libsvn_ra_neon subversion/libsvn_ra_serf subversion/libsvn_ra_svn subversion/libsvn_repos subversion/libsvn_subr subversion/bindings/swig/perl/libsvn_swig_perl subversion/bindings/swig/python/libsvn_swig_py subversion/bindings/swig/ruby/libsvn_swig_ruby subversion/tests subversion/libsvn_wc subversion/bindings/javahl/native subversion/po subversion/mod_authz_svn subversion/mod_dav_svn subversion/mod_dav_svn/reports subversion/tests/libsvn_ra_local subversion/tests/libsvn_delta subversion/tests/libsvn_repos subversion/svn tools/server-side contrib/client-side/svn-push subversion/svnadmin subversion/svndumpfilter subversion/svnlook tools/client-side/svnmucc subversion/svnserve subversion/svnsync subversion/svnversion subversion/bindings/swig subversion/tests/libsvn_wc subversion/tests/cmdline subversion/bindings/swig/python subversion/bindings/swig/perl subversion/bindings/swig/ruby subversion/bindings/swig/proxy

BDB_TEST_DEPS = subversion/tests/libsvn_fs_base/changes-test$(EXEEXT) subversion/tests/libsvn_fs_base/fs-base-test$(EXEEXT) subversion/tests/libsvn_fs_base/key-test$(EXEEXT) subversion/tests/libsvn_fs_base/strings-reps-test$(EXEEXT)

BDB_TEST_PROGRAMS = subversion/tests/libsvn_fs_base/changes-test$(EXEEXT) subversion/tests/libsvn_fs_base/fs-base-test$(EXEEXT) subversion/tests/libsvn_fs_base/key-test$(EXEEXT) subversion/tests/libsvn_fs_base/strings-reps-test$(EXEEXT)

TEST_DEPS = subversion/tests/libsvn_subr/auth-test$(EXEEXT) subversion/tests/libsvn_subr/cache-test$(EXEEXT) subversion/tests/libsvn_subr/checksum-test$(EXEEXT) subversion/tests/libsvn_client/client-test$(EXEEXT) subversion/tests/libsvn_subr/compat-test$(EXEEXT) subversion/tests/libsvn_subr/config-test$(EXEEXT) subversion/tests/libsvn_diff/diff-diff3-test$(EXEEXT) subversion/tests/libsvn_subr/dirent_uri-test$(EXEEXT) subversion/tests/libsvn_subr/error-test$(EXEEXT) subversion/tests/libsvn_fs_fs/fs-pack-test$(EXEEXT) subversion/tests/libsvn_fs/fs-test$(EXEEXT) subversion/tests/libsvn_subr/hashdump-test$(EXEEXT) subversion/tests/libsvn_fs/locks-test$(EXEEXT) subversion/tests/libsvn_subr/mergeinfo-test$(EXEEXT) subversion/tests/libsvn_subr/opt-test$(EXEEXT) subversion/tests/libsvn_subr/path-test$(EXEEXT) subversion/tests/libsvn_ra_local/ra-local-test$(EXEEXT) subversion/tests/libsvn_delta/random-test$(EXEEXT) subversion/tests/libsvn_repos/repos-test$(EXEEXT) subversion/tests/libsvn_subr/revision-test$(EXEEXT) subversion/tests/libsvn_subr/skel-test$(EXEEXT) subversion/tests/libsvn_subr/stream-test$(EXEEXT) subversion/tests/libsvn_subr/string-test$(EXEEXT) subversion/tests/libsvn_delta/svndiff-test$(EXEEXT) subversion/tests/libsvn_subr/target-test$(EXEEXT) subversion/tests/libsvn_subr/time-test$(EXEEXT) subversion/tests/libsvn_subr/translate-test$(EXEEXT) subversion/tests/libsvn_wc/tree-conflict-data-test$(EXEEXT) subversion/tests/libsvn_subr/utf-test$(EXEEXT) subversion/tests/libsvn_delta/vdelta-test$(EXEEXT) subversion/tests/libsvn_delta/window-test$(EXEEXT) subversion/tests/cmdline/getopt_tests.py subversion/tests/cmdline/basic_tests.py subversion/tests/cmdline/checkout_tests.py subversion/tests/cmdline/commit_tests.py subversion/tests/cmdline/update_tests.py subversion/tests/cmdline/switch_tests.py subversion/tests/cmdline/prop_tests.py subversion/tests/cmdline/schedule_tests.py subversion/tests/cmdline/log_tests.py subversion/tests/cmdline/copy_tests.py subversion/tests/cmdline/diff_tests.py subversion/tests/cmdline/export_tests.py subversion/tests/cmdline/externals_tests.py subversion/tests/cmdline/merge_tests.py subversion/tests/cmdline/merge_authz_tests.py subversion/tests/cmdline/revert_tests.py subversion/tests/cmdline/mergeinfo_tests.py subversion/tests/cmdline/stat_tests.py subversion/tests/cmdline/trans_tests.py subversion/tests/cmdline/autoprop_tests.py subversion/tests/cmdline/blame_tests.py subversion/tests/cmdline/special_tests.py subversion/tests/cmdline/svnadmin_tests.py subversion/tests/cmdline/svnlook_tests.py subversion/tests/cmdline/svnversion_tests.py subversion/tests/cmdline/utf8_tests.py subversion/tests/cmdline/history_tests.py subversion/tests/cmdline/lock_tests.py subversion/tests/cmdline/cat_tests.py subversion/tests/cmdline/import_tests.py subversion/tests/cmdline/svnsync_tests.py subversion/tests/cmdline/authz_tests.py subversion/tests/cmdline/depth_tests.py subversion/tests/cmdline/svndumpfilter_tests.py subversion/tests/cmdline/changelist_tests.py subversion/tests/cmdline/info_tests.py subversion/tests/cmdline/tree_conflict_tests.py subversion/tests/cmdline/resolved_tests.py

TEST_PROGRAMS = subversion/tests/libsvn_subr/auth-test$(EXEEXT) subversion/tests/libsvn_subr/cache-test$(EXEEXT) subversion/tests/libsvn_subr/checksum-test$(EXEEXT) subversion/tests/libsvn_client/client-test$(EXEEXT) subversion/tests/libsvn_subr/compat-test$(EXEEXT) subversion/tests/libsvn_subr/config-test$(EXEEXT) subversion/tests/libsvn_diff/diff-diff3-test$(EXEEXT) subversion/tests/libsvn_subr/dirent_uri-test$(EXEEXT) subversion/tests/libsvn_subr/error-test$(EXEEXT) subversion/tests/libsvn_fs_fs/fs-pack-test$(EXEEXT) subversion/tests/libsvn_fs/fs-test$(EXEEXT) subversion/tests/libsvn_subr/hashdump-test$(EXEEXT) subversion/tests/libsvn_fs/locks-test$(EXEEXT) subversion/tests/libsvn_subr/mergeinfo-test$(EXEEXT) subversion/tests/libsvn_subr/opt-test$(EXEEXT) subversion/tests/libsvn_subr/path-test$(EXEEXT) subversion/tests/libsvn_ra_local/ra-local-test$(EXEEXT) subversion/tests/libsvn_delta/random-test$(EXEEXT) subversion/tests/libsvn_repos/repos-test$(EXEEXT) subversion/tests/libsvn_subr/revision-test$(EXEEXT) subversion/tests/libsvn_subr/skel-test$(EXEEXT) subversion/tests/libsvn_subr/stream-test$(EXEEXT) subversion/tests/libsvn_subr/string-test$(EXEEXT) subversion/tests/libsvn_subr/target-test$(EXEEXT) subversion/tests/libsvn_subr/time-test$(EXEEXT) subversion/tests/libsvn_subr/translate-test$(EXEEXT) subversion/tests/libsvn_wc/tree-conflict-data-test$(EXEEXT) subversion/tests/libsvn_subr/utf-test$(EXEEXT) subversion/tests/libsvn_delta/window-test$(EXEEXT) subversion/tests/cmdline/getopt_tests.py subversion/tests/cmdline/basic_tests.py subversion/tests/cmdline/checkout_tests.py subversion/tests/cmdline/commit_tests.py subversion/tests/cmdline/update_tests.py subversion/tests/cmdline/switch_tests.py subversion/tests/cmdline/prop_tests.py subversion/tests/cmdline/schedule_tests.py subversion/tests/cmdline/log_tests.py subversion/tests/cmdline/copy_tests.py subversion/tests/cmdline/diff_tests.py subversion/tests/cmdline/export_tests.py subversion/tests/cmdline/externals_tests.py subversion/tests/cmdline/merge_tests.py subversion/tests/cmdline/merge_authz_tests.py subversion/tests/cmdline/revert_tests.py subversion/tests/cmdline/mergeinfo_tests.py subversion/tests/cmdline/stat_tests.py subversion/tests/cmdline/trans_tests.py subversion/tests/cmdline/autoprop_tests.py subversion/tests/cmdline/blame_tests.py subversion/tests/cmdline/special_tests.py subversion/tests/cmdline/svnadmin_tests.py subversion/tests/cmdline/svnlook_tests.py subversion/tests/cmdline/svnversion_tests.py subversion/tests/cmdline/utf8_tests.py subversion/tests/cmdline/history_tests.py subversion/tests/cmdline/lock_tests.py subversion/tests/cmdline/cat_tests.py subversion/tests/cmdline/import_tests.py subversion/tests/cmdline/svnsync_tests.py subversion/tests/cmdline/authz_tests.py subversion/tests/cmdline/depth_tests.py subversion/tests/cmdline/svndumpfilter_tests.py subversion/tests/cmdline/changelist_tests.py subversion/tests/cmdline/info_tests.py subversion/tests/cmdline/tree_conflict_tests.py subversion/tests/cmdline/resolved_tests.py

MANPAGES = subversion/svn/svn.1 subversion/svnadmin/svnadmin.1 subversion/svndumpfilter/svndumpfilter.1 subversion/svnlook/svnlook.1 subversion/svnserve/svnserve.8 subversion/svnserve/svnserve.conf.5 subversion/svnsync/svnsync.1 subversion/svnversion/svnversion.1

CLEAN_FILES = contrib/client-side/svn-push/svn-push$(EXEEXT) subversion/svn/svn$(EXEEXT) subversion/svnadmin/svnadmin$(EXEEXT) subversion/svndumpfilter/svndumpfilter$(EXEEXT) subversion/svnlook/svnlook$(EXEEXT) subversion/svnserve/svnserve$(EXEEXT) subversion/svnsync/svnsync$(EXEEXT) subversion/svnversion/svnversion$(EXEEXT) subversion/tests/libsvn_client/client-test$(EXEEXT) subversion/tests/libsvn_delta/random-test$(EXEEXT) subversion/tests/libsvn_delta/svndiff-test$(EXEEXT) subversion/tests/libsvn_delta/vdelta-test$(EXEEXT) subversion/tests/libsvn_delta/window-test$(EXEEXT) subversion/tests/libsvn_diff/diff-diff3-test$(EXEEXT) subversion/tests/libsvn_fs/fs-test$(EXEEXT) subversion/tests/libsvn_fs/locks-test$(EXEEXT) subversion/tests/libsvn_fs_base/changes-test$(EXEEXT) subversion/tests/libsvn_fs_base/fs-base-test$(EXEEXT) subversion/tests/libsvn_fs_base/key-test$(EXEEXT) subversion/tests/libsvn_fs_base/strings-reps-test$(EXEEXT) subversion/tests/libsvn_fs_fs/fs-pack-test$(EXEEXT) subversion/tests/libsvn_ra_local/ra-local-test$(EXEEXT) subversion/tests/libsvn_repos/repos-test$(EXEEXT) subversion/tests/libsvn_subr/auth-test$(EXEEXT) subversion/tests/libsvn_subr/cache-test$(EXEEXT) subversion/tests/libsvn_subr/checksum-test$(EXEEXT) subversion/tests/libsvn_subr/compat-test$(EXEEXT) subversion/tests/libsvn_subr/config-test$(EXEEXT) subversion/tests/libsvn_subr/dirent_uri-test$(EXEEXT) subversion/tests/libsvn_subr/error-test$(EXEEXT) subversion/tests/libsvn_subr/hashdump-test$(EXEEXT) subversion/tests/libsvn_subr/mergeinfo-test$(EXEEXT) subversion/tests/libsvn_subr/opt-test$(EXEEXT) subversion/tests/libsvn_subr/path-test$(EXEEXT) subversion/tests/libsvn_subr/revision-test$(EXEEXT) subversion/tests/libsvn_subr/skel-test$(EXEEXT) subversion/tests/libsvn_subr/stream-test$(EXEEXT) subversion/tests/libsvn_subr/string-test$(EXEEXT) subversion/tests/libsvn_subr/target-test$(EXEEXT) subversion/tests/libsvn_subr/time-test$(EXEEXT) subversion/tests/libsvn_subr/translate-test$(EXEEXT) subversion/tests/libsvn_subr/utf-test$(EXEEXT) subversion/tests/libsvn_wc/tree-conflict-data-test$(EXEEXT) tools/client-side/svnmucc/svnmucc$(EXEEXT) tools/diff/diff$(EXEEXT) tools/diff/diff3$(EXEEXT) tools/diff/diff4$(EXEEXT) tools/server-side/svn-populate-node-origins-index$(EXEEXT) tools/server-side/svnauthz-validate$(EXEEXT)

SWIG_INCLUDES = -I$(abs_builddir)/subversion \
  -I$(abs_srcdir)/subversion/include \
  -I$(abs_srcdir)/subversion/bindings/swig \
  -I$(abs_srcdir)/subversion/bindings/swig/include \
  -I$(abs_srcdir)/subversion/bindings/swig/proxy \
  -I$(abs_builddir)/subversion/bindings/swig/proxy \
  $(SVN_APR_INCLUDES) $(SVN_APRUTIL_INCLUDES)

RELEASE_MODE = 1


########################################
# Section 2: SWIG headers (wrappers and external runtimes)
########################################


########################################
# Section 3: SWIG autogen rules
########################################

autogen-swig-py: subversion/bindings/swig/python/core.c subversion/bindings/swig/python/svn_client.c subversion/bindings/swig/python/svn_delta.c subversion/bindings/swig/python/svn_diff.c subversion/bindings/swig/python/svn_fs.c subversion/bindings/swig/python/svn_ra.c subversion/bindings/swig/python/svn_repos.c subversion/bindings/swig/python/svn_wc.c
autogen-swig: autogen-swig-py

autogen-swig-pl: subversion/bindings/swig/perl/native/core.c subversion/bindings/swig/perl/native/svn_client.c subversion/bindings/swig/perl/native/svn_delta.c subversion/bindings/swig/perl/native/svn_diff.c subversion/bindings/swig/perl/native/svn_fs.c subversion/bindings/swig/perl/native/svn_ra.c subversion/bindings/swig/perl/native/svn_repos.c subversion/bindings/swig/perl/native/svn_wc.c
autogen-swig: autogen-swig-pl

autogen-swig-rb: subversion/bindings/swig/ruby/core.c subversion/bindings/swig/ruby/svn_client.c subversion/bindings/swig/ruby/svn_delta.c subversion/bindings/swig/ruby/svn_diff.c subversion/bindings/swig/ruby/svn_fs.c subversion/bindings/swig/ruby/svn_ra.c subversion/bindings/swig/ruby/svn_repos.c subversion/bindings/swig/ruby/svn_wc.c
autogen-swig: autogen-swig-rb



########################################
# Section 4: Rules to build SWIG .c files from .i files
########################################



########################################
# Section 5: Individual target build rules
########################################

auth_test_PATH = subversion/tests/libsvn_subr
auth_test_DEPS =  subversion/tests/libsvn_subr/auth-test.o subversion/tests/libsvn_test-1.la
auth_test_OBJECTS = auth-test.o
subversion/tests/libsvn_subr/auth-test$(EXEEXT): $(auth_test_DEPS)
	cd subversion/tests/libsvn_subr && $(LINK) -o auth-test$(EXEEXT)  $(auth_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_subr-1 $(LIBS)

cache_test_PATH = subversion/tests/libsvn_subr
cache_test_DEPS =  subversion/tests/libsvn_subr/cache-test.o subversion/tests/libsvn_test-1.la
cache_test_OBJECTS = cache-test.o
subversion/tests/libsvn_subr/cache-test$(EXEEXT): $(cache_test_DEPS)
	cd subversion/tests/libsvn_subr && $(LINK) -o cache-test$(EXEEXT)  $(cache_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

changes_test_PATH = subversion/tests/libsvn_fs_base
changes_test_DEPS =  subversion/tests/libsvn_fs_base/changes-test.o subversion/tests/libsvn_test-1.la subversion/libsvn_fs_base/libsvn_fs_base-1.la
changes_test_OBJECTS = changes-test.o
subversion/tests/libsvn_fs_base/changes-test$(EXEEXT): $(changes_test_DEPS)
	cd subversion/tests/libsvn_fs_base && $(LINK) -o changes-test$(EXEEXT)  $(changes_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_fs-1 ../../../subversion/libsvn_fs_base/libsvn_fs_base-1.la -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

checksum_test_PATH = subversion/tests/libsvn_subr
checksum_test_DEPS =  subversion/tests/libsvn_subr/checksum-test.o subversion/tests/libsvn_test-1.la
checksum_test_OBJECTS = checksum-test.o
subversion/tests/libsvn_subr/checksum-test$(EXEEXT): $(checksum_test_DEPS)
	cd subversion/tests/libsvn_subr && $(LINK) -o checksum-test$(EXEEXT)  $(checksum_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

client_test_PATH = subversion/tests/libsvn_client
client_test_DEPS =  subversion/tests/libsvn_client/client-test.o subversion/tests/libsvn_test-1.la
client_test_OBJECTS = client-test.o
subversion/tests/libsvn_client/client-test$(EXEEXT): $(client_test_DEPS)
	cd subversion/tests/libsvn_client && $(LINK) -o client-test$(EXEEXT)  $(client_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_delta-1 -lsvn_subr-1 -lsvn_client-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(NEON_LIBS) $(LIBS)

compat_test_PATH = subversion/tests/libsvn_subr
compat_test_DEPS =  subversion/tests/libsvn_subr/compat-test.o subversion/tests/libsvn_test-1.la
compat_test_OBJECTS = compat-test.o
subversion/tests/libsvn_subr/compat-test$(EXEEXT): $(compat_test_DEPS)
	cd subversion/tests/libsvn_subr && $(LINK) -o compat-test$(EXEEXT)  $(compat_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

config_test_PATH = subversion/tests/libsvn_subr
config_test_DEPS =  subversion/tests/libsvn_subr/config-test.o subversion/tests/libsvn_test-1.la
config_test_OBJECTS = config-test.o
subversion/tests/libsvn_subr/config-test$(EXEEXT): $(config_test_DEPS)
	cd subversion/tests/libsvn_subr && $(LINK) -o config-test$(EXEEXT)  $(config_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

diff_PATH = tools/diff
diff_DEPS =  tools/diff/diff.o
diff_OBJECTS = diff.o
tools/diff/diff$(EXEEXT): $(diff_DEPS)
	cd tools/diff && $(LINK) -o diff$(EXEEXT)  $(diff_OBJECTS) -lsvn_diff-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

diff_diff3_test_PATH = subversion/tests/libsvn_diff
diff_diff3_test_DEPS =  subversion/tests/libsvn_diff/diff-diff3-test.o subversion/tests/libsvn_test-1.la
diff_diff3_test_OBJECTS = diff-diff3-test.o
subversion/tests/libsvn_diff/diff-diff3-test$(EXEEXT): $(diff_diff3_test_DEPS)
	cd subversion/tests/libsvn_diff && $(LINK) -o diff-diff3-test$(EXEEXT)  $(diff_diff3_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_diff-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

diff3_PATH = tools/diff
diff3_DEPS =  tools/diff/diff3.o
diff3_OBJECTS = diff3.o
tools/diff/diff3$(EXEEXT): $(diff3_DEPS)
	cd tools/diff && $(LINK) -o diff3$(EXEEXT)  $(diff3_OBJECTS) -lsvn_diff-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

diff4_PATH = tools/diff
diff4_DEPS =  tools/diff/diff4.o
diff4_OBJECTS = diff4.o
tools/diff/diff4$(EXEEXT): $(diff4_DEPS)
	cd tools/diff && $(LINK) -o diff4$(EXEEXT)  $(diff4_OBJECTS) -lsvn_diff-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

dirent_uri_test_PATH = subversion/tests/libsvn_subr
dirent_uri_test_DEPS =  subversion/tests/libsvn_subr/dirent_uri-test.o subversion/tests/libsvn_test-1.la
dirent_uri_test_OBJECTS = dirent_uri-test.o
subversion/tests/libsvn_subr/dirent_uri-test$(EXEEXT): $(dirent_uri_test_DEPS)
	cd subversion/tests/libsvn_subr && $(LINK) -o dirent_uri-test$(EXEEXT)  $(dirent_uri_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

error_test_PATH = subversion/tests/libsvn_subr
error_test_DEPS =  subversion/tests/libsvn_subr/error-test.o subversion/tests/libsvn_test-1.la
error_test_OBJECTS = error-test.o
subversion/tests/libsvn_subr/error-test$(EXEEXT): $(error_test_DEPS)
	cd subversion/tests/libsvn_subr && $(LINK) -o error-test$(EXEEXT)  $(error_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

fs_base_test_PATH = subversion/tests/libsvn_fs_base
fs_base_test_DEPS =  subversion/tests/libsvn_fs_base/fs-base-test.o subversion/tests/libsvn_test-1.la subversion/libsvn_fs_base/libsvn_fs_base-1.la subversion/libsvn_fs_util/libsvn_fs_util-1.la
fs_base_test_OBJECTS = fs-base-test.o
subversion/tests/libsvn_fs_base/fs-base-test$(EXEEXT): $(fs_base_test_DEPS)
	cd subversion/tests/libsvn_fs_base && $(LINK) -o fs-base-test$(EXEEXT)  $(fs_base_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_fs-1 ../../../subversion/libsvn_fs_base/libsvn_fs_base-1.la -lsvn_delta-1 ../../../subversion/libsvn_fs_util/libsvn_fs_util-1.la -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

fs_pack_test_PATH = subversion/tests/libsvn_fs_fs
fs_pack_test_DEPS =  subversion/tests/libsvn_fs_fs/fs-pack-test.o subversion/tests/libsvn_test-1.la subversion/libsvn_fs_fs/libsvn_fs_fs-1.la
fs_pack_test_OBJECTS = fs-pack-test.o
subversion/tests/libsvn_fs_fs/fs-pack-test$(EXEEXT): $(fs_pack_test_DEPS)
	cd subversion/tests/libsvn_fs_fs && $(LINK) -o fs-pack-test$(EXEEXT)  $(fs_pack_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_fs-1 ../../../subversion/libsvn_fs_fs/libsvn_fs_fs-1.la -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

fs_test_PATH = subversion/tests/libsvn_fs
fs_test_DEPS =  subversion/tests/libsvn_fs/fs-test.o subversion/tests/libsvn_test-1.la
fs_test_OBJECTS = fs-test.o
subversion/tests/libsvn_fs/fs-test$(EXEEXT): $(fs_test_DEPS)
	cd subversion/tests/libsvn_fs && $(LINK) -o fs-test$(EXEEXT)  $(fs_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_fs-1 -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

hashdump_test_PATH = subversion/tests/libsvn_subr
hashdump_test_DEPS =  subversion/tests/libsvn_subr/hashdump-test.o subversion/tests/libsvn_test-1.la
hashdump_test_OBJECTS = hashdump-test.o
subversion/tests/libsvn_subr/hashdump-test$(EXEEXT): $(hashdump_test_DEPS)
	cd subversion/tests/libsvn_subr && $(LINK) -o hashdump-test$(EXEEXT)  $(hashdump_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

javahl_java_PATH = subversion/bindings/javahl/classes
javahl_java_HEADERS = 
javahl_java_OBJECTS = subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNClientInterface.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/DiffSummaryReceiver.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ProgressListener.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Notify.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/InputInterface.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Lock.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Path.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Notify2.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ListCallback.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/CommitItemStateFlags.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/LogMessage.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ConflictResult.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/BlameCallback2.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Info.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/StatusCallback.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/NodeKind.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/DirEntry.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/NativeException.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/OutputInterface.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNClientLogLevel.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Info2.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ProplistCallbackImpl.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/NotifyStatus.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/PromptUserPassword2.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/NotifyAction.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Mergeinfo.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/StatusKind.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/MergeinfoLogKind.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/CommitMessage.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Operation.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/CommitItem.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/BlameCallback.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ConflictVersion.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/RevisionKind.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/LogDate.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNClientSynchronized.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/CopySource.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/NativeResources.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/PromptUserPassword3.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Version.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNOutputStream.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/PropertyData.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ChangePath.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ScheduleKind.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNClient.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ChangelistCallback.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNAdmin.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNInputStream.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ClientException.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ErrorCodes.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ProplistCallback.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Status.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/JNIError.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SubversionException.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/LogMessageCallback.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Revision.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ConflictDescriptor.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ProgressEvent.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/BlameCallbackImpl.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Depth.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/InfoCallback.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/DiffSummary.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/LockStatus.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ConflictResolverCallback.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/RevisionRange.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/PromptUserPassword.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/NotifyInformation.class
javahl_java_DEPS = $(javahl_java_HEADERS) $(javahl_java_OBJECTS)  
javahl-java: $(javahl_java_DEPS)
javahl_java_SRC = $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/SVNClientInterface.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/DiffSummaryReceiver.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/ProgressListener.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/Notify.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/InputInterface.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/Lock.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/Path.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/Notify2.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/ListCallback.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/CommitItemStateFlags.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/LogMessage.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/ConflictResult.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/BlameCallback2.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/Info.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/StatusCallback.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/NodeKind.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/DirEntry.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/NativeException.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/OutputInterface.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/SVNClientLogLevel.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/Info2.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/ProplistCallbackImpl.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/NotifyStatus.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/PromptUserPassword2.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/NotifyAction.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/Mergeinfo.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/StatusKind.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/MergeinfoLogKind.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/CommitMessage.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/Operation.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/CommitItem.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/BlameCallback.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/ConflictVersion.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/RevisionKind.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/LogDate.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/SVNClientSynchronized.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/CopySource.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/NativeResources.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/PromptUserPassword3.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/Version.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/SVNOutputStream.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/PropertyData.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/ChangePath.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/ScheduleKind.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/SVNClient.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/ChangelistCallback.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/SVNAdmin.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/SVNInputStream.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/ClientException.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/ErrorCodes.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/ProplistCallback.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/Status.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/JNIError.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/SubversionException.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/LogMessageCallback.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/Revision.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/ConflictDescriptor.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/ProgressEvent.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/BlameCallbackImpl.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/Depth.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/InfoCallback.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/DiffSummary.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/LockStatus.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/ConflictResolverCallback.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/RevisionRange.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/PromptUserPassword.java $(abs_srcdir)/subversion/bindings/javahl/src/org/tigris/subversion/javahl/NotifyInformation.java
$(javahl_java_OBJECTS): $(javahl_java_SRC)
	$(COMPILE_JAVAHL_JAVAC) -d subversion/bindings/javahl/classes -classpath subversion/bindings/javahl/classes:$(javahl_java_CLASSPATH) $(javahl_java_SRC)


javahl_javah_PATH = subversion/bindings/javahl/include
javahl_javah_HEADERS = subversion/bindings/javahl/include/org_tigris_subversion_javahl_SVNClientInterface.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_DiffSummaryReceiver.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_ProgressListener.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_Notify.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_InputInterface.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_Lock.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_Path.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_Notify2.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_ListCallback.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_CommitItemStateFlags.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_LogMessage.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_ConflictResult.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_BlameCallback2.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_Info.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_StatusCallback.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_NodeKind.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_DirEntry.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_NativeException.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_OutputInterface.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_SVNClientLogLevel.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_Info2.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_ProplistCallbackImpl.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_NotifyStatus.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_PromptUserPassword2.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_NotifyAction.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_Mergeinfo.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_StatusKind.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_MergeinfoLogKind.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_CommitMessage.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_Operation.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_CommitItem.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_BlameCallback.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_ConflictVersion.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_RevisionKind.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_LogDate.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_SVNClientSynchronized.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_CopySource.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_NativeResources.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_PromptUserPassword3.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_Version.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_SVNOutputStream.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_PropertyData.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_ChangePath.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_ScheduleKind.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_SVNClient.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_ChangelistCallback.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_SVNAdmin.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_SVNInputStream.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_ClientException.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_ErrorCodes.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_ProplistCallback.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_Status.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_JNIError.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_SubversionException.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_LogMessageCallback.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_Revision.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_ConflictDescriptor.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_ProgressEvent.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_BlameCallbackImpl.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_Depth.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_InfoCallback.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_DiffSummary.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_LockStatus.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_ConflictResolverCallback.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_RevisionRange.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_PromptUserPassword.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_NotifyInformation.h
javahl_javah_OBJECTS = 
javahl_javah_DEPS = $(javahl_javah_HEADERS) $(javahl_javah_OBJECTS) $(javahl_java_DEPS) 
javahl-javah: $(javahl_javah_DEPS)
javahl_javah_CLASS_FILENAMES = subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNClientInterface.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/DiffSummaryReceiver.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ProgressListener.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Notify.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/InputInterface.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Lock.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Path.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Notify2.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ListCallback.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/CommitItemStateFlags.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/LogMessage.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ConflictResult.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/BlameCallback2.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Info.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/StatusCallback.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/NodeKind.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/DirEntry.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/NativeException.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/OutputInterface.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNClientLogLevel.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Info2.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ProplistCallbackImpl.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/NotifyStatus.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/PromptUserPassword2.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/NotifyAction.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Mergeinfo.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/StatusKind.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/MergeinfoLogKind.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/CommitMessage.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Operation.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/CommitItem.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/BlameCallback.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ConflictVersion.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/RevisionKind.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/LogDate.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNClientSynchronized.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/CopySource.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/NativeResources.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/PromptUserPassword3.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Version.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNOutputStream.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/PropertyData.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ChangePath.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ScheduleKind.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNClient.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ChangelistCallback.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNAdmin.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNInputStream.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ClientException.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ErrorCodes.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ProplistCallback.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Status.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/JNIError.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SubversionException.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/LogMessageCallback.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Revision.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ConflictDescriptor.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ProgressEvent.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/BlameCallbackImpl.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Depth.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/InfoCallback.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/DiffSummary.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/LockStatus.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ConflictResolverCallback.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/RevisionRange.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/PromptUserPassword.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/NotifyInformation.class
javahl_javah_CLASSES = org.tigris.subversion.javahl.SVNClientInterface org.tigris.subversion.javahl.DiffSummaryReceiver org.tigris.subversion.javahl.ProgressListener org.tigris.subversion.javahl.Notify org.tigris.subversion.javahl.InputInterface org.tigris.subversion.javahl.Lock org.tigris.subversion.javahl.Path org.tigris.subversion.javahl.Notify2 org.tigris.subversion.javahl.ListCallback org.tigris.subversion.javahl.CommitItemStateFlags org.tigris.subversion.javahl.LogMessage org.tigris.subversion.javahl.ConflictResult org.tigris.subversion.javahl.BlameCallback2 org.tigris.subversion.javahl.Info org.tigris.subversion.javahl.StatusCallback org.tigris.subversion.javahl.NodeKind org.tigris.subversion.javahl.DirEntry org.tigris.subversion.javahl.NativeException org.tigris.subversion.javahl.OutputInterface org.tigris.subversion.javahl.SVNClientLogLevel org.tigris.subversion.javahl.Info2 org.tigris.subversion.javahl.ProplistCallbackImpl org.tigris.subversion.javahl.NotifyStatus org.tigris.subversion.javahl.PromptUserPassword2 org.tigris.subversion.javahl.NotifyAction org.tigris.subversion.javahl.Mergeinfo org.tigris.subversion.javahl.StatusKind org.tigris.subversion.javahl.MergeinfoLogKind org.tigris.subversion.javahl.CommitMessage org.tigris.subversion.javahl.Operation org.tigris.subversion.javahl.CommitItem org.tigris.subversion.javahl.BlameCallback org.tigris.subversion.javahl.ConflictVersion org.tigris.subversion.javahl.RevisionKind org.tigris.subversion.javahl.LogDate org.tigris.subversion.javahl.SVNClientSynchronized org.tigris.subversion.javahl.CopySource org.tigris.subversion.javahl.NativeResources org.tigris.subversion.javahl.PromptUserPassword3 org.tigris.subversion.javahl.Version org.tigris.subversion.javahl.SVNOutputStream org.tigris.subversion.javahl.PropertyData org.tigris.subversion.javahl.ChangePath org.tigris.subversion.javahl.ScheduleKind org.tigris.subversion.javahl.SVNClient org.tigris.subversion.javahl.ChangelistCallback org.tigris.subversion.javahl.SVNAdmin org.tigris.subversion.javahl.SVNInputStream org.tigris.subversion.javahl.ClientException org.tigris.subversion.javahl.ErrorCodes org.tigris.subversion.javahl.ProplistCallback org.tigris.subversion.javahl.Status org.tigris.subversion.javahl.JNIError org.tigris.subversion.javahl.SubversionException org.tigris.subversion.javahl.LogMessageCallback org.tigris.subversion.javahl.Revision org.tigris.subversion.javahl.ConflictDescriptor org.tigris.subversion.javahl.ProgressEvent org.tigris.subversion.javahl.BlameCallbackImpl org.tigris.subversion.javahl.Depth org.tigris.subversion.javahl.InfoCallback org.tigris.subversion.javahl.DiffSummary org.tigris.subversion.javahl.LockStatus org.tigris.subversion.javahl.ConflictResolverCallback org.tigris.subversion.javahl.RevisionRange org.tigris.subversion.javahl.PromptUserPassword org.tigris.subversion.javahl.NotifyInformation
$(javahl_javah_HEADERS): $(javahl_javah_CLASS_FILENAMES)
	$(COMPILE_JAVAHL_JAVAH) -force -d subversion/bindings/javahl/include -classpath subversion/bindings/javahl/classes:$(javahl_javah_CLASSPATH) $(javahl_javah_CLASSES)


javahl_tests_PATH = subversion/bindings/javahl/classes
javahl_tests_HEADERS = 
javahl_tests_OBJECTS = subversion/bindings/javahl/classes/org/tigris/subversion/javahl/WC.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/RunTests.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/BasicTests.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNAdminTests.class subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNTests.class
javahl_tests_DEPS = $(javahl_tests_HEADERS) $(javahl_tests_OBJECTS)  
javahl-tests: $(javahl_tests_DEPS)
javahl_tests_SRC = $(abs_srcdir)/subversion/bindings/javahl/tests/org/tigris/subversion/javahl/WC.java $(abs_srcdir)/subversion/bindings/javahl/tests/org/tigris/subversion/javahl/RunTests.java $(abs_srcdir)/subversion/bindings/javahl/tests/org/tigris/subversion/javahl/BasicTests.java $(abs_srcdir)/subversion/bindings/javahl/tests/org/tigris/subversion/javahl/SVNAdminTests.java $(abs_srcdir)/subversion/bindings/javahl/tests/org/tigris/subversion/javahl/SVNTests.java
$(javahl_tests_OBJECTS): $(javahl_tests_SRC)
	$(COMPILE_JAVAHL_JAVAC) -d subversion/bindings/javahl/classes -classpath subversion/bindings/javahl/classes:$(javahl_tests_CLASSPATH) $(javahl_tests_SRC)


key_test_PATH = subversion/tests/libsvn_fs_base
key_test_DEPS =  subversion/tests/libsvn_fs_base/key-test.o subversion/tests/libsvn_test-1.la subversion/libsvn_fs_base/libsvn_fs_base-1.la
key_test_OBJECTS = key-test.o
subversion/tests/libsvn_fs_base/key-test$(EXEEXT): $(key_test_DEPS)
	cd subversion/tests/libsvn_fs_base && $(LINK) -o key-test$(EXEEXT)  $(key_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la ../../../subversion/libsvn_fs_base/libsvn_fs_base-1.la -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

libsvn_auth_gnome_keyring_PATH = subversion/libsvn_auth_gnome_keyring
libsvn_auth_gnome_keyring_DEPS =  subversion/libsvn_auth_gnome_keyring/gnome_keyring.lo subversion/libsvn_auth_gnome_keyring/version.lo
libsvn_auth_gnome_keyring_OBJECTS = gnome_keyring.lo version.lo
subversion/libsvn_auth_gnome_keyring/libsvn_auth_gnome_keyring-1.la: $(libsvn_auth_gnome_keyring_DEPS)
	cd subversion/libsvn_auth_gnome_keyring && $(LINK) -o libsvn_auth_gnome_keyring-1.la $(LT_NO_UNDEFINED) $(libsvn_auth_gnome_keyring_OBJECTS) $(SVN_APR_LIBS) $(SVN_GNOME_KEYRING_LIBS) -lsvn_subr-1 $(LIBS)

libsvn_auth_kwallet_PATH = subversion/libsvn_auth_kwallet
libsvn_auth_kwallet_DEPS =  subversion/libsvn_auth_kwallet/kwallet.lo subversion/libsvn_auth_kwallet/version.lo
libsvn_auth_kwallet_OBJECTS = kwallet.lo version.lo
subversion/libsvn_auth_kwallet/libsvn_auth_kwallet-1.la: $(libsvn_auth_kwallet_DEPS)
	cd subversion/libsvn_auth_kwallet && $(LINK_CXX) -o libsvn_auth_kwallet-1.la $(LT_NO_UNDEFINED) $(libsvn_auth_kwallet_OBJECTS) $(SVN_APR_LIBS) $(SVN_KWALLET_LIBS) -lsvn_subr-1 $(LIBS)

libsvn_client_PATH = subversion/libsvn_client
libsvn_client_DEPS =  subversion/libsvn_client/add.lo subversion/libsvn_client/blame.lo subversion/libsvn_client/cat.lo subversion/libsvn_client/changelist.lo subversion/libsvn_client/checkout.lo subversion/libsvn_client/cleanup.lo subversion/libsvn_client/cmdline.lo subversion/libsvn_client/commit.lo subversion/libsvn_client/commit_util.lo subversion/libsvn_client/compat_providers.lo subversion/libsvn_client/copy.lo subversion/libsvn_client/ctx.lo subversion/libsvn_client/delete.lo subversion/libsvn_client/deprecated.lo subversion/libsvn_client/diff.lo subversion/libsvn_client/export.lo subversion/libsvn_client/externals.lo subversion/libsvn_client/info.lo subversion/libsvn_client/list.lo subversion/libsvn_client/locking_commands.lo subversion/libsvn_client/log.lo subversion/libsvn_client/merge.lo subversion/libsvn_client/mergeinfo.lo subversion/libsvn_client/prop_commands.lo subversion/libsvn_client/ra.lo subversion/libsvn_client/relocate.lo subversion/libsvn_client/repos_diff.lo subversion/libsvn_client/repos_diff_summarize.lo subversion/libsvn_client/resolved.lo subversion/libsvn_client/revert.lo subversion/libsvn_client/revisions.lo subversion/libsvn_client/status.lo subversion/libsvn_client/switch.lo subversion/libsvn_client/update.lo subversion/libsvn_client/url.lo subversion/libsvn_client/util.lo subversion/libsvn_client/version.lo
libsvn_client_OBJECTS = add.lo blame.lo cat.lo changelist.lo checkout.lo cleanup.lo cmdline.lo commit.lo commit_util.lo compat_providers.lo copy.lo ctx.lo delete.lo deprecated.lo diff.lo export.lo externals.lo info.lo list.lo locking_commands.lo log.lo merge.lo mergeinfo.lo prop_commands.lo ra.lo relocate.lo repos_diff.lo repos_diff_summarize.lo resolved.lo revert.lo revisions.lo status.lo switch.lo update.lo url.lo util.lo version.lo
subversion/libsvn_client/libsvn_client-1.la: $(libsvn_client_DEPS)
	cd subversion/libsvn_client && $(LINK) -o libsvn_client-1.la $(LT_NO_UNDEFINED) $(libsvn_client_OBJECTS) -lsvn_wc-1 -lsvn_ra-1 -lsvn_delta-1 -lsvn_diff-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

libsvn_delta_PATH = subversion/libsvn_delta
libsvn_delta_DEPS =  subversion/libsvn_delta/cancel.lo subversion/libsvn_delta/compat.lo subversion/libsvn_delta/compose_delta.lo subversion/libsvn_delta/debug_editor.lo subversion/libsvn_delta/default_editor.lo subversion/libsvn_delta/depth_filter_editor.lo subversion/libsvn_delta/path_driver.lo subversion/libsvn_delta/svndiff.lo subversion/libsvn_delta/text_delta.lo subversion/libsvn_delta/version.lo subversion/libsvn_delta/xdelta.lo
libsvn_delta_OBJECTS = cancel.lo compat.lo compose_delta.lo debug_editor.lo default_editor.lo depth_filter_editor.lo path_driver.lo svndiff.lo text_delta.lo version.lo xdelta.lo
subversion/libsvn_delta/libsvn_delta-1.la: $(libsvn_delta_DEPS)
	cd subversion/libsvn_delta && $(LINK) -o libsvn_delta-1.la $(LT_NO_UNDEFINED) $(libsvn_delta_OBJECTS) -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(SVN_ZLIB_LIBS) $(LIBS)

libsvn_diff_PATH = subversion/libsvn_diff
libsvn_diff_DEPS =  subversion/libsvn_diff/deprecated.lo subversion/libsvn_diff/diff.lo subversion/libsvn_diff/diff3.lo subversion/libsvn_diff/diff4.lo subversion/libsvn_diff/diff_file.lo subversion/libsvn_diff/diff_memory.lo subversion/libsvn_diff/lcs.lo subversion/libsvn_diff/token.lo subversion/libsvn_diff/util.lo
libsvn_diff_OBJECTS = deprecated.lo diff.lo diff3.lo diff4.lo diff_file.lo diff_memory.lo lcs.lo token.lo util.lo
subversion/libsvn_diff/libsvn_diff-1.la: $(libsvn_diff_DEPS)
	cd subversion/libsvn_diff && $(LINK) -o libsvn_diff-1.la $(LT_NO_UNDEFINED) $(libsvn_diff_OBJECTS) -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

libsvn_fs_PATH = subversion/libsvn_fs
install-ramod-lib: $(SVN_FS_LIB_INSTALL_DEPS)
libsvn_fs_DEPS = $(SVN_FS_LIB_DEPS) subversion/libsvn_fs/access.lo subversion/libsvn_fs/fs-loader.lo subversion/libsvn_fs_util/libsvn_fs_util-1.la
libsvn_fs_OBJECTS = access.lo fs-loader.lo
subversion/libsvn_fs/libsvn_fs-1.la: $(libsvn_fs_DEPS)
	cd subversion/libsvn_fs && $(LINK) -o libsvn_fs-1.la $(LT_NO_UNDEFINED) $(libsvn_fs_OBJECTS) ../../subversion/libsvn_fs_util/libsvn_fs_util-1.la -lsvn_subr-1 $(SVN_FS_LIB_LINK) $(SVN_APR_LIBS) $(LIBS)

libsvn_fs_base_PATH = subversion/libsvn_fs_base
libsvn_fs_base_DEPS =  subversion/libsvn_fs_base/bdb/bdb-err.lo subversion/libsvn_fs_base/bdb/bdb_compat.lo subversion/libsvn_fs_base/bdb/changes-table.lo subversion/libsvn_fs_base/bdb/checksum-reps-table.lo subversion/libsvn_fs_base/bdb/copies-table.lo subversion/libsvn_fs_base/bdb/dbt.lo subversion/libsvn_fs_base/bdb/env.lo subversion/libsvn_fs_base/bdb/lock-tokens-table.lo subversion/libsvn_fs_base/bdb/locks-table.lo subversion/libsvn_fs_base/bdb/miscellaneous-table.lo subversion/libsvn_fs_base/bdb/node-origins-table.lo subversion/libsvn_fs_base/bdb/nodes-table.lo subversion/libsvn_fs_base/bdb/reps-table.lo subversion/libsvn_fs_base/bdb/rev-table.lo subversion/libsvn_fs_base/bdb/strings-table.lo subversion/libsvn_fs_base/bdb/txn-table.lo subversion/libsvn_fs_base/bdb/uuids-table.lo subversion/libsvn_fs_base/dag.lo subversion/libsvn_fs_base/err.lo subversion/libsvn_fs_base/fs.lo subversion/libsvn_fs_base/id.lo subversion/libsvn_fs_base/key-gen.lo subversion/libsvn_fs_base/lock.lo subversion/libsvn_fs_base/node-rev.lo subversion/libsvn_fs_base/reps-strings.lo subversion/libsvn_fs_base/revs-txns.lo subversion/libsvn_fs_base/trail.lo subversion/libsvn_fs_base/tree.lo subversion/libsvn_fs_base/util/fs_skels.lo subversion/libsvn_fs_base/uuid.lo subversion/libsvn_fs_util/libsvn_fs_util-1.la
libsvn_fs_base_OBJECTS = bdb/bdb-err.lo bdb/bdb_compat.lo bdb/changes-table.lo bdb/checksum-reps-table.lo bdb/copies-table.lo bdb/dbt.lo bdb/env.lo bdb/lock-tokens-table.lo bdb/locks-table.lo bdb/miscellaneous-table.lo bdb/node-origins-table.lo bdb/nodes-table.lo bdb/reps-table.lo bdb/rev-table.lo bdb/strings-table.lo bdb/txn-table.lo bdb/uuids-table.lo dag.lo err.lo fs.lo id.lo key-gen.lo lock.lo node-rev.lo reps-strings.lo revs-txns.lo trail.lo tree.lo util/fs_skels.lo uuid.lo
subversion/libsvn_fs_base/libsvn_fs_base-1.la: $(libsvn_fs_base_DEPS)
	cd subversion/libsvn_fs_base && $(LINK) -o libsvn_fs_base-1.la $(LT_NO_UNDEFINED) $(libsvn_fs_base_OBJECTS) -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(SVN_DB_LIBS) ../../subversion/libsvn_fs_util/libsvn_fs_util-1.la $(LIBS)

libsvn_fs_fs_PATH = subversion/libsvn_fs_fs
libsvn_fs_fs_DEPS =  subversion/libsvn_fs_fs/caching.lo subversion/libsvn_fs_fs/dag.lo subversion/libsvn_fs_fs/err.lo subversion/libsvn_fs_fs/fs.lo subversion/libsvn_fs_fs/fs_fs.lo subversion/libsvn_fs_fs/id.lo subversion/libsvn_fs_fs/key-gen.lo subversion/libsvn_fs_fs/lock.lo subversion/libsvn_fs_fs/rep-cache.lo subversion/libsvn_fs_fs/tree.lo subversion/libsvn_fs_util/libsvn_fs_util-1.la
libsvn_fs_fs_OBJECTS = caching.lo dag.lo err.lo fs.lo fs_fs.lo id.lo key-gen.lo lock.lo rep-cache.lo tree.lo
subversion/libsvn_fs_fs/libsvn_fs_fs-1.la: $(libsvn_fs_fs_DEPS)
	cd subversion/libsvn_fs_fs && $(LINK) -o libsvn_fs_fs-1.la $(LT_NO_UNDEFINED) $(libsvn_fs_fs_OBJECTS) -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) ../../subversion/libsvn_fs_util/libsvn_fs_util-1.la $(LIBS)

libsvn_fs_util_PATH = subversion/libsvn_fs_util
libsvn_fs_util_DEPS =  subversion/libsvn_fs_util/fs-util.lo
libsvn_fs_util_OBJECTS = fs-util.lo
subversion/libsvn_fs_util/libsvn_fs_util-1.la: $(libsvn_fs_util_DEPS)
	cd subversion/libsvn_fs_util && $(LINK) -o libsvn_fs_util-1.la $(LT_NO_UNDEFINED) $(libsvn_fs_util_OBJECTS) -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

libsvn_ra_PATH = subversion/libsvn_ra
install-lib: $(SVN_RA_LIB_INSTALL_DEPS)
libsvn_ra_DEPS = $(SVN_RA_LIB_DEPS) subversion/libsvn_ra/compat.lo subversion/libsvn_ra/deprecated.lo subversion/libsvn_ra/ra_loader.lo subversion/libsvn_ra/util.lo
libsvn_ra_OBJECTS = compat.lo deprecated.lo ra_loader.lo util.lo
subversion/libsvn_ra/libsvn_ra-1.la: $(libsvn_ra_DEPS)
	cd subversion/libsvn_ra && $(LINK) -o libsvn_ra-1.la $(LT_NO_UNDEFINED) $(libsvn_ra_OBJECTS) -lsvn_delta-1 -lsvn_subr-1 $(SVN_RA_LIB_LINK) $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

libsvn_ra_local_PATH = subversion/libsvn_ra_local
libsvn_ra_local_DEPS =  subversion/libsvn_ra_local/ra_plugin.lo subversion/libsvn_ra_local/split_url.lo
libsvn_ra_local_OBJECTS = ra_plugin.lo split_url.lo
subversion/libsvn_ra_local/libsvn_ra_local-1.la: $(libsvn_ra_local_DEPS)
	cd subversion/libsvn_ra_local && $(LINK) -o libsvn_ra_local-1.la $(LT_NO_UNDEFINED) $(libsvn_ra_local_OBJECTS) -lsvn_repos-1 -lsvn_fs-1 -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

libsvn_ra_neon_PATH = subversion/libsvn_ra_neon
libsvn_ra_neon_DEPS =  subversion/libsvn_ra_neon/commit.lo subversion/libsvn_ra_neon/fetch.lo subversion/libsvn_ra_neon/file_revs.lo subversion/libsvn_ra_neon/get_dated_rev.lo subversion/libsvn_ra_neon/get_deleted_rev.lo subversion/libsvn_ra_neon/get_location_segments.lo subversion/libsvn_ra_neon/get_locations.lo subversion/libsvn_ra_neon/get_locks.lo subversion/libsvn_ra_neon/lock.lo subversion/libsvn_ra_neon/log.lo subversion/libsvn_ra_neon/merge.lo subversion/libsvn_ra_neon/mergeinfo.lo subversion/libsvn_ra_neon/options.lo subversion/libsvn_ra_neon/props.lo subversion/libsvn_ra_neon/replay.lo subversion/libsvn_ra_neon/session.lo subversion/libsvn_ra_neon/util.lo
libsvn_ra_neon_OBJECTS = commit.lo fetch.lo file_revs.lo get_dated_rev.lo get_deleted_rev.lo get_location_segments.lo get_locations.lo get_locks.lo lock.lo log.lo merge.lo mergeinfo.lo options.lo props.lo replay.lo session.lo util.lo
subversion/libsvn_ra_neon/libsvn_ra_neon-1.la: $(libsvn_ra_neon_DEPS)
	cd subversion/libsvn_ra_neon && $(LINK) -o libsvn_ra_neon-1.la $(LT_NO_UNDEFINED) $(libsvn_ra_neon_OBJECTS) -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(NEON_LIBS) $(LIBS)

libsvn_ra_serf_PATH = subversion/libsvn_ra_serf
libsvn_ra_serf_DEPS =  subversion/libsvn_ra_serf/auth.lo subversion/libsvn_ra_serf/blame.lo subversion/libsvn_ra_serf/commit.lo subversion/libsvn_ra_serf/get_deleted_rev.lo subversion/libsvn_ra_serf/getdate.lo subversion/libsvn_ra_serf/getlocations.lo subversion/libsvn_ra_serf/getlocationsegments.lo subversion/libsvn_ra_serf/getlocks.lo subversion/libsvn_ra_serf/locks.lo subversion/libsvn_ra_serf/log.lo subversion/libsvn_ra_serf/merge.lo subversion/libsvn_ra_serf/mergeinfo.lo subversion/libsvn_ra_serf/options.lo subversion/libsvn_ra_serf/property.lo subversion/libsvn_ra_serf/replay.lo subversion/libsvn_ra_serf/serf.lo subversion/libsvn_ra_serf/update.lo subversion/libsvn_ra_serf/util.lo subversion/libsvn_ra_serf/win32_auth_sspi.lo subversion/libsvn_ra_serf/xml.lo
libsvn_ra_serf_OBJECTS = auth.lo blame.lo commit.lo get_deleted_rev.lo getdate.lo getlocations.lo getlocationsegments.lo getlocks.lo locks.lo log.lo merge.lo mergeinfo.lo options.lo property.lo replay.lo serf.lo update.lo util.lo win32_auth_sspi.lo xml.lo
subversion/libsvn_ra_serf/libsvn_ra_serf-1.la: $(libsvn_ra_serf_DEPS)
	cd subversion/libsvn_ra_serf && $(LINK) -o libsvn_ra_serf-1.la $(LT_NO_UNDEFINED) $(libsvn_ra_serf_OBJECTS) -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(SVN_SERF_LIBS) $(LIBS)

libsvn_ra_svn_PATH = subversion/libsvn_ra_svn
libsvn_ra_svn_DEPS =  subversion/libsvn_ra_svn/client.lo subversion/libsvn_ra_svn/cram.lo subversion/libsvn_ra_svn/cyrus_auth.lo subversion/libsvn_ra_svn/editorp.lo subversion/libsvn_ra_svn/internal_auth.lo subversion/libsvn_ra_svn/marshal.lo subversion/libsvn_ra_svn/streams.lo subversion/libsvn_ra_svn/version.lo
libsvn_ra_svn_OBJECTS = client.lo cram.lo cyrus_auth.lo editorp.lo internal_auth.lo marshal.lo streams.lo version.lo
subversion/libsvn_ra_svn/libsvn_ra_svn-1.la: $(libsvn_ra_svn_DEPS)
	cd subversion/libsvn_ra_svn && $(LINK) -o libsvn_ra_svn-1.la $(LT_NO_UNDEFINED) $(libsvn_ra_svn_OBJECTS) -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(SVN_SASL_LIBS) $(LIBS)

libsvn_repos_PATH = subversion/libsvn_repos
libsvn_repos_DEPS =  subversion/libsvn_repos/authz.lo subversion/libsvn_repos/commit.lo subversion/libsvn_repos/delta.lo subversion/libsvn_repos/deprecated.lo subversion/libsvn_repos/dump.lo subversion/libsvn_repos/fs-wrap.lo subversion/libsvn_repos/hooks.lo subversion/libsvn_repos/load.lo subversion/libsvn_repos/log.lo subversion/libsvn_repos/node_tree.lo subversion/libsvn_repos/replay.lo subversion/libsvn_repos/reporter.lo subversion/libsvn_repos/repos.lo subversion/libsvn_repos/rev_hunt.lo
libsvn_repos_OBJECTS = authz.lo commit.lo delta.lo deprecated.lo dump.lo fs-wrap.lo hooks.lo load.lo log.lo node_tree.lo replay.lo reporter.lo repos.lo rev_hunt.lo
subversion/libsvn_repos/libsvn_repos-1.la: $(libsvn_repos_DEPS)
	cd subversion/libsvn_repos && $(LINK) -o libsvn_repos-1.la $(LT_NO_UNDEFINED) $(libsvn_repos_OBJECTS) -lsvn_fs-1 -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

libsvn_subr_PATH = subversion/libsvn_subr
libsvn_subr_DEPS =  subversion/libsvn_subr/atomic.lo subversion/libsvn_subr/auth.lo subversion/libsvn_subr/cache-inprocess.lo subversion/libsvn_subr/cache-memcache.lo subversion/libsvn_subr/cache.lo subversion/libsvn_subr/checksum.lo subversion/libsvn_subr/cmdline.lo subversion/libsvn_subr/compat.lo subversion/libsvn_subr/config.lo subversion/libsvn_subr/config_auth.lo subversion/libsvn_subr/config_file.lo subversion/libsvn_subr/config_win.lo subversion/libsvn_subr/constructors.lo subversion/libsvn_subr/ctype.lo subversion/libsvn_subr/date.lo subversion/libsvn_subr/deprecated.lo subversion/libsvn_subr/dirent_uri.lo subversion/libsvn_subr/dso.lo subversion/libsvn_subr/error.lo subversion/libsvn_subr/hash.lo subversion/libsvn_subr/io.lo subversion/libsvn_subr/iter.lo subversion/libsvn_subr/kitchensink.lo subversion/libsvn_subr/lock.lo subversion/libsvn_subr/log.lo subversion/libsvn_subr/macos_keychain.lo subversion/libsvn_subr/md5.lo subversion/libsvn_subr/mergeinfo.lo subversion/libsvn_subr/nls.lo subversion/libsvn_subr/opt.lo subversion/libsvn_subr/path.lo subversion/libsvn_subr/pool.lo subversion/libsvn_subr/prompt.lo subversion/libsvn_subr/properties.lo subversion/libsvn_subr/quoprint.lo subversion/libsvn_subr/sha1.lo subversion/libsvn_subr/simple_providers.lo subversion/libsvn_subr/skel.lo subversion/libsvn_subr/sorts.lo subversion/libsvn_subr/sqlite.lo subversion/libsvn_subr/ssl_client_cert_providers.lo subversion/libsvn_subr/ssl_client_cert_pw_providers.lo subversion/libsvn_subr/ssl_server_trust_providers.lo subversion/libsvn_subr/stream.lo subversion/libsvn_subr/subst.lo subversion/libsvn_subr/svn_base64.lo subversion/libsvn_subr/svn_string.lo subversion/libsvn_subr/target.lo subversion/libsvn_subr/time.lo subversion/libsvn_subr/user.lo subversion/libsvn_subr/username_providers.lo subversion/libsvn_subr/utf.lo subversion/libsvn_subr/utf_validate.lo subversion/libsvn_subr/validate.lo subversion/libsvn_subr/version.lo subversion/libsvn_subr/win32_crashrpt.lo subversion/libsvn_subr/win32_crypto.lo subversion/libsvn_subr/win32_xlate.lo subversion/libsvn_subr/xml.lo
libsvn_subr_OBJECTS = atomic.lo auth.lo cache-inprocess.lo cache-memcache.lo cache.lo checksum.lo cmdline.lo compat.lo config.lo config_auth.lo config_file.lo config_win.lo constructors.lo ctype.lo date.lo deprecated.lo dirent_uri.lo dso.lo error.lo hash.lo io.lo iter.lo kitchensink.lo lock.lo log.lo macos_keychain.lo md5.lo mergeinfo.lo nls.lo opt.lo path.lo pool.lo prompt.lo properties.lo quoprint.lo sha1.lo simple_providers.lo skel.lo sorts.lo sqlite.lo ssl_client_cert_providers.lo ssl_client_cert_pw_providers.lo ssl_server_trust_providers.lo stream.lo subst.lo svn_base64.lo svn_string.lo target.lo time.lo user.lo username_providers.lo utf.lo utf_validate.lo validate.lo version.lo win32_crashrpt.lo win32_crypto.lo win32_xlate.lo xml.lo
subversion/libsvn_subr/libsvn_subr-1.la: $(libsvn_subr_DEPS)
	cd subversion/libsvn_subr && $(LINK) -o libsvn_subr-1.la $(LT_NO_UNDEFINED) $(libsvn_subr_OBJECTS) $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(SVN_XML_LIBS) $(SVN_ZLIB_LIBS) $(SVN_APR_MEMCACHE_LIBS) $(SVN_SQLITE_LIBS) $(LIBS)

libsvn_swig_perl_PATH = subversion/bindings/swig/perl/libsvn_swig_perl
libsvn_swig_perl_DEPS =  subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.lo
libsvn_swig_perl_OBJECTS = swigutil_pl.lo
subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la: $(libsvn_swig_perl_DEPS)
	cd subversion/bindings/swig/perl/libsvn_swig_perl && $(LINK) -o libsvn_swig_perl-1.la $(LT_NO_UNDEFINED) $(libsvn_swig_perl_OBJECTS) -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

libsvn_swig_py_PATH = subversion/bindings/swig/python/libsvn_swig_py
libsvn_swig_py_DEPS =  subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.lo
libsvn_swig_py_OBJECTS = swigutil_py.lo
subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la: $(libsvn_swig_py_DEPS)
	cd subversion/bindings/swig/python/libsvn_swig_py && $(LINK) $(SWIG_PY_LIBS) -o libsvn_swig_py-1.la $(LT_NO_UNDEFINED) $(libsvn_swig_py_OBJECTS) -lsvn_client-1 -lsvn_wc-1 -lsvn_ra-1 -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

libsvn_swig_ruby_PATH = subversion/bindings/swig/ruby/libsvn_swig_ruby
libsvn_swig_ruby_DEPS =  subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.lo
libsvn_swig_ruby_OBJECTS = swigutil_rb.lo
subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la: $(libsvn_swig_ruby_DEPS)
	cd subversion/bindings/swig/ruby/libsvn_swig_ruby && $(LINK) $(SWIG_RB_LIBS) -o libsvn_swig_ruby-1.la $(LT_NO_UNDEFINED) $(libsvn_swig_ruby_OBJECTS) -lsvn_client-1 -lsvn_wc-1 -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

libsvn_test_PATH = subversion/tests
libsvn_test_DEPS =  subversion/tests/svn_test_editor.lo subversion/tests/svn_test_fs.lo subversion/tests/svn_test_main.lo
libsvn_test_OBJECTS = svn_test_editor.lo svn_test_fs.lo svn_test_main.lo
subversion/tests/libsvn_test-1.la: $(libsvn_test_DEPS)
	cd subversion/tests && $(LINK) -o libsvn_test-1.la  $(libsvn_test_OBJECTS) -lsvn_repos-1 -lsvn_fs-1 -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

libsvn_wc_PATH = subversion/libsvn_wc
libsvn_wc_DEPS =  subversion/libsvn_wc/adm_crawler.lo subversion/libsvn_wc/adm_files.lo subversion/libsvn_wc/adm_ops.lo subversion/libsvn_wc/ambient_depth_filter_editor.lo subversion/libsvn_wc/copy.lo subversion/libsvn_wc/crop.lo subversion/libsvn_wc/deprecated.lo subversion/libsvn_wc/diff.lo subversion/libsvn_wc/entries.lo subversion/libsvn_wc/lock.lo subversion/libsvn_wc/log.lo subversion/libsvn_wc/merge.lo subversion/libsvn_wc/props.lo subversion/libsvn_wc/questions.lo subversion/libsvn_wc/relocate.lo subversion/libsvn_wc/revision_status.lo subversion/libsvn_wc/status.lo subversion/libsvn_wc/translate.lo subversion/libsvn_wc/tree_conflicts.lo subversion/libsvn_wc/update_editor.lo subversion/libsvn_wc/util.lo subversion/libsvn_wc/wc_db.lo
libsvn_wc_OBJECTS = adm_crawler.lo adm_files.lo adm_ops.lo ambient_depth_filter_editor.lo copy.lo crop.lo deprecated.lo diff.lo entries.lo lock.lo log.lo merge.lo props.lo questions.lo relocate.lo revision_status.lo status.lo translate.lo tree_conflicts.lo update_editor.lo util.lo wc_db.lo
subversion/libsvn_wc/libsvn_wc-1.la: $(libsvn_wc_DEPS)
	cd subversion/libsvn_wc && $(LINK) -o libsvn_wc-1.la $(LT_NO_UNDEFINED) $(libsvn_wc_OBJECTS) -lsvn_delta-1 -lsvn_diff-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

libsvnjavahl_PATH = subversion/bindings/javahl/native
libsvnjavahl_DEPS = $(javahl_javah_DEPS) $(javahl_java_DEPS) subversion/bindings/javahl/native/BlameCallback.lo subversion/bindings/javahl/native/ChangelistCallback.lo subversion/bindings/javahl/native/CommitMessage.lo subversion/bindings/javahl/native/ConflictResolverCallback.lo subversion/bindings/javahl/native/CopySources.lo subversion/bindings/javahl/native/CreateJ.lo subversion/bindings/javahl/native/DiffSummaryReceiver.lo subversion/bindings/javahl/native/EnumMapper.lo subversion/bindings/javahl/native/InfoCallback.lo subversion/bindings/javahl/native/Inputer.lo subversion/bindings/javahl/native/JNIByteArray.lo subversion/bindings/javahl/native/JNICriticalSection.lo subversion/bindings/javahl/native/JNIMutex.lo subversion/bindings/javahl/native/JNIStackElement.lo subversion/bindings/javahl/native/JNIStringHolder.lo subversion/bindings/javahl/native/JNIThreadData.lo subversion/bindings/javahl/native/JNIUtil.lo subversion/bindings/javahl/native/ListCallback.lo subversion/bindings/javahl/native/LogMessageCallback.lo subversion/bindings/javahl/native/MessageReceiver.lo subversion/bindings/javahl/native/Notify.lo subversion/bindings/javahl/native/Notify2.lo subversion/bindings/javahl/native/Outputer.lo subversion/bindings/javahl/native/Path.lo subversion/bindings/javahl/native/Pool.lo subversion/bindings/javahl/native/ProgressListener.lo subversion/bindings/javahl/native/Prompter.lo subversion/bindings/javahl/native/ProplistCallback.lo subversion/bindings/javahl/native/Revision.lo subversion/bindings/javahl/native/RevisionRange.lo subversion/bindings/javahl/native/RevpropTable.lo subversion/bindings/javahl/native/SVNAdmin.lo subversion/bindings/javahl/native/SVNBase.lo subversion/bindings/javahl/native/SVNClient.lo subversion/bindings/javahl/native/StatusCallback.lo subversion/bindings/javahl/native/StringArray.lo subversion/bindings/javahl/native/Targets.lo subversion/bindings/javahl/native/libsvnjavahl.la.lo subversion/bindings/javahl/native/org_tigris_subversion_javahl_NativeResources.lo subversion/bindings/javahl/native/org_tigris_subversion_javahl_Path.lo subversion/bindings/javahl/native/org_tigris_subversion_javahl_SVNAdmin.lo subversion/bindings/javahl/native/org_tigris_subversion_javahl_SVNClient.lo subversion/bindings/javahl/native/org_tigris_subversion_javahl_Version.lo
libsvnjavahl_OBJECTS = BlameCallback.lo ChangelistCallback.lo CommitMessage.lo ConflictResolverCallback.lo CopySources.lo CreateJ.lo DiffSummaryReceiver.lo EnumMapper.lo InfoCallback.lo Inputer.lo JNIByteArray.lo JNICriticalSection.lo JNIMutex.lo JNIStackElement.lo JNIStringHolder.lo JNIThreadData.lo JNIUtil.lo ListCallback.lo LogMessageCallback.lo MessageReceiver.lo Notify.lo Notify2.lo Outputer.lo Path.lo Pool.lo ProgressListener.lo Prompter.lo ProplistCallback.lo Revision.lo RevisionRange.lo RevpropTable.lo SVNAdmin.lo SVNBase.lo SVNClient.lo StatusCallback.lo StringArray.lo Targets.lo libsvnjavahl.la.lo org_tigris_subversion_javahl_NativeResources.lo org_tigris_subversion_javahl_Path.lo org_tigris_subversion_javahl_SVNAdmin.lo org_tigris_subversion_javahl_SVNClient.lo org_tigris_subversion_javahl_Version.lo
subversion/bindings/javahl/native/libsvnjavahl-1.la: $(libsvnjavahl_DEPS)
	cd subversion/bindings/javahl/native && $(LINK_JAVAHL_CXX) -o libsvnjavahl-1.la $(LT_NO_UNDEFINED) $(libsvnjavahl_OBJECTS) -lsvn_repos-1 -lsvn_client-1 -lsvn_wc-1 -lsvn_ra-1 -lsvn_delta-1 -lsvn_diff-1 -lsvn_subr-1 -lsvn_fs-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(NEON_LIBS) $(LIBS)

locale_PATH = subversion/po
locale_DEPS =  subversion/po/de.mo subversion/po/es.mo subversion/po/fr.mo subversion/po/it.mo subversion/po/ja.mo subversion/po/ko.mo subversion/po/nb.mo subversion/po/pl.mo subversion/po/pt_BR.mo subversion/po/sv.mo subversion/po/zh_CN.mo subversion/po/zh_TW.mo
locale: $(locale_DEPS)

locks_test_PATH = subversion/tests/libsvn_fs
locks_test_DEPS =  subversion/tests/libsvn_fs/locks-test.o subversion/tests/libsvn_test-1.la
locks_test_OBJECTS = locks-test.o
subversion/tests/libsvn_fs/locks-test$(EXEEXT): $(locks_test_DEPS)
	cd subversion/tests/libsvn_fs && $(LINK) -o locks-test$(EXEEXT)  $(locks_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_fs-1 -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

mergeinfo_test_PATH = subversion/tests/libsvn_subr
mergeinfo_test_DEPS =  subversion/tests/libsvn_subr/mergeinfo-test.o subversion/tests/libsvn_test-1.la
mergeinfo_test_OBJECTS = mergeinfo-test.o
subversion/tests/libsvn_subr/mergeinfo-test$(EXEEXT): $(mergeinfo_test_DEPS)
	cd subversion/tests/libsvn_subr && $(LINK) -o mergeinfo-test$(EXEEXT)  $(mergeinfo_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

mod_authz_svn_PATH = subversion/mod_authz_svn
mod_authz_svn_DEPS =  subversion/mod_authz_svn/mod_authz_svn.lo subversion/mod_dav_svn/mod_dav_svn.la
mod_authz_svn_OBJECTS = mod_authz_svn.lo
subversion/mod_authz_svn/mod_authz_svn.la: $(mod_authz_svn_DEPS)
	cd subversion/mod_authz_svn && $(LINK_APACHE_MOD) -o mod_authz_svn.la $(LT_NO_UNDEFINED) $(mod_authz_svn_OBJECTS) -lsvn_repos-1 -lsvn_subr-1 $(LIBS)

mod_dav_svn_PATH = subversion/mod_dav_svn
mod_dav_svn_DEPS =  subversion/mod_dav_svn/activity.lo subversion/mod_dav_svn/authz.lo subversion/mod_dav_svn/deadprops.lo subversion/mod_dav_svn/liveprops.lo subversion/mod_dav_svn/lock.lo subversion/mod_dav_svn/merge.lo subversion/mod_dav_svn/mirror.lo subversion/mod_dav_svn/mod_dav_svn.lo subversion/mod_dav_svn/reports/dated-rev.lo subversion/mod_dav_svn/reports/deleted-rev.lo subversion/mod_dav_svn/reports/file-revs.lo subversion/mod_dav_svn/reports/get-location-segments.lo subversion/mod_dav_svn/reports/get-locations.lo subversion/mod_dav_svn/reports/get-locks.lo subversion/mod_dav_svn/reports/log.lo subversion/mod_dav_svn/reports/mergeinfo.lo subversion/mod_dav_svn/reports/replay.lo subversion/mod_dav_svn/reports/update.lo subversion/mod_dav_svn/repos.lo subversion/mod_dav_svn/util.lo subversion/mod_dav_svn/version.lo
mod_dav_svn_OBJECTS = activity.lo authz.lo deadprops.lo liveprops.lo lock.lo merge.lo mirror.lo mod_dav_svn.lo reports/dated-rev.lo reports/deleted-rev.lo reports/file-revs.lo reports/get-location-segments.lo reports/get-locations.lo reports/get-locks.lo reports/log.lo reports/mergeinfo.lo reports/replay.lo reports/update.lo repos.lo util.lo version.lo
subversion/mod_dav_svn/mod_dav_svn.la: $(mod_dav_svn_DEPS)
	cd subversion/mod_dav_svn && $(LINK_APACHE_MOD) -o mod_dav_svn.la $(LT_NO_UNDEFINED) $(mod_dav_svn_OBJECTS) -lsvn_repos-1 -lsvn_fs-1 -lsvn_delta-1 -lsvn_subr-1 $(LIBS)

opt_test_PATH = subversion/tests/libsvn_subr
opt_test_DEPS =  subversion/tests/libsvn_subr/opt-test.o subversion/tests/libsvn_test-1.la
opt_test_OBJECTS = opt-test.o
subversion/tests/libsvn_subr/opt-test$(EXEEXT): $(opt_test_DEPS)
	cd subversion/tests/libsvn_subr && $(LINK) -o opt-test$(EXEEXT)  $(opt_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

path_test_PATH = subversion/tests/libsvn_subr
path_test_DEPS =  subversion/tests/libsvn_subr/path-test.o subversion/tests/libsvn_test-1.la
path_test_OBJECTS = path-test.o
subversion/tests/libsvn_subr/path-test$(EXEEXT): $(path_test_DEPS)
	cd subversion/tests/libsvn_subr && $(LINK) -o path-test$(EXEEXT)  $(path_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

perl_client_PATH = subversion/bindings/swig/perl/native
perl_client_DEPS =  subversion/bindings/swig/perl/native/svn_client.lo subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la subversion/bindings/swig/perl/native/_Core.la
perl_client_OBJECTS = svn_client.lo
subversion/bindings/swig/perl/native/_Client.la: $(perl_client_DEPS)
	cd subversion/bindings/swig/perl/native && $(LINK_PL_WRAPPER) -o _Client.la $(LT_NO_UNDEFINED) $(perl_client_OBJECTS) ../../../../../subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la -lsvn_client-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

perl_core_PATH = subversion/bindings/swig/perl/native
perl_core_DEPS =  subversion/bindings/swig/perl/native/core.lo subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la
perl_core_OBJECTS = core.lo
subversion/bindings/swig/perl/native/_Core.la: $(perl_core_DEPS)
	cd subversion/bindings/swig/perl/native && $(LINK_PL_WRAPPER) -o _Core.la $(LT_NO_UNDEFINED) $(perl_core_OBJECTS) ../../../../../subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la -lsvn_diff-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

perl_delta_PATH = subversion/bindings/swig/perl/native
perl_delta_DEPS =  subversion/bindings/swig/perl/native/svn_delta.lo subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la subversion/bindings/swig/perl/native/_Core.la
perl_delta_OBJECTS = svn_delta.lo
subversion/bindings/swig/perl/native/_Delta.la: $(perl_delta_DEPS)
	cd subversion/bindings/swig/perl/native && $(LINK_PL_WRAPPER) -o _Delta.la $(LT_NO_UNDEFINED) $(perl_delta_OBJECTS) ../../../../../subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la -lsvn_delta-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

perl_diff_PATH = subversion/bindings/swig/perl/native
perl_diff_DEPS =  subversion/bindings/swig/perl/native/svn_diff.lo subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la subversion/bindings/swig/perl/native/_Core.la
perl_diff_OBJECTS = svn_diff.lo
subversion/bindings/swig/perl/native/_Diff.la: $(perl_diff_DEPS)
	cd subversion/bindings/swig/perl/native && $(LINK_PL_WRAPPER) -o _Diff.la $(LT_NO_UNDEFINED) $(perl_diff_OBJECTS) ../../../../../subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la -lsvn_diff-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

perl_fs_PATH = subversion/bindings/swig/perl/native
perl_fs_DEPS =  subversion/bindings/swig/perl/native/svn_fs.lo subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la subversion/bindings/swig/perl/native/_Core.la
perl_fs_OBJECTS = svn_fs.lo
subversion/bindings/swig/perl/native/_Fs.la: $(perl_fs_DEPS)
	cd subversion/bindings/swig/perl/native && $(LINK_PL_WRAPPER) -o _Fs.la $(LT_NO_UNDEFINED) $(perl_fs_OBJECTS) ../../../../../subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la -lsvn_fs-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

perl_ra_PATH = subversion/bindings/swig/perl/native
perl_ra_DEPS =  subversion/bindings/swig/perl/native/svn_ra.lo subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la subversion/bindings/swig/perl/native/_Core.la
perl_ra_OBJECTS = svn_ra.lo
subversion/bindings/swig/perl/native/_Ra.la: $(perl_ra_DEPS)
	cd subversion/bindings/swig/perl/native && $(LINK_PL_WRAPPER) -o _Ra.la $(LT_NO_UNDEFINED) $(perl_ra_OBJECTS) ../../../../../subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la -lsvn_ra-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

perl_repos_PATH = subversion/bindings/swig/perl/native
perl_repos_DEPS =  subversion/bindings/swig/perl/native/svn_repos.lo subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la subversion/bindings/swig/perl/native/_Core.la
perl_repos_OBJECTS = svn_repos.lo
subversion/bindings/swig/perl/native/_Repos.la: $(perl_repos_DEPS)
	cd subversion/bindings/swig/perl/native && $(LINK_PL_WRAPPER) -o _Repos.la $(LT_NO_UNDEFINED) $(perl_repos_OBJECTS) ../../../../../subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la -lsvn_repos-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

perl_wc_PATH = subversion/bindings/swig/perl/native
perl_wc_DEPS =  subversion/bindings/swig/perl/native/svn_wc.lo subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la subversion/bindings/swig/perl/native/_Core.la
perl_wc_OBJECTS = svn_wc.lo
subversion/bindings/swig/perl/native/_Wc.la: $(perl_wc_DEPS)
	cd subversion/bindings/swig/perl/native && $(LINK_PL_WRAPPER) -o _Wc.la $(LT_NO_UNDEFINED) $(perl_wc_OBJECTS) ../../../../../subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la -lsvn_wc-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

python_client_PATH = subversion/bindings/swig/python
python_client_DEPS =  subversion/bindings/swig/python/svn_client.lo subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la subversion/bindings/swig/python/_core.la
python_client_OBJECTS = svn_client.lo
subversion/bindings/swig/python/_client.la: $(python_client_DEPS)
	cd subversion/bindings/swig/python && $(LINK_PY_WRAPPER) -o _client.la $(LT_NO_UNDEFINED) $(python_client_OBJECTS) ../../../../subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la -lsvn_client-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

python_core_PATH = subversion/bindings/swig/python
python_core_DEPS =  subversion/bindings/swig/python/core.lo subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la
python_core_OBJECTS = core.lo
subversion/bindings/swig/python/_core.la: $(python_core_DEPS)
	cd subversion/bindings/swig/python && $(LINK_PY_WRAPPER) -o _core.la $(LT_NO_UNDEFINED) $(python_core_OBJECTS) ../../../../subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la -lsvn_diff-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

python_delta_PATH = subversion/bindings/swig/python
python_delta_DEPS =  subversion/bindings/swig/python/svn_delta.lo subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la subversion/bindings/swig/python/_core.la
python_delta_OBJECTS = svn_delta.lo
subversion/bindings/swig/python/_delta.la: $(python_delta_DEPS)
	cd subversion/bindings/swig/python && $(LINK_PY_WRAPPER) -o _delta.la $(LT_NO_UNDEFINED) $(python_delta_OBJECTS) ../../../../subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la -lsvn_delta-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

python_diff_PATH = subversion/bindings/swig/python
python_diff_DEPS =  subversion/bindings/swig/python/svn_diff.lo subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la subversion/bindings/swig/python/_core.la
python_diff_OBJECTS = svn_diff.lo
subversion/bindings/swig/python/_diff.la: $(python_diff_DEPS)
	cd subversion/bindings/swig/python && $(LINK_PY_WRAPPER) -o _diff.la $(LT_NO_UNDEFINED) $(python_diff_OBJECTS) ../../../../subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la -lsvn_diff-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

python_fs_PATH = subversion/bindings/swig/python
python_fs_DEPS =  subversion/bindings/swig/python/svn_fs.lo subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la subversion/bindings/swig/python/_core.la
python_fs_OBJECTS = svn_fs.lo
subversion/bindings/swig/python/_fs.la: $(python_fs_DEPS)
	cd subversion/bindings/swig/python && $(LINK_PY_WRAPPER) -o _fs.la $(LT_NO_UNDEFINED) $(python_fs_OBJECTS) ../../../../subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la -lsvn_fs-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

python_ra_PATH = subversion/bindings/swig/python
python_ra_DEPS =  subversion/bindings/swig/python/svn_ra.lo subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la subversion/bindings/swig/python/_core.la
python_ra_OBJECTS = svn_ra.lo
subversion/bindings/swig/python/_ra.la: $(python_ra_DEPS)
	cd subversion/bindings/swig/python && $(LINK_PY_WRAPPER) -o _ra.la $(LT_NO_UNDEFINED) $(python_ra_OBJECTS) ../../../../subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la -lsvn_ra-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

python_repos_PATH = subversion/bindings/swig/python
python_repos_DEPS =  subversion/bindings/swig/python/svn_repos.lo subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la subversion/bindings/swig/python/_core.la
python_repos_OBJECTS = svn_repos.lo
subversion/bindings/swig/python/_repos.la: $(python_repos_DEPS)
	cd subversion/bindings/swig/python && $(LINK_PY_WRAPPER) -o _repos.la $(LT_NO_UNDEFINED) $(python_repos_OBJECTS) ../../../../subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la -lsvn_repos-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

python_wc_PATH = subversion/bindings/swig/python
python_wc_DEPS =  subversion/bindings/swig/python/svn_wc.lo subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la subversion/bindings/swig/python/_core.la
python_wc_OBJECTS = svn_wc.lo
subversion/bindings/swig/python/_wc.la: $(python_wc_DEPS)
	cd subversion/bindings/swig/python && $(LINK_PY_WRAPPER) -o _wc.la $(LT_NO_UNDEFINED) $(python_wc_OBJECTS) ../../../../subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la -lsvn_wc-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

ra_local_test_PATH = subversion/tests/libsvn_ra_local
ra_local_test_DEPS =  subversion/tests/libsvn_ra_local/ra-local-test.o subversion/tests/libsvn_test-1.la subversion/libsvn_ra_local/libsvn_ra_local-1.la
ra_local_test_OBJECTS = ra-local-test.o
subversion/tests/libsvn_ra_local/ra-local-test$(EXEEXT): $(ra_local_test_DEPS)
	cd subversion/tests/libsvn_ra_local && $(LINK) -o ra-local-test$(EXEEXT)  $(ra_local_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la ../../../subversion/libsvn_ra_local/libsvn_ra_local-1.la -lsvn_ra-1 -lsvn_fs-1 -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(NEON_LIBS) $(LIBS)

random_test_PATH = subversion/tests/libsvn_delta
random_test_DEPS =  subversion/tests/libsvn_delta/random-test.o subversion/tests/libsvn_test-1.la
random_test_OBJECTS = random-test.o
subversion/tests/libsvn_delta/random-test$(EXEEXT): $(random_test_DEPS)
	cd subversion/tests/libsvn_delta && $(LINK) -o random-test$(EXEEXT)  $(random_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

repos_test_PATH = subversion/tests/libsvn_repos
repos_test_DEPS =  subversion/tests/libsvn_repos/dir-delta-editor.o subversion/tests/libsvn_repos/repos-test.o subversion/tests/libsvn_test-1.la
repos_test_OBJECTS = dir-delta-editor.o repos-test.o
subversion/tests/libsvn_repos/repos-test$(EXEEXT): $(repos_test_DEPS)
	cd subversion/tests/libsvn_repos && $(LINK) -o repos-test$(EXEEXT)  $(repos_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_repos-1 -lsvn_fs-1 -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

revision_test_PATH = subversion/tests/libsvn_subr
revision_test_DEPS =  subversion/tests/libsvn_subr/revision-test.o subversion/tests/libsvn_test-1.la
revision_test_OBJECTS = revision-test.o
subversion/tests/libsvn_subr/revision-test$(EXEEXT): $(revision_test_DEPS)
	cd subversion/tests/libsvn_subr && $(LINK) -o revision-test$(EXEEXT)  $(revision_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

ruby_client_PATH = subversion/bindings/swig/ruby
ruby_client_DEPS =  subversion/bindings/swig/ruby/svn_client.lo subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la subversion/bindings/swig/ruby/core.la
ruby_client_OBJECTS = svn_client.lo
subversion/bindings/swig/ruby/client.la: $(ruby_client_DEPS)
	cd subversion/bindings/swig/ruby && $(LINK_RB_WRAPPER) -o client.la $(LT_NO_UNDEFINED) $(ruby_client_OBJECTS) ../../../../subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la -lsvn_client-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

ruby_core_PATH = subversion/bindings/swig/ruby
ruby_core_DEPS =  subversion/bindings/swig/ruby/core.lo subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la
ruby_core_OBJECTS = core.lo
subversion/bindings/swig/ruby/core.la: $(ruby_core_DEPS)
	cd subversion/bindings/swig/ruby && $(LINK_RB_WRAPPER) -o core.la $(LT_NO_UNDEFINED) $(ruby_core_OBJECTS) ../../../../subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la -lsvn_diff-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

ruby_delta_PATH = subversion/bindings/swig/ruby
ruby_delta_DEPS =  subversion/bindings/swig/ruby/svn_delta.lo subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la subversion/bindings/swig/ruby/core.la
ruby_delta_OBJECTS = svn_delta.lo
subversion/bindings/swig/ruby/delta.la: $(ruby_delta_DEPS)
	cd subversion/bindings/swig/ruby && $(LINK_RB_WRAPPER) -o delta.la $(LT_NO_UNDEFINED) $(ruby_delta_OBJECTS) ../../../../subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la -lsvn_delta-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

ruby_diff_PATH = subversion/bindings/swig/ruby
ruby_diff_DEPS =  subversion/bindings/swig/ruby/svn_diff.lo subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la subversion/bindings/swig/ruby/core.la
ruby_diff_OBJECTS = svn_diff.lo
subversion/bindings/swig/ruby/diff.la: $(ruby_diff_DEPS)
	cd subversion/bindings/swig/ruby && $(LINK_RB_WRAPPER) -o diff.la $(LT_NO_UNDEFINED) $(ruby_diff_OBJECTS) ../../../../subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la -lsvn_diff-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

ruby_fs_PATH = subversion/bindings/swig/ruby
ruby_fs_DEPS =  subversion/bindings/swig/ruby/svn_fs.lo subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la subversion/bindings/swig/ruby/core.la
ruby_fs_OBJECTS = svn_fs.lo
subversion/bindings/swig/ruby/fs.la: $(ruby_fs_DEPS)
	cd subversion/bindings/swig/ruby && $(LINK_RB_WRAPPER) -o fs.la $(LT_NO_UNDEFINED) $(ruby_fs_OBJECTS) ../../../../subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la -lsvn_fs-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

ruby_ra_PATH = subversion/bindings/swig/ruby
ruby_ra_DEPS =  subversion/bindings/swig/ruby/svn_ra.lo subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la subversion/bindings/swig/ruby/core.la
ruby_ra_OBJECTS = svn_ra.lo
subversion/bindings/swig/ruby/ra.la: $(ruby_ra_DEPS)
	cd subversion/bindings/swig/ruby && $(LINK_RB_WRAPPER) -o ra.la $(LT_NO_UNDEFINED) $(ruby_ra_OBJECTS) ../../../../subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la -lsvn_ra-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

ruby_repos_PATH = subversion/bindings/swig/ruby
ruby_repos_DEPS =  subversion/bindings/swig/ruby/svn_repos.lo subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la subversion/bindings/swig/ruby/core.la
ruby_repos_OBJECTS = svn_repos.lo
subversion/bindings/swig/ruby/repos.la: $(ruby_repos_DEPS)
	cd subversion/bindings/swig/ruby && $(LINK_RB_WRAPPER) -o repos.la $(LT_NO_UNDEFINED) $(ruby_repos_OBJECTS) ../../../../subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la -lsvn_repos-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

ruby_wc_PATH = subversion/bindings/swig/ruby
ruby_wc_DEPS =  subversion/bindings/swig/ruby/svn_wc.lo subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la subversion/bindings/swig/ruby/core.la
ruby_wc_OBJECTS = svn_wc.lo
subversion/bindings/swig/ruby/wc.la: $(ruby_wc_DEPS)
	cd subversion/bindings/swig/ruby && $(LINK_RB_WRAPPER) -o wc.la $(LT_NO_UNDEFINED) $(ruby_wc_OBJECTS) ../../../../subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la -lsvn_wc-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

skel_test_PATH = subversion/tests/libsvn_subr
skel_test_DEPS =  subversion/tests/libsvn_subr/skel-test.o subversion/tests/libsvn_test-1.la
skel_test_OBJECTS = skel-test.o
subversion/tests/libsvn_subr/skel-test$(EXEEXT): $(skel_test_DEPS)
	cd subversion/tests/libsvn_subr && $(LINK) -o skel-test$(EXEEXT)  $(skel_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

stream_test_PATH = subversion/tests/libsvn_subr
stream_test_DEPS =  subversion/tests/libsvn_subr/stream-test.o subversion/tests/libsvn_test-1.la
stream_test_OBJECTS = stream-test.o
subversion/tests/libsvn_subr/stream-test$(EXEEXT): $(stream_test_DEPS)
	cd subversion/tests/libsvn_subr && $(LINK) -o stream-test$(EXEEXT)  $(stream_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

string_test_PATH = subversion/tests/libsvn_subr
string_test_DEPS =  subversion/tests/libsvn_subr/string-test.o subversion/tests/libsvn_test-1.la
string_test_OBJECTS = string-test.o
subversion/tests/libsvn_subr/string-test$(EXEEXT): $(string_test_DEPS)
	cd subversion/tests/libsvn_subr && $(LINK) -o string-test$(EXEEXT)  $(string_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

strings_reps_test_PATH = subversion/tests/libsvn_fs_base
strings_reps_test_DEPS =  subversion/tests/libsvn_fs_base/strings-reps-test.o subversion/tests/libsvn_test-1.la subversion/libsvn_fs_base/libsvn_fs_base-1.la
strings_reps_test_OBJECTS = strings-reps-test.o
subversion/tests/libsvn_fs_base/strings-reps-test$(EXEEXT): $(strings_reps_test_DEPS)
	cd subversion/tests/libsvn_fs_base && $(LINK) -o strings-reps-test$(EXEEXT)  $(strings_reps_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_fs-1 ../../../subversion/libsvn_fs_base/libsvn_fs_base-1.la -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

svn_PATH = subversion/svn
svn_DEPS =  subversion/svn/add-cmd.o subversion/svn/blame-cmd.o subversion/svn/cat-cmd.o subversion/svn/changelist-cmd.o subversion/svn/checkout-cmd.o subversion/svn/cleanup-cmd.o subversion/svn/commit-cmd.o subversion/svn/conflict-callbacks.o subversion/svn/copy-cmd.o subversion/svn/delete-cmd.o subversion/svn/diff-cmd.o subversion/svn/export-cmd.o subversion/svn/help-cmd.o subversion/svn/import-cmd.o subversion/svn/info-cmd.o subversion/svn/list-cmd.o subversion/svn/lock-cmd.o subversion/svn/log-cmd.o subversion/svn/main.o subversion/svn/merge-cmd.o subversion/svn/mergeinfo-cmd.o subversion/svn/mkdir-cmd.o subversion/svn/move-cmd.o subversion/svn/notify.o subversion/svn/propdel-cmd.o subversion/svn/propedit-cmd.o subversion/svn/propget-cmd.o subversion/svn/proplist-cmd.o subversion/svn/props.o subversion/svn/propset-cmd.o subversion/svn/resolve-cmd.o subversion/svn/resolved-cmd.o subversion/svn/revert-cmd.o subversion/svn/status-cmd.o subversion/svn/status.o subversion/svn/switch-cmd.o subversion/svn/tree-conflicts.o subversion/svn/unlock-cmd.o subversion/svn/update-cmd.o subversion/svn/util.o
svn_OBJECTS = add-cmd.o blame-cmd.o cat-cmd.o changelist-cmd.o checkout-cmd.o cleanup-cmd.o commit-cmd.o conflict-callbacks.o copy-cmd.o delete-cmd.o diff-cmd.o export-cmd.o help-cmd.o import-cmd.o info-cmd.o list-cmd.o lock-cmd.o log-cmd.o main.o merge-cmd.o mergeinfo-cmd.o mkdir-cmd.o move-cmd.o notify.o propdel-cmd.o propedit-cmd.o propget-cmd.o proplist-cmd.o props.o propset-cmd.o resolve-cmd.o resolved-cmd.o revert-cmd.o status-cmd.o status.o switch-cmd.o tree-conflicts.o unlock-cmd.o update-cmd.o util.o
subversion/svn/svn$(EXEEXT): $(svn_DEPS)
	cd subversion/svn && $(LINK) -o svn$(EXEEXT)  $(svn_OBJECTS) -lsvn_client-1 -lsvn_wc-1 -lsvn_ra-1 -lsvn_delta-1 -lsvn_diff-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(NEON_LIBS) $(LIBS)

svn_populate_node_origins_index_PATH = tools/server-side
svn_populate_node_origins_index_DEPS =  tools/server-side/svn-populate-node-origins-index.o
svn_populate_node_origins_index_OBJECTS = svn-populate-node-origins-index.o
tools/server-side/svn-populate-node-origins-index$(EXEEXT): $(svn_populate_node_origins_index_DEPS)
	cd tools/server-side && $(LINK) -o svn-populate-node-origins-index$(EXEEXT)  $(svn_populate_node_origins_index_OBJECTS) -lsvn_repos-1 -lsvn_fs-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

svn_push_PATH = contrib/client-side/svn-push
svn_push_DEPS =  contrib/client-side/svn-push/svn-push.o
svn_push_OBJECTS = svn-push.o
contrib/client-side/svn-push/svn-push$(EXEEXT): $(svn_push_DEPS)
	cd contrib/client-side/svn-push && $(LINK) -o svn-push$(EXEEXT)  $(svn_push_OBJECTS) -lsvn_ra-1 -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(NEON_LIBS) $(LIBS)

svnadmin_PATH = subversion/svnadmin
svnadmin_DEPS =  subversion/svnadmin/main.o
svnadmin_OBJECTS = main.o
subversion/svnadmin/svnadmin$(EXEEXT): $(svnadmin_DEPS)
	cd subversion/svnadmin && $(LINK) -o svnadmin$(EXEEXT)  $(svnadmin_OBJECTS) -lsvn_repos-1 -lsvn_fs-1 -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

svnauthz_validate_PATH = tools/server-side
svnauthz_validate_DEPS =  tools/server-side/svnauthz-validate.o
svnauthz_validate_OBJECTS = svnauthz-validate.o
tools/server-side/svnauthz-validate$(EXEEXT): $(svnauthz_validate_DEPS)
	cd tools/server-side && $(LINK) -o svnauthz-validate$(EXEEXT)  $(svnauthz_validate_OBJECTS) -lsvn_repos-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(LIBS)

svndiff_test_PATH = subversion/tests/libsvn_delta
svndiff_test_DEPS =  subversion/tests/libsvn_delta/svndiff-test.o
svndiff_test_OBJECTS = svndiff-test.o
subversion/tests/libsvn_delta/svndiff-test$(EXEEXT): $(svndiff_test_DEPS)
	cd subversion/tests/libsvn_delta && $(LINK) -o svndiff-test$(EXEEXT)  $(svndiff_test_OBJECTS) -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

svndumpfilter_PATH = subversion/svndumpfilter
svndumpfilter_DEPS =  subversion/svndumpfilter/main.o
svndumpfilter_OBJECTS = main.o
subversion/svndumpfilter/svndumpfilter$(EXEEXT): $(svndumpfilter_DEPS)
	cd subversion/svndumpfilter && $(LINK) -o svndumpfilter$(EXEEXT)  $(svndumpfilter_OBJECTS) -lsvn_repos-1 -lsvn_fs-1 -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

svnlook_PATH = subversion/svnlook
svnlook_DEPS =  subversion/svnlook/main.o
svnlook_OBJECTS = main.o
subversion/svnlook/svnlook$(EXEEXT): $(svnlook_DEPS)
	cd subversion/svnlook && $(LINK) -o svnlook$(EXEEXT)  $(svnlook_OBJECTS) -lsvn_repos-1 -lsvn_fs-1 -lsvn_delta-1 -lsvn_diff-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

svnmucc_PATH = tools/client-side/svnmucc
svnmucc_DEPS =  tools/client-side/svnmucc/svnmucc.o
svnmucc_OBJECTS = svnmucc.o
tools/client-side/svnmucc/svnmucc$(EXEEXT): $(svnmucc_DEPS)
	cd tools/client-side/svnmucc && $(LINK) -o svnmucc$(EXEEXT)  $(svnmucc_OBJECTS) -lsvn_client-1 -lsvn_ra-1 -lsvn_subr-1 -lsvn_delta-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(NEON_LIBS) $(LIBS)

svnserve_PATH = subversion/svnserve
svnserve_DEPS =  subversion/svnserve/cyrus_auth.o subversion/svnserve/log-escape.o subversion/svnserve/main.o subversion/svnserve/serve.o subversion/svnserve/winservice.o subversion/libsvn_ra_svn/libsvn_ra_svn-1.la
svnserve_OBJECTS = cyrus_auth.o log-escape.o main.o serve.o winservice.o
subversion/svnserve/svnserve$(EXEEXT): $(svnserve_DEPS)
	cd subversion/svnserve && $(LINK) -o svnserve$(EXEEXT)  $(svnserve_OBJECTS) -lsvn_repos-1 -lsvn_fs-1 -lsvn_delta-1 -lsvn_subr-1 ../../subversion/libsvn_ra_svn/libsvn_ra_svn-1.la $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(SVN_SASL_LIBS) $(LIBS)

svnsync_PATH = subversion/svnsync
svnsync_DEPS =  subversion/svnsync/main.o
svnsync_OBJECTS = main.o
subversion/svnsync/svnsync$(EXEEXT): $(svnsync_DEPS)
	cd subversion/svnsync && $(LINK) -o svnsync$(EXEEXT)  $(svnsync_OBJECTS) -lsvn_ra-1 -lsvn_delta-1 -lsvn_subr-1 $(SVN_APR_LIBS) $(NEON_LIBS) $(LIBS)

svnversion_PATH = subversion/svnversion
svnversion_DEPS =  subversion/svnversion/main.o
svnversion_OBJECTS = main.o
subversion/svnversion/svnversion$(EXEEXT): $(svnversion_DEPS)
	cd subversion/svnversion && $(LINK) -o svnversion$(EXEEXT)  $(svnversion_OBJECTS) -lsvn_wc-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

target_test_PATH = subversion/tests/libsvn_subr
target_test_DEPS =  subversion/tests/libsvn_subr/target-test.o subversion/tests/libsvn_test-1.la
target_test_OBJECTS = target-test.o
subversion/tests/libsvn_subr/target-test$(EXEEXT): $(target_test_DEPS)
	cd subversion/tests/libsvn_subr && $(LINK) -o target-test$(EXEEXT)  $(target_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

time_test_PATH = subversion/tests/libsvn_subr
time_test_DEPS =  subversion/tests/libsvn_subr/time-test.o subversion/tests/libsvn_test-1.la
time_test_OBJECTS = time-test.o
subversion/tests/libsvn_subr/time-test$(EXEEXT): $(time_test_DEPS)
	cd subversion/tests/libsvn_subr && $(LINK) -o time-test$(EXEEXT)  $(time_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

translate_test_PATH = subversion/tests/libsvn_subr
translate_test_DEPS =  subversion/tests/libsvn_subr/translate-test.o subversion/tests/libsvn_test-1.la
translate_test_OBJECTS = translate-test.o
subversion/tests/libsvn_subr/translate-test$(EXEEXT): $(translate_test_DEPS)
	cd subversion/tests/libsvn_subr && $(LINK) -o translate-test$(EXEEXT)  $(translate_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

tree_conflict_data_test_PATH = subversion/tests/libsvn_wc
tree_conflict_data_test_DEPS =  subversion/tests/libsvn_wc/tree-conflict-data-test.o subversion/tests/libsvn_test-1.la
tree_conflict_data_test_OBJECTS = tree-conflict-data-test.o
subversion/tests/libsvn_wc/tree-conflict-data-test$(EXEEXT): $(tree_conflict_data_test_DEPS)
	cd subversion/tests/libsvn_wc && $(LINK) -o tree-conflict-data-test$(EXEEXT)  $(tree_conflict_data_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_wc-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

utf_test_PATH = subversion/tests/libsvn_subr
utf_test_DEPS =  subversion/tests/libsvn_subr/utf-test.o subversion/tests/libsvn_test-1.la
utf_test_OBJECTS = utf-test.o
subversion/tests/libsvn_subr/utf-test$(EXEEXT): $(utf_test_DEPS)
	cd subversion/tests/libsvn_subr && $(LINK) -o utf-test$(EXEEXT)  $(utf_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

vdelta_test_PATH = subversion/tests/libsvn_delta
vdelta_test_DEPS =  subversion/tests/libsvn_delta/vdelta-test.o
vdelta_test_OBJECTS = vdelta-test.o
subversion/tests/libsvn_delta/vdelta-test$(EXEEXT): $(vdelta_test_DEPS)
	cd subversion/tests/libsvn_delta && $(LINK) -o vdelta-test$(EXEEXT)  $(vdelta_test_OBJECTS) -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)

window_test_PATH = subversion/tests/libsvn_delta
window_test_DEPS =  subversion/tests/libsvn_delta/window-test.o subversion/tests/libsvn_test-1.la
window_test_OBJECTS = window-test.o
subversion/tests/libsvn_delta/window-test$(EXEEXT): $(window_test_DEPS)
	cd subversion/tests/libsvn_delta && $(LINK) -o window-test$(EXEEXT)  $(window_test_OBJECTS) ../../../subversion/tests/libsvn_test-1.la -lsvn_delta-1 -lsvn_subr-1 $(SVN_APRUTIL_LIBS) $(SVN_APR_LIBS) $(LIBS)


########################################
# Section 6: Install-Group build targets
########################################

apache-mod: subversion/mod_authz_svn/mod_authz_svn.la subversion/mod_dav_svn/mod_dav_svn.la

bdb-lib: subversion/libsvn_fs_base/libsvn_fs_base-1.la

bdb-test: subversion/tests/libsvn_fs_base/changes-test$(EXEEXT) subversion/tests/libsvn_fs_base/fs-base-test$(EXEEXT) subversion/tests/libsvn_fs_base/key-test$(EXEEXT) subversion/tests/libsvn_fs_base/strings-reps-test$(EXEEXT)

bin: subversion/svn/svn$(EXEEXT) subversion/svnadmin/svnadmin$(EXEEXT) subversion/svndumpfilter/svndumpfilter$(EXEEXT) subversion/svnlook/svnlook$(EXEEXT) subversion/svnserve/svnserve$(EXEEXT) subversion/svnsync/svnsync$(EXEEXT) subversion/svnversion/svnversion$(EXEEXT)

contrib: contrib/client-side/svn-push/svn-push$(EXEEXT)

fsmod-lib: subversion/libsvn_delta/libsvn_delta-1.la subversion/libsvn_fs_fs/libsvn_fs_fs-1.la subversion/libsvn_fs_util/libsvn_fs_util-1.la subversion/libsvn_subr/libsvn_subr-1.la

gnome-keyring-lib: subversion/libsvn_auth_gnome_keyring/libsvn_auth_gnome_keyring-1.la

javahl-java: 

javahl-javah: 

javahl-lib: subversion/bindings/javahl/native/libsvnjavahl-1.la

javahl-tests: 

kwallet-lib: subversion/libsvn_auth_kwallet/libsvn_auth_kwallet-1.la

lib: subversion/libsvn_client/libsvn_client-1.la subversion/libsvn_diff/libsvn_diff-1.la subversion/libsvn_ra/libsvn_ra-1.la subversion/libsvn_wc/libsvn_wc-1.la

locale: 

neon-lib: subversion/libsvn_ra_neon/libsvn_ra_neon-1.la

ramod-lib: subversion/libsvn_fs/libsvn_fs-1.la subversion/libsvn_ra_local/libsvn_ra_local-1.la subversion/libsvn_ra_svn/libsvn_ra_svn-1.la subversion/libsvn_repos/libsvn_repos-1.la

serf-lib: subversion/libsvn_ra_serf/libsvn_ra_serf-1.la

swig-pl-lib: subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la

swig-py: subversion/bindings/swig/python/_client.la subversion/bindings/swig/python/_core.la subversion/bindings/swig/python/_delta.la subversion/bindings/swig/python/_diff.la subversion/bindings/swig/python/_fs.la subversion/bindings/swig/python/_ra.la subversion/bindings/swig/python/_repos.la subversion/bindings/swig/python/_wc.la

swig-py-lib: subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la

swig-rb: subversion/bindings/swig/ruby/client.la subversion/bindings/swig/ruby/core.la subversion/bindings/swig/ruby/delta.la subversion/bindings/swig/ruby/diff.la subversion/bindings/swig/ruby/fs.la subversion/bindings/swig/ruby/ra.la subversion/bindings/swig/ruby/repos.la subversion/bindings/swig/ruby/wc.la

swig-rb-lib: subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la

test: subversion/tests/libsvn_subr/auth-test$(EXEEXT) subversion/tests/libsvn_subr/cache-test$(EXEEXT) subversion/tests/libsvn_subr/checksum-test$(EXEEXT) subversion/tests/libsvn_client/client-test$(EXEEXT) subversion/tests/libsvn_subr/compat-test$(EXEEXT) subversion/tests/libsvn_subr/config-test$(EXEEXT) subversion/tests/libsvn_diff/diff-diff3-test$(EXEEXT) subversion/tests/libsvn_subr/dirent_uri-test$(EXEEXT) subversion/tests/libsvn_subr/error-test$(EXEEXT) subversion/tests/libsvn_fs_fs/fs-pack-test$(EXEEXT) subversion/tests/libsvn_fs/fs-test$(EXEEXT) subversion/tests/libsvn_subr/hashdump-test$(EXEEXT) subversion/tests/libsvn_test-1.la subversion/tests/libsvn_fs/locks-test$(EXEEXT) subversion/tests/libsvn_subr/mergeinfo-test$(EXEEXT) subversion/tests/libsvn_subr/opt-test$(EXEEXT) subversion/tests/libsvn_subr/path-test$(EXEEXT) subversion/tests/libsvn_ra_local/ra-local-test$(EXEEXT) subversion/tests/libsvn_delta/random-test$(EXEEXT) subversion/tests/libsvn_repos/repos-test$(EXEEXT) subversion/tests/libsvn_subr/revision-test$(EXEEXT) subversion/tests/libsvn_subr/skel-test$(EXEEXT) subversion/tests/libsvn_subr/stream-test$(EXEEXT) subversion/tests/libsvn_subr/string-test$(EXEEXT) subversion/tests/libsvn_delta/svndiff-test$(EXEEXT) subversion/tests/libsvn_subr/target-test$(EXEEXT) subversion/tests/libsvn_subr/time-test$(EXEEXT) subversion/tests/libsvn_subr/translate-test$(EXEEXT) subversion/tests/libsvn_wc/tree-conflict-data-test$(EXEEXT) subversion/tests/libsvn_subr/utf-test$(EXEEXT) subversion/tests/libsvn_delta/vdelta-test$(EXEEXT) subversion/tests/libsvn_delta/window-test$(EXEEXT)

tools: tools/diff/diff$(EXEEXT) tools/diff/diff3$(EXEEXT) tools/diff/diff4$(EXEEXT) tools/server-side/svn-populate-node-origins-index$(EXEEXT) tools/server-side/svnauthz-validate$(EXEEXT) tools/client-side/svnmucc/svnmucc$(EXEEXT)


########################################
# Section 7: Install-Group install targets
########################################

install-mods-shared: subversion/mod_dav_svn/mod_dav_svn.la subversion/mod_authz_svn/mod_authz_svn.la
	cd subversion/mod_dav_svn ; $(MKDIR) "$(APACHE_LIBEXECDIR)" ; $(INSTALL_MOD_SHARED) -n dav_svn mod_dav_svn.la
	cd subversion/mod_authz_svn ; $(MKDIR) "$(APACHE_LIBEXECDIR)" ; $(INSTALL_MOD_SHARED) -n authz_svn mod_authz_svn.la

install-bdb-lib: subversion/libsvn_fs_base/libsvn_fs_base-1.la
	$(MKDIR) $(DESTDIR)$(bdb_libdir)
	cd subversion/libsvn_fs_base ; $(INSTALL_BDB_LIB) libsvn_fs_base-1.la $(DESTDIR)$(bdb_libdir)/libsvn_fs_base-1.la

install-bin: subversion/svn/svn$(EXEEXT) subversion/svnadmin/svnadmin$(EXEEXT) subversion/svndumpfilter/svndumpfilter$(EXEEXT) subversion/svnlook/svnlook$(EXEEXT) subversion/svnserve/svnserve$(EXEEXT) subversion/svnsync/svnsync$(EXEEXT) subversion/svnversion/svnversion$(EXEEXT)
	$(MKDIR) $(DESTDIR)$(bindir)
	cd subversion/svn ; $(INSTALL_BIN) svn$(EXEEXT) $(DESTDIR)$(bindir)/svn$(EXEEXT)
	cd subversion/svnadmin ; $(INSTALL_BIN) svnadmin$(EXEEXT) $(DESTDIR)$(bindir)/svnadmin$(EXEEXT)
	cd subversion/svndumpfilter ; $(INSTALL_BIN) svndumpfilter$(EXEEXT) $(DESTDIR)$(bindir)/svndumpfilter$(EXEEXT)
	cd subversion/svnlook ; $(INSTALL_BIN) svnlook$(EXEEXT) $(DESTDIR)$(bindir)/svnlook$(EXEEXT)
	cd subversion/svnserve ; $(INSTALL_BIN) svnserve$(EXEEXT) $(DESTDIR)$(bindir)/svnserve$(EXEEXT)
	cd subversion/svnsync ; $(INSTALL_BIN) svnsync$(EXEEXT) $(DESTDIR)$(bindir)/svnsync$(EXEEXT)
	cd subversion/svnversion ; $(INSTALL_BIN) svnversion$(EXEEXT) $(DESTDIR)$(bindir)/svnversion$(EXEEXT)

install-contrib: contrib/client-side/svn-push/svn-push$(EXEEXT)
	$(MKDIR) $(DESTDIR)$(contribdir)
	cd contrib/client-side/svn-push ; $(INSTALL_CONTRIB) svn-push$(EXEEXT) $(DESTDIR)$(contribdir)/svn-push$(EXEEXT)

install-fsmod-lib: subversion/libsvn_subr/libsvn_subr-1.la subversion/libsvn_delta/libsvn_delta-1.la subversion/libsvn_fs_util/libsvn_fs_util-1.la subversion/libsvn_fs_fs/libsvn_fs_fs-1.la
	$(MKDIR) $(DESTDIR)$(fsmod_libdir)
	cd subversion/libsvn_subr ; $(INSTALL_FSMOD_LIB) libsvn_subr-1.la $(DESTDIR)$(fsmod_libdir)/libsvn_subr-1.la
	cd subversion/libsvn_delta ; $(INSTALL_FSMOD_LIB) libsvn_delta-1.la $(DESTDIR)$(fsmod_libdir)/libsvn_delta-1.la
	cd subversion/libsvn_fs_util ; $(INSTALL_FSMOD_LIB) libsvn_fs_util-1.la $(DESTDIR)$(fsmod_libdir)/libsvn_fs_util-1.la
	cd subversion/libsvn_fs_fs ; $(INSTALL_FSMOD_LIB) libsvn_fs_fs-1.la $(DESTDIR)$(fsmod_libdir)/libsvn_fs_fs-1.la

install-gnome-keyring-lib: subversion/libsvn_auth_gnome_keyring/libsvn_auth_gnome_keyring-1.la
	$(MKDIR) $(DESTDIR)$(gnome_keyring_libdir)
	cd subversion/libsvn_auth_gnome_keyring ; $(INSTALL_GNOME_KEYRING_LIB) libsvn_auth_gnome_keyring-1.la $(DESTDIR)$(gnome_keyring_libdir)/libsvn_auth_gnome_keyring-1.la

install-javahl-java: 
	$(MKDIR) $(DESTDIR)$(javahl_javadir)
	$(INSTALL_EXTRA_JAVAHL_JAVA)

install-javahl-javah: 
	$(MKDIR) $(DESTDIR)$(javahl_javahdir)
	$(INSTALL_EXTRA_JAVAHL_JAVAH)

install-javahl-lib: subversion/bindings/javahl/native/libsvnjavahl-1.la
	$(MKDIR) $(DESTDIR)$(javahl_libdir)
	cd subversion/bindings/javahl/native ; $(INSTALL_JAVAHL_LIB) libsvnjavahl-1.la $(DESTDIR)$(javahl_libdir)/libsvnjavahl-1.la
	$(INSTALL_EXTRA_JAVAHL_LIB)

install-javahl-tests: 
	$(MKDIR) $(DESTDIR)$(javahl_testsdir)
	$(INSTALL_EXTRA_JAVAHL_TESTS)

install-kwallet-lib: subversion/libsvn_auth_kwallet/libsvn_auth_kwallet-1.la
	$(MKDIR) $(DESTDIR)$(kwallet_libdir)
	cd subversion/libsvn_auth_kwallet ; $(INSTALL_KWALLET_LIB) libsvn_auth_kwallet-1.la $(DESTDIR)$(kwallet_libdir)/libsvn_auth_kwallet-1.la

install-lib: subversion/libsvn_diff/libsvn_diff-1.la subversion/libsvn_ra/libsvn_ra-1.la subversion/libsvn_wc/libsvn_wc-1.la subversion/libsvn_client/libsvn_client-1.la
	$(MKDIR) $(DESTDIR)$(libdir)
	cd subversion/libsvn_diff ; $(INSTALL_LIB) libsvn_diff-1.la $(DESTDIR)$(libdir)/libsvn_diff-1.la
	cd subversion/libsvn_ra ; $(INSTALL_LIB) libsvn_ra-1.la $(DESTDIR)$(libdir)/libsvn_ra-1.la
	cd subversion/libsvn_wc ; $(INSTALL_LIB) libsvn_wc-1.la $(DESTDIR)$(libdir)/libsvn_wc-1.la
	cd subversion/libsvn_client ; $(INSTALL_LIB) libsvn_client-1.la $(DESTDIR)$(libdir)/libsvn_client-1.la

install-locale: subversion/po/de.mo subversion/po/es.mo subversion/po/fr.mo subversion/po/it.mo subversion/po/ja.mo subversion/po/ko.mo subversion/po/nb.mo subversion/po/pl.mo subversion/po/pt_BR.mo subversion/po/sv.mo subversion/po/zh_CN.mo subversion/po/zh_TW.mo
	$(MKDIR) $(DESTDIR)$(localedir)
	$(MKDIR) $(DESTDIR)$(localedir)/de/LC_MESSAGES
	cd subversion/po ; $(INSTALL_LOCALE) de.mo $(DESTDIR)$(localedir)/de/LC_MESSAGES/$(PACKAGE_NAME).mo
	$(MKDIR) $(DESTDIR)$(localedir)/es/LC_MESSAGES
	cd subversion/po ; $(INSTALL_LOCALE) es.mo $(DESTDIR)$(localedir)/es/LC_MESSAGES/$(PACKAGE_NAME).mo
	$(MKDIR) $(DESTDIR)$(localedir)/fr/LC_MESSAGES
	cd subversion/po ; $(INSTALL_LOCALE) fr.mo $(DESTDIR)$(localedir)/fr/LC_MESSAGES/$(PACKAGE_NAME).mo
	$(MKDIR) $(DESTDIR)$(localedir)/it/LC_MESSAGES
	cd subversion/po ; $(INSTALL_LOCALE) it.mo $(DESTDIR)$(localedir)/it/LC_MESSAGES/$(PACKAGE_NAME).mo
	$(MKDIR) $(DESTDIR)$(localedir)/ja/LC_MESSAGES
	cd subversion/po ; $(INSTALL_LOCALE) ja.mo $(DESTDIR)$(localedir)/ja/LC_MESSAGES/$(PACKAGE_NAME).mo
	$(MKDIR) $(DESTDIR)$(localedir)/ko/LC_MESSAGES
	cd subversion/po ; $(INSTALL_LOCALE) ko.mo $(DESTDIR)$(localedir)/ko/LC_MESSAGES/$(PACKAGE_NAME).mo
	$(MKDIR) $(DESTDIR)$(localedir)/nb/LC_MESSAGES
	cd subversion/po ; $(INSTALL_LOCALE) nb.mo $(DESTDIR)$(localedir)/nb/LC_MESSAGES/$(PACKAGE_NAME).mo
	$(MKDIR) $(DESTDIR)$(localedir)/pl/LC_MESSAGES
	cd subversion/po ; $(INSTALL_LOCALE) pl.mo $(DESTDIR)$(localedir)/pl/LC_MESSAGES/$(PACKAGE_NAME).mo
	$(MKDIR) $(DESTDIR)$(localedir)/pt_BR/LC_MESSAGES
	cd subversion/po ; $(INSTALL_LOCALE) pt_BR.mo $(DESTDIR)$(localedir)/pt_BR/LC_MESSAGES/$(PACKAGE_NAME).mo
	$(MKDIR) $(DESTDIR)$(localedir)/sv/LC_MESSAGES
	cd subversion/po ; $(INSTALL_LOCALE) sv.mo $(DESTDIR)$(localedir)/sv/LC_MESSAGES/$(PACKAGE_NAME).mo
	$(MKDIR) $(DESTDIR)$(localedir)/zh_CN/LC_MESSAGES
	cd subversion/po ; $(INSTALL_LOCALE) zh_CN.mo $(DESTDIR)$(localedir)/zh_CN/LC_MESSAGES/$(PACKAGE_NAME).mo
	$(MKDIR) $(DESTDIR)$(localedir)/zh_TW/LC_MESSAGES
	cd subversion/po ; $(INSTALL_LOCALE) zh_TW.mo $(DESTDIR)$(localedir)/zh_TW/LC_MESSAGES/$(PACKAGE_NAME).mo

install-neon-lib: subversion/libsvn_ra_neon/libsvn_ra_neon-1.la
	$(MKDIR) $(DESTDIR)$(neon_libdir)
	cd subversion/libsvn_ra_neon ; $(INSTALL_NEON_LIB) libsvn_ra_neon-1.la $(DESTDIR)$(neon_libdir)/libsvn_ra_neon-1.la

install-ramod-lib: subversion/libsvn_fs/libsvn_fs-1.la subversion/libsvn_ra_svn/libsvn_ra_svn-1.la subversion/libsvn_repos/libsvn_repos-1.la subversion/libsvn_ra_local/libsvn_ra_local-1.la
	$(MKDIR) $(DESTDIR)$(ramod_libdir)
	cd subversion/libsvn_fs ; $(INSTALL_RAMOD_LIB) libsvn_fs-1.la $(DESTDIR)$(ramod_libdir)/libsvn_fs-1.la
	cd subversion/libsvn_ra_svn ; $(INSTALL_RAMOD_LIB) libsvn_ra_svn-1.la $(DESTDIR)$(ramod_libdir)/libsvn_ra_svn-1.la
	cd subversion/libsvn_repos ; $(INSTALL_RAMOD_LIB) libsvn_repos-1.la $(DESTDIR)$(ramod_libdir)/libsvn_repos-1.la
	cd subversion/libsvn_ra_local ; $(INSTALL_RAMOD_LIB) libsvn_ra_local-1.la $(DESTDIR)$(ramod_libdir)/libsvn_ra_local-1.la

install-serf-lib: subversion/libsvn_ra_serf/libsvn_ra_serf-1.la
	$(MKDIR) $(DESTDIR)$(serf_libdir)
	cd subversion/libsvn_ra_serf ; $(INSTALL_SERF_LIB) libsvn_ra_serf-1.la $(DESTDIR)$(serf_libdir)/libsvn_ra_serf-1.la

install-swig-pl-lib: subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la
	$(MKDIR) $(DESTDIR)$(swig_pl_libdir)
	cd subversion/bindings/swig/perl/libsvn_swig_perl ; $(INSTALL_SWIG_PL_LIB) libsvn_swig_perl-1.la $(DESTDIR)$(swig_pl_libdir)/libsvn_swig_perl-1.la

install-swig-py: subversion/bindings/swig/python/_core.la subversion/bindings/swig/python/_client.la subversion/bindings/swig/python/_delta.la subversion/bindings/swig/python/_diff.la subversion/bindings/swig/python/_fs.la subversion/bindings/swig/python/_ra.la subversion/bindings/swig/python/_repos.la subversion/bindings/swig/python/_wc.la
	$(MKDIR) $(DESTDIR)$(swig_pydir)
	cd subversion/bindings/swig/python ; $(INSTALL_SWIG_PY) _core.la $(DESTDIR)$(swig_pydir)/_core.la
	cd subversion/bindings/swig/python ; $(INSTALL_SWIG_PY) _client.la $(DESTDIR)$(swig_pydir)/_client.la
	cd subversion/bindings/swig/python ; $(INSTALL_SWIG_PY) _delta.la $(DESTDIR)$(swig_pydir)/_delta.la
	cd subversion/bindings/swig/python ; $(INSTALL_SWIG_PY) _diff.la $(DESTDIR)$(swig_pydir)/_diff.la
	cd subversion/bindings/swig/python ; $(INSTALL_SWIG_PY) _fs.la $(DESTDIR)$(swig_pydir)/_fs.la
	cd subversion/bindings/swig/python ; $(INSTALL_SWIG_PY) _ra.la $(DESTDIR)$(swig_pydir)/_ra.la
	cd subversion/bindings/swig/python ; $(INSTALL_SWIG_PY) _repos.la $(DESTDIR)$(swig_pydir)/_repos.la
	cd subversion/bindings/swig/python ; $(INSTALL_SWIG_PY) _wc.la $(DESTDIR)$(swig_pydir)/_wc.la
	$(INSTALL_EXTRA_SWIG_PY)

install-swig-py-lib: subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la
	$(MKDIR) $(DESTDIR)$(swig_py_libdir)
	cd subversion/bindings/swig/python/libsvn_swig_py ; $(INSTALL_SWIG_PY_LIB) libsvn_swig_py-1.la $(DESTDIR)$(swig_py_libdir)/libsvn_swig_py-1.la

install-swig-rb: subversion/bindings/swig/ruby/core.la subversion/bindings/swig/ruby/client.la subversion/bindings/swig/ruby/delta.la subversion/bindings/swig/ruby/diff.la subversion/bindings/swig/ruby/fs.la subversion/bindings/swig/ruby/ra.la subversion/bindings/swig/ruby/repos.la subversion/bindings/swig/ruby/wc.la
	$(MKDIR) $(DESTDIR)$(swig_rbdir)
	cd subversion/bindings/swig/ruby ; $(INSTALL_SWIG_RB) core.la $(DESTDIR)$(swig_rbdir)/core.la
	cd subversion/bindings/swig/ruby ; $(INSTALL_SWIG_RB) client.la $(DESTDIR)$(swig_rbdir)/client.la
	cd subversion/bindings/swig/ruby ; $(INSTALL_SWIG_RB) delta.la $(DESTDIR)$(swig_rbdir)/delta.la
	cd subversion/bindings/swig/ruby ; $(INSTALL_SWIG_RB) diff.la $(DESTDIR)$(swig_rbdir)/diff.la
	cd subversion/bindings/swig/ruby ; $(INSTALL_SWIG_RB) fs.la $(DESTDIR)$(swig_rbdir)/fs.la
	cd subversion/bindings/swig/ruby ; $(INSTALL_SWIG_RB) ra.la $(DESTDIR)$(swig_rbdir)/ra.la
	cd subversion/bindings/swig/ruby ; $(INSTALL_SWIG_RB) repos.la $(DESTDIR)$(swig_rbdir)/repos.la
	cd subversion/bindings/swig/ruby ; $(INSTALL_SWIG_RB) wc.la $(DESTDIR)$(swig_rbdir)/wc.la
	$(INSTALL_EXTRA_SWIG_RB)

install-swig-rb-lib: subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la
	$(MKDIR) $(DESTDIR)$(swig_rb_libdir)
	cd subversion/bindings/swig/ruby/libsvn_swig_ruby ; $(INSTALL_SWIG_RB_LIB) libsvn_swig_ruby-1.la $(DESTDIR)$(swig_rb_libdir)/libsvn_swig_ruby-1.la

install-tools: tools/diff/diff$(EXEEXT) tools/diff/diff3$(EXEEXT) tools/diff/diff4$(EXEEXT) tools/server-side/svn-populate-node-origins-index$(EXEEXT) tools/server-side/svnauthz-validate$(EXEEXT) tools/client-side/svnmucc/svnmucc$(EXEEXT)
	$(MKDIR) $(DESTDIR)$(toolsdir)
	cd tools/diff ; $(INSTALL_TOOLS) diff$(EXEEXT) $(DESTDIR)$(toolsdir)/diff$(EXEEXT)
	cd tools/diff ; $(INSTALL_TOOLS) diff3$(EXEEXT) $(DESTDIR)$(toolsdir)/diff3$(EXEEXT)
	cd tools/diff ; $(INSTALL_TOOLS) diff4$(EXEEXT) $(DESTDIR)$(toolsdir)/diff4$(EXEEXT)
	cd tools/server-side ; $(INSTALL_TOOLS) svn-populate-node-origins-index$(EXEEXT) $(DESTDIR)$(toolsdir)/svn-populate-node-origins-index$(EXEEXT)
	cd tools/server-side ; $(INSTALL_TOOLS) svnauthz-validate$(EXEEXT) $(DESTDIR)$(toolsdir)/svnauthz-validate$(EXEEXT)
	cd tools/client-side/svnmucc ; $(INSTALL_TOOLS) svnmucc$(EXEEXT) $(DESTDIR)$(toolsdir)/svnmucc$(EXEEXT)


########################################
# Section 8: The install-include rule
########################################

install-include: subversion/include/svn_user.h subversion/include/svn_dav.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_iter.h subversion/include/svn_ra.h subversion/include/svn_utf.h subversion/include/svn_types.h subversion/include/svn_ctype.h subversion/include/svn_error_codes.h subversion/include/svn_nls.h subversion/include/svn_base64.h subversion/include/svn_checksum.h subversion/include/svn_ra_svn.h subversion/include/mod_dav_svn.h subversion/include/svn_xml.h subversion/include/svn_string.h subversion/include/svn_delta.h subversion/include/mod_authz_svn.h subversion/include/svn_hash.h subversion/include/svn_md5.h subversion/include/svn_compat.h subversion/include/svn_mergeinfo.h subversion/include/svn_wc.h subversion/include/svn_error.h subversion/include/svn_io.h subversion/include/svn_dirent_uri.h subversion/include/svn_sorts.h subversion/include/svn_opt.h subversion/include/svn_props.h subversion/include/svn_diff.h subversion/include/svn_subst.h subversion/include/svn_config.h subversion/include/svn_path.h subversion/include/svn_time.h subversion/include/svn_fs.h subversion/include/svn_repos.h subversion/include/svn_version.h subversion/include/svn_dso.h subversion/include/svn_auth.h subversion/include/svn_quoprint.h subversion/include/svn_pools.h
	$(MKDIR) $(DESTDIR)$(includedir)/subversion-1
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_user.h $(DESTDIR)$(includedir)/subversion-1/svn_user.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_dav.h $(DESTDIR)$(includedir)/subversion-1/svn_dav.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_client.h $(DESTDIR)$(includedir)/subversion-1/svn_client.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_cmdline.h $(DESTDIR)$(includedir)/subversion-1/svn_cmdline.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_iter.h $(DESTDIR)$(includedir)/subversion-1/svn_iter.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_ra.h $(DESTDIR)$(includedir)/subversion-1/svn_ra.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_utf.h $(DESTDIR)$(includedir)/subversion-1/svn_utf.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_types.h $(DESTDIR)$(includedir)/subversion-1/svn_types.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_ctype.h $(DESTDIR)$(includedir)/subversion-1/svn_ctype.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_error_codes.h $(DESTDIR)$(includedir)/subversion-1/svn_error_codes.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_nls.h $(DESTDIR)$(includedir)/subversion-1/svn_nls.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_base64.h $(DESTDIR)$(includedir)/subversion-1/svn_base64.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_checksum.h $(DESTDIR)$(includedir)/subversion-1/svn_checksum.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_ra_svn.h $(DESTDIR)$(includedir)/subversion-1/svn_ra_svn.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/mod_dav_svn.h $(DESTDIR)$(includedir)/subversion-1/mod_dav_svn.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_xml.h $(DESTDIR)$(includedir)/subversion-1/svn_xml.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_string.h $(DESTDIR)$(includedir)/subversion-1/svn_string.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_delta.h $(DESTDIR)$(includedir)/subversion-1/svn_delta.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/mod_authz_svn.h $(DESTDIR)$(includedir)/subversion-1/mod_authz_svn.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_hash.h $(DESTDIR)$(includedir)/subversion-1/svn_hash.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_md5.h $(DESTDIR)$(includedir)/subversion-1/svn_md5.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_compat.h $(DESTDIR)$(includedir)/subversion-1/svn_compat.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_mergeinfo.h $(DESTDIR)$(includedir)/subversion-1/svn_mergeinfo.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_wc.h $(DESTDIR)$(includedir)/subversion-1/svn_wc.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_error.h $(DESTDIR)$(includedir)/subversion-1/svn_error.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_io.h $(DESTDIR)$(includedir)/subversion-1/svn_io.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_dirent_uri.h $(DESTDIR)$(includedir)/subversion-1/svn_dirent_uri.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_sorts.h $(DESTDIR)$(includedir)/subversion-1/svn_sorts.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_opt.h $(DESTDIR)$(includedir)/subversion-1/svn_opt.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_props.h $(DESTDIR)$(includedir)/subversion-1/svn_props.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_diff.h $(DESTDIR)$(includedir)/subversion-1/svn_diff.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_subst.h $(DESTDIR)$(includedir)/subversion-1/svn_subst.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_config.h $(DESTDIR)$(includedir)/subversion-1/svn_config.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_path.h $(DESTDIR)$(includedir)/subversion-1/svn_path.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_time.h $(DESTDIR)$(includedir)/subversion-1/svn_time.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_fs.h $(DESTDIR)$(includedir)/subversion-1/svn_fs.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_repos.h $(DESTDIR)$(includedir)/subversion-1/svn_repos.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_version.h $(DESTDIR)$(includedir)/subversion-1/svn_version.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_dso.h $(DESTDIR)$(includedir)/subversion-1/svn_dso.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_auth.h $(DESTDIR)$(includedir)/subversion-1/svn_auth.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_quoprint.h $(DESTDIR)$(includedir)/subversion-1/svn_quoprint.h
	$(INSTALL_INCLUDE) $(abs_srcdir)/subversion/include/svn_pools.h $(DESTDIR)$(includedir)/subversion-1/svn_pools.h

########################################
# Section 9: Shortcut targets for manual builds of specific items
########################################

auth-test: subversion/tests/libsvn_subr/auth-test$(EXEEXT)
cache-test: subversion/tests/libsvn_subr/cache-test$(EXEEXT)
changes-test: subversion/tests/libsvn_fs_base/changes-test$(EXEEXT)
checksum-test: subversion/tests/libsvn_subr/checksum-test$(EXEEXT)
client-test: subversion/tests/libsvn_client/client-test$(EXEEXT)
compat-test: subversion/tests/libsvn_subr/compat-test$(EXEEXT)
config-test: subversion/tests/libsvn_subr/config-test$(EXEEXT)
diff: tools/diff/diff$(EXEEXT)
diff-diff3-test: subversion/tests/libsvn_diff/diff-diff3-test$(EXEEXT)
diff3: tools/diff/diff3$(EXEEXT)
diff4: tools/diff/diff4$(EXEEXT)
dirent_uri-test: subversion/tests/libsvn_subr/dirent_uri-test$(EXEEXT)
error-test: subversion/tests/libsvn_subr/error-test$(EXEEXT)
fs-base-test: subversion/tests/libsvn_fs_base/fs-base-test$(EXEEXT)
fs-pack-test: subversion/tests/libsvn_fs_fs/fs-pack-test$(EXEEXT)
fs-test: subversion/tests/libsvn_fs/fs-test$(EXEEXT)
hashdump-test: subversion/tests/libsvn_subr/hashdump-test$(EXEEXT)
key-test: subversion/tests/libsvn_fs_base/key-test$(EXEEXT)
libsvn_auth_gnome_keyring: subversion/libsvn_auth_gnome_keyring/libsvn_auth_gnome_keyring-1.la
libsvn_auth_kwallet: subversion/libsvn_auth_kwallet/libsvn_auth_kwallet-1.la
libsvn_client: subversion/libsvn_client/libsvn_client-1.la
libsvn_delta: subversion/libsvn_delta/libsvn_delta-1.la
libsvn_diff: subversion/libsvn_diff/libsvn_diff-1.la
libsvn_fs: subversion/libsvn_fs/libsvn_fs-1.la
libsvn_fs_base: subversion/libsvn_fs_base/libsvn_fs_base-1.la
libsvn_fs_fs: subversion/libsvn_fs_fs/libsvn_fs_fs-1.la
libsvn_fs_util: subversion/libsvn_fs_util/libsvn_fs_util-1.la
libsvn_ra: subversion/libsvn_ra/libsvn_ra-1.la
libsvn_ra_local: subversion/libsvn_ra_local/libsvn_ra_local-1.la
libsvn_ra_neon: subversion/libsvn_ra_neon/libsvn_ra_neon-1.la
libsvn_ra_serf: subversion/libsvn_ra_serf/libsvn_ra_serf-1.la
libsvn_ra_svn: subversion/libsvn_ra_svn/libsvn_ra_svn-1.la
libsvn_repos: subversion/libsvn_repos/libsvn_repos-1.la
libsvn_subr: subversion/libsvn_subr/libsvn_subr-1.la
libsvn_swig_perl: subversion/bindings/swig/perl/libsvn_swig_perl/libsvn_swig_perl-1.la
libsvn_swig_py: subversion/bindings/swig/python/libsvn_swig_py/libsvn_swig_py-1.la
libsvn_swig_ruby: subversion/bindings/swig/ruby/libsvn_swig_ruby/libsvn_swig_ruby-1.la
libsvn_test: subversion/tests/libsvn_test-1.la
libsvn_wc: subversion/libsvn_wc/libsvn_wc-1.la
libsvnjavahl: subversion/bindings/javahl/native/libsvnjavahl-1.la
locks-test: subversion/tests/libsvn_fs/locks-test$(EXEEXT)
mergeinfo-test: subversion/tests/libsvn_subr/mergeinfo-test$(EXEEXT)
mod_authz_svn: subversion/mod_authz_svn/mod_authz_svn.la
mod_dav_svn: subversion/mod_dav_svn/mod_dav_svn.la
opt-test: subversion/tests/libsvn_subr/opt-test$(EXEEXT)
path-test: subversion/tests/libsvn_subr/path-test$(EXEEXT)
perl_client: subversion/bindings/swig/perl/native/_Client.la
perl_core: subversion/bindings/swig/perl/native/_Core.la
perl_delta: subversion/bindings/swig/perl/native/_Delta.la
perl_diff: subversion/bindings/swig/perl/native/_Diff.la
perl_fs: subversion/bindings/swig/perl/native/_Fs.la
perl_ra: subversion/bindings/swig/perl/native/_Ra.la
perl_repos: subversion/bindings/swig/perl/native/_Repos.la
perl_wc: subversion/bindings/swig/perl/native/_Wc.la
python_client: subversion/bindings/swig/python/_client.la
python_core: subversion/bindings/swig/python/_core.la
python_delta: subversion/bindings/swig/python/_delta.la
python_diff: subversion/bindings/swig/python/_diff.la
python_fs: subversion/bindings/swig/python/_fs.la
python_ra: subversion/bindings/swig/python/_ra.la
python_repos: subversion/bindings/swig/python/_repos.la
python_wc: subversion/bindings/swig/python/_wc.la
ra-local-test: subversion/tests/libsvn_ra_local/ra-local-test$(EXEEXT)
random-test: subversion/tests/libsvn_delta/random-test$(EXEEXT)
repos-test: subversion/tests/libsvn_repos/repos-test$(EXEEXT)
revision-test: subversion/tests/libsvn_subr/revision-test$(EXEEXT)
ruby_client: subversion/bindings/swig/ruby/client.la
ruby_core: subversion/bindings/swig/ruby/core.la
ruby_delta: subversion/bindings/swig/ruby/delta.la
ruby_diff: subversion/bindings/swig/ruby/diff.la
ruby_fs: subversion/bindings/swig/ruby/fs.la
ruby_ra: subversion/bindings/swig/ruby/ra.la
ruby_repos: subversion/bindings/swig/ruby/repos.la
ruby_wc: subversion/bindings/swig/ruby/wc.la
skel-test: subversion/tests/libsvn_subr/skel-test$(EXEEXT)
stream-test: subversion/tests/libsvn_subr/stream-test$(EXEEXT)
string-test: subversion/tests/libsvn_subr/string-test$(EXEEXT)
strings-reps-test: subversion/tests/libsvn_fs_base/strings-reps-test$(EXEEXT)
svn: subversion/svn/svn$(EXEEXT)
svn-populate-node-origins-index: tools/server-side/svn-populate-node-origins-index$(EXEEXT)
svn-push: contrib/client-side/svn-push/svn-push$(EXEEXT)
svnadmin: subversion/svnadmin/svnadmin$(EXEEXT)
svnauthz-validate: tools/server-side/svnauthz-validate$(EXEEXT)
svndiff-test: subversion/tests/libsvn_delta/svndiff-test$(EXEEXT)
svndumpfilter: subversion/svndumpfilter/svndumpfilter$(EXEEXT)
svnlook: subversion/svnlook/svnlook$(EXEEXT)
svnmucc: tools/client-side/svnmucc/svnmucc$(EXEEXT)
svnserve: subversion/svnserve/svnserve$(EXEEXT)
svnsync: subversion/svnsync/svnsync$(EXEEXT)
svnversion: subversion/svnversion/svnversion$(EXEEXT)
target-test: subversion/tests/libsvn_subr/target-test$(EXEEXT)
time-test: subversion/tests/libsvn_subr/time-test$(EXEEXT)
translate-test: subversion/tests/libsvn_subr/translate-test$(EXEEXT)
tree-conflict-data-test: subversion/tests/libsvn_wc/tree-conflict-data-test$(EXEEXT)
utf-test: subversion/tests/libsvn_subr/utf-test$(EXEEXT)
vdelta-test: subversion/tests/libsvn_delta/vdelta-test$(EXEEXT)
window-test: subversion/tests/libsvn_delta/window-test$(EXEEXT)

########################################
# Section 10: Rules to build all other kinds of object-like files
########################################

contrib/client-side/svn-push/svn-push.o: contrib/client-side/svn-push/svn-push.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/BasicTests.class: subversion/bindings/javahl/tests/org/tigris/subversion/javahl/BasicTests.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/BlameCallback.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/BlameCallback.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/BlameCallback2.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/BlameCallback2.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/BlameCallbackImpl.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/BlameCallbackImpl.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ChangePath.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/ChangePath.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ChangelistCallback.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/ChangelistCallback.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ClientException.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/ClientException.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/CommitItem.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/CommitItem.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/CommitItemStateFlags.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/CommitItemStateFlags.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/CommitMessage.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/CommitMessage.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ConflictDescriptor.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/ConflictDescriptor.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ConflictResolverCallback.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/ConflictResolverCallback.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ConflictResult.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/ConflictResult.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ConflictVersion.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/ConflictVersion.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/CopySource.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/CopySource.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Depth.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/Depth.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/DiffSummary.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/DiffSummary.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/DiffSummaryReceiver.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/DiffSummaryReceiver.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/DirEntry.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/DirEntry.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ErrorCodes.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/ErrorCodes.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Info.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/Info.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Info2.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/Info2.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/InfoCallback.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/InfoCallback.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/InputInterface.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/InputInterface.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/JNIError.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/JNIError.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ListCallback.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/ListCallback.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Lock.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/Lock.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/LockStatus.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/LockStatus.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/LogDate.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/LogDate.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/LogMessage.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/LogMessage.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/LogMessageCallback.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/LogMessageCallback.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Mergeinfo.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/Mergeinfo.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/MergeinfoLogKind.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/MergeinfoLogKind.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/NativeException.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/NativeException.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/NativeResources.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/NativeResources.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/NodeKind.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/NodeKind.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Notify.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/Notify.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Notify2.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/Notify2.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/NotifyAction.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/NotifyAction.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/NotifyInformation.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/NotifyInformation.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/NotifyStatus.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/NotifyStatus.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Operation.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/Operation.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/OutputInterface.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/OutputInterface.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Path.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/Path.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ProgressEvent.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/ProgressEvent.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ProgressListener.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/ProgressListener.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/PromptUserPassword.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/PromptUserPassword.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/PromptUserPassword2.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/PromptUserPassword2.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/PromptUserPassword3.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/PromptUserPassword3.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/PropertyData.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/PropertyData.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ProplistCallback.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/ProplistCallback.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ProplistCallbackImpl.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/ProplistCallbackImpl.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Revision.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/Revision.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/RevisionKind.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/RevisionKind.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/RevisionRange.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/RevisionRange.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/RunTests.class: subversion/bindings/javahl/tests/org/tigris/subversion/javahl/RunTests.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNAdmin.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/SVNAdmin.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNAdminTests.class: subversion/bindings/javahl/tests/org/tigris/subversion/javahl/SVNAdminTests.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNClient.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/SVNClient.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNClientInterface.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/SVNClientInterface.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNClientLogLevel.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/SVNClientLogLevel.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNClientSynchronized.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/SVNClientSynchronized.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNInputStream.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/SVNInputStream.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNOutputStream.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/SVNOutputStream.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNTests.class: subversion/bindings/javahl/tests/org/tigris/subversion/javahl/SVNTests.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ScheduleKind.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/ScheduleKind.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Status.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/Status.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/StatusCallback.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/StatusCallback.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/StatusKind.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/StatusKind.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SubversionException.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/SubversionException.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Version.class: subversion/bindings/javahl/src/org/tigris/subversion/javahl/Version.java

subversion/bindings/javahl/classes/org/tigris/subversion/javahl/WC.class: subversion/bindings/javahl/tests/org/tigris/subversion/javahl/WC.java

subversion/bindings/javahl/include/BlameCallback.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/BlameCallback.class

subversion/bindings/javahl/include/BlameCallback2.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/BlameCallback2.class

subversion/bindings/javahl/include/BlameCallbackImpl.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/BlameCallbackImpl.class

subversion/bindings/javahl/include/ChangePath.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ChangePath.class

subversion/bindings/javahl/include/ChangelistCallback.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ChangelistCallback.class

subversion/bindings/javahl/include/ClientException.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ClientException.class

subversion/bindings/javahl/include/CommitItem.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/CommitItem.class

subversion/bindings/javahl/include/CommitItemStateFlags.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/CommitItemStateFlags.class

subversion/bindings/javahl/include/CommitMessage.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/CommitMessage.class

subversion/bindings/javahl/include/ConflictDescriptor.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ConflictDescriptor.class

subversion/bindings/javahl/include/ConflictResolverCallback.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ConflictResolverCallback.class

subversion/bindings/javahl/include/ConflictResult.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ConflictResult.class

subversion/bindings/javahl/include/ConflictVersion.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ConflictVersion.class

subversion/bindings/javahl/include/CopySource.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/CopySource.class

subversion/bindings/javahl/include/Depth.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Depth.class

subversion/bindings/javahl/include/DiffSummary.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/DiffSummary.class

subversion/bindings/javahl/include/DiffSummaryReceiver.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/DiffSummaryReceiver.class

subversion/bindings/javahl/include/DirEntry.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/DirEntry.class

subversion/bindings/javahl/include/ErrorCodes.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ErrorCodes.class

subversion/bindings/javahl/include/Info.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Info.class

subversion/bindings/javahl/include/Info2.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Info2.class

subversion/bindings/javahl/include/InfoCallback.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/InfoCallback.class

subversion/bindings/javahl/include/InputInterface.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/InputInterface.class

subversion/bindings/javahl/include/JNIError.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/JNIError.class

subversion/bindings/javahl/include/ListCallback.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ListCallback.class

subversion/bindings/javahl/include/Lock.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Lock.class

subversion/bindings/javahl/include/LockStatus.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/LockStatus.class

subversion/bindings/javahl/include/LogDate.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/LogDate.class

subversion/bindings/javahl/include/LogMessage.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/LogMessage.class

subversion/bindings/javahl/include/LogMessageCallback.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/LogMessageCallback.class

subversion/bindings/javahl/include/Mergeinfo.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Mergeinfo.class

subversion/bindings/javahl/include/MergeinfoLogKind.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/MergeinfoLogKind.class

subversion/bindings/javahl/include/NativeException.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/NativeException.class

subversion/bindings/javahl/include/NativeResources.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/NativeResources.class

subversion/bindings/javahl/include/NodeKind.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/NodeKind.class

subversion/bindings/javahl/include/Notify.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Notify.class

subversion/bindings/javahl/include/Notify2.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Notify2.class

subversion/bindings/javahl/include/NotifyAction.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/NotifyAction.class

subversion/bindings/javahl/include/NotifyInformation.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/NotifyInformation.class

subversion/bindings/javahl/include/NotifyStatus.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/NotifyStatus.class

subversion/bindings/javahl/include/Operation.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Operation.class

subversion/bindings/javahl/include/OutputInterface.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/OutputInterface.class

subversion/bindings/javahl/include/Path.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Path.class

subversion/bindings/javahl/include/ProgressEvent.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ProgressEvent.class

subversion/bindings/javahl/include/ProgressListener.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ProgressListener.class

subversion/bindings/javahl/include/PromptUserPassword.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/PromptUserPassword.class

subversion/bindings/javahl/include/PromptUserPassword2.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/PromptUserPassword2.class

subversion/bindings/javahl/include/PromptUserPassword3.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/PromptUserPassword3.class

subversion/bindings/javahl/include/PropertyData.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/PropertyData.class

subversion/bindings/javahl/include/ProplistCallback.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ProplistCallback.class

subversion/bindings/javahl/include/ProplistCallbackImpl.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ProplistCallbackImpl.class

subversion/bindings/javahl/include/Revision.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Revision.class

subversion/bindings/javahl/include/RevisionKind.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/RevisionKind.class

subversion/bindings/javahl/include/RevisionRange.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/RevisionRange.class

subversion/bindings/javahl/include/SVNAdmin.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNAdmin.class

subversion/bindings/javahl/include/SVNClient.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNClient.class

subversion/bindings/javahl/include/SVNClientInterface.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNClientInterface.class

subversion/bindings/javahl/include/SVNClientLogLevel.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNClientLogLevel.class

subversion/bindings/javahl/include/SVNClientSynchronized.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNClientSynchronized.class

subversion/bindings/javahl/include/SVNInputStream.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNInputStream.class

subversion/bindings/javahl/include/SVNOutputStream.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SVNOutputStream.class

subversion/bindings/javahl/include/ScheduleKind.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/ScheduleKind.class

subversion/bindings/javahl/include/Status.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Status.class

subversion/bindings/javahl/include/StatusCallback.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/StatusCallback.class

subversion/bindings/javahl/include/StatusKind.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/StatusKind.class

subversion/bindings/javahl/include/SubversionException.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/SubversionException.class

subversion/bindings/javahl/include/Version.h: subversion/bindings/javahl/classes/org/tigris/subversion/javahl/Version.class

subversion/bindings/javahl/native/BlameCallback.lo: subversion/bindings/javahl/native/BlameCallback.cpp subversion/bindings/javahl/native/BlameCallback.h subversion/bindings/javahl/native/JNIUtil.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/BlameCallback.cpp

subversion/bindings/javahl/native/ChangelistCallback.lo: subversion/bindings/javahl/native/ChangelistCallback.cpp subversion/bindings/javahl/native/ChangelistCallback.h subversion/bindings/javahl/native/JNIUtil.h subversion/bindings/javahl/native/Path.h subversion/bindings/javahl/native/SVNBase.h subversion/bindings/javahl/native/SVNClient.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/ChangelistCallback.cpp

subversion/bindings/javahl/native/CommitMessage.lo: subversion/bindings/javahl/native/CommitMessage.cpp subversion/bindings/javahl/include/org_tigris_subversion_javahl_CommitItemStateFlags.h subversion/bindings/javahl/native/CommitMessage.h subversion/bindings/javahl/native/JNIUtil.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/CommitMessage.cpp

subversion/bindings/javahl/native/ConflictResolverCallback.lo: subversion/bindings/javahl/native/ConflictResolverCallback.cpp subversion/bindings/javahl/include/org_tigris_subversion_javahl_ConflictResult.h subversion/bindings/javahl/native/ConflictResolverCallback.h subversion/bindings/javahl/native/CreateJ.h subversion/bindings/javahl/native/EnumMapper.h subversion/bindings/javahl/native/JNIStringHolder.h subversion/bindings/javahl/native/JNIUtil.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/ConflictResolverCallback.cpp

subversion/bindings/javahl/native/CopySources.lo: subversion/bindings/javahl/native/CopySources.cpp subversion/bindings/javahl/native/CopySources.h subversion/bindings/javahl/native/JNIStringHolder.h subversion/bindings/javahl/native/JNIUtil.h subversion/bindings/javahl/native/Pool.h subversion/bindings/javahl/native/Revision.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/CopySources.cpp

subversion/bindings/javahl/native/CreateJ.lo: subversion/bindings/javahl/native/CreateJ.cpp subversion/bindings/javahl/native/CreateJ.h subversion/bindings/javahl/native/EnumMapper.h subversion/bindings/javahl/native/JNIStringHolder.h subversion/bindings/javahl/native/JNIUtil.h subversion/bindings/javahl/native/RevisionRange.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/CreateJ.cpp

subversion/bindings/javahl/native/DiffSummaryReceiver.lo: subversion/bindings/javahl/native/DiffSummaryReceiver.cpp subversion/bindings/javahl/native/DiffSummaryReceiver.h subversion/bindings/javahl/native/EnumMapper.h subversion/bindings/javahl/native/JNIUtil.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/DiffSummaryReceiver.cpp

subversion/bindings/javahl/native/EnumMapper.lo: subversion/bindings/javahl/native/EnumMapper.cpp subversion/bindings/javahl/include/org_tigris_subversion_javahl_CommitItemStateFlags.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_ConflictDescriptor_Action.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_ConflictDescriptor_Kind.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_ConflictDescriptor_Reason.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_Depth.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_LockStatus.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_NodeKind.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_NotifyAction.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_NotifyStatus.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_Operation.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_Revision.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_ScheduleKind.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_StatusKind.h subversion/bindings/javahl/native/EnumMapper.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/EnumMapper.cpp

subversion/bindings/javahl/native/InfoCallback.lo: subversion/bindings/javahl/native/InfoCallback.cpp subversion/bindings/javahl/native/CreateJ.h subversion/bindings/javahl/native/EnumMapper.h subversion/bindings/javahl/native/InfoCallback.h subversion/bindings/javahl/native/JNIUtil.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/InfoCallback.cpp

subversion/bindings/javahl/native/Inputer.lo: subversion/bindings/javahl/native/Inputer.cpp subversion/bindings/javahl/native/Inputer.h subversion/bindings/javahl/native/JNIByteArray.h subversion/bindings/javahl/native/JNIUtil.h subversion/bindings/javahl/native/Pool.h subversion/include/svn_checksum.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/Inputer.cpp

subversion/bindings/javahl/native/JNIByteArray.lo: subversion/bindings/javahl/native/JNIByteArray.cpp subversion/bindings/javahl/native/JNIByteArray.h subversion/bindings/javahl/native/JNIUtil.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/JNIByteArray.cpp

subversion/bindings/javahl/native/JNICriticalSection.lo: subversion/bindings/javahl/native/JNICriticalSection.cpp subversion/bindings/javahl/native/JNICriticalSection.h subversion/bindings/javahl/native/JNIMutex.h subversion/bindings/javahl/native/JNIUtil.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/JNICriticalSection.cpp

subversion/bindings/javahl/native/JNIMutex.lo: subversion/bindings/javahl/native/JNIMutex.cpp subversion/bindings/javahl/native/JNIMutex.h subversion/bindings/javahl/native/JNIUtil.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/JNIMutex.cpp

subversion/bindings/javahl/native/JNIStackElement.lo: subversion/bindings/javahl/native/JNIStackElement.cpp subversion/bindings/javahl/native/JNIStackElement.h subversion/bindings/javahl/native/JNIStringHolder.h subversion/bindings/javahl/native/JNIThreadData.h subversion/bindings/javahl/native/JNIUtil.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/JNIStackElement.cpp

subversion/bindings/javahl/native/JNIStringHolder.lo: subversion/bindings/javahl/native/JNIStringHolder.cpp subversion/bindings/javahl/native/JNIStringHolder.h subversion/bindings/javahl/native/JNIUtil.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/JNIStringHolder.cpp

subversion/bindings/javahl/native/JNIThreadData.lo: subversion/bindings/javahl/native/JNIThreadData.cpp subversion/bindings/javahl/native/JNIThreadData.h subversion/bindings/javahl/native/JNIUtil.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/JNIThreadData.cpp

subversion/bindings/javahl/native/JNIUtil.lo: subversion/bindings/javahl/native/JNIUtil.cpp subversion/bindings/javahl/native/JNICriticalSection.h subversion/bindings/javahl/native/JNIMutex.h subversion/bindings/javahl/native/JNIStringHolder.h subversion/bindings/javahl/native/JNIThreadData.h subversion/bindings/javahl/native/JNIUtil.h subversion/bindings/javahl/native/Pool.h subversion/bindings/javahl/native/SVNBase.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_dso.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/JNIUtil.cpp

subversion/bindings/javahl/native/ListCallback.lo: subversion/bindings/javahl/native/ListCallback.cpp subversion/bindings/javahl/native/CreateJ.h subversion/bindings/javahl/native/EnumMapper.h subversion/bindings/javahl/native/JNIUtil.h subversion/bindings/javahl/native/ListCallback.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/ListCallback.cpp

subversion/bindings/javahl/native/LogMessageCallback.lo: subversion/bindings/javahl/native/LogMessageCallback.cpp subversion/bindings/javahl/native/EnumMapper.h subversion/bindings/javahl/native/JNIUtil.h subversion/bindings/javahl/native/LogMessageCallback.h subversion/bindings/javahl/native/ProplistCallback.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_compat.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_ra.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/LogMessageCallback.cpp

subversion/bindings/javahl/native/MessageReceiver.lo: subversion/bindings/javahl/native/MessageReceiver.cpp subversion/bindings/javahl/native/JNIUtil.h subversion/bindings/javahl/native/MessageReceiver.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/MessageReceiver.cpp

subversion/bindings/javahl/native/Notify.lo: subversion/bindings/javahl/native/Notify.cpp subversion/bindings/javahl/native/EnumMapper.h subversion/bindings/javahl/native/JNIUtil.h subversion/bindings/javahl/native/Notify.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/Notify.cpp

subversion/bindings/javahl/native/Notify2.lo: subversion/bindings/javahl/native/Notify2.cpp subversion/bindings/javahl/native/CreateJ.h subversion/bindings/javahl/native/EnumMapper.h subversion/bindings/javahl/native/JNIUtil.h subversion/bindings/javahl/native/Notify2.h subversion/bindings/javahl/native/RevisionRange.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/Notify2.cpp

subversion/bindings/javahl/native/Outputer.lo: subversion/bindings/javahl/native/Outputer.cpp subversion/bindings/javahl/native/JNIByteArray.h subversion/bindings/javahl/native/JNIUtil.h subversion/bindings/javahl/native/Outputer.h subversion/bindings/javahl/native/Pool.h subversion/include/svn_checksum.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/Outputer.cpp

subversion/bindings/javahl/native/Path.lo: subversion/bindings/javahl/native/Path.cpp subversion/bindings/javahl/native/JNIUtil.h subversion/bindings/javahl/native/Path.h subversion/bindings/javahl/native/Pool.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/Path.cpp

subversion/bindings/javahl/native/Pool.lo: subversion/bindings/javahl/native/Pool.cpp subversion/bindings/javahl/native/JNICriticalSection.h subversion/bindings/javahl/native/JNIMutex.h subversion/bindings/javahl/native/JNIUtil.h subversion/bindings/javahl/native/Pool.h subversion/include/svn_pools.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/Pool.cpp

subversion/bindings/javahl/native/ProgressListener.lo: subversion/bindings/javahl/native/ProgressListener.cpp subversion/bindings/javahl/native/JNIUtil.h subversion/bindings/javahl/native/ProgressListener.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/ProgressListener.cpp

subversion/bindings/javahl/native/Prompter.lo: subversion/bindings/javahl/native/Prompter.cpp subversion/bindings/javahl/include/org_tigris_subversion_javahl_PromptUserPassword2.h subversion/bindings/javahl/native/JNIStringHolder.h subversion/bindings/javahl/native/JNIUtil.h subversion/bindings/javahl/native/Pool.h subversion/bindings/javahl/native/Prompter.h subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_pools.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/svn_private_config.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/Prompter.cpp

subversion/bindings/javahl/native/ProplistCallback.lo: subversion/bindings/javahl/native/ProplistCallback.cpp subversion/bindings/javahl/native/JNIUtil.h subversion/bindings/javahl/native/ProplistCallback.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/ProplistCallback.cpp

subversion/bindings/javahl/native/Revision.lo: subversion/bindings/javahl/native/Revision.cpp subversion/bindings/javahl/include/org_tigris_subversion_javahl_RevisionKind.h subversion/bindings/javahl/native/JNIUtil.h subversion/bindings/javahl/native/Revision.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_opt.h subversion/include/svn_types.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/Revision.cpp

subversion/bindings/javahl/native/RevisionRange.lo: subversion/bindings/javahl/native/RevisionRange.cpp subversion/bindings/javahl/native/JNIUtil.h subversion/bindings/javahl/native/Pool.h subversion/bindings/javahl/native/Revision.h subversion/bindings/javahl/native/RevisionRange.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/RevisionRange.cpp

subversion/bindings/javahl/native/RevpropTable.lo: subversion/bindings/javahl/native/RevpropTable.cpp subversion/bindings/javahl/native/JNIStringHolder.h subversion/bindings/javahl/native/JNIUtil.h subversion/bindings/javahl/native/Path.h subversion/bindings/javahl/native/Pool.h subversion/bindings/javahl/native/RevpropTable.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/RevpropTable.cpp

subversion/bindings/javahl/native/SVNAdmin.lo: subversion/bindings/javahl/native/SVNAdmin.cpp subversion/bindings/javahl/native/CreateJ.h subversion/bindings/javahl/native/Inputer.h subversion/bindings/javahl/native/JNIUtil.h subversion/bindings/javahl/native/MessageReceiver.h subversion/bindings/javahl/native/Outputer.h subversion/bindings/javahl/native/Path.h subversion/bindings/javahl/native/Pool.h subversion/bindings/javahl/native/Revision.h subversion/bindings/javahl/native/SVNAdmin.h subversion/bindings/javahl/native/SVNBase.h subversion/bindings/javahl/native/Targets.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/SVNAdmin.cpp

subversion/bindings/javahl/native/SVNBase.lo: subversion/bindings/javahl/native/SVNBase.cpp subversion/bindings/javahl/native/JNIUtil.h subversion/bindings/javahl/native/SVNBase.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/SVNBase.cpp

subversion/bindings/javahl/native/SVNClient.lo: subversion/bindings/javahl/native/SVNClient.cpp subversion/bindings/javahl/include/org_tigris_subversion_javahl_NodeKind.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_Revision.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_StatusKind.h subversion/bindings/javahl/native/BlameCallback.h subversion/bindings/javahl/native/ChangelistCallback.h subversion/bindings/javahl/native/CommitMessage.h subversion/bindings/javahl/native/ConflictResolverCallback.h subversion/bindings/javahl/native/CopySources.h subversion/bindings/javahl/native/CreateJ.h subversion/bindings/javahl/native/DiffSummaryReceiver.h subversion/bindings/javahl/native/EnumMapper.h subversion/bindings/javahl/native/InfoCallback.h subversion/bindings/javahl/native/JNIByteArray.h subversion/bindings/javahl/native/JNIStringHolder.h subversion/bindings/javahl/native/JNIUtil.h subversion/bindings/javahl/native/ListCallback.h subversion/bindings/javahl/native/LogMessageCallback.h subversion/bindings/javahl/native/Notify.h subversion/bindings/javahl/native/Notify2.h subversion/bindings/javahl/native/Path.h subversion/bindings/javahl/native/Pool.h subversion/bindings/javahl/native/ProgressListener.h subversion/bindings/javahl/native/Prompter.h subversion/bindings/javahl/native/ProplistCallback.h subversion/bindings/javahl/native/Revision.h subversion/bindings/javahl/native/RevisionRange.h subversion/bindings/javahl/native/RevpropTable.h subversion/bindings/javahl/native/SVNBase.h subversion/bindings/javahl/native/SVNClient.h subversion/bindings/javahl/native/StatusCallback.h subversion/bindings/javahl/native/StringArray.h subversion/bindings/javahl/native/Targets.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_dso.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/SVNClient.cpp

subversion/bindings/javahl/native/StatusCallback.lo: subversion/bindings/javahl/native/StatusCallback.cpp subversion/bindings/javahl/include/org_tigris_subversion_javahl_NodeKind.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_Revision.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_StatusKind.h subversion/bindings/javahl/native/CreateJ.h subversion/bindings/javahl/native/EnumMapper.h subversion/bindings/javahl/native/JNIUtil.h subversion/bindings/javahl/native/StatusCallback.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/StatusCallback.cpp

subversion/bindings/javahl/native/StringArray.lo: subversion/bindings/javahl/native/StringArray.cpp subversion/bindings/javahl/native/JNIStringHolder.h subversion/bindings/javahl/native/JNIUtil.h subversion/bindings/javahl/native/Path.h subversion/bindings/javahl/native/Pool.h subversion/bindings/javahl/native/StringArray.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/StringArray.cpp

subversion/bindings/javahl/native/Targets.lo: subversion/bindings/javahl/native/Targets.cpp subversion/bindings/javahl/native/JNIStringHolder.h subversion/bindings/javahl/native/JNIUtil.h subversion/bindings/javahl/native/Path.h subversion/bindings/javahl/native/Pool.h subversion/bindings/javahl/native/Targets.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/Targets.cpp

subversion/bindings/javahl/native/libsvnjavahl.la.lo: subversion/bindings/javahl/native/libsvnjavahl.la.c
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/libsvnjavahl.la.c

subversion/bindings/javahl/native/org_tigris_subversion_javahl_NativeResources.lo: subversion/bindings/javahl/native/org_tigris_subversion_javahl_NativeResources.cpp subversion/bindings/javahl/include/org_tigris_subversion_javahl_NativeResources.h subversion/bindings/javahl/native/JNIUtil.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/org_tigris_subversion_javahl_NativeResources.cpp

subversion/bindings/javahl/native/org_tigris_subversion_javahl_Path.lo: subversion/bindings/javahl/native/org_tigris_subversion_javahl_Path.cpp subversion/bindings/javahl/include/org_tigris_subversion_javahl_Path.h subversion/bindings/javahl/native/JNIStackElement.h subversion/bindings/javahl/native/JNIStringHolder.h subversion/bindings/javahl/native/JNIUtil.h subversion/bindings/javahl/native/Path.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/org_tigris_subversion_javahl_Path.cpp

subversion/bindings/javahl/native/org_tigris_subversion_javahl_SVNAdmin.lo: subversion/bindings/javahl/native/org_tigris_subversion_javahl_SVNAdmin.cpp subversion/bindings/javahl/include/org_tigris_subversion_javahl_SVNAdmin.h subversion/bindings/javahl/native/Inputer.h subversion/bindings/javahl/native/JNIByteArray.h subversion/bindings/javahl/native/JNIStackElement.h subversion/bindings/javahl/native/JNIStringHolder.h subversion/bindings/javahl/native/JNIUtil.h subversion/bindings/javahl/native/MessageReceiver.h subversion/bindings/javahl/native/Outputer.h subversion/bindings/javahl/native/Path.h subversion/bindings/javahl/native/Pool.h subversion/bindings/javahl/native/Revision.h subversion/bindings/javahl/native/SVNAdmin.h subversion/bindings/javahl/native/SVNBase.h subversion/bindings/javahl/native/Targets.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/svn_private_config.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/org_tigris_subversion_javahl_SVNAdmin.cpp

subversion/bindings/javahl/native/org_tigris_subversion_javahl_SVNClient.lo: subversion/bindings/javahl/native/org_tigris_subversion_javahl_SVNClient.cpp subversion/bindings/javahl/include/org_tigris_subversion_javahl_SVNClient.h subversion/bindings/javahl/include/org_tigris_subversion_javahl_SVNClientLogLevel.h subversion/bindings/javahl/native/BlameCallback.h subversion/bindings/javahl/native/ChangelistCallback.h subversion/bindings/javahl/native/CommitMessage.h subversion/bindings/javahl/native/ConflictResolverCallback.h subversion/bindings/javahl/native/CopySources.h subversion/bindings/javahl/native/DiffSummaryReceiver.h subversion/bindings/javahl/native/InfoCallback.h subversion/bindings/javahl/native/JNIByteArray.h subversion/bindings/javahl/native/JNIStackElement.h subversion/bindings/javahl/native/JNIStringHolder.h subversion/bindings/javahl/native/JNIUtil.h subversion/bindings/javahl/native/ListCallback.h subversion/bindings/javahl/native/LogMessageCallback.h subversion/bindings/javahl/native/Notify.h subversion/bindings/javahl/native/Notify2.h subversion/bindings/javahl/native/Outputer.h subversion/bindings/javahl/native/Path.h subversion/bindings/javahl/native/Pool.h subversion/bindings/javahl/native/ProgressListener.h subversion/bindings/javahl/native/Prompter.h subversion/bindings/javahl/native/ProplistCallback.h subversion/bindings/javahl/native/Revision.h subversion/bindings/javahl/native/RevisionRange.h subversion/bindings/javahl/native/RevpropTable.h subversion/bindings/javahl/native/SVNBase.h subversion/bindings/javahl/native/SVNClient.h subversion/bindings/javahl/native/StatusCallback.h subversion/bindings/javahl/native/StringArray.h subversion/bindings/javahl/native/Targets.h subversion/bindings/javahl/native/version.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/org_tigris_subversion_javahl_SVNClient.cpp

subversion/bindings/javahl/native/org_tigris_subversion_javahl_Version.lo: subversion/bindings/javahl/native/org_tigris_subversion_javahl_Version.cpp subversion/bindings/javahl/include/org_tigris_subversion_javahl_Version.h subversion/bindings/javahl/native/JNIStackElement.h subversion/bindings/javahl/native/JNIUtil.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_types.h subversion/include/svn_version.h
	$(COMPILE_JAVAHL_CXX) $(canonicalized_srcdir)subversion/bindings/javahl/native/org_tigris_subversion_javahl_Version.cpp

subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.lo: subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/proxy/swig_perl_external_runtime.swg subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_SWIG_PL) $(canonicalized_srcdir)subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.c

subversion/bindings/swig/perl/native/core.lo: subversion/bindings/swig/perl/native/core.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_fs.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_PL_WRAPPER) subversion/bindings/swig/perl/native/core.c

subversion/bindings/swig/perl/native/svn_client.lo: subversion/bindings/swig/perl/native/svn_client.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_fs.h subversion/include/svn_repos.h subversion/svn_private_config.h
	$(COMPILE_PL_WRAPPER) subversion/bindings/swig/perl/native/svn_client.c

subversion/bindings/swig/perl/native/svn_delta.lo: subversion/bindings/swig/perl/native/svn_delta.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_fs.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_PL_WRAPPER) subversion/bindings/swig/perl/native/svn_delta.c

subversion/bindings/swig/perl/native/svn_diff.lo: subversion/bindings/swig/perl/native/svn_diff.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_fs.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_PL_WRAPPER) subversion/bindings/swig/perl/native/svn_diff.c

subversion/bindings/swig/perl/native/svn_fs.lo: subversion/bindings/swig/perl/native/svn_fs.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_PL_WRAPPER) subversion/bindings/swig/perl/native/svn_fs.c

subversion/bindings/swig/perl/native/svn_ra.lo: subversion/bindings/swig/perl/native/svn_ra.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_fs.h subversion/include/svn_repos.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_PL_WRAPPER) subversion/bindings/swig/perl/native/svn_ra.c

subversion/bindings/swig/perl/native/svn_repos.lo: subversion/bindings/swig/perl/native/svn_repos.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_ra.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_PL_WRAPPER) subversion/bindings/swig/perl/native/svn_repos.c

subversion/bindings/swig/perl/native/svn_wc.lo: subversion/bindings/swig/perl/native/svn_wc.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_fs.h subversion/include/svn_repos.h subversion/svn_private_config.h
	$(COMPILE_PL_WRAPPER) subversion/bindings/swig/perl/native/svn_wc.c

subversion/bindings/swig/python/core.lo: subversion/bindings/swig/python/core.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_fs.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_PY_WRAPPER) subversion/bindings/swig/python/core.c

subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.lo: subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.c subversion/bindings/swig/proxy/swig_python_external_runtime.swg subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_SWIG_PY) $(canonicalized_srcdir)subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.c

subversion/bindings/swig/python/svn_client.lo: subversion/bindings/swig/python/svn_client.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_fs.h subversion/include/svn_repos.h subversion/svn_private_config.h
	$(COMPILE_PY_WRAPPER) subversion/bindings/swig/python/svn_client.c

subversion/bindings/swig/python/svn_delta.lo: subversion/bindings/swig/python/svn_delta.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_fs.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_PY_WRAPPER) subversion/bindings/swig/python/svn_delta.c

subversion/bindings/swig/python/svn_diff.lo: subversion/bindings/swig/python/svn_diff.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_fs.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_PY_WRAPPER) subversion/bindings/swig/python/svn_diff.c

subversion/bindings/swig/python/svn_fs.lo: subversion/bindings/swig/python/svn_fs.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_PY_WRAPPER) subversion/bindings/swig/python/svn_fs.c

subversion/bindings/swig/python/svn_ra.lo: subversion/bindings/swig/python/svn_ra.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_fs.h subversion/include/svn_repos.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_PY_WRAPPER) subversion/bindings/swig/python/svn_ra.c

subversion/bindings/swig/python/svn_repos.lo: subversion/bindings/swig/python/svn_repos.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_ra.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_PY_WRAPPER) subversion/bindings/swig/python/svn_repos.c

subversion/bindings/swig/python/svn_wc.lo: subversion/bindings/swig/python/svn_wc.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_fs.h subversion/include/svn_repos.h subversion/svn_private_config.h
	$(COMPILE_PY_WRAPPER) subversion/bindings/swig/python/svn_wc.c

subversion/bindings/swig/ruby/core.lo: subversion/bindings/swig/ruby/core.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_fs.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_RB_WRAPPER) subversion/bindings/swig/ruby/core.c

subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.lo: subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.c subversion/bindings/swig/proxy/swig_ruby_external_runtime.swg subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_nls.h subversion/include/svn_opt.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_SWIG_RB) $(canonicalized_srcdir)subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.c

subversion/bindings/swig/ruby/svn_client.lo: subversion/bindings/swig/ruby/svn_client.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_fs.h subversion/include/svn_repos.h subversion/svn_private_config.h
	$(COMPILE_RB_WRAPPER) subversion/bindings/swig/ruby/svn_client.c

subversion/bindings/swig/ruby/svn_delta.lo: subversion/bindings/swig/ruby/svn_delta.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_fs.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_RB_WRAPPER) subversion/bindings/swig/ruby/svn_delta.c

subversion/bindings/swig/ruby/svn_diff.lo: subversion/bindings/swig/ruby/svn_diff.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_delta.h subversion/include/svn_fs.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_RB_WRAPPER) subversion/bindings/swig/ruby/svn_diff.c

subversion/bindings/swig/ruby/svn_fs.lo: subversion/bindings/swig/ruby/svn_fs.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_RB_WRAPPER) subversion/bindings/swig/ruby/svn_fs.c

subversion/bindings/swig/ruby/svn_ra.lo: subversion/bindings/swig/ruby/svn_ra.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_fs.h subversion/include/svn_repos.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_RB_WRAPPER) subversion/bindings/swig/ruby/svn_ra.c

subversion/bindings/swig/ruby/svn_repos.lo: subversion/bindings/swig/ruby/svn_repos.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_ra.h subversion/include/svn_wc.h subversion/svn_private_config.h
	$(COMPILE_RB_WRAPPER) subversion/bindings/swig/ruby/svn_repos.c

subversion/bindings/swig/ruby/svn_wc.lo: subversion/bindings/swig/ruby/svn_wc.c subversion/bindings/swig/perl/libsvn_swig_perl/swigutil_pl.h subversion/bindings/swig/python/libsvn_swig_py/swigutil_py.h subversion/bindings/swig/ruby/libsvn_swig_ruby/swigutil_rb.h subversion/include/svn_client.h subversion/include/svn_fs.h subversion/include/svn_repos.h subversion/svn_private_config.h
	$(COMPILE_RB_WRAPPER) subversion/bindings/swig/ruby/svn_wc.c

subversion/libsvn_auth_gnome_keyring/gnome_keyring.lo: subversion/libsvn_auth_gnome_keyring/gnome_keyring.c subversion/include/private/svn_auth_private.h subversion/include/svn_auth.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_pools.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/svn_private_config.h

subversion/libsvn_auth_gnome_keyring/version.lo: subversion/libsvn_auth_gnome_keyring/version.c subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_types.h subversion/include/svn_version.h

subversion/libsvn_auth_kwallet/kwallet.lo: subversion/libsvn_auth_kwallet/kwallet.cpp subversion/include/private/svn_auth_private.h subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/svn_private_config.h

subversion/libsvn_auth_kwallet/version.lo: subversion/libsvn_auth_kwallet/version.c subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_types.h subversion/include/svn_version.h

subversion/libsvn_client/add.lo: subversion/libsvn_client/add.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_dirent_uri.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/blame.lo: subversion/libsvn_client/blame.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/cat.lo: subversion/libsvn_client/cat.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/changelist.lo: subversion/libsvn_client/changelist.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h

subversion/libsvn_client/checkout.lo: subversion/libsvn_client/checkout.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/cleanup.lo: subversion/libsvn_client/cleanup.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/cmdline.lo: subversion/libsvn_client/cmdline.c subversion/include/private/svn_opt_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/commit.lo: subversion/libsvn_client/commit.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_dirent_uri.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_iter.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/commit_util.lo: subversion/libsvn_client/commit_util.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_iter.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/compat_providers.lo: subversion/libsvn_client/compat_providers.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h

subversion/libsvn_client/copy.lo: subversion/libsvn_client/copy.c subversion/include/private/svn_mergeinfo_private.h subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/libsvn_client/mergeinfo.h subversion/svn_private_config.h

subversion/libsvn_client/ctx.lo: subversion/libsvn_client/ctx.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h

subversion/libsvn_client/delete.lo: subversion/libsvn_client/delete.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/deprecated.lo: subversion/libsvn_client/deprecated.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_compat.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/libsvn_client/mergeinfo.h subversion/svn_private_config.h

subversion/libsvn_client/diff.lo: subversion/libsvn_client/diff.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/export.lo: subversion/libsvn_client/export.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/externals.lo: subversion/libsvn_client/externals.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/info.lo: subversion/libsvn_client/info.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/list.lo: subversion/libsvn_client/list.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/locking_commands.lo: subversion/libsvn_client/locking_commands.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/log.lo: subversion/libsvn_client/log.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_compat.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/merge.lo: subversion/libsvn_client/merge.c subversion/include/private/svn_mergeinfo_private.h subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_dirent_uri.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/libsvn_client/mergeinfo.h subversion/svn_private_config.h

subversion/libsvn_client/mergeinfo.lo: subversion/libsvn_client/mergeinfo.c subversion/include/private/svn_mergeinfo_private.h subversion/include/private/svn_ra_private.h subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_dirent_uri.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/libsvn_client/mergeinfo.h subversion/svn_private_config.h

subversion/libsvn_client/prop_commands.lo: subversion/libsvn_client/prop_commands.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/ra.lo: subversion/libsvn_client/ra.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/libsvn_client/mergeinfo.h subversion/svn_private_config.h

subversion/libsvn_client/relocate.lo: subversion/libsvn_client/relocate.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/repos_diff.lo: subversion/libsvn_client/repos_diff.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h

subversion/libsvn_client/repos_diff_summarize.lo: subversion/libsvn_client/repos_diff_summarize.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h

subversion/libsvn_client/resolved.lo: subversion/libsvn_client/resolved.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h

subversion/libsvn_client/revert.lo: subversion/libsvn_client/revert.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h

subversion/libsvn_client/revisions.lo: subversion/libsvn_client/revisions.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/status.lo: subversion/libsvn_client/status.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/switch.lo: subversion/libsvn_client/switch.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_dirent_uri.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/update.lo: subversion/libsvn_client/update.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_dirent_uri.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/url.lo: subversion/libsvn_client/url.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/util.lo: subversion/libsvn_client/util.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/client.h subversion/svn_private_config.h

subversion/libsvn_client/version.lo: subversion/libsvn_client/version.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h

subversion/libsvn_delta/cancel.lo: subversion/libsvn_delta/cancel.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h

subversion/libsvn_delta/compat.lo: subversion/libsvn_delta/compat.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h

subversion/libsvn_delta/compose_delta.lo: subversion/libsvn_delta/compose_delta.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_delta/delta.h

subversion/libsvn_delta/debug_editor.lo: subversion/libsvn_delta/debug_editor.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_delta/debug_editor.h

subversion/libsvn_delta/default_editor.lo: subversion/libsvn_delta/default_editor.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h

subversion/libsvn_delta/depth_filter_editor.lo: subversion/libsvn_delta/depth_filter_editor.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h

subversion/libsvn_delta/path_driver.lo: subversion/libsvn_delta/path_driver.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h

subversion/libsvn_delta/svndiff.lo: subversion/libsvn_delta/svndiff.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_delta/delta.h subversion/svn_private_config.h

subversion/libsvn_delta/text_delta.lo: subversion/libsvn_delta/text_delta.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_delta/delta.h

subversion/libsvn_delta/version.lo: subversion/libsvn_delta/version.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h

subversion/libsvn_delta/xdelta.lo: subversion/libsvn_delta/xdelta.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_delta/delta.h

subversion/libsvn_diff/deprecated.lo: subversion/libsvn_diff/deprecated.c subversion/include/svn_checksum.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/svn_private_config.h

subversion/libsvn_diff/diff.lo: subversion/libsvn_diff/diff.c subversion/include/svn_checksum.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_diff/diff.h

subversion/libsvn_diff/diff3.lo: subversion/libsvn_diff/diff3.c subversion/include/svn_checksum.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_diff/diff.h

subversion/libsvn_diff/diff4.lo: subversion/libsvn_diff/diff4.c subversion/include/svn_checksum.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_diff/diff.h

subversion/libsvn_diff/diff_file.lo: subversion/libsvn_diff/diff_file.c subversion/include/private/svn_utf_private.h subversion/include/svn_checksum.h subversion/include/svn_ctype.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/libsvn_diff/diff.h subversion/svn_private_config.h

subversion/libsvn_diff/diff_memory.lo: subversion/libsvn_diff/diff_memory.c subversion/include/svn_checksum.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/libsvn_diff/diff.h subversion/svn_private_config.h

subversion/libsvn_diff/lcs.lo: subversion/libsvn_diff/lcs.c subversion/include/svn_checksum.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_diff/diff.h

subversion/libsvn_diff/token.lo: subversion/libsvn_diff/token.c subversion/include/svn_checksum.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_diff/diff.h

subversion/libsvn_diff/util.lo: subversion/libsvn_diff/util.c subversion/include/svn_checksum.h subversion/include/svn_ctype.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_diff/diff.h

subversion/libsvn_fs/access.lo: subversion/libsvn_fs/access.c subversion/include/private/svn_fs_private.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h

subversion/libsvn_fs/fs-loader.lo: subversion/libsvn_fs/fs-loader.c subversion/include/private/svn_fs_util.h subversion/include/private/svn_utf_private.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_dso.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_fs/fs-loader.h subversion/svn_private_config.h

subversion/libsvn_fs_base/bdb/bdb-err.lo: subversion/libsvn_fs_base/bdb/bdb-err.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/svn_private_config.h

subversion/libsvn_fs_base/bdb/bdb_compat.lo: subversion/libsvn_fs_base/bdb/bdb_compat.c subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/svn_private_config.h

subversion/libsvn_fs_base/bdb/changes-table.lo: subversion/libsvn_fs_base/bdb/changes-table.c subversion/include/private/svn_fs_util.h subversion/include/private/svn_skel.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/changes-table.h subversion/libsvn_fs_base/bdb/dbt.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/id.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/util/fs_skels.h subversion/svn_private_config.h

subversion/libsvn_fs_base/bdb/checksum-reps-table.lo: subversion/libsvn_fs_base/bdb/checksum-reps-table.c subversion/include/private/svn_skel.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/checksum-reps-table.h subversion/libsvn_fs_base/bdb/dbt.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/key-gen.h subversion/libsvn_fs_base/trail.h subversion/svn_private_config.h

subversion/libsvn_fs_base/bdb/copies-table.lo: subversion/libsvn_fs_base/bdb/copies-table.c subversion/include/private/svn_skel.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/copies-table.h subversion/libsvn_fs_base/bdb/dbt.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/rev-table.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/key-gen.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/util/fs_skels.h subversion/svn_private_config.h

subversion/libsvn_fs_base/bdb/dbt.lo: subversion/libsvn_fs_base/bdb/dbt.c subversion/include/private/svn_skel.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs_base/bdb/dbt.h subversion/libsvn_fs_base/id.h subversion/svn_private_config.h

subversion/libsvn_fs_base/bdb/env.lo: subversion/libsvn_fs_base/bdb/env.c subversion/include/private/svn_atomic.h subversion/include/private/svn_dep_compat.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/env.h subversion/svn_private_config.h

subversion/libsvn_fs_base/bdb/lock-tokens-table.lo: subversion/libsvn_fs_base/bdb/lock-tokens-table.c subversion/include/private/svn_fs_util.h subversion/include/private/svn_skel.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/dbt.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/lock-tokens-table.h subversion/libsvn_fs_base/bdb/locks-table.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/util/fs_skels.h subversion/svn_private_config.h

subversion/libsvn_fs_base/bdb/locks-table.lo: subversion/libsvn_fs_base/bdb/locks-table.c subversion/include/private/svn_fs_util.h subversion/include/private/svn_skel.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/dbt.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/lock-tokens-table.h subversion/libsvn_fs_base/bdb/locks-table.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/util/fs_skels.h subversion/svn_private_config.h

subversion/libsvn_fs_base/bdb/miscellaneous-table.lo: subversion/libsvn_fs_base/bdb/miscellaneous-table.c subversion/include/private/svn_fs_util.h subversion/include/private/svn_skel.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/dbt.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/miscellaneous-table.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/trail.h subversion/svn_private_config.h

subversion/libsvn_fs_base/bdb/node-origins-table.lo: subversion/libsvn_fs_base/bdb/node-origins-table.c subversion/include/private/svn_skel.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/dbt.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/node-origins-table.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/id.h subversion/libsvn_fs_base/trail.h subversion/svn_private_config.h

subversion/libsvn_fs_base/bdb/nodes-table.lo: subversion/libsvn_fs_base/bdb/nodes-table.c subversion/include/private/svn_skel.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/dbt.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/nodes-table.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/id.h subversion/libsvn_fs_base/key-gen.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/util/fs_skels.h subversion/svn_private_config.h

subversion/libsvn_fs_base/bdb/reps-table.lo: subversion/libsvn_fs_base/bdb/reps-table.c subversion/include/private/svn_skel.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/dbt.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/reps-table.h subversion/libsvn_fs_base/bdb/strings-table.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/key-gen.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/util/fs_skels.h subversion/svn_private_config.h

subversion/libsvn_fs_base/bdb/rev-table.lo: subversion/libsvn_fs_base/bdb/rev-table.c subversion/include/private/svn_fs_util.h subversion/include/private/svn_skel.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/dbt.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/rev-table.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/util/fs_skels.h subversion/svn_private_config.h

subversion/libsvn_fs_base/bdb/strings-table.lo: subversion/libsvn_fs_base/bdb/strings-table.c subversion/include/private/svn_skel.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/dbt.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/strings-table.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/key-gen.h subversion/libsvn_fs_base/trail.h subversion/svn_private_config.h

subversion/libsvn_fs_base/bdb/txn-table.lo: subversion/libsvn_fs_base/bdb/txn-table.c subversion/include/private/svn_skel.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/dbt.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/txn-table.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/key-gen.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/util/fs_skels.h subversion/svn_private_config.h

subversion/libsvn_fs_base/bdb/uuids-table.lo: subversion/libsvn_fs_base/bdb/uuids-table.c subversion/include/private/svn_skel.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/dbt.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/uuids-table.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/trail.h subversion/svn_private_config.h

subversion/libsvn_fs_base/dag.lo: subversion/libsvn_fs_base/dag.c subversion/include/private/svn_fs_util.h subversion/include/private/svn_skel.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/checksum-reps-table.h subversion/libsvn_fs_base/bdb/copies-table.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/nodes-table.h subversion/libsvn_fs_base/bdb/reps-table.h subversion/libsvn_fs_base/bdb/rev-table.h subversion/libsvn_fs_base/bdb/strings-table.h subversion/libsvn_fs_base/bdb/txn-table.h subversion/libsvn_fs_base/dag.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/id.h subversion/libsvn_fs_base/key-gen.h subversion/libsvn_fs_base/node-rev.h subversion/libsvn_fs_base/reps-strings.h subversion/libsvn_fs_base/revs-txns.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/util/fs_skels.h subversion/svn_private_config.h

subversion/libsvn_fs_base/err.lo: subversion/libsvn_fs_base/err.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/id.h subversion/svn_private_config.h

subversion/libsvn_fs_base/fs.lo: subversion/libsvn_fs_base/fs.c subversion/include/private/svn_fs_util.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/changes-table.h subversion/libsvn_fs_base/bdb/checksum-reps-table.h subversion/libsvn_fs_base/bdb/copies-table.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/lock-tokens-table.h subversion/libsvn_fs_base/bdb/locks-table.h subversion/libsvn_fs_base/bdb/miscellaneous-table.h subversion/libsvn_fs_base/bdb/node-origins-table.h subversion/libsvn_fs_base/bdb/nodes-table.h subversion/libsvn_fs_base/bdb/reps-table.h subversion/libsvn_fs_base/bdb/rev-table.h subversion/libsvn_fs_base/bdb/strings-table.h subversion/libsvn_fs_base/bdb/txn-table.h subversion/libsvn_fs_base/bdb/uuids-table.h subversion/libsvn_fs_base/dag.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/id.h subversion/libsvn_fs_base/lock.h subversion/libsvn_fs_base/revs-txns.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/tree.h subversion/libsvn_fs_base/uuid.h subversion/svn_private_config.h

subversion/libsvn_fs_base/id.lo: subversion/libsvn_fs_base/id.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/id.h

subversion/libsvn_fs_base/key-gen.lo: subversion/libsvn_fs_base/key-gen.c subversion/include/private/svn_skel.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/libsvn_fs_base/key-gen.h

subversion/libsvn_fs_base/lock.lo: subversion/libsvn_fs_base/lock.c subversion/include/private/svn_fs_util.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/lock-tokens-table.h subversion/libsvn_fs_base/bdb/locks-table.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/lock.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/tree.h subversion/svn_private_config.h

subversion/libsvn_fs_base/node-rev.lo: subversion/libsvn_fs_base/node-rev.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/node-origins-table.h subversion/libsvn_fs_base/bdb/nodes-table.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/id.h subversion/libsvn_fs_base/node-rev.h subversion/libsvn_fs_base/reps-strings.h subversion/libsvn_fs_base/trail.h subversion/svn_private_config.h

subversion/libsvn_fs_base/reps-strings.lo: subversion/libsvn_fs_base/reps-strings.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/reps-table.h subversion/libsvn_fs_base/bdb/strings-table.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/reps-strings.h subversion/libsvn_fs_base/trail.h subversion/svn_private_config.h

subversion/libsvn_fs_base/revs-txns.lo: subversion/libsvn_fs_base/revs-txns.c subversion/include/private/svn_fs_util.h subversion/include/private/svn_skel.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/changes-table.h subversion/libsvn_fs_base/bdb/copies-table.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/rev-table.h subversion/libsvn_fs_base/bdb/txn-table.h subversion/libsvn_fs_base/dag.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/id.h subversion/libsvn_fs_base/key-gen.h subversion/libsvn_fs_base/revs-txns.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/tree.h subversion/svn_private_config.h

subversion/libsvn_fs_base/trail.lo: subversion/libsvn_fs_base/trail.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb-err.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/trail.h subversion/svn_private_config.h

subversion/libsvn_fs_base/tree.lo: subversion/libsvn_fs_base/tree.c subversion/include/private/svn_fs_util.h subversion/include/private/svn_mergeinfo_private.h subversion/include/private/svn_skel.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/changes-table.h subversion/libsvn_fs_base/bdb/copies-table.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/miscellaneous-table.h subversion/libsvn_fs_base/bdb/node-origins-table.h subversion/libsvn_fs_base/bdb/nodes-table.h subversion/libsvn_fs_base/bdb/rev-table.h subversion/libsvn_fs_base/bdb/txn-table.h subversion/libsvn_fs_base/dag.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/id.h subversion/libsvn_fs_base/key-gen.h subversion/libsvn_fs_base/lock.h subversion/libsvn_fs_base/node-rev.h subversion/libsvn_fs_base/revs-txns.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/tree.h subversion/svn_private_config.h

subversion/libsvn_fs_base/util/fs_skels.lo: subversion/libsvn_fs_base/util/fs_skels.c subversion/include/private/svn_skel.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/id.h subversion/libsvn_fs_base/util/fs_skels.h subversion/svn_private_config.h

subversion/libsvn_fs_base/uuid.lo: subversion/libsvn_fs_base/uuid.c subversion/include/private/svn_fs_util.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/uuids-table.h subversion/libsvn_fs_base/err.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/uuid.h subversion/svn_private_config.h

subversion/libsvn_fs_fs/caching.lo: subversion/libsvn_fs_fs/caching.c subversion/include/private/svn_atomic.h subversion/include/private/svn_cache.h subversion/include/private/svn_dep_compat.h subversion/include/private/svn_fs_private.h subversion/include/private/svn_sqlite.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_iter.h subversion/include/svn_mergeinfo.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_fs/dag.h subversion/libsvn_fs_fs/fs.h subversion/libsvn_fs_fs/fs_fs.h subversion/libsvn_fs_fs/id.h subversion/svn_private_config.h

subversion/libsvn_fs_fs/dag.lo: subversion/libsvn_fs_fs/dag.c subversion/include/private/svn_atomic.h subversion/include/private/svn_cache.h subversion/include/private/svn_dep_compat.h subversion/include/private/svn_fs_private.h subversion/include/private/svn_sqlite.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_iter.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_fs/dag.h subversion/libsvn_fs_fs/err.h subversion/libsvn_fs_fs/fs.h subversion/libsvn_fs_fs/fs_fs.h subversion/libsvn_fs_fs/id.h subversion/libsvn_fs_fs/key-gen.h subversion/svn_private_config.h

subversion/libsvn_fs_fs/err.lo: subversion/libsvn_fs_fs/err.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_fs/err.h subversion/libsvn_fs_fs/id.h subversion/svn_private_config.h

subversion/libsvn_fs_fs/fs.lo: subversion/libsvn_fs_fs/fs.c subversion/include/private/svn_atomic.h subversion/include/private/svn_cache.h subversion/include/private/svn_dep_compat.h subversion/include/private/svn_fs_private.h subversion/include/private/svn_fs_util.h subversion/include/private/svn_sqlite.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_iter.h subversion/include/svn_mergeinfo.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_fs/err.h subversion/libsvn_fs_fs/fs.h subversion/libsvn_fs_fs/fs_fs.h subversion/libsvn_fs_fs/id.h subversion/libsvn_fs_fs/lock.h subversion/libsvn_fs_fs/tree.h subversion/svn_private_config.h

subversion/libsvn_fs_fs/fs_fs.lo: subversion/libsvn_fs_fs/fs_fs.c subversion/include/private/svn_atomic.h subversion/include/private/svn_cache.h subversion/include/private/svn_dep_compat.h subversion/include/private/svn_fs_private.h subversion/include/private/svn_fs_util.h subversion/include/private/svn_sqlite.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_dirent_uri.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_iter.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_fs/err.h subversion/libsvn_fs_fs/fs.h subversion/libsvn_fs_fs/fs_fs.h subversion/libsvn_fs_fs/id.h subversion/libsvn_fs_fs/key-gen.h subversion/libsvn_fs_fs/lock.h subversion/libsvn_fs_fs/rep-cache.h subversion/libsvn_fs_fs/tree.h subversion/svn_private_config.h

subversion/libsvn_fs_fs/id.lo: subversion/libsvn_fs_fs/id.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_fs/id.h

subversion/libsvn_fs_fs/key-gen.lo: subversion/libsvn_fs_fs/key-gen.c subversion/include/private/svn_fs_private.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs_fs/key-gen.h

subversion/libsvn_fs_fs/lock.lo: subversion/libsvn_fs_fs/lock.c subversion/include/private/svn_atomic.h subversion/include/private/svn_cache.h subversion/include/private/svn_dep_compat.h subversion/include/private/svn_fs_private.h subversion/include/private/svn_fs_util.h subversion/include/private/svn_sqlite.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_iter.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_fs/err.h subversion/libsvn_fs_fs/fs.h subversion/libsvn_fs_fs/fs_fs.h subversion/libsvn_fs_fs/lock.h subversion/libsvn_fs_fs/tree.h subversion/svn_private_config.h

subversion/libsvn_fs_fs/rep-cache.lo: subversion/libsvn_fs_fs/rep-cache.c subversion/include/private/svn_atomic.h subversion/include/private/svn_cache.h subversion/include/private/svn_dep_compat.h subversion/include/private/svn_fs_private.h subversion/include/private/svn_sqlite.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_iter.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_fs/fs.h subversion/libsvn_fs_fs/fs_fs.h subversion/libsvn_fs_fs/rep-cache-db.h subversion/libsvn_fs_fs/rep-cache.h subversion/svn_private_config.h

subversion/libsvn_fs_fs/tree.lo: subversion/libsvn_fs_fs/tree.c subversion/include/private/svn_atomic.h subversion/include/private/svn_cache.h subversion/include/private/svn_dep_compat.h subversion/include/private/svn_fs_private.h subversion/include/private/svn_fs_util.h subversion/include/private/svn_mergeinfo_private.h subversion/include/private/svn_sqlite.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_iter.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_fs/dag.h subversion/libsvn_fs_fs/err.h subversion/libsvn_fs_fs/fs.h subversion/libsvn_fs_fs/fs_fs.h subversion/libsvn_fs_fs/id.h subversion/libsvn_fs_fs/key-gen.h subversion/libsvn_fs_fs/lock.h subversion/libsvn_fs_fs/tree.h subversion/svn_private_config.h

subversion/libsvn_fs_util/fs-util.lo: subversion/libsvn_fs_util/fs-util.c subversion/include/private/svn_fs_util.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/svn_private_config.h

subversion/libsvn_ra/compat.lo: subversion/libsvn_ra/compat.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_compat.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_ra/ra_loader.h subversion/svn_private_config.h

subversion/libsvn_ra/deprecated.lo: subversion/libsvn_ra/deprecated.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_compat.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_ra/ra_loader.h subversion/svn_private_config.h

subversion/libsvn_ra/ra_loader.lo: subversion/libsvn_ra/ra_loader.c subversion/include/private/svn_ra_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_dso.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/svn_private_config.h

subversion/libsvn_ra/util.lo: subversion/libsvn_ra/util.c subversion/include/private/svn_ra_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/svn_private_config.h

subversion/libsvn_ra_local/ra_plugin.lo: subversion/libsvn_ra_local/ra_plugin.c subversion/include/private/svn_mergeinfo_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_compat.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra/wrapper_template.h subversion/libsvn_ra_local/ra_local.h subversion/svn_private_config.h

subversion/libsvn_ra_local/split_url.lo: subversion/libsvn_ra_local/split_url.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_ra_local/ra_local.h subversion/svn_private_config.h

subversion/libsvn_ra_neon/commit.lo: subversion/libsvn_ra_neon/commit.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_neon/ra_neon.h subversion/svn_private_config.h

subversion/libsvn_ra_neon/fetch.lo: subversion/libsvn_ra_neon/fetch.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_base64.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_neon/ra_neon.h subversion/svn_private_config.h

subversion/libsvn_ra_neon/file_revs.lo: subversion/libsvn_ra_neon/file_revs.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_base64.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_neon/ra_neon.h subversion/svn_private_config.h

subversion/libsvn_ra_neon/get_dated_rev.lo: subversion/libsvn_ra_neon/get_dated_rev.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_neon/ra_neon.h subversion/svn_private_config.h

subversion/libsvn_ra_neon/get_deleted_rev.lo: subversion/libsvn_ra_neon/get_deleted_rev.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_neon/ra_neon.h subversion/svn_private_config.h

subversion/libsvn_ra_neon/get_location_segments.lo: subversion/libsvn_ra_neon/get_location_segments.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_neon/ra_neon.h subversion/svn_private_config.h

subversion/libsvn_ra_neon/get_locations.lo: subversion/libsvn_ra_neon/get_locations.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_neon/ra_neon.h subversion/svn_private_config.h

subversion/libsvn_ra_neon/get_locks.lo: subversion/libsvn_ra_neon/get_locks.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_base64.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_neon/ra_neon.h subversion/svn_private_config.h

subversion/libsvn_ra_neon/lock.lo: subversion/libsvn_ra_neon/lock.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_neon/ra_neon.h subversion/svn_private_config.h

subversion/libsvn_ra_neon/log.lo: subversion/libsvn_ra_neon/log.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_neon/ra_neon.h subversion/svn_private_config.h

subversion/libsvn_ra_neon/merge.lo: subversion/libsvn_ra_neon/merge.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra_neon/ra_neon.h subversion/svn_private_config.h

subversion/libsvn_ra_neon/mergeinfo.lo: subversion/libsvn_ra_neon/mergeinfo.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_neon/ra_neon.h subversion/svn_private_config.h

subversion/libsvn_ra_neon/options.lo: subversion/libsvn_ra_neon/options.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_neon/ra_neon.h subversion/svn_private_config.h

subversion/libsvn_ra_neon/props.lo: subversion/libsvn_ra_neon/props.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_base64.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_neon/ra_neon.h subversion/svn_private_config.h

subversion/libsvn_ra_neon/replay.lo: subversion/libsvn_ra_neon/replay.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_base64.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_neon/ra_neon.h subversion/svn_private_config.h

subversion/libsvn_ra_neon/session.lo: subversion/libsvn_ra_neon/session.c subversion/include/private/svn_atomic.h subversion/include/private/svn_dav_protocol.h subversion/include/private/svn_dep_compat.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_compat.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra/wrapper_template.h subversion/libsvn_ra_neon/ra_neon.h subversion/svn_private_config.h

subversion/libsvn_ra_neon/util.lo: subversion/libsvn_ra_neon/util.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra_neon/ra_neon.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/auth.lo: subversion/libsvn_ra_serf/auth.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_ra_serf/ra_serf.h subversion/libsvn_ra_serf/win32_auth_sspi.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/blame.lo: subversion/libsvn_ra_serf/blame.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_base64.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/commit.lo: subversion/libsvn_ra_serf/commit.c subversion/include/private/svn_dav_protocol.h subversion/include/private/svn_dep_compat.h subversion/include/svn_auth.h subversion/include/svn_base64.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/get_deleted_rev.lo: subversion/libsvn_ra_serf/get_deleted_rev.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/getdate.lo: subversion/libsvn_ra_serf/getdate.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/getlocations.lo: subversion/libsvn_ra_serf/getlocations.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/getlocationsegments.lo: subversion/libsvn_ra_serf/getlocationsegments.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/getlocks.lo: subversion/libsvn_ra_serf/getlocks.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/locks.lo: subversion/libsvn_ra_serf/locks.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/log.lo: subversion/libsvn_ra_serf/log.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/merge.lo: subversion/libsvn_ra_serf/merge.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/mergeinfo.lo: subversion/libsvn_ra_serf/mergeinfo.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/options.lo: subversion/libsvn_ra_serf/options.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/property.lo: subversion/libsvn_ra_serf/property.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_base64.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/replay.lo: subversion/libsvn_ra_serf/replay.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_base64.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/serf.lo: subversion/libsvn_ra_serf/serf.c subversion/include/private/svn_dav_protocol.h subversion/include/private/svn_dep_compat.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_compat.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra/wrapper_template.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/update.lo: subversion/libsvn_ra_serf/update.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_base64.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/util.lo: subversion/libsvn_ra_serf/util.c subversion/include/private/svn_dav_protocol.h subversion/include/private/svn_dep_compat.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_serf/win32_auth_sspi.lo: subversion/libsvn_ra_serf/win32_auth_sspi.c subversion/include/private/svn_atomic.h subversion/include/private/svn_dav_protocol.h subversion/include/private/svn_dep_compat.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_ra_serf/ra_serf.h subversion/libsvn_ra_serf/win32_auth_sspi.h

subversion/libsvn_ra_serf/xml.lo: subversion/libsvn_ra_serf/xml.c subversion/include/private/svn_dav_protocol.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra_serf/ra_serf.h subversion/svn_private_config.h

subversion/libsvn_ra_svn/client.lo: subversion/libsvn_ra_svn/client.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_compat.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_ra_svn.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_ra/ra_loader.h subversion/libsvn_ra/wrapper_template.h subversion/libsvn_ra_svn/ra_svn.h subversion/svn_private_config.h

subversion/libsvn_ra_svn/cram.lo: subversion/libsvn_ra_svn/cram.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_ra.h subversion/include/svn_ra_svn.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_ra_svn/ra_svn.h subversion/svn_private_config.h

subversion/libsvn_ra_svn/cyrus_auth.lo: subversion/libsvn_ra_svn/cyrus_auth.c subversion/include/private/ra_svn_sasl.h subversion/include/private/svn_atomic.h subversion/include/private/svn_dep_compat.h subversion/include/svn_auth.h subversion/include/svn_base64.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_ra_svn.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_ra_svn/ra_svn.h subversion/svn_private_config.h

subversion/libsvn_ra_svn/editorp.lo: subversion/libsvn_ra_svn/editorp.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_ra_svn.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_ra_svn/ra_svn.h subversion/svn_private_config.h

subversion/libsvn_ra_svn/internal_auth.lo: subversion/libsvn_ra_svn/internal_auth.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_ra.h subversion/include/svn_ra_svn.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_ra_svn/ra_svn.h subversion/svn_private_config.h

subversion/libsvn_ra_svn/marshal.lo: subversion/libsvn_ra_svn/marshal.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_ra_svn.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_ra_svn/ra_svn.h subversion/svn_private_config.h

subversion/libsvn_ra_svn/streams.lo: subversion/libsvn_ra_svn/streams.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_ra_svn.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_ra_svn/ra_svn.h subversion/svn_private_config.h

subversion/libsvn_ra_svn/version.lo: subversion/libsvn_ra_svn/version.c subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_ra_svn.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h

subversion/libsvn_repos/authz.lo: subversion/libsvn_repos/authz.c subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_ctype.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h

subversion/libsvn_repos/commit.lo: subversion/libsvn_repos/commit.c subversion/include/private/svn_repos_private.h subversion/include/svn_checksum.h subversion/include/svn_compat.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_repos/repos.h subversion/svn_private_config.h

subversion/libsvn_repos/delta.lo: subversion/libsvn_repos/delta.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_repos/repos.h subversion/svn_private_config.h

subversion/libsvn_repos/deprecated.lo: subversion/libsvn_repos/deprecated.c subversion/include/svn_checksum.h subversion/include/svn_compat.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/svn_private_config.h

subversion/libsvn_repos/dump.lo: subversion/libsvn_repos/dump.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_iter.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/svn_private_config.h

subversion/libsvn_repos/fs-wrap.lo: subversion/libsvn_repos/fs-wrap.c subversion/include/private/svn_utf_private.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_repos/repos.h subversion/svn_private_config.h

subversion/libsvn_repos/hooks.lo: subversion/libsvn_repos/hooks.c subversion/include/private/svn_fs_private.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/libsvn_repos/repos.h subversion/svn_private_config.h

subversion/libsvn_repos/load.lo: subversion/libsvn_repos/load.c subversion/include/private/svn_mergeinfo_private.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_repos/repos.h subversion/svn_private_config.h

subversion/libsvn_repos/log.lo: subversion/libsvn_repos/log.c subversion/include/private/svn_mergeinfo_private.h subversion/include/svn_checksum.h subversion/include/svn_compat.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_repos/repos.h subversion/svn_private_config.h

subversion/libsvn_repos/node_tree.lo: subversion/libsvn_repos/node_tree.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_repos/repos.h subversion/svn_private_config.h

subversion/libsvn_repos/replay.lo: subversion/libsvn_repos/replay.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/svn_private_config.h

subversion/libsvn_repos/reporter.lo: subversion/libsvn_repos/reporter.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_repos/repos.h subversion/svn_private_config.h

subversion/libsvn_repos/repos.lo: subversion/libsvn_repos/repos.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_dirent_uri.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/libsvn_repos/repos.h subversion/svn_private_config.h

subversion/libsvn_repos/rev_hunt.lo: subversion/libsvn_repos/rev_hunt.c subversion/include/svn_checksum.h subversion/include/svn_compat.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_repos/repos.h subversion/svn_private_config.h

subversion/libsvn_subr/atomic.lo: subversion/libsvn_subr/atomic.c subversion/include/private/svn_atomic.h subversion/include/private/svn_dep_compat.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_types.h

subversion/libsvn_subr/auth.lo: subversion/libsvn_subr/auth.c subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_dso.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/svn_private_config.h

subversion/libsvn_subr/cache-inprocess.lo: subversion/libsvn_subr/cache-inprocess.c subversion/include/private/svn_cache.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_iter.h subversion/include/svn_pools.h subversion/include/svn_types.h subversion/libsvn_subr/cache.h subversion/svn_private_config.h

subversion/libsvn_subr/cache-memcache.lo: subversion/libsvn_subr/cache-memcache.c subversion/include/private/svn_cache.h subversion/include/svn_base64.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_iter.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/libsvn_subr/cache.h subversion/svn_private_config.h

subversion/libsvn_subr/cache.lo: subversion/libsvn_subr/cache.c subversion/include/private/svn_cache.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_iter.h subversion/include/svn_types.h subversion/libsvn_subr/cache.h

subversion/libsvn_subr/checksum.lo: subversion/libsvn_subr/checksum.c subversion/include/svn_checksum.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_types.h subversion/libsvn_subr/md5.h subversion/libsvn_subr/sha1.h

subversion/libsvn_subr/cmdline.lo: subversion/libsvn_subr/cmdline.c subversion/include/private/svn_cmdline_private.h subversion/include/private/svn_utf_private.h subversion/include/svn_auth.h subversion/include/svn_base64.h subversion/include/svn_checksum.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_dso.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_nls.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/libsvn_subr/win32_crashrpt.h subversion/svn_private_config.h

subversion/libsvn_subr/compat.lo: subversion/libsvn_subr/compat.c subversion/include/svn_compat.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h

subversion/libsvn_subr/config.lo: subversion/libsvn_subr/config.c subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/libsvn_subr/config_impl.h subversion/svn_private_config.h

subversion/libsvn_subr/config_auth.lo: subversion/libsvn_subr/config_auth.c subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/libsvn_subr/config_impl.h subversion/svn_private_config.h

subversion/libsvn_subr/config_file.lo: subversion/libsvn_subr/config_file.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_types.h subversion/include/svn_user.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/libsvn_subr/config_impl.h subversion/svn_private_config.h

subversion/libsvn_subr/config_win.lo: subversion/libsvn_subr/config_win.c subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/libsvn_subr/config_impl.h subversion/svn_private_config.h

subversion/libsvn_subr/constructors.lo: subversion/libsvn_subr/constructors.c subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h

subversion/libsvn_subr/ctype.lo: subversion/libsvn_subr/ctype.c subversion/include/svn_ctype.h

subversion/libsvn_subr/date.lo: subversion/libsvn_subr/date.c subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/svn_private_config.h

subversion/libsvn_subr/deprecated.lo: subversion/libsvn_subr/deprecated.c subversion/include/private/svn_opt_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_dso.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_subr/opt.h subversion/svn_private_config.h

subversion/libsvn_subr/dirent_uri.lo: subversion/libsvn_subr/dirent_uri.c subversion/include/svn_dirent_uri.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_path.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/libsvn_subr/private_uri.h subversion/svn_private_config.h

subversion/libsvn_subr/dso.lo: subversion/libsvn_subr/dso.c subversion/include/svn_dso.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_pools.h subversion/include/svn_types.h subversion/svn_private_config.h

subversion/libsvn_subr/error.lo: subversion/libsvn_subr/error.c subversion/include/svn_auth.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/svn_private_config.h

subversion/libsvn_subr/hash.lo: subversion/libsvn_subr/hash.c subversion/include/private/svn_dep_compat.h subversion/include/svn_checksum.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_types.h

subversion/libsvn_subr/io.lo: subversion/libsvn_subr/io.c subversion/include/private/svn_atomic.h subversion/include/private/svn_dep_compat.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dirent_uri.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/svn_private_config.h

subversion/libsvn_subr/iter.lo: subversion/libsvn_subr/iter.c subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_iter.h subversion/include/svn_pools.h subversion/include/svn_types.h

subversion/libsvn_subr/kitchensink.lo: subversion/libsvn_subr/kitchensink.c subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_mergeinfo.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/svn_private_config.h

subversion/libsvn_subr/lock.lo: subversion/libsvn_subr/lock.c subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_types.h

subversion/libsvn_subr/log.lo: subversion/libsvn_subr/log.c subversion/include/private/svn_log.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h

subversion/libsvn_subr/macos_keychain.lo: subversion/libsvn_subr/macos_keychain.c subversion/include/private/svn_auth_private.h subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_user.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/svn_private_config.h

subversion/libsvn_subr/md5.lo: subversion/libsvn_subr/md5.c subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_md5.h subversion/include/svn_types.h subversion/libsvn_subr/md5.h

subversion/libsvn_subr/mergeinfo.lo: subversion/libsvn_subr/mergeinfo.c subversion/include/private/svn_mergeinfo_private.h subversion/include/svn_checksum.h subversion/include/svn_ctype.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/svn_private_config.h

subversion/libsvn_subr/nls.lo: subversion/libsvn_subr/nls.c subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_nls.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/svn_private_config.h

subversion/libsvn_subr/opt.lo: subversion/libsvn_subr/opt.c subversion/include/private/svn_opt_private.h subversion/include/svn_auth.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/libsvn_subr/opt.h subversion/svn_private_config.h

subversion/libsvn_subr/path.lo: subversion/libsvn_subr/path.c subversion/include/svn_checksum.h subversion/include/svn_ctype.h subversion/include/svn_dirent_uri.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/libsvn_subr/private_uri.h subversion/svn_private_config.h

subversion/libsvn_subr/pool.lo: subversion/libsvn_subr/pool.c subversion/include/svn_pools.h

subversion/libsvn_subr/prompt.lo: subversion/libsvn_subr/prompt.c subversion/include/private/svn_cmdline_private.h subversion/include/svn_auth.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_path.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/svn_private_config.h

subversion/libsvn_subr/properties.lo: subversion/libsvn_subr/properties.c subversion/include/svn_ctype.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_props.h subversion/include/svn_string.h subversion/include/svn_types.h

subversion/libsvn_subr/quoprint.lo: subversion/libsvn_subr/quoprint.c subversion/include/svn_checksum.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_quoprint.h subversion/include/svn_string.h subversion/include/svn_types.h

subversion/libsvn_subr/sha1.lo: subversion/libsvn_subr/sha1.c subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_types.h subversion/libsvn_subr/sha1.h

subversion/libsvn_subr/simple_providers.lo: subversion/libsvn_subr/simple_providers.c subversion/include/private/svn_auth_private.h subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_user.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/svn_private_config.h

subversion/libsvn_subr/skel.lo: subversion/libsvn_subr/skel.c subversion/include/private/svn_skel.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_string.h subversion/include/svn_types.h

subversion/libsvn_subr/sorts.lo: subversion/libsvn_subr/sorts.c subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_path.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_types.h

subversion/libsvn_subr/sqlite.lo: subversion/libsvn_subr/sqlite.c subversion/include/private/svn_atomic.h subversion/include/private/svn_dep_compat.h subversion/include/private/svn_sqlite.h subversion/include/svn_checksum.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/svn_private_config.h

subversion/libsvn_subr/ssl_client_cert_providers.lo: subversion/libsvn_subr/ssl_client_cert_providers.c subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_types.h subversion/include/svn_version.h

subversion/libsvn_subr/ssl_client_cert_pw_providers.lo: subversion/libsvn_subr/ssl_client_cert_pw_providers.c subversion/include/private/svn_auth_private.h subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/svn_private_config.h

subversion/libsvn_subr/ssl_server_trust_providers.lo: subversion/libsvn_subr/ssl_server_trust_providers.c subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h

subversion/libsvn_subr/stream.lo: subversion/libsvn_subr/stream.c subversion/include/svn_checksum.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/svn_private_config.h

subversion/libsvn_subr/subst.lo: subversion/libsvn_subr/subst.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/svn_private_config.h

subversion/libsvn_subr/svn_base64.lo: subversion/libsvn_subr/svn_base64.c subversion/include/svn_base64.h subversion/include/svn_checksum.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h

subversion/libsvn_subr/svn_string.lo: subversion/libsvn_subr/svn_string.c subversion/include/svn_ctype.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_string.h subversion/include/svn_types.h

subversion/libsvn_subr/target.lo: subversion/libsvn_subr/target.c subversion/include/svn_dirent_uri.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h

subversion/libsvn_subr/time.lo: subversion/libsvn_subr/time.c subversion/include/svn_checksum.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/svn_private_config.h

subversion/libsvn_subr/user.lo: subversion/libsvn_subr/user.c subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_user.h subversion/include/svn_utf.h

subversion/libsvn_subr/username_providers.lo: subversion/libsvn_subr/username_providers.c subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_user.h subversion/include/svn_utf.h subversion/include/svn_version.h

subversion/libsvn_subr/utf.lo: subversion/libsvn_subr/utf.c subversion/include/private/svn_utf_private.h subversion/include/svn_ctype.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/libsvn_subr/win32_xlate.h subversion/svn_private_config.h

subversion/libsvn_subr/utf_validate.lo: subversion/libsvn_subr/utf_validate.c subversion/include/private/svn_utf_private.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_types.h

subversion/libsvn_subr/validate.lo: subversion/libsvn_subr/validate.c subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_types.h subversion/svn_private_config.h

subversion/libsvn_subr/version.lo: subversion/libsvn_subr/version.c subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/svn_private_config.h

subversion/libsvn_subr/win32_crashrpt.lo: subversion/libsvn_subr/win32_crashrpt.c subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_subr/win32_crashrpt.h subversion/libsvn_subr/win32_crashrpt_dll.h

subversion/libsvn_subr/win32_crypto.lo: subversion/libsvn_subr/win32_crypto.c subversion/include/private/svn_auth_private.h subversion/include/svn_auth.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_user.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/svn_private_config.h

subversion/libsvn_subr/win32_xlate.lo: subversion/libsvn_subr/win32_xlate.c subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/libsvn_subr/win32_xlate.h

subversion/libsvn_subr/xml.lo: subversion/libsvn_subr/xml.c subversion/include/private/svn_utf_private.h subversion/include/svn_ctype.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_xml.h subversion/svn_private_config.h

subversion/libsvn_wc/adm_crawler.lo: subversion/libsvn_wc/adm_crawler.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_base64.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_wc/adm_files.h subversion/libsvn_wc/entries.h subversion/libsvn_wc/lock.h subversion/libsvn_wc/props.h subversion/libsvn_wc/translate.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/adm_files.lo: subversion/libsvn_wc/adm_files.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_wc/adm_files.h subversion/libsvn_wc/entries.h subversion/libsvn_wc/lock.h subversion/libsvn_wc/props.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/adm_ops.lo: subversion/libsvn_wc/adm_ops.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_dirent_uri.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/libsvn_wc/adm_files.h subversion/libsvn_wc/adm_ops.h subversion/libsvn_wc/entries.h subversion/libsvn_wc/lock.h subversion/libsvn_wc/log.h subversion/libsvn_wc/props.h subversion/libsvn_wc/translate.h subversion/libsvn_wc/tree_conflicts.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/ambient_depth_filter_editor.lo: subversion/libsvn_wc/ambient_depth_filter_editor.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_wc/wc.h

subversion/libsvn_wc/copy.lo: subversion/libsvn_wc/copy.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_dirent_uri.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_wc/adm_files.h subversion/libsvn_wc/entries.h subversion/libsvn_wc/props.h subversion/libsvn_wc/translate.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/crop.lo: subversion/libsvn_wc/crop.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_wc/entries.h subversion/libsvn_wc/lock.h subversion/svn_private_config.h

subversion/libsvn_wc/deprecated.lo: subversion/libsvn_wc/deprecated.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/diff.lo: subversion/libsvn_wc/diff.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_wc/adm_files.h subversion/libsvn_wc/props.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/entries.lo: subversion/libsvn_wc/entries.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_ctype.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/libsvn_wc/adm_files.h subversion/libsvn_wc/adm_ops.h subversion/libsvn_wc/entries.h subversion/libsvn_wc/lock.h subversion/libsvn_wc/props.h subversion/libsvn_wc/tree_conflicts.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/lock.lo: subversion/libsvn_wc/lock.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_dirent_uri.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_wc/adm_files.h subversion/libsvn_wc/entries.h subversion/libsvn_wc/lock.h subversion/libsvn_wc/log.h subversion/libsvn_wc/props.h subversion/libsvn_wc/questions.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/log.lo: subversion/libsvn_wc/log.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_iter.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/libsvn_wc/adm_files.h subversion/libsvn_wc/entries.h subversion/libsvn_wc/lock.h subversion/libsvn_wc/log.h subversion/libsvn_wc/props.h subversion/libsvn_wc/questions.h subversion/libsvn_wc/translate.h subversion/libsvn_wc/tree_conflicts.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/merge.lo: subversion/libsvn_wc/merge.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_wc/adm_files.h subversion/libsvn_wc/entries.h subversion/libsvn_wc/log.h subversion/libsvn_wc/props.h subversion/libsvn_wc/questions.h subversion/libsvn_wc/translate.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/props.lo: subversion/libsvn_wc/props.c subversion/include/private/svn_mergeinfo_private.h subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/libsvn_wc/adm_files.h subversion/libsvn_wc/entries.h subversion/libsvn_wc/lock.h subversion/libsvn_wc/log.h subversion/libsvn_wc/props.h subversion/libsvn_wc/questions.h subversion/libsvn_wc/translate.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/questions.lo: subversion/libsvn_wc/questions.c subversion/include/private/svn_sqlite.h subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_wc/adm_files.h subversion/libsvn_wc/entries.h subversion/libsvn_wc/props.h subversion/libsvn_wc/questions.h subversion/libsvn_wc/translate.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/relocate.lo: subversion/libsvn_wc/relocate.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_wc/entries.h subversion/libsvn_wc/lock.h subversion/libsvn_wc/props.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/revision_status.lo: subversion/libsvn_wc/revision_status.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn_private_config.h

subversion/libsvn_wc/status.lo: subversion/libsvn_wc/status.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_wc/lock.h subversion/libsvn_wc/props.h subversion/libsvn_wc/translate.h subversion/libsvn_wc/tree_conflicts.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/translate.lo: subversion/libsvn_wc/translate.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_wc/adm_files.h subversion/libsvn_wc/props.h subversion/libsvn_wc/translate.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/tree_conflicts.lo: subversion/libsvn_wc/tree_conflicts.c subversion/include/private/svn_skel.h subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_wc/entries.h subversion/libsvn_wc/log.h subversion/libsvn_wc/tree_conflicts.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/update_editor.lo: subversion/libsvn_wc/update_editor.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_dirent_uri.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_iter.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/libsvn_wc/adm_files.h subversion/libsvn_wc/adm_ops.h subversion/libsvn_wc/entries.h subversion/libsvn_wc/lock.h subversion/libsvn_wc/log.h subversion/libsvn_wc/props.h subversion/libsvn_wc/questions.h subversion/libsvn_wc/translate.h subversion/libsvn_wc/tree_conflicts.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/util.lo: subversion/libsvn_wc/util.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_dirent_uri.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_wc/wc.h subversion/svn_private_config.h

subversion/libsvn_wc/wc_db.lo: subversion/libsvn_wc/wc_db.c subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/libsvn_wc/wc_db.h subversion/svn_private_config.h

subversion/mod_authz_svn/mod_authz_svn.lo: subversion/mod_authz_svn/mod_authz_svn.c subversion/include/mod_authz_svn.h subversion/include/mod_dav_svn.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h
	$(COMPILE_APACHE_MOD) $(canonicalized_srcdir)subversion/mod_authz_svn/mod_authz_svn.c

subversion/mod_dav_svn/activity.lo: subversion/mod_dav_svn/activity.c subversion/include/mod_authz_svn.h subversion/include/private/svn_dav_protocol.h subversion/include/private/svn_fs_private.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(canonicalized_srcdir)subversion/mod_dav_svn/activity.c

subversion/mod_dav_svn/authz.lo: subversion/mod_dav_svn/authz.c subversion/include/mod_authz_svn.h subversion/include/private/svn_dav_protocol.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(canonicalized_srcdir)subversion/mod_dav_svn/authz.c

subversion/mod_dav_svn/deadprops.lo: subversion/mod_dav_svn/deadprops.c subversion/include/mod_authz_svn.h subversion/include/private/svn_dav_protocol.h subversion/include/private/svn_log.h subversion/include/svn_base64.h subversion/include/svn_checksum.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(canonicalized_srcdir)subversion/mod_dav_svn/deadprops.c

subversion/mod_dav_svn/liveprops.lo: subversion/mod_dav_svn/liveprops.c subversion/include/mod_authz_svn.h subversion/include/private/svn_dav_protocol.h subversion/include/svn_checksum.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(canonicalized_srcdir)subversion/mod_dav_svn/liveprops.c

subversion/mod_dav_svn/lock.lo: subversion/mod_dav_svn/lock.c subversion/include/mod_authz_svn.h subversion/include/private/svn_dav_protocol.h subversion/include/private/svn_log.h subversion/include/svn_checksum.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(canonicalized_srcdir)subversion/mod_dav_svn/lock.c

subversion/mod_dav_svn/merge.lo: subversion/mod_dav_svn/merge.c subversion/include/mod_authz_svn.h subversion/include/private/svn_dav_protocol.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(canonicalized_srcdir)subversion/mod_dav_svn/merge.c

subversion/mod_dav_svn/mirror.lo: subversion/mod_dav_svn/mirror.c subversion/include/mod_authz_svn.h subversion/include/private/svn_dav_protocol.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(canonicalized_srcdir)subversion/mod_dav_svn/mirror.c

subversion/mod_dav_svn/mod_dav_svn.lo: subversion/mod_dav_svn/mod_dav_svn.c subversion/include/mod_authz_svn.h subversion/include/mod_dav_svn.h subversion/include/private/svn_dav_protocol.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_dso.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(canonicalized_srcdir)subversion/mod_dav_svn/mod_dav_svn.c

subversion/mod_dav_svn/reports/dated-rev.lo: subversion/mod_dav_svn/reports/dated-rev.c subversion/include/mod_authz_svn.h subversion/include/private/svn_dav_protocol.h subversion/include/svn_base64.h subversion/include/svn_checksum.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(canonicalized_srcdir)subversion/mod_dav_svn/reports/dated-rev.c

subversion/mod_dav_svn/reports/deleted-rev.lo: subversion/mod_dav_svn/reports/deleted-rev.c subversion/include/mod_authz_svn.h subversion/include/private/svn_dav_protocol.h subversion/include/svn_checksum.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(canonicalized_srcdir)subversion/mod_dav_svn/reports/deleted-rev.c

subversion/mod_dav_svn/reports/file-revs.lo: subversion/mod_dav_svn/reports/file-revs.c subversion/include/mod_authz_svn.h subversion/include/private/svn_dav_protocol.h subversion/include/private/svn_log.h subversion/include/svn_base64.h subversion/include/svn_checksum.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(canonicalized_srcdir)subversion/mod_dav_svn/reports/file-revs.c

subversion/mod_dav_svn/reports/get-location-segments.lo: subversion/mod_dav_svn/reports/get-location-segments.c subversion/include/mod_authz_svn.h subversion/include/private/svn_dav_protocol.h subversion/include/svn_base64.h subversion/include/svn_checksum.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(canonicalized_srcdir)subversion/mod_dav_svn/reports/get-location-segments.c

subversion/mod_dav_svn/reports/get-locations.lo: subversion/mod_dav_svn/reports/get-locations.c subversion/include/mod_authz_svn.h subversion/include/private/svn_dav_protocol.h subversion/include/svn_base64.h subversion/include/svn_checksum.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(canonicalized_srcdir)subversion/mod_dav_svn/reports/get-locations.c

subversion/mod_dav_svn/reports/get-locks.lo: subversion/mod_dav_svn/reports/get-locks.c subversion/include/mod_authz_svn.h subversion/include/private/svn_dav_protocol.h subversion/include/svn_base64.h subversion/include/svn_checksum.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(canonicalized_srcdir)subversion/mod_dav_svn/reports/get-locks.c

subversion/mod_dav_svn/reports/log.lo: subversion/mod_dav_svn/reports/log.c subversion/include/mod_authz_svn.h subversion/include/private/svn_dav_protocol.h subversion/include/private/svn_log.h subversion/include/svn_checksum.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(canonicalized_srcdir)subversion/mod_dav_svn/reports/log.c

subversion/mod_dav_svn/reports/mergeinfo.lo: subversion/mod_dav_svn/reports/mergeinfo.c subversion/include/mod_authz_svn.h subversion/include/private/svn_dav_protocol.h subversion/include/private/svn_log.h subversion/include/private/svn_mergeinfo_private.h subversion/include/svn_checksum.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(canonicalized_srcdir)subversion/mod_dav_svn/reports/mergeinfo.c

subversion/mod_dav_svn/reports/replay.lo: subversion/mod_dav_svn/reports/replay.c subversion/include/mod_authz_svn.h subversion/include/private/svn_dav_protocol.h subversion/include/private/svn_log.h subversion/include/svn_base64.h subversion/include/svn_checksum.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(canonicalized_srcdir)subversion/mod_dav_svn/reports/replay.c

subversion/mod_dav_svn/reports/update.lo: subversion/mod_dav_svn/reports/update.c subversion/include/mod_authz_svn.h subversion/include/private/svn_dav_protocol.h subversion/include/private/svn_log.h subversion/include/svn_base64.h subversion/include/svn_checksum.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(canonicalized_srcdir)subversion/mod_dav_svn/reports/update.c

subversion/mod_dav_svn/repos.lo: subversion/mod_dav_svn/repos.c subversion/include/mod_authz_svn.h subversion/include/mod_dav_svn.h subversion/include/private/svn_dav_protocol.h subversion/include/private/svn_log.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(canonicalized_srcdir)subversion/mod_dav_svn/repos.c

subversion/mod_dav_svn/util.lo: subversion/mod_dav_svn/util.c subversion/include/mod_authz_svn.h subversion/include/private/svn_dav_protocol.h subversion/include/svn_base64.h subversion/include/svn_checksum.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(canonicalized_srcdir)subversion/mod_dav_svn/util.c

subversion/mod_dav_svn/version.lo: subversion/mod_dav_svn/version.c subversion/include/mod_authz_svn.h subversion/include/private/svn_dav_protocol.h subversion/include/private/svn_log.h subversion/include/private/svn_repos_private.h subversion/include/svn_base64.h subversion/include/svn_checksum.h subversion/include/svn_dav.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/mod_dav_svn/dav_svn.h
	$(COMPILE_APACHE_MOD) $(canonicalized_srcdir)subversion/mod_dav_svn/version.c

subversion/po/de.mo: subversion/po/de.po

subversion/po/es.mo: subversion/po/es.po

subversion/po/fr.mo: subversion/po/fr.po

subversion/po/it.mo: subversion/po/it.po

subversion/po/ja.mo: subversion/po/ja.po

subversion/po/ko.mo: subversion/po/ko.po

subversion/po/nb.mo: subversion/po/nb.po

subversion/po/pl.mo: subversion/po/pl.po

subversion/po/pt_BR.mo: subversion/po/pt_BR.po

subversion/po/sv.mo: subversion/po/sv.po

subversion/po/zh_CN.mo: subversion/po/zh_CN.po

subversion/po/zh_TW.mo: subversion/po/zh_TW.po

subversion/svn/add-cmd.o: subversion/svn/add-cmd.c subversion/include/private/svn_opt_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h

subversion/svn/blame-cmd.o: subversion/svn/blame-cmd.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/cat-cmd.o: subversion/svn/cat-cmd.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h

subversion/svn/changelist-cmd.o: subversion/svn/changelist-cmd.c subversion/include/private/svn_opt_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/checkout-cmd.o: subversion/svn/checkout-cmd.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/cleanup-cmd.o: subversion/svn/cleanup-cmd.c subversion/include/private/svn_opt_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h

subversion/svn/commit-cmd.o: subversion/svn/commit-cmd.c subversion/include/private/svn_opt_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/conflict-callbacks.o: subversion/svn/conflict-callbacks.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/copy-cmd.o: subversion/svn/copy-cmd.c subversion/include/private/svn_opt_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/delete-cmd.o: subversion/svn/delete-cmd.c subversion/include/private/svn_opt_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/diff-cmd.o: subversion/svn/diff-cmd.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/export-cmd.o: subversion/svn/export-cmd.c subversion/include/private/svn_opt_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/help-cmd.o: subversion/svn/help-cmd.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/import-cmd.o: subversion/svn/import-cmd.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/info-cmd.o: subversion/svn/info-cmd.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/svn/cl.h subversion/svn/tree-conflicts.h subversion/svn_private_config.h

subversion/svn/list-cmd.o: subversion/svn/list-cmd.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/lock-cmd.o: subversion/svn/lock-cmd.c subversion/include/private/svn_opt_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/log-cmd.o: subversion/svn/log-cmd.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_compat.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/main.o: subversion/svn/main.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/merge-cmd.o: subversion/svn/merge-cmd.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/mergeinfo-cmd.o: subversion/svn/mergeinfo-cmd.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/mkdir-cmd.o: subversion/svn/mkdir-cmd.c subversion/include/private/svn_opt_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/move-cmd.o: subversion/svn/move-cmd.c subversion/include/private/svn_opt_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/notify.o: subversion/svn/notify.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/propdel-cmd.o: subversion/svn/propdel-cmd.c subversion/include/private/svn_opt_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/propedit-cmd.o: subversion/svn/propedit-cmd.c subversion/include/private/svn_opt_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/propget-cmd.o: subversion/svn/propget-cmd.c subversion/include/private/svn_cmdline_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/proplist-cmd.o: subversion/svn/proplist-cmd.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/props.o: subversion/svn/props.c subversion/include/private/svn_cmdline_private.h subversion/include/svn_auth.h subversion/include/svn_base64.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/propset-cmd.o: subversion/svn/propset-cmd.c subversion/include/private/svn_opt_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/resolve-cmd.o: subversion/svn/resolve-cmd.c subversion/include/private/svn_opt_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/resolved-cmd.o: subversion/svn/resolved-cmd.c subversion/include/private/svn_opt_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/revert-cmd.o: subversion/svn/revert-cmd.c subversion/include/private/svn_opt_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/status-cmd.o: subversion/svn/status-cmd.c subversion/include/private/svn_opt_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/status.o: subversion/svn/status.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/svn/cl.h subversion/svn/tree-conflicts.h subversion/svn_private_config.h

subversion/svn/switch-cmd.o: subversion/svn/switch-cmd.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/tree-conflicts.o: subversion/svn/tree-conflicts.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/svn/cl.h subversion/svn/tree-conflicts.h subversion/svn_private_config.h

subversion/svn/unlock-cmd.o: subversion/svn/unlock-cmd.c subversion/include/private/svn_opt_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/update-cmd.o: subversion/svn/update-cmd.c subversion/include/private/svn_opt_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svn/util.o: subversion/svn/util.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_ctype.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/include/svn_xml.h subversion/svn/cl.h subversion/svn_private_config.h

subversion/svnadmin/main.o: subversion/svnadmin/main.c subversion/include/private/svn_opt_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_user.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/svn_private_config.h

subversion/svndumpfilter/main.o: subversion/svndumpfilter/main.c subversion/include/private/svn_mergeinfo_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_sorts.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/svn_private_config.h

subversion/svnlook/main.o: subversion/svnlook/main.c subversion/include/private/svn_cmdline_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_xml.h subversion/svn_private_config.h

subversion/svnserve/cyrus_auth.o: subversion/svnserve/cyrus_auth.c subversion/include/private/ra_svn_sasl.h subversion/include/private/svn_atomic.h subversion/include/private/svn_dep_compat.h subversion/include/svn_base64.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_pools.h subversion/include/svn_ra_svn.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/svn_private_config.h subversion/svnserve/server.h

subversion/svnserve/log-escape.o: subversion/svnserve/log-escape.c subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_ra_svn.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/svnserve/server.h

subversion/svnserve/main.o: subversion/svnserve/main.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra_svn.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/svn_private_config.h subversion/svnserve/server.h subversion/svnserve/winservice.h

subversion/svnserve/serve.o: subversion/svnserve/serve.c subversion/include/private/svn_log.h subversion/include/private/svn_mergeinfo_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_compat.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_ra_svn.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_user.h subversion/include/svn_version.h subversion/svn_private_config.h subversion/svnserve/server.h

subversion/svnserve/winservice.o: subversion/svnserve/winservice.c subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_types.h subversion/svn_private_config.h subversion/svnserve/winservice.h

subversion/svnsync/main.o: subversion/svnsync/main.c subversion/include/private/svn_opt_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/svn_private_config.h

subversion/svnversion/main.o: subversion/svnversion/main.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/svn_private_config.h

subversion/tests/libsvn_client/client-test.o: subversion/tests/libsvn_client/client-test.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_client/mergeinfo.h subversion/tests/svn_test.h

subversion/tests/libsvn_delta/random-test.o: subversion/tests/libsvn_delta/random-test.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_delta/compose_delta.c subversion/libsvn_delta/delta.h subversion/tests/libsvn_delta/delta-window-test.h subversion/tests/libsvn_delta/range-index-test.h subversion/tests/svn_test.h

subversion/tests/libsvn_delta/svndiff-test.o: subversion/tests/libsvn_delta/svndiff-test.c subversion/include/svn_base64.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_quoprint.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h

subversion/tests/libsvn_delta/vdelta-test.o: subversion/tests/libsvn_delta/vdelta-test.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_delta/delta.h subversion/tests/libsvn_delta/delta-window-test.h subversion/tests/svn_test.h

subversion/tests/libsvn_delta/window-test.o: subversion/tests/libsvn_delta/window-test.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h

subversion/tests/libsvn_diff/diff-diff3-test.o: subversion/tests/libsvn_diff/diff-diff3-test.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/tests/svn_test.h

subversion/tests/libsvn_fs/fs-test.o: subversion/tests/libsvn_fs/fs-test.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_delta/delta.h subversion/tests/svn_test.h subversion/tests/svn_test_fs.h

subversion/tests/libsvn_fs/locks-test.o: subversion/tests/libsvn_fs/locks-test.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h subversion/tests/svn_test_fs.h

subversion/tests/libsvn_fs_base/changes-test.o: subversion/tests/libsvn_fs_base/changes-test.c subversion/include/private/svn_skel.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/changes-table.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/util/fs_skels.h subversion/svn_private_config.h subversion/tests/svn_test.h subversion/tests/svn_test_fs.h

subversion/tests/libsvn_fs_base/fs-base-test.o: subversion/tests/libsvn_fs_base/fs-base-test.c subversion/include/private/svn_fs_util.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_delta/delta.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/nodes-table.h subversion/libsvn_fs_base/bdb/txn-table.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/id.h subversion/libsvn_fs_base/trail.h subversion/svn_private_config.h subversion/tests/svn_test.h subversion/tests/svn_test_fs.h

subversion/tests/libsvn_fs_base/key-test.o: subversion/tests/libsvn_fs_base/key-test.c subversion/include/private/svn_skel.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs_base/key-gen.h subversion/tests/svn_test.h

subversion/tests/libsvn_fs_base/strings-reps-test.o: subversion/tests/libsvn_fs_base/strings-reps-test.c subversion/include/private/svn_skel.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs/fs-loader.h subversion/libsvn_fs_base/bdb/bdb_compat.h subversion/libsvn_fs_base/bdb/env.h subversion/libsvn_fs_base/bdb/reps-table.h subversion/libsvn_fs_base/bdb/strings-table.h subversion/libsvn_fs_base/fs.h subversion/libsvn_fs_base/trail.h subversion/libsvn_fs_base/util/fs_skels.h subversion/svn_private_config.h subversion/tests/svn_test.h subversion/tests/svn_test_fs.h

subversion/tests/libsvn_fs_fs/fs-pack-test.o: subversion/tests/libsvn_fs_fs/fs-pack-test.c subversion/include/private/svn_atomic.h subversion/include/private/svn_cache.h subversion/include/private/svn_dep_compat.h subversion/include/private/svn_fs_private.h subversion/include/private/svn_sqlite.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_iter.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_fs_fs/fs.h subversion/tests/svn_test.h subversion/tests/svn_test_fs.h

subversion/tests/libsvn_ra_local/ra-local-test.o: subversion/tests/libsvn_ra_local/ra-local-test.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_ra.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_ra_local/ra_local.h subversion/tests/svn_test.h subversion/tests/svn_test_fs.h

subversion/tests/libsvn_repos/dir-delta-editor.o: subversion/tests/libsvn_repos/dir-delta-editor.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/libsvn_repos/dir-delta-editor.h subversion/tests/svn_test.h

subversion/tests/libsvn_repos/repos-test.o: subversion/tests/libsvn_repos/repos-test.c subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/libsvn_repos/dir-delta-editor.h subversion/tests/svn_test.h subversion/tests/svn_test_fs.h

subversion/tests/libsvn_subr/auth-test.o: subversion/tests/libsvn_subr/auth-test.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/svn_private_config.h subversion/tests/svn_test.h

subversion/tests/libsvn_subr/cache-test.o: subversion/tests/libsvn_subr/cache-test.c subversion/include/private/svn_cache.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_iter.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/svn_private_config.h subversion/tests/svn_test.h

subversion/tests/libsvn_subr/checksum-test.o: subversion/tests/libsvn_subr/checksum-test.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h

subversion/tests/libsvn_subr/compat-test.o: subversion/tests/libsvn_subr/compat-test.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h

subversion/tests/libsvn_subr/config-test.o: subversion/tests/libsvn_subr/config-test.c subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h

subversion/tests/libsvn_subr/dirent_uri-test.o: subversion/tests/libsvn_subr/dirent_uri-test.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_dirent_uri.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/libsvn_subr/private_uri.h subversion/tests/svn_test.h

subversion/tests/libsvn_subr/error-test.o: subversion/tests/libsvn_subr/error-test.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h

subversion/tests/libsvn_subr/hashdump-test.o: subversion/tests/libsvn_subr/hashdump-test.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_hash.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h

subversion/tests/libsvn_subr/mergeinfo-test.o: subversion/tests/libsvn_subr/mergeinfo-test.c subversion/include/private/svn_mergeinfo_private.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h

subversion/tests/libsvn_subr/opt-test.o: subversion/tests/libsvn_subr/opt-test.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h

subversion/tests/libsvn_subr/path-test.o: subversion/tests/libsvn_subr/path-test.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h

subversion/tests/libsvn_subr/revision-test.o: subversion/tests/libsvn_subr/revision-test.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h

subversion/tests/libsvn_subr/skel-test.o: subversion/tests/libsvn_subr/skel-test.c subversion/include/private/svn_skel.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h subversion/tests/svn_test_fs.h

subversion/tests/libsvn_subr/stream-test.o: subversion/tests/libsvn_subr/stream-test.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h

subversion/tests/libsvn_subr/string-test.o: subversion/tests/libsvn_subr/string-test.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h

subversion/tests/libsvn_subr/target-test.o: subversion/tests/libsvn_subr/target-test.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h

subversion/tests/libsvn_subr/time-test.o: subversion/tests/libsvn_subr/time-test.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_string.h subversion/include/svn_time.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h

subversion/tests/libsvn_subr/translate-test.o: subversion/tests/libsvn_subr/translate-test.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_subst.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h

subversion/tests/libsvn_subr/utf-test.o: subversion/tests/libsvn_subr/utf-test.c subversion/include/private/svn_utf_private.h subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/tests/svn_test.h

subversion/tests/libsvn_wc/tree-conflict-data-test.o: subversion/tests/libsvn_wc/tree-conflict-data-test.c subversion/include/private/svn_wc_private.h subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/include/svn_wc.h subversion/libsvn_wc/tree_conflicts.h subversion/libsvn_wc/wc.h subversion/tests/svn_test.h

subversion/tests/svn_test_editor.lo: subversion/tests/svn_test_editor.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_path.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h

subversion/tests/svn_test_fs.lo: subversion/tests/svn_test_fs.c subversion/include/svn_checksum.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/tests/svn_test.h subversion/tests/svn_test_fs.h

subversion/tests/svn_test_main.lo: subversion/tests/svn_test_main.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h subversion/svn_private_config.h subversion/tests/svn_test.h

tools/client-side/svnmucc/svnmucc.o: tools/client-side/svnmucc/svnmucc.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_client.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_opt.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_props.h subversion/include/svn_ra.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h subversion/include/svn_wc.h

tools/diff/diff.o: tools/diff/diff.c subversion/include/svn_checksum.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h

tools/diff/diff3.o: tools/diff/diff3.c subversion/include/svn_checksum.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h

tools/diff/diff4.o: tools/diff/diff4.c subversion/include/svn_checksum.h subversion/include/svn_diff.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_io.h subversion/include/svn_pools.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h

tools/server-side/svn-populate-node-origins-index.o: tools/server-side/svn-populate-node-origins-index.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_path.h subversion/include/svn_pools.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_utf.h subversion/include/svn_version.h

tools/server-side/svnauthz-validate.o: tools/server-side/svnauthz-validate.c subversion/include/svn_auth.h subversion/include/svn_checksum.h subversion/include/svn_cmdline.h subversion/include/svn_config.h subversion/include/svn_delta.h subversion/include/svn_error.h subversion/include/svn_error_codes.h subversion/include/svn_fs.h subversion/include/svn_io.h subversion/include/svn_mergeinfo.h subversion/include/svn_pools.h subversion/include/svn_repos.h subversion/include/svn_string.h subversion/include/svn_types.h subversion/include/svn_version.h

