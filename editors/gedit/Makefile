# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>

PORTNAME=	gedit
PORTVERSION=	40.1
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Small but powerful text editor for GNOME 3 Desktop Environment

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	iso-codes>=0:misc/iso-codes \
		vala:lang/vala \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		itstool:textproc/itstool
LIB_DEPENDS=	libenchant.so:textproc/enchant \
		libpeas-gtk-1.0.so:devel/libpeas \
		libgspell-1.so:textproc/gspell \
		libsoup-2.4.so:devel/libsoup \
		libtepl-6.so:x11-toolkits/tepl6 \
		libamtk-5.so:x11-toolkits/amtk

RUN_DEPENDS=	iso-codes>=0:misc/iso-codes \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		${PYTHON_PKGNAMEPREFIX}libpeas>=0:devel/py-libpeas@${PY_FLAVOR}

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 desktop-file-utils gettext gnome localbase meson \
		pkgconfig python:3.4+ tar:xz xorg
USE_CSTD=	c11
USE_GNOME=	cairo gdkpixbuf2 gtksourceview4 intlhack introspection \
		libxml2 pygobject3
USE_XORG=	sm x11
USE_LDCONFIG=	yes
PLIST_SUB=	VERSION=${PORTVERSION:R}.0
INSTALL_TARGET=	install-strip
MESON_ARGS+=	--buildtype plain
BINARY_ALIAS=	python3=${PYTHON_CMD}

GLIB_SCHEMAS=	org.gnome.gedit.enums.xml \
		org.gnome.gedit.plugins.externaltools.gschema.xml \
		org.gnome.gedit.gschema.xml \
		org.gnome.gedit.plugins.filebrowser.enums.xml \
		org.gnome.gedit.plugins.filebrowser.gschema.xml \
		org.gnome.gedit.plugins.pythonconsole.gschema.xml \
		org.gnome.gedit.plugins.time.enums.xml \
		org.gnome.gedit.plugins.time.gschema.xml \
		org.gnome.gedit.plugins.spell.gschema.xml

.include <bsd.port.mk>
