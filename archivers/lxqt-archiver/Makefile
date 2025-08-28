PORTNAME=	lxqt-archiver
PORTVERSION=	1.2.0
PORTREVISION=	3
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
RUN_DEPENDS=	gtar:archivers/gtar

USES=		cmake compiler:c++20-lang desktop-file-utils lxqt:2 perl5 \
		pkgconfig tar:xz gnome qt:6 xorg

USE_GNOME=	glib20
USE_QT=		tools:build base:run
USE_LXQT=	buildtools2 libfmqt6 lxqt
USE_XORG=	xcb

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1400504
RUN_DEPENDS+=	unzip:archivers/unzip
.endif

.include <bsd.port.post.mk>
