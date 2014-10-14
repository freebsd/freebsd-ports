# $FreeBSD$

PORTNAME=	homerun
PORTVERSION=	0.2.3
CATEGORIES=	deskutils
MASTER_SITES=	http://download.kde.org/unstable/homerun/src/

MAINTAINER=	yurkis@gmail.com
COMMENT=	Homerun is a fullscreen launcher with content organized in tabs. 

USES=	cmake tar:bzip2
USE_KDE4=	kdehier kdelibs kdeprefix automoc4 workspace
USE_QT4=	moc_build qmake_build rcc_build uic_build corelib gui
USE_XORG=	x11
CMAKE_ARGS+=	-DROOT_PREFIX:PATH=${STAGEDIR}

.include <bsd.port.mk>
