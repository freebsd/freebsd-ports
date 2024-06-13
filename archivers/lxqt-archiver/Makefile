PORTNAME=	lxqt-archiver
PORTVERSION=	1.0.0
CATEGORIES=	archivers
MASTER_SITES=	LXQT

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	Qt6 file archiver
WWW=		https://github.com/lxqt/lxqt-archiver

LICENSE=	GPLv2

LIB_DEPENDS=	libfm-qt6.so:x11/libfm-qt6 \
		libjson-glib-1.0.so:devel/json-glib \
		libmenu-cache.so:x11/menu-cache \
		libexif.so:graphics/libexif
RUN_DEPENDS=	gtar:archivers/gtar \
		unzip:archivers/unzip

USES=		cmake compiler:c++17-lang desktop-file-utils lxqt:2 perl5 \
		pkgconfig tar:xz gnome qt:6 xorg

USE_GNOME=	glib20
USE_QT=		tools:build base:run
USE_LXQT=	buildtools2 libfmqt6 lxqt
USE_XORG=	xcb

.include <bsd.port.mk>
