# New ports collection makefile for:	sqlite3
# Date created:				Feb 21, 2001
# Whom:					Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sqlite3
PORTVERSION=	3.6.14.2
CATEGORIES=	databases
MASTER_SITES=	http://www.sqlite.org/
DISTNAME=	sqlite-${PORTVERSION}

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	An SQL database engine in a C library

CONFLICTS=	sqlite34-[0-9]*

USE_GMAKE=	YES
USE_GNOME=	pkgconfig
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=		--prefix=${PREFIX}
CONFIGURE_ENV+=	TCLLIBDIR=${PREFIX}/lib/${PORTNAME}

OPTIONS=	DEBUG		"Enable debugging & verbose explain"	off \
		FTS3		"Enable FTS3 (Full Text Search) module"	off \
		RAMTABLE	"Store temporary tables in RAM"		off \
		TCLWRAPPER	"Enable TCL wrapper"			off \
		METADATA	"Enable column metadata"		on \
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
USE_TCL=		84+
.include		"${PORTSDIR}/Mk/bsd.tcl.mk"
MAKE_ARGS+=		TCLSH=${TCLSH}
MAKE_ENV+=		TCL_VER=${TCL_VER}
CATEGORIES+=		lang tcl
COMMENT+=		with TCL Wrapper
CONFIGURE_ARGS+=	--with-tcl=${TCL_LIBDIR}
PLIST_SUB+=		WITH_TCLWRAPPER=""
.else
CONFIGURE_ARGS+=	--disable-tcl
PLIST_SUB+=		WITH_TCLWRAPPER="@comment "
.endif

.if !defined(WITHOUT_METADATA)
CFLAGS+=		-DSQLITE_ENABLE_COLUMN_METADATA=1
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
	@${REINPLACE_CMD} -e "s|fts3.c||g" \
		-e "s|fts3_expr.c||g" ${WRKSRC}/tool/mksqlite3c.tcl

post-install:
.if defined(WITH_TCLWRAPPER)
	@${MKDIR} ${PREFIX}/lib/sqlite3
	@(cd ${WRKSRC} && ${LIBTOOL} --mode=install ${INSTALL_DATA} \
		libtclsqlite3.la ${PREFIX}/lib/sqlite3/)
	@${INSTALL_DATA} ${FILESDIR}/pkgIndex.tcl ${PREFIX}/lib/sqlite3/
	@${INSTALL_PROGRAM} ${WRKSRC}/.libs/tclsqlite3 ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${FILESDIR}/example.tcl ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
