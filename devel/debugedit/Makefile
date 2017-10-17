# Created by: sobomax
# $FreeBSD$

PORTNAME=	debugedit
PORTVERSION=	20170411.1
CATEGORIES=	devel

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	ELF file debug information extractor and editor

LICENSE=	GPLv2+

LIB_DEPENDS=	libpopt.so:devel/popt

USE_GITHUB=	yes
GH_ACCOUNT=	CoryXie
GH_PROJECT=	DebugEdit
GH_TAGNAME=	b1e81ec

USES=		gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/debugedit ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
