--- src/Makefile.orig	2016-02-02 19:44:07.760203000 -0500
+++ src/Makefile	2016-02-02 19:47:01.843358000 -0500
@@ -15,7 +15,7 @@
 release_hdr := $(shell sh -c './mkreleasehdr.sh')
 uname_S := $(shell sh -c 'uname -s 2>/dev/null || echo not')
 OPTIMIZATION?=-O2
-DEPENDENCY_TARGETS=hiredis linenoise lua geohash-int
+DEPENDENCY_TARGETS=hiredis linenoise geohash-int
 
 # Default settings
 STD=-std=c99 -pedantic -DREDIS_STATIC=''
@@ -53,7 +53,7 @@
 # Override default settings if possible
 -include .make-settings
 
-FINAL_CFLAGS=$(STD) $(WARN) $(OPT) $(DEBUG) $(CFLAGS) $(REDIS_CFLAGS) -I../deps/geohash-int
+FINAL_CFLAGS=$(STD) $(WARN) $(OPT) $(DEBUG) $(CFLAGS) -I../deps/geohash-int
 FINAL_LDFLAGS=$(LDFLAGS) $(REDIS_LDFLAGS) $(DEBUG)
 FINAL_LIBS=-lm
 DEBUG=-g -ggdb
@@ -98,6 +98,9 @@
 	FINAL_LIBS+= ../deps/jemalloc/lib/libjemalloc.a -ldl
 endif
 
+FINAL_CFLAGS+= -I${PREFIX}/include/lua51
+FINAL_LIBS+= -L${PREFIX}/lib -llua-5.1
+
 REDIS_CC=$(QUIET_CC)$(CC) $(FINAL_CFLAGS)
 REDIS_LD=$(QUIET_LINK)$(CC) $(FINAL_LDFLAGS)
 REDIS_INSTALL=$(QUIET_INSTALL)$(INSTALL)
@@ -118,6 +121,7 @@
 REDIS_SERVER_NAME=redis-server
 REDIS_SENTINEL_NAME=redis-sentinel
 REDIS_SERVER_OBJ=adlist.o quicklist.o ae.o anet.o dict.o server.o sds.o zmalloc.o lzf_c.o lzf_d.o pqsort.o zipmap.o sha1.o ziplist.o release.o networking.o util.o object.o db.o replication.o rdb.o t_string.o t_list.o t_set.o t_zset.o t_hash.o config.o aof.o pubsub.o multi.o debug.o sort.o intset.o syncio.o cluster.o crc16.o endianconv.o slowlog.o scripting.o bio.o rio.o rand.o memtest.o crc64.o bitops.o sentinel.o notify.o setproctitle.o blocked.o hyperloglog.o latency.o sparkline.o redis-check-rdb.o geo.o
+REDIS_SERVER_OBJ+=fpconv.o lua_bit.o lua_cjson.o lua_cmsgpack.o lua_struct.o strbuf.o
 REDIS_GEOHASH_OBJ=../deps/geohash-int/geohash.o ../deps/geohash-int/geohash_helper.o
 REDIS_CLI_NAME=redis-cli
 REDIS_CLI_OBJ=anet.o adlist.o redis-cli.o zmalloc.o release.o anet.o ae.o crc64.o
@@ -172,7 +176,7 @@
 
 # redis-server
 $(REDIS_SERVER_NAME): $(REDIS_SERVER_OBJ)
-	$(REDIS_LD) -o $@ $^ ../deps/hiredis/libhiredis.a ../deps/lua/src/liblua.a $(REDIS_GEOHASH_OBJ) $(FINAL_LIBS)
+	$(REDIS_LD) -o $@ $^ ../deps/hiredis/libhiredis.a $(REDIS_GEOHASH_OBJ) $(FINAL_LIBS)
 
 # redis-sentinel
 $(REDIS_SENTINEL_NAME): $(REDIS_SERVER_NAME)
