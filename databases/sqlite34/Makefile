# New ports collection makefile for:	sqlite3
# Date created:				Feb 21, 2001
# Whom:					Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sqlite3
PORTVERSION=	3.3.15
CATEGORIES=	databases
MASTER_SITES=	http://www.sqlite.org/
.if defined(USE_THOL)
PKGNAMESUFFIX=	-threads
.endif
DISTNAME=	sqlite-${PORTVERSION}

MAINTAINER=	mnag@FreeBSD.org
COMMENT?=	An SQL database engine in a C library w/ Tcl wrapper

SLAVEDIRS=	databases/sqlite3-threads

USE_GMAKE=	YES
USE_GNOME=	pkgconfig
USE_AUTOTOOLS=	libtool:15
USE_DOS2UNIX=	*.pc.in
USE_LDCONFIG=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=		--prefix=${PREFIX} --with-hints=freebsd.hints
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

OPTIONS=	DEBUG		"Enable debugging & verbose explain"	off \
		DOCS		"Building docs (depends on TCL)"	on \
		FTS1		"Enable FTS1 (Full Text Search) module"	off \
		TCLWRAPPER	"TCL wrapper for SQLITE"		off

# Defaults, for building the docs:
TCL_V?=		8.4
MAKE_ARGS+=	TCLSH=tclsh${TCL_V}
MAKE_ENV+=	TCL_VER=${TCL_V}

.if !defined(USE_THOL)
OPTIONS+=	THREADS		"Enable threads support"		off
PLIST_SUB+=	THOL="@comment "
CONFLICTS=	sqlite-threads-3*
.else
CONFIGURE_ARGS+=	--enable-threadsafe --enable-threads-override-locks
PLIST_SUB+=	THOL=""
CONFLICTS=	sqlite-3*
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !defined(NOPORTDOCS) && !defined(WITHOUT_DOCS)
BUILD_DEPENDS+=		tclsh${TCL_V}:${PORTSDIR}/lang/tcl${TCL_V:S/.//}
ALL_TARGET+=		all doc
PORTDOCS=		*
.endif

.if defined(WITH_FTS1)
CFLAGS+=		-DSQLITE_ENABLE_FTS1
EXTRA_PATCHES=		${FILESDIR}/fts1_patch-Makefile.in
.endif

.if defined(WITH_TCLWRAPPER)
CATEGORIES+=		lang tcl${TCL_V:S/.//}
LIB_DEPENDS+=		tcl${TCL_V:S/.//}:${PORTSDIR}/lang/tcl${TCL_V:S/.//}
CONFIGURE_ARGS+=	--with-tcl=${LOCALBASE}/lib/tcl${TCL_V}
PLIST_SUB+=		WITH_TCLWRAPPER=""
.else
CONFIGURE_ARGS+=	--disable-tcl
PLIST_SUB+=		WITH_TCLWRAPPER="@comment "
.endif

.if defined(WITH_THREADS)
CONFIGURE_ARGS+=	--enable-threadsafe
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|tclsh \$$(TOP)|\$$(TCLSH) \$$(TOP)|g" \
		-e "s|./libtool|${LIBTOOL}|g" \
		-e "s|\$${HAVE_TCL:1=tcl_install}||" \
			${WRKSRC}/Makefile.in
	@${ECHO} "config_TARGET_TCL_INC=\"-I${PREFIX}/include/tcl${TCL_V}\"" \
		> ${WRKSRC}/freebsd.hints
	@${ECHO} "config_TARGET_TCL_LIBS=\"-L${PREFIX}/lib -ltcl${TCL_V:S/.//}\"" \
		>> ${WRKSRC}/freebsd.hints

pre-configure:
.if defined(WITH_THREADS) || defined(USE_THOL)
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g" \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -E -e "s|(Libs:.*)|\1 ${PTHREAD_LIBS}|" \
		-e "s|(Cflags:.*)|\1 ${PTHREAD_CFLAGS}|" \
		${WRKSRC}/sqlite.pc.in ${WRKSRC}/sqlite3.pc.in
.endif

post-install:
.if defined(WITH_TCLWRAPPER)
	@${MKDIR} ${PREFIX}/lib/sqlite
	@(cd ${WRKSRC} && ${LIBTOOL} --mode=install ${INSTALL_DATA} \
		libtclsqlite3.la ${PREFIX}/lib/sqlite/)
	@${INSTALL_DATA} ${FILESDIR}/pkgIndex.tcl ${PREFIX}/lib/sqlite/
	@${INSTALL_PROGRAM} ${WRKSRC}/.libs/tclsqlite3 ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${FILESDIR}/example.tcl ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS) && !defined(WITHOUT_DOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif
.if defined(USE_THOL)
	@${MKDIR} ${DATADIR}
	@${TOUCH} ${DATADIR}/sqlite3_with_threads-override-locks
.endif

.include <bsd.port.post.mk>
