# Created by: ijliao
# $FreeBSD$

PORTNAME=	lfhex
PORTVERSION=	0.42
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://stoopidsimple.com/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Large file hex editor

LICENSE=	GPLv2

USE_QT4=	corelib gui moc_build rcc_build
USES=		bison qmake

WRKSRC=		${WRKDIR}/${DISTNAME}/src

PORTDOCS=	README
PLIST_FILES=	bin/lfhex
LICENSE_FILES=	${WRKSRC}/../COPYING

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|^DEFINES|# DEFINES|g' ${WRKSRC}/lfhex.pro
	@${REINPLACE_CMD} -e 's| abs| llabs|g' ${WRKSRC}/reader.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lfhex ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../README ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
