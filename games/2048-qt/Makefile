# $FreeBSD$

PORTNAME=	2048-qt
PORTVERSION=	0.1.5
DISTVERSIONPREFIX=	v
CATEGORIES=	games
MASTER_SITES=	GH

MAINTAINER=	swills@FreeBSD.org
COMMENT=	2048 game implemented in QT

USE_GITHUB=	yes
GH_ACCOUNT=	xiaoyong
GH_PROJECT=	2048-Qt

USES=		gmake pkgconfig qmake tar:bzip2
USE_QT5=	core gui network widgets qml quick buildtools quickcontrols

PLIST_FILES=	bin/2048-qt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/2048-qt ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
