# $FreeBSD$

PORTNAME=	2048-qt
PORTVERSION=	0.1.6
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	swills@FreeBSD.org
COMMENT=	2048 game implemented in QT

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	xiaoyong
GH_PROJECT=	2048-Qt

USES=		compiler:c++11-lang gmake pkgconfig qmake qt:5
USE_QT=		core declarative gui network widgets buildtools_build quickcontrols

PLIST_FILES=	bin/2048-qt ${DESKTOPDIR}/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.png

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/2048-qt ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/res/icons/256x256/apps/2048-qt.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_DATA} ${WRKSRC}/res/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
