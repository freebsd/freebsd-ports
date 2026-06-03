PORTNAME=	bijiben
PORTVERSION=	40.1
PORTREVISION=	10
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Note editor designed to remain simple to use
WWW=		https://wiki.gnome.org/Apps/Bijiben

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libtinysparql-3.0.so:devel/tinysparql \
		libwebkit2gtk-4.0.so:www/webkit2-gtk@40 \
		libgoa-1.0.so:net/gnome-online-accounts \
		libical.so:devel/libical \
		libuuid.so:misc/libuuid \
		libhandy-1.so:x11-toolkits/libhandy

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lib desktop-file-utils gettext gnome \
		localbase meson pkgconfig python:build \
		shared-mime-info shebangfix tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	cairo evolutiondataserver3 intltool
SHEBANG_FILES=	${WRKSRC}/build-aux/meson_post_install.py

GLIB_SCHEMAS=	org.gnome.Notes.gschema.xml

.include <bsd.port.mk>
