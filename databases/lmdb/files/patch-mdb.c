--- mdb.c.orig	2019-07-19 16:41:12 UTC
+++ mdb.c
@@ -124,7 +124,10 @@ typedef SSIZE_T	ssize_t;
 #include <resolv.h>	/* defines BYTE_ORDER on HPUX and Solaris */
 #endif
 
-#if defined(__APPLE__) || defined (BSD) || defined(__FreeBSD_kernel__)
+#if defined(__FreeBSD__) && defined(__FreeBSD_version) && __FreeBSD_version >= 1100110
+# define MDB_USE_POSIX_MUTEX   1
+# define MDB_USE_ROBUST        1
+#elif defined(__APPLE__) || defined (BSD) || defined(__FreeBSD_kernel__)
 # define MDB_USE_POSIX_SEM	1
 # define MDB_FDATASYNC		fsync
 #elif defined(ANDROID)
@@ -1375,7 +1378,7 @@ static int	mdb_page_split(MDB_cursor *mc, MDB_val *new
 static int  mdb_env_read_header(MDB_env *env, MDB_meta *meta);
 static MDB_meta *mdb_env_pick_meta(const MDB_env *env);
 static int  mdb_env_write_meta(MDB_txn *txn);
-#ifdef MDB_USE_POSIX_MUTEX /* Drop unused excl arg */
+#if defined(MDB_USE_POSIX_MUTEX) && !defined(MDB_ROBUST_SUPPORTED) /* Drop unused excl arg */
 # define mdb_env_close0(env, excl) mdb_env_close1(env)
 #endif
 static void mdb_env_close0(MDB_env *env, int excl);
@@ -5127,6 +5130,17 @@ mdb_env_close0(MDB_env *env, int excl)
 				sem_unlink(env->me_txns->mti_rmname);
 				sem_unlink(env->me_txns->mti_wmname);
 			}
+		}
+#elif defined(MDB_ROBUST_SUPPORTED)
+		/* If we have the filelock:  If we are the
+		 * only remaining user, clean up robust
+		 * mutexes.
+		 */
+		if (excl == 0)
+			mdb_env_excl_lock(env, &excl);
+		if (excl > 0) {
+			pthread_mutex_destroy(env->me_txns->mti_rmutex);
+			pthread_mutex_destroy(env->me_txns->mti_wmutex);
 		}
 #endif
 		munmap((void *)env->me_txns, (env->me_maxreaders-1)*sizeof(MDB_reader)+sizeof(MDB_txninfo));
