PORTNAME=	gedit
DISTVERSION=	49.0
CATEGORIES=	editors gnome
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Small but powerful GTK text editor
WWW=		https://gitlab.gnome.org/World/gedit/gedit

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		itstool:textproc/itstool
LIB_DEPENDS=	libgspell-1.so:textproc/gspell \
		libpeas-gtk-1.0.so:devel/libpeas1 \
		libgedit-gtksourceview-300.so:x11-toolkits/libgedit-gtksourceview \
		libgedit-gfls-1.so:filesystems/libgedit-gfls \
		libgedit-amtk-5.so:x11-toolkits/amtk \
		libgedit-tepl-6.so:x11-toolkits/tepl6

USES=		compiler:c11 cpe desktop-file-utils gettext gnome localbase \
		meson pkgconfig tar:xz vala:build
USE_CSTD=	c11
USE_GNOME=	glib20 gtk30 introspection
#USE_LDCONFIG=	yes
PLIST_SUB=	VERSION=49
MESON_ARGS=	-Dgtk_doc=false
CPE_VENDOR=	gnome

USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World/gedit
GL_TUPLE=	GNOME:libgd:3cccf992:libgd/subprojects/libgd

PORTSCOUT=	limit:^48\.

GLIB_SCHEMAS=	org.gnome.gedit.enums.xml \
		org.gnome.gedit.gschema.xml \
		org.gnome.gedit.plugins.filebrowser.enums.xml \
		org.gnome.gedit.plugins.filebrowser.gschema.xml \
		org.gnome.gedit.plugins.spell.gschema.xml \
		org.gnome.gedit.plugins.time.enums.xml \
		org.gnome.gedit.plugins.time.gschema.xml

.include <bsd.port.mk>
