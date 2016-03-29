# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lfhex
PORTVERSION=	0.42
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://stoopidsimple.com/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Large file hex editor

LICENSE=	GPLv2 # only
LICENSE_FILE=	${WRKSRC}/../COPYING

USES=		bison qmake
USE_QT4=	corelib gui moc_build rcc_build

WRKSRC_SUBDIR=	src

PORTDOCS=	README
PLIST_FILES=	bin/lfhex

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|^DEFINES|# DEFINES|g' ${WRKSRC}/lfhex.pro
	@${REINPLACE_CMD} -e 's| abs| llabs|g' ${WRKSRC}/reader.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lfhex ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
