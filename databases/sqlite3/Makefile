# New ports collection makefile for:	sqlite3
# Date created:				Feb 21, 2001
# Whom:					Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sqlite3
PORTVERSION=	3.5.6
CATEGORIES=	databases
MASTER_SITES=	http://www.sqlite.org/
DISTNAME=	sqlite-${PORTVERSION}

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	An SQL database engine in a C library w/ Tcl wrapper

CONFLICTS=	sqlite34-[0-9]*

USE_GMAKE=	YES
USE_GNOME=	pkgconfig
USE_AUTOTOOLS=	libtool:15
USE_DOS2UNIX=	*.pc.in
USE_LDCONFIG=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=		--prefix=${PREFIX}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

OPTIONS=	DEBUG		"Enable debugging & verbose explain"	off \
		FTS3		"Enable FTS3 (Full Text Search) module"	off \
		RAMTABLE	"Store temporary tables in RAM"		off \
		TCLWRAPPER	"TCL wrapper for SQLITE"		off \
		THREADS		"Enable threads support"		on

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_FTS3)
CFLAGS+=		-DSQLITE_CORE=1 -DSQLITE_ENABLE_FTS3=1
EXTRA_PATCHES+=		${FILESDIR}/fts3_patch-Makefile.in
.endif

.if defined(WITH_RAMTABLE)
CONFIGURE_ARGS+=	--enable-tempstore=yes
.endif

.if defined(WITH_TCLWRAPPER)
TCL_V?=			8.4
MAKE_ARGS+=		TCLSH=tclsh${TCL_V}
MAKE_ENV+=		TCL_VER=${TCL_V}
CATEGORIES+=		lang tcl
LIB_DEPENDS+=		tcl${TCL_V:S/.//}:${PORTSDIR}/lang/tcl${TCL_V:S/.//}
CONFIGURE_ARGS+=	--with-tcl=${LOCALBASE}/lib/tcl${TCL_V}
PLIST_SUB+=		WITH_TCLWRAPPER=""
.else
CONFIGURE_ARGS+=	--disable-tcl
PLIST_SUB+=		WITH_TCLWRAPPER="@comment "
.endif

.if !defined(WITHOUT_THREADS)
CONFIGURE_ARGS+=	--enable-threadsafe \
			--enable-cross-thread-connections \
			--enable-threads-override-locks
.else
CONFIGURE_ARGS+=	--disable-threadsafe
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|tclsh \$$(TOP)|\$$(TCLSH) \$$(TOP)|g" \
		-e "s|./libtool|${LIBTOOL}|g" \
		-e "s|--mode=link|--mode=link --tag=CC|g" \
		-e "s|\$${HAVE_TCL:1=tcl_install}||" \
			${WRKSRC}/Makefile.in
.if !defined(WITHOUT_THREADS)
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g" \
		${WRKSRC}/configure ${WRKSRC}/sqlite.pc.in \
		${WRKSRC}/sqlite3.pc.in
.else
	@${REINPLACE_CMD} -E -e "s|-lpthread||g" \
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

.include <bsd.port.post.mk>
