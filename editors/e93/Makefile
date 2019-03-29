# Created by: Satoshi Asami (asami)
# $FreeBSD$

PORTNAME=	e93
PORTVERSION=	1.4.2
CATEGORIES=	editors tcl
MASTER_SITES=	http://www.sqrt.com/downloads/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tcl-based text editor oriented to the programmers

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

USES=		tar:tgz tcl
USE_XORG=	x11 xinerama

MAKE_ENV=	TCL_VERSION=${TCL_SHLIB_VER}

PORTDOCS=	README* TODO

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -E \
		'/^TCL_INCLUDE=/s,/usr/local/include,${TCL_INCLUDEDIR}, \
		;/^X_(INCLUDE|LIB)=/s,/usr/X11R6,${LOCALBASE}, \
		;/^EXTRALIBS=/s, -ldl,, \
		;/^OPTIONS=/s,-O2.*-g,${CFLAGS}, \
		;/^(PREFIX|CC)/s,=,?=,' ${WRKSRC}/machdef.mk
	@${REINPLACE_CMD} -e '30s,^,#include	<stdbool.h>,' \
		${WRKSRC}/includes.h
	@${REINPLACE_CMD} -E '/X11\/(Intrinsic|Shell)\.h/d' \
		${WRKSRC}/xgui/includes.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/e93 ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/e93lib
	cd ${WRKSRC}/e93lib && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/e93lib

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
