PORTNAME=	gedit
PORTVERSION=	44.2
PORTREVISION=	1
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Small but powerful text editor for the GNOME Desktop Environment
WWW=		https://www.gnome.org/projects/gedit/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		gtk-doc>0:textproc/gtk-doc \
		iso-codes>=0:misc/iso-codes \
		itstool:textproc/itstool
LIB_DEPENDS=	libamtk-5.so:x11-toolkits/amtk \
		libenchant.so:textproc/enchant \
		libgspell-1.so:textproc/gspell \
		libpeas-gtk-1.0.so:devel/libpeas \
		libsoup-2.4.so:devel/libsoup \
		libtepl-6.so:x11-toolkits/tepl6

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libpeas>=0:devel/py-libpeas@${PY_FLAVOR} \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		iso-codes>=0:misc/iso-codes

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 cpe desktop-file-utils gettext gnome localbase \
		meson pkgconfig python tar:xz vala:build xorg
USE_CSTD=	c11
USE_GNOME=	cairo gdkpixbuf2 gtksourceview4 intlhack introspection libxml2 \
		pygobject3
USE_XORG=	sm x11
USE_LDCONFIG=	yes
PLIST_SUB=	VERSION=44
INSTALL_TARGET=	install-strip
MESON_ARGS+=	--buildtype \
		plain
BINARY_ALIAS=	python3=${PYTHON_CMD}
CPE_VENDOR=	gnome

GLIB_SCHEMAS=	org.gnome.gedit.enums.xml \
		org.gnome.gedit.gschema.xml \
		org.gnome.gedit.plugins.externaltools.gschema.xml \
		org.gnome.gedit.plugins.filebrowser.enums.xml \
		org.gnome.gedit.plugins.filebrowser.gschema.xml \
		org.gnome.gedit.plugins.pythonconsole.gschema.xml \
		org.gnome.gedit.plugins.spell.gschema.xml \
		org.gnome.gedit.plugins.time.enums.xml \
		org.gnome.gedit.plugins.time.gschema.xml

.include <bsd.port.mk>
