# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libqtxdg
PORTVERSION=	3.3.0
CATEGORIES=	devel
MASTER_SITES=	LXQT/${PORTNAME}

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Qt implementation of freedesktop.org xdg specs

LICENSE=	LGPL21+

USES=		cmake compiler:c++14-lang lxqt pkgconfig qt:5 tar:xz
USE_LDCONFIG=	yes
USE_QT=		buildtools_build qmake_build core dbus gui svg widgets \
		xml

.include <bsd.port.mk>
