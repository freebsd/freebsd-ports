PORTNAME=	libqtxdg
PORTVERSION=	3.12.0
CATEGORIES=	devel
MASTER_SITES=	LXQT/${PORTNAME}

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Qt implementation of freedesktop.org xdg specs
WWW=		https://github.com/lxde/libqtxdg

LICENSE=	LGPL21+

USES=		cmake compiler:c++14-lang gnome lxqt pkgconfig qt:5 tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	glib20
USE_QT=		buildtools:build qmake:build core dbus gui svg widgets \
		xml
USE_LXQT=	buildtools
.include <bsd.port.mk>
