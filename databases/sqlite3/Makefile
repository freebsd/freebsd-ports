# New ports collection makefile for:	sqlite3
# Date created:				Feb 21, 2001
# Whom:					Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sqlite3
PORTVERSION=	3.7.13
CATEGORIES=	databases
MASTER_SITES=	http://www.sqlite.org/ http://www2.sqlite.org/ http://www3.sqlite.org/
DISTNAME=	sqlite-autoconf-3071300

MAINTAINER=	pavelivolkov@googlemail.com
COMMENT=	An SQL database engine in a C library

LICENSE=	public
LICENSE_NAME=	Public Domain
LICENSE_TEXT=	Description of the license can be obtained from the following URL: http://www.sqlite.org/copyright.html
LICENSE_PERMS=	${_LICENSE_PERMS_DEFAULT}

CONFLICTS=	sqlite34-[0-9]*

USE_GNOME=	pkgconfig
USE_LDCONFIG=	YES
GNU_CONFIGURE=	YES

MAKE_JOBS_UNSAFE=	yes

# Compilation Options For SQLite http://www.sqlite.org/compile.html
OPTIONS=	\
		FTS3		"Enable FTS3/4 (Full Text Search) module" on \
		ICU		"Enable built with ICU"			off \
		RTREE		"Enable R*Tree module (${RTREE_INT})"	off \
		RAMTABLE	"Store temporary tables in RAM = ${TEMP_STORE}" off \
		UPD_DEL_LIMIT	"ORDER BY and LIMIT on UPDATE and DELETE" off \
		URI		"Enable use the URI filename"		off \
		SOUNDEX		"Enables the soundex() SQL function"	off \
		METADATA	"Enable column metadata"		on \
		STAT3		"Help SQLite to chose a better query plan" off \
		DIRECT_READ	"File is read directly from disk"	off \
		MEMMAN		"Allows it to release unused memory"	off \
		SECURE_DELETE	"Overwrite deleted information with zeros" on \
		UNLOCK_NOTIFY	"Enable notification on unlocking"	on \
		THREADSAFE	"Build thread-safe library"		on \
		EXTENSION	"Allow loadable extensions"		on \

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
.if defined(WITH_NAME83)
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

.if defined(WITH_MEMMAN)
CPPFLAGS+=		-DSQLITE_ENABLE_MEMORY_MANAGEMENT=1
.endif

.if defined(WITH_UPD_DEL_LIMIT)
CPPFLAGS+=		-DSQLITE_ENABLE_UPDATE_DELETE_LIMIT=1
.endif

.if defined(WITH_URI)
CPPFLAGS+=		-DSQLITE_USE_URI=1
.endif

.if defined(WITH_SOUNDEX)
CPPFLAGS+=		-DSQLITE_SOUNDEX=1
.endif

.if defined(WITH_STAT3)
CPPFLAGS+=		-DSQLITE_ENABLE_STAT3=1
.endif

.if defined(WITH_DIRECT_READ)
CPPFLAGS+=		-DSQLITE_DIRECT_OVERFLOW_READ=1
.endif

.if defined(WITH_FTS3)
CPPFLAGS+=		-DSQLITE_ENABLE_FTS3=1 -DSQLITE_ENABLE_FTS3_PARENTHESIS=1 -DSQLITE_ENABLE_FTS4=1
.endif

.if defined(WITH_RTREE)
CPPFLAGS+=		-DSQLITE_ENABLE_RTREE=1
.ifdef RTREE_INT
CPPFLAGS+=		-DSQLITE_RTREE_INT_ONLY=1
RTREE_INT=		"int"
.else
RTREE_INT=		"float"
.endif
.endif

.if defined(WITH_ICU)
BUILD_DEPENDS+=		${LOCALBASE}/bin/icu-config:${PORTSDIR}/devel/icu
LIB_DEPENDS+=		icudata:${PORTSDIR}/devel/icu
CPPFLAGS+=		-DSQLITE_ENABLE_ICU=1
CPPFLAGS+=		`${LOCALBASE}/bin/icu-config --cppflags`
LDFLAGS+=		`${LOCALBASE}/bin/icu-config --ldflags`
.endif

# Use an in-ram database for temporary tables (never,no,yes,always),
# which is equivalent of TEMP_STORE=[0,1,2,3], default = 1.
.if defined(WITH_RAMTABLE)
TEMP_STORE?=		2
CPPFLAGS+=		-DSQLITE_TEMP_STORE=${TEMP_STORE}
.endif

.if defined(WITH_SECURE_DELETE)
CPPFLAGS+=		-DSQLITE_SECURE_DELETE=1
.endif

.if defined(WITH_UNLOCK_NOTIFY)
CPPFLAGS+=		-DSQLITE_ENABLE_UNLOCK_NOTIFY=1
.endif

.if !defined(WITHOUT_METADATA)
CPPFLAGS+=		-DSQLITE_ENABLE_COLUMN_METADATA=1
.endif

.if !defined(WITHOUT_THREADSAFE)
CONFIGURE_ARGS+=	--enable-threadsafe
LDFLAGS+=		${PTHREAD_LIBS}
.else
CONFIGURE_ARGS+=	--disable-threadsafe
.endif

.if !defined(WITHOUT_EXTENSION)
CONFIGURE_ARGS+=	--enable-dynamic-extensions
.else
CONFIGURE_ARGS+=	--disable-dynamic-extensions
.endif

.include <bsd.port.pre.mk>

post-install:
.if !defined(NO_INSTALL_MANPAGES)
	@${INSTALL_MAN} ${WRKSRC}/sqlite3.1 ${MANPREFIX}/man/man1
.endif

.include <bsd.port.post.mk>
