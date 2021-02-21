# $FreeBSD$

PORTNAME=	gammy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.64
CATEGORIES=	accessibility

MAINTAINER=	me@igalic.co
COMMENT=	Adaptive screen brightness and temperature for Windows and Unix

LICENSE=	GPLv3

USES=		compiler:c++11-lang gl qmake qt:5 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	Fushko
USE_GL=		gl
USE_QT=		core dbus gui widgets \
		buildtools_build qmake_build
USE_XORG=	x11 xext xxf86vm

PLIST_FILES=	bin/gammy \
		share/applications/gammy.desktop \
		share/pixmaps/gammy.png

.include <bsd.port.mk>
