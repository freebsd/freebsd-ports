PORTNAME=	libqtxdg
PORTVERSION=	3.12.0
CATEGORIES=	devel
MASTER_SITES=	LXQT/${PORTNAME}

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	Qt implementation of freedesktop.org xdg specs
WWW=		https://github.com/lxde/libqtxdg

LICENSE=	LGPL21+

USES=		cmake compiler:c++17-lang gnome lxqt:1 pkgconfig qt:5 tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	glib20
USE_QT=		buildtools:build qmake:build core dbus gui svg widgets \
		xml
USE_LXQT=	buildtools

post-extract:
	@${MV} ${WRKSRC}/config/lxqt-qtxdg.conf ${WRKSRC}/config/lxqt-qtxdg-legacy.conf
	@${MV} ${WRKSRC}/config/qtxdg.conf ${WRKSRC}/config/qtxdg-legacy.conf

.include <bsd.port.mk>
