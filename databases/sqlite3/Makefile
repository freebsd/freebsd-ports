# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sqlite3
DISTVERSION=	3.30.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	https://www.sqlite.org/2019/ http://www2.sqlite.org/2019/ http://www3.sqlite.org/2019/
DISTNAME=	sqlite-autoconf-${PORTVERSION:C/\.([[:digit:]])[[:>:]]/0\1/g:S/.//g}00

MAINTAINER=	pavelivolkov@gmail.com
COMMENT=	SQL database engine in a C library

LICENSE=	PD

USES=		libtool ncurses pathfix
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip

# Compilation Options For SQLite https://www.sqlite.org/compile.html
OPTIONS_DEFINE=		FTS4 URI URI_AUTHORITY METADATA \
			DIRECT_READ MEMMAN SECURE_DELETE UNLOCK_NOTIFY THREADS \
			EXTENSION ARMOR STMT DBPAGE DBSTAT FTS5 RBU NULL_TRIM \
			LIKENOTBLOB STSHELL FTS3_TOKEN UNKNOWN_SQL SORT_REF \
			NORMALIZE DQS
OPTIONS_SINGLE=		RAMT
OPTIONS_RADIO=		STAT
OPTIONS_GROUP=		OPT_EXT OPT_FUNC UNICODE RTREEG RL

OPTIONS_GROUP_OPT_EXT=	JSON1 SESSION
OPTIONS_GROUP_OPT_FUNC=	OFFSET SER1 SOUNDEX

OPT_EXT_DESC=		Optional extensions
OPT_FUNC_DESC=		Optional functions
URI_DESC=		Enable use the URI filename
URI_AUTHORITY_DESC=	Allow convert URL into a UNC
SOUNDEX_DESC=		Enable the soundex() SQL function
METADATA_DESC=		Enable column metadata
DIRECT_READ_DESC=	File is read directly from disk
MEMMAN_DESC=		Allow it to release unused memory
SECURE_DELETE_DESC=	Overwrite deleted information with zeros
UNLOCK_NOTIFY_DESC=	Enable notification on unlocking
EXTENSION_DESC=		Allow loadable extensions
STSHELL_DESC=		Statically link libsqlite3 into shell
NORMALIZE_DESC=		Enable normalized sql function

# https://www.sqlite.org/compile.html#dqs
DQS_DESC=		Double-quoted String Literals

# https://sqlite.org/compile.html#enable_null_trim
NULL_TRIM_DESC=		Omits NULL columns at the ends of rows

# http://www.sqlite.org/compile.html#enable_offset_sql_func
OFFSET_DESC=		Enable sqlite_offset() returning record's file offset

# https://www.sqlite.org/compile.html#enable_deserialize
SER1_DESC=		Enable the sqlite3_[de]serialize() interface

# https://www.sqlite.org/sessionintro.html
SESSION_DESC=		Enable the session extension

# https://sqlite.org/compile.html#like_doesnt_match_blobs
LIKENOTBLOB_DESC=	LIKE does not match blobs

# https://www.sqlite.org/compile.html#enable_api_armor
ARMOR_DESC=		Detect misuse of the API

# http://sqlite.org/compile.html#enable_unknown_sql_function
UNKNOWN_SQL_DESC=	Suppress unknown function errors

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
RBU_DESC=		Enable the resumable bulk update

# https://www.sqlite.org/c3ref/stmt_scanstatus.html
STMT_DESC=		Prepared statement scan status

# https://www.sqlite.org/compile.html#enable_sorter_references
SORT_REF_DESC=		To use references in the sorter

# https://www.sqlite.org/tempfiles.html#tempstore
OPTIONS_SINGLE_RAMT=	TS0 TS1 TS2 TS3
RAMT_DESC=		Where to store temporary file
TS0_DESC=		Always use temporary file
TS1_DESC=		File by default, change allowed PRAGMA
TS2_DESC=		Memory by default, change allowed PRAGMA
TS3_DESC=		Always use memory

# https://www.sqlite.org/queryplanner-ng.html#qpstab
OPTIONS_RADIO_STAT=	STAT3 STAT4
STAT_DESC=		Which query planner to use, stability or ...
STAT3_DESC=		collect histogram data from leftmost column
STAT4_DESC=		collect histogram data from all columns

# https://sqlite.org/compile.html#enable_dbpage_vtab
DBPAGE_DESC=		Enable DBPAGE Virtual Table

# https://www.sqlite.org/dbstat.html
DBSTAT_DESC=		Enable DBSTAT Virtual Table

# https://www.sqlite.org/fts3.html#tokenizer
OPTIONS_GROUP_UNICODE=	ICU UNICODE61
UNICODE_DESC=		Unicode support
UNICODE61_DESC=		Unicode Version 6.1 tokenizer

# https://www.sqlite.org/rtree.html
OPTIONS_GROUP_RTREEG=	RTREE RTREE_INT GEOPOLY
RTREEG_DESC=		Index type for range queries
RTREE_DESC=		Enable R*Tree module
RTREE_INT_DESC=		Store 32-bit sig int (no float) coordinates
# https://www.sqlite.org/geopoly.html
GEOPOLY_DESC=		Uses the GeoJSON notation (RFC-7946)
GEOPOLY_IMPLIES=	RTREE

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
			FTS3_TOKEN FTS5 DQS
# SECURE_DELETE, UNLOCK_NOTIFY, DBSTAT (since 41.0) used by www/firefox et al.
# RTREE used by graphics/mapnik, databases/spatialite
# FTS3_TOKEN used by audio/clementine-player, mail/thunderbird, www/seamonkey
# FTS5 used by sysutils/tracker

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
GEOPOLY_CPPFLAGS=	-DSQLITE_ENABLE_GEOPOLY=1

FTS4_CPPFLAGS=	-DSQLITE_ENABLE_FTS3 -DSQLITE_ENABLE_FTS3_PARENTHESIS=1 -DSQLITE_ENABLE_FTS4=1
FTS5_CONFIGURE_ENABLE=	fts5
FTS5_LIBS=		-lm
FTS3_TOKEN_CPPFLAGS=	-DSQLITE_ENABLE_FTS3_TOKENIZER=1

SOUNDEX_CPPFLAGS=	-DSQLITE_SOUNDEX=1
MEMMAN_CPPFLAGS=	-DSQLITE_ENABLE_MEMORY_MANAGEMENT=1
SECURE_DELETE_CPPFLAGS=	-DSQLITE_SECURE_DELETE=1
UNLOCK_NOTIFY_CPPFLAGS=	-DSQLITE_ENABLE_UNLOCK_NOTIFY=1
METADATA_CPPFLAGS=	-DSQLITE_ENABLE_COLUMN_METADATA=1
STAT3_CPPFLAGS=	-DSQLITE_ENABLE_STAT3=1
STAT4_CPPFLAGS=	-DSQLITE_ENABLE_STAT4=1
DBPAGE_CPPFLAGS=	-DSQLITE_ENABLE_DBPAGE_VTAB=1
DBSTAT_CPPFLAGS=	-DSQLITE_ENABLE_DBSTAT_VTAB=1
URI_CPPFLAGS=	-DSQLITE_USE_URI=1
URI_AUTHORITY_CPPFLAGS=	-DSQLITE_ALLOW_URI_AUTHORITY=1
DIRECT_READ_CPPFLAGS=	-DSQLITE_DIRECT_OVERFLOW_READ=1
ARMOR_CPPFLAGS=	-DSQLITE_ENABLE_API_ARMOR=1
STMT_CPPFLAGS=	-DSQLITE_ENABLE_STMT_SCANSTATUS=1

EXTENSION_CONFIGURE_ENABLE=	dynamic-extensions

THREADS_CONFIGURE_ENABLE=	threadsafe
THREADS_LIBS=		-lpthread

ICU_BUILD_DEPENDS=	${LOCALBASE}/bin/icu-config:devel/icu
ICU_LIB_DEPENDS=	libicudata.so:devel/icu
ICU_CPPFLAGS=	`${LOCALBASE}/bin/icu-config --cppflags` -DSQLITE_ENABLE_ICU=1
ICU_LIBS=	`${LOCALBASE}/bin/icu-config --ldflags`

UNICODE61_CPPFLAGS=	""
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

SESSION_CONFIGURE_ENABLE=	session

UNKNOWN_SQL_CPPFLAGS=	-DSQLITE_ENABLE_UNKNOWN_SQL_FUNCTION=1

NULL_TRIM_CPPFLAGS=	-DSQLITE_ENABLE_NULL_TRIM=1

OFFSET_CPPFLAGS=	-DSQLITE_ENABLE_OFFSET_SQL_FUNC=1

SER1_CPPFLAGS=	-DSQLITE_ENABLE_DESERIALIZE=1

SORT_REF_CPPFLAGS=	-DSQLITE_ENABLE_SORTER_REFERENCES=1

NORMALIZE_CPPFLAGS=	-DSQLITE_ENABLE_NORMALIZE=1

DQS_CPPFLAGS=	-DSQLITE_DQS=3
DQS_CPPFLAGS_OFF=	-DSQLITE_DQS=0

.include <bsd.port.options.mk>

# Platform Configuration
CPPFLAGS+=	-DHAVE_ISNAN=1 -DHAVE_MALLOC_USABLE_SIZE=1 -DHAVE_GMTIME_R=1 -DHAVE_LOCALTIME_R=1 -DHAVE_USLEEP=1 -DHAVE_STRCHRNUL=1

post-configure:
	@${ECHO_MSG} "===> CONFIGURE_ARGS=${CONFIGURE_ARGS}"
	@${ECHO_MSG} "===> CPPFLAGS=${CPPFLAGS}"
	@${ECHO_MSG} "===> CFLAGS=${CFLAGS}"
	@${ECHO_MSG} "===> LDFLAGS=${LDFLAGS}"
	@${ECHO_MSG} "===> LIBS=${LIBS}"

post-build:
.if ${ARCH}=="i386"
	@${ECHO_MSG} "===> WARNING: on ${ARCH} don't pass atof1-* tests"
.endif

post-install:
	${RM} ${STAGEDIR}${PREFIX}/include/msvc.h

# for compares with checksum from of the site
sha1: checksum
.if defined(SHA1) && !empty(SHA1)
	@sha1 -c ${SHA1} ${DISTDIR}/${ALLFILES}
.else
	@sha1 ${DISTDIR}/${ALLFILES}
.endif

.include <bsd.port.mk>
