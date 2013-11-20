# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/editors/gedit3/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	gedit
PORTVERSION=	3.6.2
CATEGORIES=	editors gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Small but powerful text editor for GNOME 3 Desktop Environment

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas \
		itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libenchant.so:${PORTSDIR}/textproc/enchant \
		libpeas-gtk-1.0.so:${PORTSDIR}/devel/libpeas \
		libsoup-2.4.so:${PORTSDIR}/devel/libsoup
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
		${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas

USE_XORG=	sm
USE_XZ=		yes
USES=		desktop-file-utils gettext gmake pathfix pkgconfig
USE_PYTHON=	yes
INSTALLS_OMF=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomeprefix intlhack gtksourceview3 libxml2 \
		gnomedocutils pygobject3
CONFIGURE_ARGS=	--disable-updater
CONFIGURE_ARGS+=--disable-zeitgeist
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-format-nonliteral
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB=	VERSION="3.0"

GLIB_SCHEMAS=	org.gnome.gedit.enums.xml \
		org.gnome.gedit.gschema.xml \
		org.gnome.gedit.plugins.externaltools.gschema.xml \
		org.gnome.gedit.plugins.filebrowser.enums.xml \
		org.gnome.gedit.plugins.filebrowser.gschema.xml \
		org.gnome.gedit.plugins.pythonconsole.gschema.xml \
		org.gnome.gedit.plugins.time.enums.xml \
		org.gnome.gedit.plugins.time.gschema.xml

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gedit/plugins/lib*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gedit/libgedit-private.so

.include <bsd.port.mk>
