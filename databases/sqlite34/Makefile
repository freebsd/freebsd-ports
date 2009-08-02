# New ports collection makefile for:	sqlite3
# Date created:				Feb 21, 2001
# Whom:					Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sqlite34
PORTVERSION=	3.4.2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	mnag/${PORTNAME}
DISTNAME=	sqlite-${PORTVERSION}

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	An SQL database engine in a C library

CONFLICTS=	sqlite3-[0-9]*

USE_GMAKE=	YES
USE_GNOME=	pkgconfig
USE_AUTOTOOLS=	libtool:22
USE_DOS2UNIX=	*.pc.in
USE_LDCONFIG=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=		--prefix=${PREFIX} --with-hints=freebsd.hints

OPTIONS=	DEBUG		"Enable debugging & verbose explain"	off \
		DOCS		"Building docs (depends on TCL)"	on \
		FTS1		"Enable FTS1 (Full Text Search) module"	off \
		FTS2		"Enable FTS2 (Full Text Search) module"	off \
		TCLWRAPPER	"Enable TCL wrapper"			off \
		THREADS		"Enable threads support"		off

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITHOUT_DOCS)
NOPORTDOCS=		yes
.elif defined(NOPORTDOCS)
WITHOUT_DOCS=		yes
.endif

.if defined(WITH_TCLWRAPPER)
USE_TCL=		84+
.include		"${PORTSDIR}/Mk/bsd.tcl.mk"
.else
. if !defined(WITHOUT_DOCS)
USE_TCL_BUILD=		84+
. include		"${PORTSDIR}/Mk/bsd.tcl.mk"
. endif
.endif

.if !defined(WITHOUT_DOCS)
MAKE_ARGS+=		TCLSH=${TCLSH}
MAKE_ENV+=		TCL_VER=${TCL_VER}
ALL_TARGET+=		all doc
PORTDOCS=		*
.endif

.if defined(WITH_FTS1) && defined(WITH_FTS2)
CFLAGS+=		-DSQLITE_CORE -DSQLITE_ENABLE_FTS1 -DSQLITE_ENABLE_FTS2
EXTRA_PATCHES+=		${FILESDIR}/fts12_patch-Makefile.in
.elif defined(WITH_FTS1) && !defined(WITH_FTS2)
CFLAGS+=		-DSQLITE_CORE -DSQLITE_ENABLE_FTS1
EXTRA_PATCHES+=		${FILESDIR}/fts1_patch-Makefile.in
.elif defined(WITH_FTS2) && !defined(WITH_FTS1)
CFLAGS+=		-DSQLITE_CORE -DSQLITE_ENABLE_FTS2
EXTRA_PATCHES+=		${FILESDIR}/fts2_patch-Makefile.in
.endif

.if defined(WITH_TCLWRAPPER)
CATEGORIES+=		lang tcl
COMMENT+=		with TCL wrapper
MAKE_ARGS+=		TCLSH=${TCLSH}
MAKE_ENV+=		TCL_VER=${TCL_VER}
CONFIGURE_ARGS+=	--with-tcl=${TCL_LIBDIR}
PLIST_SUB+=		WITH_TCLWRAPPER=""
.else
CONFIGURE_ARGS+=	--disable-tcl
PLIST_SUB+=		WITH_TCLWRAPPER="@comment "
.endif

.if defined(WITH_THREADS)
CONFIGURE_ARGS+=	--enable-threadsafe --enable-threads-override-locks
.endif

post-patch:
	@${REINPLACE_CMD} -E -e "s|^(TLIBS.*)|\1 -lm|g" \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|tclsh \$$(TOP)|\$$(TCLSH) \$$(TOP)|g" \
		-e "s|./libtool|${LIBTOOL}|g" \
		-e "s|--mode=link|--mode=link --tag=CC|g" \
		-e "s|\$${HAVE_TCL:1=tcl_install}||" \
			${WRKSRC}/Makefile.in
	@${ECHO} "config_TARGET_TCL_INC=\"-I${TCL_INCLUDEDIR}\"" \
		> ${WRKSRC}/freebsd.hints
	@${ECHO} "config_TARGET_TCL_LIBS=\"-L${PREFIX}/lib -ltcl${TCL_VER:S/.//}\"" \
		>> ${WRKSRC}/freebsd.hints

pre-configure:
.if defined(WITH_THREADS)
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
.if !defined(WITHOUT_DOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
