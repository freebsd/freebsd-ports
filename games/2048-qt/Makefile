# $FreeBSD$

PORTNAME=	2048-qt
PORTVERSION=	0.1.5
CATEGORIES=	games
MASTER_SITES=	GH

MAINTAINER=	swills@FreeBSD.org
COMMENT=	2048 game implemented in QT

USE_GITHUB=	yes
GH_ACCOUNT=	xiaoyong
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	v${DISTVERSION}

USES=		gmake pkgconfig qmake tar:bzip2
USE_QT5=	core gui network widgets qml quick buildtools quickcontrols

WRKSRC=		${WRKDIR}/2048-Qt-${PORTVERSION}
PLIST_FILES=	bin/2048-qt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/2048-qt ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
