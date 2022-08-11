PORTNAME=	gnome-text-editor
PORTVERSION=	42.2
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Small but powerful text editor for the GNOME Desktop Environment

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool>0:textproc/itstool
LIB_DEPENDS=	libenchant-2.so:textproc/enchant2 \
		libicudata.so:devel/icu \
		libpcre2-8.so:devel/pcre2

USES=		compiler:c11 desktop-file-utils gettext gnome localbase meson \
		pkgconfig tar:xz
USE_CSTD=	c11
USE_GNOME=	gtk40 gtksourceview5 libadwaita
GLIB_SCHEMAS=	org.gnome.TextEditor.gschema.xml

PORTSCOUT=	limitw:1,even

.include <bsd.port.mk>
