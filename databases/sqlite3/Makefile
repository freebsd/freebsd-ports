# New ports collection makefile for:	sqlite3
# Date created:				Feb 21, 2001
# Whom:					Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sqlite3
PORTVERSION=	3.6.19
CATEGORIES=	databases
MASTER_SITES=	http://www.sqlite.org/
DISTNAME=	sqlite-${PORTVERSION}

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	An SQL database engine in a C library

CONFLICTS=	sqlite34-[0-9]*

USE_GMAKE=	YES
USE_GNOME=	pkgconfig
USE_LDCONFIG=	YES
GNU_CONFIGURE=	YES
USE_GNOME=	gnomehack
USE_TCL_BUILD=	84+
CONFIGURE_ENV+=	TCLSH_CMD="${TCLSH}" \
		TCLLIBDIR="${PREFIX}/lib/${PORTNAME}" \
		ac_cv_search_pthread_create=""

OPTIONS=	DEBUG		"Enable debugging & verbose explain"	off \
		FTS3		"Enable FTS3 (Full Text Search) module"	off \
		RTREE		"Enable R*Tree module"			off \
		RAMTABLE	"Store temporary tables in RAM"		off \
		TCLWRAPPER	"Enable TCL wrapper"			off \
		METADATA	"Enable column metadata"		on \
		THREADSAFE	"Build thread-safe library"		on

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
EXTRA_PATCHES+=		${FILESDIR}/pthread_equal_stub
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_FTS3)
CFLAGS+=		-DSQLITE_ENABLE_FTS3=1
.endif

.if defined(WITH_RTREE)
CFLAGS+=		-DSQLITE_ENABLE_RTREE=1
.endif

.if defined(WITH_RAMTABLE)
CONFIGURE_ARGS+=	--enable-tempstore=yes
.endif

.if defined(WITH_TCLWRAPPER)
CATEGORIES+=		lang tcl
COMMENT+=		with TCL Wrapper
USE_TCL_RUN=		84+
CONFIGURE_ARGS+=	--with-tcl=${TCL_LIBDIR}
PLIST_SUB+=		WITH_TCLWRAPPER=""
ALL_TARGET=		all tclsqlite3
INSTALL_TARGET=		install tcl_install
.else
CONFIGURE_ARGS+=	--disable-tcl
PLIST_SUB+=		WITH_TCLWRAPPER="@comment "
.endif

.if !defined(WITHOUT_METADATA)
CFLAGS+=		-DSQLITE_ENABLE_COLUMN_METADATA=1
.endif

.if !defined(WITHOUT_THREADSAFE)
CONFIGURE_ARGS+=	--enable-threadsafe \
			--enable-threads-override-locks
.else
CONFIGURE_ARGS+=	--disable-threadsafe
.endif

.if defined(WITH_TCLWRAPPER)
post-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/.libs/tclsqlite3 ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${FILESDIR}/example.tcl ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
