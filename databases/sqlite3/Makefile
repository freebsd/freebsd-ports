# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sqlite3
PORTVERSION=	3.7.17
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.sqlite.org/2013/ http://www2.sqlite.org/2013/ http://www3.sqlite.org/2013/
DISTNAME=	sqlite-autoconf-3071700

MAINTAINER=	pavelivolkov@gmail.com
COMMENT=	SQL database engine in a C library

LICENSE=	public
LICENSE_NAME=	Public Domain
LICENSE_TEXT=	Description of the license can be obtained from the following URL: http://www.sqlite.org/copyright.html
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

CONFLICTS=	sqlite34-[0-9]* sqlcipher-[0-9]*

USES=		pathfix
USE_LDCONFIG=	YES
GNU_CONFIGURE=	YES

MAKE_JOBS_UNSAFE=	yes

# Compilation Options For SQLite http://www.sqlite.org/compile.html
OPTIONS_DEFINE=	FTS3 ICU RTREE RAMTABLE UPD_DEL_LIMIT URI SOUNDEX METADATA \
		STAT3 DIRECT_READ MEMMAN SECURE_DELETE UNLOCK_NOTIFY THREADSAFE \
		EXTENSION
OPTIONS_DEFAULT=	FTS3 URI METADATA SECURE_DELETE UNLOCK_NOTIFY THREADSAFE EXTENSION
FTS3_DESC=		Enable FTS3/4 (Full Text Search) module
ICU_DESC=		Enable built with ICU
RTREE_DESC=		Enable R*Tree module (${RTREE_INT})
RAMTABLE_DESC=		Store temporary tables in RAM = ${TEMP_STORE}
UPD_DEL_LIMIT_DESC=	ORDER BY and LIMIT on UPDATE and DELETE
URI_DESC=		Enable use the URI filename
SOUNDEX_DESC=		Enables the soundex() SQL function
METADATA_DESC=		Enable column metadata
STAT3_DESC=		Help SQLite to chose a better query plan
DIRECT_READ_DESC=	File is read directly from disk
MEMMAN_DESC=		Allows it to release unused memory
SECURE_DELETE_DESC=	Overwrite deleted information with zeros
UNLOCK_NOTIFY_DESC=	Enable notification on unlocking
THREADSAFE_DESC=	Build thread-safe library
EXTENSION_DESC=		Allow loadable extensions

.include <bsd.port.options.mk>

PLIST_FILES=	bin/sqlite3 include/sqlite3.h include/sqlite3ext.h \
		lib/libsqlite3.a lib/libsqlite3.la lib/libsqlite3.so \
		lib/libsqlite3.so.8 libdata/pkgconfig/sqlite3.pc

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		sqlite3.1
.endif

#		NAME83		"Enable use 8.3 filename for temp files" off \
# Some devices are compelled to use an older file system with 8+3 filename
# restrictions for backwards compatibility, or due to other non-technical factors.
# http://www.sqlite.org/shortnames.html
.if ${PORT_OPTIONS:MNAME83}
CPPFLAGS+=		-DSQLITE_ENABLE_8_3_NAMES=1
.endif

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

.if ${PORT_OPTIONS:MMEMMAN}
CPPFLAGS+=		-DSQLITE_ENABLE_MEMORY_MANAGEMENT=1
.endif

.if ${PORT_OPTIONS:MUPD_DEL_LIMIT}
CPPFLAGS+=		-DSQLITE_ENABLE_UPDATE_DELETE_LIMIT=1
.endif

.if ${PORT_OPTIONS:MURI}
CPPFLAGS+=		-DSQLITE_USE_URI=1
.endif

.if ${PORT_OPTIONS:MSOUNDEX}
CPPFLAGS+=		-DSQLITE_SOUNDEX=1
.endif

.if ${PORT_OPTIONS:MSTAT3}
CPPFLAGS+=		-DSQLITE_ENABLE_STAT3=1
.endif

.if ${PORT_OPTIONS:MDIRECT_READ}
CPPFLAGS+=		-DSQLITE_DIRECT_OVERFLOW_READ=1
.endif

.if ${PORT_OPTIONS:MFTS3}
CPPFLAGS+=		-DSQLITE_ENABLE_FTS3=1 -DSQLITE_ENABLE_FTS3_PARENTHESIS=1 -DSQLITE_ENABLE_FTS4=1
.endif

.if ${PORT_OPTIONS:MRTREE}
CPPFLAGS+=		-DSQLITE_ENABLE_RTREE=1
.ifdef RTREE_INT
CPPFLAGS+=		-DSQLITE_RTREE_INT_ONLY=1
RTREE_INT=		"int"
.else
RTREE_INT=		"float"
.endif
.endif

.if ${PORT_OPTIONS:MICU}
BUILD_DEPENDS+=		${LOCALBASE}/bin/icu-config:${PORTSDIR}/devel/icu
LIB_DEPENDS+=		icudata:${PORTSDIR}/devel/icu
CPPFLAGS+=		-DSQLITE_ENABLE_ICU=1
CPPFLAGS+=		`${LOCALBASE}/bin/icu-config --cppflags`
LDFLAGS+=		`${LOCALBASE}/bin/icu-config --ldflags`
.endif

# Use an in-ram database for temporary tables (never,no,yes,always),
# which is equivalent of TEMP_STORE=[0,1,2,3], default = 1.
.if ${PORT_OPTIONS:MRAMTABLE}
TEMP_STORE?=		2
CPPFLAGS+=		-DSQLITE_TEMP_STORE=${TEMP_STORE}
.endif

.if ${PORT_OPTIONS:MSECURE_DELETE}
CPPFLAGS+=		-DSQLITE_SECURE_DELETE=1
.endif

.if ${PORT_OPTIONS:MUNLOCK_NOTIFY}
CPPFLAGS+=		-DSQLITE_ENABLE_UNLOCK_NOTIFY=1
.endif

.if ${PORT_OPTIONS:MMETADATA}
CPPFLAGS+=		-DSQLITE_ENABLE_COLUMN_METADATA=1
.endif

.if ${PORT_OPTIONS:MTHREADSAFE}
CONFIGURE_ARGS+=	--enable-threadsafe
LDFLAGS+=		${PTHREAD_LIBS}
.else
CONFIGURE_ARGS+=	--disable-threadsafe
.endif

.if ${PORT_OPTIONS:MEXTENSION}
CONFIGURE_ARGS+=	--enable-dynamic-extensions
.else
CONFIGURE_ARGS+=	--disable-dynamic-extensions
.endif

post-build:
.if ${ARCH}=="i386"
	@${ECHO_MSG} "===> WARNING: on ${ARCH} don't pass atof1-* tests"
.endif

post-install:
.if !defined(NO_INSTALL_MANPAGES)
	@${INSTALL_MAN} ${WRKSRC}/sqlite3.1 ${MANPREFIX}/man/man1
.endif

.include <bsd.port.mk>
