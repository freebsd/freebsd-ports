# Created by: Satoshi Asami (asami)
# $FreeBSD$

PORTNAME=	e93
PORTVERSION=	1.4.3
CATEGORIES=	editors tcl
MASTER_SITES=	http://www.sqrt.com/downloads/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tcl-based, programmer-oriented text editor

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

USES=		compiler:c11 tar:tgz tcl xorg
USE_XORG=	x11 xinerama xmu

MAKE_ENV=	TCL_INCLUDEDIR=${TCL_INCLUDEDIR} TCL_VERSION=${TCL_SHLIB_VER}

PORTDOCS=	README* TODO

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/e93 ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/e93lib
	cd ${WRKSRC}/e93lib && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/e93lib

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
