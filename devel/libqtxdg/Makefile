# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libqtxdg
PORTVERSION=	3.2.0
CATEGORIES=	devel
MASTER_SITES=	LXQT/${PORTNAME}

MAINTAINER=	jesper@schmitz.computer
COMMENT=	Qt implementation of freedesktop.org xdg specs

LICENSE=	LGPL21+

USES=	cmake:outsource compiler:c++11-lib lxqt pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_QT5=	buildtools_build qmake_build core dbus gui svg widgets \
	xml

.include <bsd.port.mk>
