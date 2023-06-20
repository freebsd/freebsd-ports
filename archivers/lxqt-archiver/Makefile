PORTNAME=	lxqt-archiver
PORTVERSION=	0.8.0
CATEGORIES=	archivers
MASTER_SITES=	LXQT

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Qt file archiver
WWW=		https://github.com/lxqt/lxqt-archiver

LICENSE=	GPLv2

LIB_DEPENDS=	libfm-qt.so:x11/libfm-qt \
		libjson-glib-1.0.so:devel/json-glib \
		libmenu-cache.so:x11/menu-cache \
		libexif.so:graphics/libexif
RUN_DEPENDS=	${LOCALBASE}/bin/gtar:archivers/gtar \
		${LOCALBASE}/bin/unzip:archivers/unzip

USES=	cmake compiler:c++14-lang desktop-file-utils lxqt perl5 pkgconfig tar:xz gnome qt:5 xorg

USE_GNOME=	glib20
USE_PERL5=	build
USE_QT=		buildtools:build qmake:build core dbus gui linguisttools \
		network printsupport svg widgets x11extras
USE_LXQT=	buildtools lxqt
USE_XORG=	xcb

.include <bsd.port.mk>
