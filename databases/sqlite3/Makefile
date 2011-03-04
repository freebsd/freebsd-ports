# New ports collection makefile for:	sqlite3
# Date created:				Feb 21, 2001
# Whom:					Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sqlite3
PORTVERSION=	3.7.5
CATEGORIES=	databases
MASTER_SITES=	http://www.sqlite.org/ http://www2.sqlite.org/
DISTNAME=	sqlite-src-3070500

MAINTAINER=	pavelivolkov@googlemail.com
COMMENT=	An SQL database engine in a C library

LICENSE=	unknown
LICENSE_NAME=	Public Domain
LICENSE_PERMS=	${_LICENSE_PERMS_DEFAULT}
LICENSE_TEXT=	Description of the license can be obtained from the following URL: http://www.sqlite.org/copyright.html

CONFLICTS=	sqlite34-[0-9]*

USE_ZIP=	YES
USE_GMAKE=	YES
USE_GNOME=	pkgconfig gnomehack
USE_LDCONFIG=	YES
GNU_CONFIGURE=	YES

USE_TCL_BUILD=	84+
CONFIGURE_ENV+=	TCLSH_CMD="${TCLSH}" \
		TCLLIBDIR="${PREFIX}/lib/${PORTNAME}" \
		ac_cv_search_pthread_create=""

# Use an in-ram database for temporary tables (never,no,yes,always),
# which is equivalent of SQLITE_TEMP_STORE=[0,1,2,3]
RAMTABLE?=	yes

# Compilation Options For SQLite http://www.sqlite.org/compile.html
OPTIONS=	\
		FTS3		"Enable FTS3/4 (Full Text Search) module" on \
		ICU		"Enable built with ICU"			off \
		RTREE		"Enable R*Tree module"			off \
		RAMTABLE	"Store temporary tables in RAM = ${RAMTABLE}" off \
		UPD_DEL_LIMIT	"ORDER BY and LIMIT on UPDATE and DELETE" off \
		SOUNDEX		"Enables the soundex() SQL function"	off \
		METADATA	"Enable column metadata"		on \
		STAT2		"Help SQLite to chose a better query plan" off \
		MEMMAN		"Allows it to release unused memory"	off \
		SECURE_DELETE	"Overwrite deleted information with zeros" on \
		UNLOCK_NOTIFY	"Enable notification on unlocking"	on \
		THREADSAFE	"Build thread-safe library"		on \
		EXTENSION	"Allow loadable extensions"		on \
		TCLWRAPPER	"Enable TCL wrapper"			off \

.include <bsd.port.options.mk>

PLIST_FILES=	bin/sqlite3 include/sqlite3.h include/sqlite3ext.h \
		lib/libsqlite3.a lib/libsqlite3.la lib/libsqlite3.so \
		lib/libsqlite3.so.8 libdata/pkgconfig/sqlite3.pc
PORTDOCS=	*

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		sqlite3.1
.endif

.if ${OSVERSION} < 700000
EXTRA_PATCHES+=		${FILESDIR}/pthread_equal_stub
.endif

#		DEBUG	"Enable debugging & verbose explain"	off \
# This options used only for debug and is not required during normal work
# applications or its libraries.
#    This options can be specified on the command line.
# Execute: make -D WITH_DEBUG ...
.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
CFLAGS+=		-Wall
.endif

#		GCOV	"Enable coverage testing using gcov/gprof"	off \
# These options are only used for debugging, profiling the application.
# And can cause errors when using the application or its libraries in other
# products (for example build security/nss is BROKEN).
#    This options can be specified on the command line.
# Execute: make -D WITH_GCOV ...
.if defined(WITH_GCOV)
CONFIGURE_ARGS+=	--enable-gcov
LDFLAGS+=		-fstack-protector
.endif

#    By default, the sqlite3_step() interface will automatically invoke
# sqlite3_reset() to reset the prepared statement if necessary. This
# compile-time option changes that behavior so that sqlite3_step() will
# return SQLITE_MISUSE if it called again after returning anything other
# than SQLITE_ROW, SQLITE_BUSY, or SQLITE_LOCKED unless there was an
# intervening call to sqlite3_reset().
#    A detailed description of this option, the compile can be found here:
# http://www.sqlite.org/compile.html#omit_autoreset
#    This options can be specified on the command line.
# Execute: make -D WITH_OMIT_AUTORESET ...
.if defined(WITH_OMIT_AUTORESET)
CFLAGS+=		-DSQLITE_OMIT_AUTORESET=1
.endif

# This macro sets the default size of the page-cache for temporary files
# created by SQLite to store intermediate results, in pages.
.ifdef TEMP_CACHE_SIZE
CFLAGS+=		-DSQLITE_DEFAULT_TEMP_CACHE_SIZE=${TEMP_CACHE_SIZE}
.endif

.if defined(WITH_MEMMAN)
CFLAGS+=		-DSQLITE_ENABLE_MEMORY_MANAGEMENT=1
.endif

.if defined(WITH_UPD_DEL_LIMIT)
CFLAGS+=		-DSQLITE_ENABLE_UPDATE_DELETE_LIMIT=1
.endif

.if defined(WITH_SOUNDEX)
CFLAGS+=		-DSQLITE_SOUNDEX=1
.endif

