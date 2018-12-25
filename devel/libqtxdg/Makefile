# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libqtxdg
PORTVERSION=	3.2.0
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	LXQT/${PORTNAME}

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Qt implementation of freedesktop.org xdg specs

LICENSE=	LGPL21+

USES=		cmake compiler:c++11-lib lxqt pkgconfig qt:5 tar:xz
USE_LDCONFIG=	yes
USE_QT=		buildtools_build qmake_build core dbus gui svg widgets \
		xml

.include <bsd.port.mk>
