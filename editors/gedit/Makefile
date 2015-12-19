# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gedit
PORTVERSION=	3.16.4
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Small but powerful text editor for GNOME 3 Desktop Environment

BUILD_DEPENDS=	iso-codes>=0:${PORTSDIR}/misc/iso-codes \
		vala:${PORTSDIR}/lang/vala \
		gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas \
		itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libenchant.so:${PORTSDIR}/textproc/enchant \
		libpeas-gtk-1.0.so:${PORTSDIR}/devel/libpeas \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup
RUN_DEPENDS=	iso-codes>=0:${PORTSDIR}/misc/iso-codes \
		gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas \
		${PYTHON_PKGNAMEPREFIX}libpeas>=0:${PORTSDIR}/devel/py3-libpeas

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake libtool \
		pathfix pkgconfig python:3 tar:xz
USE_GNOME=	gtksourceview3 intlhack introspection:build \
		libxml2 py3gobject3
USE_XORG=	sm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-updater \
		--enable-python
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-error=format-nonliteral
CFLAGS+=	-I${LOCALBASE}/include -Wno-error=format-nonliteral
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB=	VERSION="3.14"
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.gnome.gedit.enums.xml \
		org.gnome.gedit.plugins.externaltools.gschema.xml \
		org.gnome.gedit.gschema.xml \
		org.gnome.gedit.plugins.filebrowser.enums.xml \
		org.gnome.gedit.plugins.filebrowser.gschema.xml \
		org.gnome.gedit.plugins.pythonconsole.gschema.xml \
		org.gnome.gedit.plugins.time.enums.xml \
		org.gnome.gedit.plugins.time.gschema.xml

PLIST_SUB+=	PYVER=${PYTHON_VER:S/.//}

.include <bsd.port.mk>