.if defined(WITH_STAT2)
CFLAGS+=		-DSQLITE_ENABLE_STAT2=1
.endif

.if defined(WITH_FTS3)
CFLAGS+=		-DSQLITE_ENABLE_FTS3=1 -DSQLITE_ENABLE_FTS3_PARENTHESIS=1
.endif

.if defined(WITH_RTREE)
CFLAGS+=		-DSQLITE_ENABLE_RTREE=1
.endif

.if defined(WITH_ICU)
BUILD_DEPENDS+=		${LOCALBASE}/bin/icu-config:${PORTSDIR}/devel/icu
LIB_DEPENDS+=		icudata.46:${PORTSDIR}/devel/icu
CFLAGS+=		-DSQLITE_ENABLE_ICU=1
CPPFLAGS+=		`${LOCALBASE}/bin/icu-config --cppflags`
LDFLAGS+=		`${LOCALBASE}/bin/icu-config --ldflags`
.endif

.if defined(WITH_RAMTABLE)
CONFIGURE_ARGS+=	--enable-tempstore=${RAMTABLE}
.endif

.if defined(WITH_SECURE_DELETE)
CFLAGS+=		-DSQLITE_SECURE_DELETE=1
.endif

.if defined(WITH_UNLOCK_NOTIFY)
CFLAGS+=		-DSQLITE_ENABLE_UNLOCK_NOTIFY=1
.endif

.if defined(WITH_TCLWRAPPER)
CATEGORIES+=		lang tcl
COMMENT+=		with TCL Wrapper
USE_TCL_RUN=		yes
ALL_TARGET=		all tclsqlite3
INSTALL_TARGET=		install tcl_install
CONFIGURE_ARGS+=	--with-tcl=${TCL_LIBDIR}
PORTEXAMPLES+=		example.tcl
PLIST_DIRS+=		lib/sqlite3
PLIST_FILES+=		bin/tclsqlite3 lib/sqlite3/libtclsqlite3.so \
			lib/sqlite3/pkgIndex.tcl
.else
CONFIGURE_ARGS+=	--disable-tcl
.endif

.if !defined(WITHOUT_METADATA)
CFLAGS+=		-DSQLITE_ENABLE_COLUMN_METADATA=1
.endif

.if !defined(WITHOUT_THREADSAFE)
CONFIGURE_ARGS+=	--enable-threadsafe
.else
CONFIGURE_ARGS+=	--disable-threadsafe
.endif

.if !defined(WITHOUT_EXTENSION)
CONFIGURE_ARGS+=	--enable-load-extension
.else
CONFIGURE_ARGS+=	--disable-load-extension
.endif

CONFIGURE_ENV+=		CPPFLAGS="-I. -I./src ${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAKE_ENV+=		CPPFLAGS="-I. -I./src ${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

.include <bsd.port.pre.mk>

.if defined(TCL_VER) && ${TCL_VER} > 8.4
BUILD_DEPENDS+=		${LOCALBASE}/lib/tcl8/${TCL_VER}:${PORTSDIR}/lang/tcl-modules
.if defined(WITH_TCLWRAPPER)
RUN_DEPENDS+=		${LOCALBASE}/lib/tcl8/${TCL_VER}:${PORTSDIR}/lang/tcl-modules
.endif
.endif

# To test you must specify the value of TESTUSER variable.
# It must correspond to a normal (not root) user, from which it will be tested.
# Execute: make TESTUSER=ordinary_user_login_name test
.ifmake test
.ifndef TESTUSER
IGNORE=	set the value of the variable TESTUSER corresponding normal (not root) user, from which will be tested
.endif
.ifndef WITH_TCLWRAPPER
IGNORE=	for the purpose of test you want to include TCL wrapper
.endif
.endif

test: build
	@(cd ${WRKSRC} && ${CHOWN} -R ${TESTUSER} ${WRKSRC} && su ${TESTUSER} -c "${MAKE} test"; ${CHOWN} ${USER} ${WRKSRC})

post-build:
	@${ECHO_CMD}
	@${ECHO_CMD} "You can test sqlite using supplied with the him tests."
	@${ECHO_CMD} "Execute: make TESTUSER=ordinary_user_login_name test"

post-install:
.if defined(WITH_TCLWRAPPER)
	@${INSTALL_PROGRAM} ${WRKSRC}/.libs/tclsqlite3 ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${FILESDIR}/example.tcl ${EXAMPLESDIR}
.endif
.if !defined(NO_INSTALL_MANPAGES)
	@${INSTALL_MAN} ${WRKSRC}/sqlite3.1 ${MANPREFIX}/man/man1
.endif
.ifndef NOPORTDOCS
	@${MKDIR} ${DOCSDIR}
.ifdef WITH_FTS3
	@${INSTALL_DATA} ${WRKSRC}/ext/fts3/README.syntax ${WRKSRC}/ext/fts3/README.tokenizers ${DOCSDIR}
.endif
.ifdef WITH_RTREE
	@${INSTALL_DATA} ${WRKSRC}/ext/rtree/README ${DOCSDIR}
.endif
.ifdef WITH_ICU
	@${INSTALL_DATA} ${WRKSRC}/ext/icu/README.txt ${DOCSDIR}
.endif
.endif

.include <bsd.port.post.mk>
