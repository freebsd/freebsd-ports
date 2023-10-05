PORTNAME=	gnome-text-editor
PORTVERSION=	42.2
PORTREVISION=	5
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Small but powerful text editor for the GNOME Desktop Environment
WWW=		https://gitlab.gnome.org/GNOME/gnome-text-editor

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool>0:textproc/itstool
LIB_DEPENDS=	libenchant-2.so:textproc/enchant2 \
		libicudata.so:devel/icu \
		libpcre.so:devel/pcre

USES=		compiler:c11 desktop-file-utils gettext gnome localbase meson \
		pkgconfig tar:xz
USE_CSTD=	c11
USE_GNOME=	cairo gtk40 gtksourceview5 libadwaita
GLIB_SCHEMAS=	org.gnome.TextEditor.gschema.xml

PORTSCOUT=	limitw:1,even

.include <bsd.port.mk>
