# Created by: Gustau Perez <gustau.perez@gmail.com>

PORTNAME=	bijiben
PORTVERSION=	40.1
PORTREVISION=	4
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

PATCH_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/commit/
PATCHFILES+=	01ccae2ccb64.patch:-p1 # https://gitlab.gnome.org/GNOME/bijiben/-/merge_requests/158

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Note editor designed to remain simple to use

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libtracker-sparql-3.0.so:sysutils/tracker3 \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libgoa-1.0.so:net/gnome-online-accounts \
		libical.so:devel/libical \
		libuuid.so:misc/e2fsprogs-libuuid \
		libhandy-1.so:x11-toolkits/libhandy

PORTSCOUT=	limitw:1,even

USES=		compiler:c++11-lib desktop-file-utils gettext gnome \
		localbase meson pkgconfig python:build,3.4+ \
		shared-mime-info shebangfix tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	cairo evolutiondataserver3 intltool
SHEBANG_FILES=	${WRKSRC}/build-aux/meson_post_install.py

GLIB_SCHEMAS=	org.gnome.Notes.gschema.xml

.include <bsd.port.mk>
