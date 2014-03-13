# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sqlite3
PORTVERSION=	3.8.4
CATEGORIES=	databases
MASTER_SITES=	http://www.sqlite.org/2014/ http://www2.sqlite.org/2014/ http://www3.sqlite.org/2014/
DISTNAME=	sqlite-autoconf-3080400

MAINTAINER=	pavelivolkov@gmail.com
COMMENT=	SQL database engine in a C library

LICENSE=	public
LICENSE_NAME=	Public Domain
LICENSE_TEXT=	Description of the license can be obtained from the following URL: http://www.sqlite.org/copyright.html
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

CONFLICTS=	sqlite34-[0-9]* sqlcipher-[0-9]*

USES=		pathfix
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=	yes

# Compilation Options For SQLite http://www.sqlite.org/compile.html
OPTIONS_DEFINE=	FTS4 UPD_DEL_LIMIT URI URI_AUTHORITY SOUNDEX METADATA \
		DIRECT_READ MEMMAN SECURE_DELETE UNLOCK_NOTIFY THREADS EXTENSION
OPTIONS_SINGLE=	RAMT
OPTIONS_RADIO=	STAT
OPTIONS_GROUP=	UNICODE RTREEG

FTS4_DESC=		Enable FTS3/4 (Full Text Search) module
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

OPTIONS_SINGLE_RAMT=	TS0 TS1 TS2 TS3
RAMT_DESC=		Where to store temporary files
TS0_DESC=		Always use temporary files
TS1_DESC=		Files by default, allow changes with PRAGMA
TS2_DESC=		Memory by default,allow changes with PRAGMA
TS3_DESC=		Always use memory

OPTIONS_RADIO_STAT=	STAT3 STAT4
STAT_DESC=		Which query planner to use
STAT3_DESC=		collect histogram data from leftmost column
STAT4_DESC=		collect histogram data from all columns

# http://www.sqlite.org/fts3.html#tokenizer
OPTIONS_GROUP_UNICODE=	ICU UNICODE61
UNICODE_DESC=		Unicode support
UNICODE61_DESC=		Unicode Version 6.1 tokenizer

# http://www.sqlite.org/rtree.html
OPTIONS_GROUP_RTREEG=	RTREE RTREE_INT
RTREEG_DESC=		Index type for range queries
RTREE_DESC=		Enable R*Tree module
RTREE_INT_DESC=		Store 32-bit sig int (no float) coordinates

OPTIONS_DEFAULT=	FTS4 URI METADATA SECURE_DELETE UNLOCK_NOTIFY THREADS EXTENSION TS1 RTREE
# SECURE_DELETE, UNLOCK_NOTIFY used by www/firefox, www/libxul
# RTREE used by graphics/mapnik, databases/spatialite

PLIST_FILES=	bin/sqlite3 include/sqlite3.h include/sqlite3ext.h \
		lib/libsqlite3.a lib/libsqlite3.la lib/libsqlite3.so \
		lib/libsqlite3.so.8 libdata/pkgconfig/sqlite3.pc \
		man/man1/sqlite3.1.gz

# The default numeric file permissions for newly created database files under unix.
# If not specified, the default is 0644 which means that the files is globally
# readable but only writable by the creator.
.ifdef DEFAULT_FILE_PERMISSIONS
CPPFLAGS+=		-DSQLITE_DEFAULT_FILE_PERMISSIONS=${DEFAULT_FILE_PERMISSIONS}
.endif

# This macro sets the default size of the page-cache for temporary files
# created by SQLite to store intermediate results, in pages.
.ifdef TEMP_CACHE_SIZE
CPPFLAGS+=		-DSQLITE_DEFAULT_TEMP_CACHE_SIZE=${TEMP_CACHE_SIZE}
.endif

# Use an in-ram database for temporary tables (never,no,yes,always),
TS0_CPPFLAGS=	-DSQLITE_TEMP_STORE=0
TS1_CPPFLAGS=	-DSQLITE_TEMP_STORE=1
TS2_CPPFLAGS=	-DSQLITE_TEMP_STORE=2
TS3_CPPFLAGS=	-DSQLITE_TEMP_STORE=3

RTREE_CPPFLAGS=	-DSQLITE_ENABLE_RTREE=1
RTREE_INT_CPPFLAGS=	-DSQLITE_RTREE_INT_ONLY=1

FTS4_CPPFLAGS=	-DSQLITE_ENABLE_FTS3=1 -DSQLITE_ENABLE_FTS3_PARENTHESIS=1 -DSQLITE_ENABLE_FTS4=1
SOUNDEX_CPPFLAGS=	-DSQLITE_SOUNDEX=1
MEMMAN_CPPFLAGS=	-DSQLITE_ENABLE_MEMORY_MANAGEMENT=1
UPD_DEL_LIMIT_CPPFLAGS=	-DSQLITE_ENABLE_UPDATE_DELETE_LIMIT=1
SECURE_DELETE_CPPFLAGS=	-DSQLITE_SECURE_DELETE=1
UNLOCK_NOTIFY_CPPFLAGS=	-DSQLITE_ENABLE_UNLOCK_NOTIFY=1
METADATA_CPPFLAGS=	-DSQLITE_ENABLE_COLUMN_METADATA=1
STAT3_CPPFLAGS=	-DSQLITE_ENABLE_STAT3=1
STAT4_CPPFLAGS=	-DSQLITE_ENABLE_STAT4=1
URI_CPPFLAGS=	-DSQLITE_USE_URI=1
URI_AUTHORITY_CPPFLAGS=	-DSQLITE_ALLOW_URI_AUTHORITY=1
DIRECT_READ_CPPFLAGS=	-DSQLITE_DIRECT_OVERFLOW_READ=1

EXTENSION_CONFIGURE_ENABLE=	dynamic-extensions

THREADS_CONFIGURE_ENABLE=	threadsafe
THREADS_LDFLAGS=	${PTHREAD_LIBS}

ICU_BUILD_DEPENDS=	${LOCALBASE}/bin/icu-config:${PORTSDIR}/devel/icu
ICU_LIB_DEPENDS=	libicudata.so:${PORTSDIR}/devel/icu
ICU_CPPFLAGS=	`${LOCALBASE}/bin/icu-config --cppflags` -DSQLITE_ENABLE_ICU=1
ICU_LDFLAGS=	`${LOCALBASE}/bin/icu-config --ldflags`

UNICODE61_CPPFLAGS=	-DSQLITE_ENABLE_FTS4_UNICODE61=1

.include <bsd.port.options.mk>

post-configure:
	@${ECHO_MSG} "===> CONFIGURE_ARGS=${CONFIGURE_ARGS}"
	@${ECHO_MSG} "===> CPPFLAGS=${CPPFLAGS}"
	@${ECHO_MSG} "===> LDFLAGS=${LDFLAGS}"

post-build:
.if ${ARCH}=="i386"
	@${ECHO_MSG} "===> WARNING: on ${ARCH} don't pass atof1-* tests"
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsqlite3.so.8

.include <bsd.port.mk>
