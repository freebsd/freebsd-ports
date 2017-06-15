# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tuxcards
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://www.tuxcards.de/src/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for managing notes within a hierarchical tree

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		qmake
USE_QT4=	gui xml moc_build uic_build rcc_build

PLIST_FILES=	bin/tuxcards

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
