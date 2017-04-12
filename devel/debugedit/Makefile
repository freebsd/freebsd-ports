# Created by: sobomax
# $FreeBSD$

PORTNAME=	debugedit
PORTVERSION=	20170411.1
#PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	ELF file debug information extractor and editor

LICENSE=	GPLv2

LIB_DEPENDS=	libpopt.so:devel/popt

USE_GITHUB=	yes
GH_ACCOUNT=	CoryXie
GH_TAGNAME=	b1e81ec

USES=		gmake

WRKSRC=		${WRKDIR}/DebugEdit-${GH_TAGNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/debugedit ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
