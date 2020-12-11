# $FreeBSD$

PORTNAME=	gammy
PORTVERSION=	0.9.59
DISTVERSIONPREFIX=	v
CATEGORIES=	accessibility

MAINTAINER=	me@igalic.co
COMMENT=	Adaptive screen brightness and temperature for Windows and Unix

LICENSE=	GPLv3

USES=		compiler:c++11-lang gl qmake qt:5 xorg
USE_QT=		core dbus gui widgets \
		buildtools_build qmake_build
USE_GL=		gl
USE_XORG=	x11 xxf86vm

USE_GITHUB=	YES
GH_ACCOUNT=	Fushko

PLIST_FILES=	bin/gammy

.include <bsd.port.mk>
