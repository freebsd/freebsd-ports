--- src/Makefile.orig	2014-05-26 20:06:48.000000000 +0400
+++ src/Makefile	2014-06-02 00:19:36.000000000 +0400
@@ -15,7 +15,7 @@
 release_hdr := $(shell sh -c './mkreleasehdr.sh')
 uname_S := $(shell sh -c 'uname -s 2>/dev/null || echo not')
 OPTIMIZATION?=-O2
-DEPENDENCY_TARGETS=hiredis linenoise lua
+DEPENDENCY_TARGETS=hiredis linenoise
 
 # Default settings
 STD=-std=c99 -pedantic
@@ -49,7 +49,7 @@
 # Override default settings if possible
 -include .make-settings
 
-FINAL_CFLAGS=$(STD) $(WARN) $(OPT) $(DEBUG) $(CFLAGS) $(REDIS_CFLAGS)
+FINAL_CFLAGS=$(STD) $(WARN) $(OPT) $(DEBUG) $(CFLAGS)
 FINAL_LDFLAGS=$(LDFLAGS) $(REDIS_LDFLAGS) $(DEBUG)
 FINAL_LIBS=-lm
 DEBUG=-g -ggdb
@@ -88,6 +88,9 @@
 	FINAL_LIBS+= ../deps/jemalloc/lib/libjemalloc.a -ldl
 endif
 
+FINAL_CFLAGS+= -I${PREFIX}/include/lua51
+FINAL_LIBS+= -L${PREFIX}/lib -llua-5.1
+
 REDIS_CC=$(QUIET_CC)$(CC) $(FINAL_CFLAGS)
 REDIS_LD=$(QUIET_LINK)$(CC) $(FINAL_LDFLAGS)
 REDIS_INSTALL=$(QUIET_INSTALL)$(INSTALL)
@@ -108,6 +111,7 @@
 REDIS_SERVER_NAME=redis-server
 REDIS_SENTINEL_NAME=redis-sentinel
 REDIS_SERVER_OBJ=adlist.o ae.o anet.o dict.o redis.o sds.o zmalloc.o lzf_c.o lzf_d.o pqsort.o zipmap.o sha1.o ziplist.o release.o networking.o util.o object.o db.o replication.o rdb.o t_string.o t_list.o t_set.o t_zset.o t_hash.o config.o aof.o pubsub.o multi.o debug.o sort.o intset.o syncio.o cluster.o crc16.o endianconv.o slowlog.o scripting.o bio.o rio.o rand.o memtest.o crc64.o bitops.o sentinel.o notify.o setproctitle.o blocked.o hyperloglog.o latency.o sparkline.o
+REDIS_SERVER_OBJ+=lua_cjson.o lua_cmsgpack.o lua_struct.o strbuf.o
 REDIS_CLI_NAME=redis-cli
 REDIS_CLI_OBJ=anet.o sds.o adlist.o redis-cli.o zmalloc.o release.o anet.o ae.o crc64.o
 REDIS_BENCHMARK_NAME=redis-benchmark
@@ -162,7 +166,7 @@
 
 # redis-server
 $(REDIS_SERVER_NAME): $(REDIS_SERVER_OBJ)
-	$(REDIS_LD) -o $@ $^ ../deps/hiredis/libhiredis.a ../deps/lua/src/liblua.a $(FINAL_LIBS)
+	$(REDIS_LD) -o $@ $^ ../deps/hiredis/libhiredis.a $(FINAL_LIBS)
 
 # redis-sentinel
 $(REDIS_SENTINEL_NAME): $(REDIS_SERVER_NAME)
