# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tuxcards
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://www.tuxcards.de/src/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for managing notes within a hierarchical tree

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		qmake qt:4
USE_QT=		gui xml moc_build uic_build rcc_build

PLIST_FILES=	bin/tuxcards

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
