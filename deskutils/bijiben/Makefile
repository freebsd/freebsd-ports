# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	bijiben
PORTVERSION=	3.28.3
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Note editor designed to remain simple to use

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libtracker-control-2.0.so:sysutils/tracker \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libgoa-1.0.so:net/gnome-online-accounts \
		libical.so:devel/libical \
		libzeitgeist-2.0.so:sysutils/zeitgeist \
		libuuid.so:misc/e2fsprogs-libuuid

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lib desktop-file-utils gettext gnome \
		localbase meson pkgconfig python:build,3.4+ \
		shared-mime-info shebangfix tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	cairo evolutiondataserver3 intltool
INSTALLS_ICONS=	yes
MESON_ARGS=	-Dzeitgeist=true
SHEBANG_FILES=	${WRKSRC}/build-aux/meson_post_install.py

GLIB_SCHEMAS=	org.gnome.bijiben.gschema.xml \
		org.gnome.bijiben.enums.xml

.include <bsd.port.mk>
