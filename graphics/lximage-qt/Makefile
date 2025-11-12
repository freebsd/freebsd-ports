PORTNAME=	lximage-qt
PORTVERSION=	2.3.0
CATEGORIES=	graphics
MASTER_SITES=	LXQT

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	Image viewer
WWW=		https://github.com/lxde/lximage-qt

LICENSE=	GPLv2

LIB_DEPENDS=	libexif.so:graphics/libexif \
		libmenu-cache.so:x11/menu-cache

USES=		cmake compiler:c++20-lang desktop-file-utils gettext-runtime \
		gnome localbase:ldflags lxqt:2 perl5 pkgconfig qt:6 gnome tar:xz xorg

USE_GNOME=	glib20
USE_PERL5=	build
USE_QT=		base:run tools:build svg
USE_LXQT=	buildtools2 libfmqt6
USE_XORG=	ice sm x11 xcb xext xfixes

.include <bsd.port.mk>
