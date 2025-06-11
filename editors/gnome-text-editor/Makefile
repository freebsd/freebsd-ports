PORTNAME=	gnome-text-editor
PORTVERSION=	47.4
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Small but powerful text editor for the GNOME Desktop Environment
WWW=		https://apps.gnome.org/TextEditor/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

PORTSCOUT=	limit:^47\.

BUILD_DEPENDS=	itstool>0:textproc/itstool
LIB_DEPENDS=	libenchant-2.so:textproc/enchant2 \
		libicudata.so:devel/icu \
		libpcre2-8.so:devel/pcre2 \
		libspelling-1.so:x11-toolkits/libspelling \
		libeditorconfig.so:editors/editorconfig-core-c

USES=		compiler:c11 desktop-file-utils gettext gnome localbase meson \
		pkgconfig tar:xz
USE_CSTD=	c11
USE_GNOME=	cairo glib20 gtk40 gtksourceview5 libadwaita
GLIB_SCHEMAS=	org.gnome.TextEditor.gschema.xml

.include <bsd.port.mk>
