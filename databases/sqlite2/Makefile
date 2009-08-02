# ex:ts=8
# New ports collection makefile for:	sqlite
# Date created:			Feb 21, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sqlite
PORTVERSION=	2.8.17
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.sqlite.org/

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	An SQL database engine in a C library

USE_GMAKE=	YES
USE_GNOME=	pkgconfig
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	YES

CONFIGURE_ARGS=		--prefix=${PREFIX} --with-hints=freebsd.hints

DOCSDIR=	${PREFIX}/share/doc/sqlite2
EXAMPLESDIR=	${PREFIX}/share/examples/sqlite2

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}2

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude CVS

OPTIONS=	TCLWRAPPER	"Enable TCL wrapper"			off \
		THREADS		"Compile with threads support"		off \
		DOCS		"Building docs (depends on TCL)"	on

.include <bsd.port.pre.mk>

# Deprecated options
.if defined(SQLITE_WITH_TCL83) || defined(WITH_TCL83)
WITH_TCL_VER=		83
WITH_TCLWRAPPER=	yes
.endif
.if defined(SQLITE_WITH_TCL84) || defined(WITH_TCL84)
WITH_TCL_VER=		84
WITH_TCLWRAPPER=	yes
.endif

.if defined(WITHOUT_DOCS)
NOPORTDOCS=		yes
.elif defined(NOPORTDOCS)
WITHOUT_DOCS=		yes
.endif

.if defined(WITH_TCLWRAPPER)
USE_TCL=		83+
.include		"${PORTSDIR}/Mk/bsd.tcl.mk"
.else
. if !defined(WITHOUT_DOCS)
USE_TCL_BUILD=		83+
. include		"${PORTSDIR}/Mk/bsd.tcl.mk"
. endif
.endif

.if defined(WITH_TCLWRAPPER)
CATEGORIES+=	lang tcl
COMMENT+=	with TCL wrapper
MAKE_ARGS+=	TCLSH=${TCLSH}
MAKE_ENV+=	TCL_VER=${TCL_VER}
PLIST_SUB+=	WITH_TCLWRAPPER=""
.else
PLIST_SUB+=	WITH_TCLWRAPPER="@comment "
.endif

.if !defined(WITHOUT_DOCS)
PORTDOCS=	*
MAKE_ARGS+=	TCLSH=${TCLSH}
MAKE_ENV+=	TCL_VER=${TCL_VER}
.endif

post-patch:
	@${REINPLACE_CMD} -e "s/tclsh \$$(TOP)/\$$(TCLSH) \$$(TOP)/g" \
		 -e "s|\./libtool|${LIBTOOL}|g" ${WRKSRC}/Makefile.in
.if defined(WITH_TCLWRAPPER) || !defined(WITHOUT_DOCS)
	@${ECHO} "config_TARGET_TCL_INC=\"-I${TCL_INCLUDEDIR}\"" \
		> ${WRKSRC}/freebsd.hints
	@${ECHO} "config_TARGET_TCL_LIBS=\"-L${PREFIX}/lib -ltcl${TCL_VER:S/.//}\"" \
		>> ${WRKSRC}/freebsd.hints
.else
	@${ECHO} "" > ${WRKSRC}/freebsd.hints
.endif
.if defined(WITH_THREADS)
	@${ECHO} "config_TARGET_CFLAGS=\"-DTHREADSAFE=1 ${PTHREAD_LIBS}\"" \
		>> ${WRKSRC}/freebsd.hints
.endif

post-build:
.if !defined(NOPORTDOCS) && !defined(WITHOUT_DOCS)
	@${ECHO_MSG} "===> Building docs"
	@(cd ${WRKSRC} && ${GMAKE} ${MAKE_ARGS} doc)
.endif

post-install:
.if defined(WITH_TCLWRAPPER)
	@(cd ${WRKSRC} && ${GMAKE} install-tcl)
	${INSTALL_DATA} ${FILESDIR}/pkgIndex.tcl ${PREFIX}/lib/sqlite/
.endif
.if !defined(NOPORTDOCS) && !defined(WITHOUT_DOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/example.tcl ${EXAMPLESDIR}

.include <bsd.port.post.mk>
