# $FreeBSD$

PORTNAME=	gammy
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.61
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
USE_XORG=	x11 xxf86vm

PLIST_FILES=	bin/gammy

.include <bsd.port.mk>
