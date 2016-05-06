# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sqlite3
PORTVERSION=	3.12.2
CATEGORIES=	databases
MASTER_SITES=	https://www.sqlite.org/2016/ http://www2.sqlite.org/2016/ http://www3.sqlite.org/2016/
DISTNAME=	sqlite-autoconf-${PORTVERSION:C/\.([[:digit:]])[[:>:]]/0\1/g:S/.//g}00

MAINTAINER=	pavelivolkov@gmail.com
COMMENT=	SQL database engine in a C library

LICENSE=	PD

USES=		libtool ncurses pathfix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CFLAGS+=	-Os
CPPFLAGS+=	-DHAVE_ISNAN=1 -DHAVE_MALLOC_USABLE_SIZE=1

MAKE_JOBS_UNSAFE=	yes

# Compilation Options For SQLite https://www.sqlite.org/compile.html
OPTIONS_DEFINE=	FTS4 UPD_DEL_LIMIT URI URI_AUTHORITY SOUNDEX METADATA \
		DIRECT_READ MEMMAN SECURE_DELETE UNLOCK_NOTIFY THREADS \
		EXTENSION ARMOR STMT DBSTAT FTS5 JSON1 RBU \
		LIKENOTBLOB STSHELL FTS3_TOKEN
OPTIONS_SINGLE=	RAMT
OPTIONS_RADIO=	STAT
OPTIONS_GROUP=	UNICODE RTREEG RL

UPD_DEL_LIMIT_DESC=	ORDER BY and LIMIT on UPDATE and DELETE
URI_DESC=		Enable use the URI filename
URI_AUTHORITY_DESC=	Allow convert URL into a UNC
SOUNDEX_DESC=		Enables the soundex() SQL function
METADATA_DESC=		Enable column metadata
DIRECT_READ_DESC=	File is read directly from disk
MEMMAN_DESC=		Allows it to release unused memory
SECURE_DELETE_DESC=	Overwrite deleted information with zeros
UNLOCK_NOTIFY_DESC=	Enable notification on unlocking
EXTENSION_DESC=		Allow loadable extensions
STSHELL_DESC=		Statically link libsqlite3 into shell

# https://sqlite.org/compile.html#like_doesnt_match_blobs
LIKENOTBLOB_DESC=	LIKE does not match blobs

# https://www.sqlite.org/compile.html#enable_api_armor
ARMOR_DESC=		Detect misuse of the API

# https://www.sqlite.org/fts3.html
# https://www.sqlite.org/compile.html#enable_fts3_parenthesis
FTS4_DESC=		Enable FTS3/4 (Full Text Search) module

# https://www.sqlite.org/fts5.html
FTS5_DESC=		Enable version 5 full-text search engine

# https://www.sqlite.org/compile.html#enable_fts3_tokenizer
# https://www.sqlite.org/fts3.html#f3tknzr
FTS3_TOKEN_DESC=	Enable two-args version fts3_tokenizer

# https://www.sqlite.org/json1.html
JSON1_DESC=		Enable the JSON1 extension

# https://www.sqlite.org/rbu.html
RBU_DESC=		Enable the Resumable Bulk Update

# https://www.sqlite.org/c3ref/stmt_scanstatus.html
STMT_DESC=		Prepared Statement Scan Status

# https://www.sqlite.org/tempfiles.html#tempstore
OPTIONS_SINGLE_RAMT=	TS0 TS1 TS2 TS3
RAMT_DESC=		Where to store temporary file
TS0_DESC=		Always use temporary file
TS1_DESC=		File by default, change allowed PRAGMA
TS2_DESC=		Memory by default, change allowed PRAGMA
TS3_DESC=		Always use memory

# https://www.sqlite.org/queryplanner-ng.html#qpstab
OPTIONS_RADIO_STAT=	STAT3 STAT4
STAT_DESC=		Which query planner to use, Stability or ...
STAT3_DESC=		collect histogram data from leftmost column
STAT4_DESC=		collect histogram data from all columns

# https://www.sqlite.org/dbstat.html
DBSTAT_DESC=		Enable DBSTAT Virtual Table

# https://www.sqlite.org/fts3.html#tokenizer
OPTIONS_GROUP_UNICODE=	ICU UNICODE61
UNICODE_DESC=		Unicode support
UNICODE61_DESC=		Unicode Version 6.1 tokenizer

# https://www.sqlite.org/rtree.html
OPTIONS_GROUP_RTREEG=	RTREE RTREE_INT
RTREEG_DESC=		Index type for range queries
RTREE_DESC=		Enable R*Tree module
RTREE_INT_DESC=		Store 32-bit sig int (no float) coordinates

OPTIONS_GROUP_RL=	READLINES READLINEP EDITLINE
RL_DESC=		Which command line editing library to use:
READLINES_DESC=		the libreadline from system
READLINEP_DESC=		the GNU libreadline from ports
EDITLINE_DESC=		the BSD libedit from ports
READLINES_PREVENTS=	READLINEP EDITLINE
READLINEP_PREVENTS=	READLINES EDITLINE
EDITLINE_PREVENTS=	READLINES READLINEP

OPTIONS_DEFAULT=	FTS4 URI METADATA SECURE_DELETE UNLOCK_NOTIFY THREADS \
			EXTENSION TS1 UNICODE61 RTREE DBSTAT STSHELL READLINES \
			FTS3_TOKEN
# SECURE_DELETE, UNLOCK_NOTIFY, DBSTAT (since 41.0) used by www/firefox et al.
# RTREE used by graphics/mapnik, databases/spatialite
# FTS3_TOKEN used by audio/clementine-player

PLIST_FILES=	bin/sqlite3 include/sqlite3.h include/sqlite3ext.h \
		lib/libsqlite3.a lib/libsqlite3.so lib/libsqlite3.so.0 \
		lib/libsqlite3.so.0.8.6 libdata/pkgconfig/sqlite3.pc \
		man/man1/sqlite3.1.gz

# The default numeric file permissions for newly created database files under unix.
# If not specified, the default is 0644 which means that the files is globally
# readable but only writable by the creator.
.ifdef DEFAULT_FILE_PERMISSIONS
CPPFLAGS+=		-DSQLITE_DEFAULT_FILE_PERMISSIONS=${DEFAULT_FILE_PERMISSIONS}
.endif

# Use an in-ram database for temporary tables (never,no,yes,always),
TS0_CPPFLAGS=	-DSQLITE_TEMP_STORE=0
TS1_CPPFLAGS=	-DSQLITE_TEMP_STORE=1
TS2_CPPFLAGS=	-DSQLITE_TEMP_STORE=2
TS3_CPPFLAGS=	-DSQLITE_TEMP_STORE=3

RTREE_CPPFLAGS=	-DSQLITE_ENABLE_RTREE=1
RTREE_INT_CPPFLAGS=	-DSQLITE_RTREE_INT_ONLY=1

FTS4_CPPFLAGS=	-DSQLITE_ENABLE_FTS3_PARENTHESIS=1 -DSQLITE_ENABLE_FTS4=1
FTS5_CONFIGURE_ENABLE=	fts5
FTS3_TOKEN_CPPFLAGS=	-DSQLITE_ENABLE_FTS3_TOKENIZER=1

SOUNDEX_CPPFLAGS=	-DSQLITE_SOUNDEX=1
MEMMAN_CPPFLAGS=	-DSQLITE_ENABLE_MEMORY_MANAGEMENT=1
UPD_DEL_LIMIT_CPPFLAGS=	-DSQLITE_ENABLE_UPDATE_DELETE_LIMIT=1
UPD_DEL_LIMIT_PREVENTS=	UPD_DEL_LIMIT
UPD_DEL_LIMIT_PREVENTS_MSG=	this option may only be used when the library is built from source, not from the amalgamation. Please, do not select it with this port.
SECURE_DELETE_CPPFLAGS=	-DSQLITE_SECURE_DELETE=1
UNLOCK_NOTIFY_CPPFLAGS=	-DSQLITE_ENABLE_UNLOCK_NOTIFY=1
METADATA_CPPFLAGS=	-DSQLITE_ENABLE_COLUMN_METADATA=1
STAT3_CPPFLAGS=	-DSQLITE_ENABLE_STAT3=1
STAT4_CPPFLAGS=	-DSQLITE_ENABLE_STAT4=1
DBSTAT_CPPFLAGS=	-DSQLITE_ENABLE_DBSTAT_VTAB=1
URI_CPPFLAGS=	-DSQLITE_USE_URI=1
URI_AUTHORITY_CPPFLAGS=	-DSQLITE_ALLOW_URI_AUTHORITY=1
DIRECT_READ_CPPFLAGS=	-DSQLITE_DIRECT_OVERFLOW_READ=1
ARMOR_CPPFLAGS=	-DSQLITE_ENABLE_API_ARMOR=1
STMT_CPPFLAGS=	-DSQLITE_ENABLE_STMT_SCANSTATUS=1

EXTENSION_CONFIGURE_ENABLE=	dynamic-extensions

THREADS_CONFIGURE_ENABLE=	threadsafe
THREADS_LDFLAGS=		-lpthread

ICU_BUILD_DEPENDS=	${LOCALBASE}/bin/icu-config:devel/icu
ICU_LIB_DEPENDS=	libicudata.so:devel/icu
ICU_CPPFLAGS=	`${LOCALBASE}/bin/icu-config --cppflags` -DSQLITE_ENABLE_ICU=1
ICU_LDFLAGS=	`${LOCALBASE}/bin/icu-config --ldflags`

UNICODE61_CPPFLAGS_OFF=	-DSQLITE_DISABLE_FTS3_UNICODE=1

READLINES_CONFIGURE_ON=	--enable-readline
READLINES_USES=	readline
READLINEP_CONFIGURE_ON=	--enable-readline
READLINEP_USES=	readline:port
EDITLINE_CONFIGURE_ENABLE=	editline
EDITLINE_USES=	libedit

JSON1_CONFIGURE_ENABLE=	json1

RBU_CPPFLAGS=	-DSQLITE_ENABLE_RBU=1

LIKENOTBLOB_CPPFLAGS=	-DSQLITE_LIKE_DOESNT_MATCH_BLOBS=1

STSHELL_CONFIGURE_ENABLE=	static-shell

.include <bsd.port.options.mk>

post-configure:
	@${ECHO_MSG} "===> CONFIGURE_ARGS=${CONFIGURE_ARGS}"
	@${ECHO_MSG} "===> CPPFLAGS=${CPPFLAGS}"
	@${ECHO_MSG} "===> CFLAGS=${CFLAGS}"
	@${ECHO_MSG} "===> LDFLAGS=${LDFLAGS}"

post-build:
.if ${ARCH}=="i386"
	@${ECHO_MSG} "===> WARNING: on ${ARCH} don't pass atof1-* tests"
.endif

.include <bsd.port.mk>
