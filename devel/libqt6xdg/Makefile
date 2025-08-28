PORTNAME=	libqt6xdg
PORTVERSION=	4.2.0
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	LXQT/${PORTNAME:S/6//}

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	Qt6 implementation of freedesktop.org xdg specs
WWW=		https://github.com/lxde/libqtxdg

LICENSE=	LGPL21+

USES=		cmake compiler:c++20-lang gnome lxqt:2 pkgconfig qt:6 tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	glib20
USE_LXQT=	buildtools2
USE_QT=		base:run tools:build svg

.include <bsd.port.mk>
