# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports-experimental/trunk/editors/gedit/Makefile 19503 2014-04-14 21:06:16Z gusi $

PORTNAME=	gedit
PORTVERSION=	3.12.1
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

USES=		desktop-file-utils gettext gmake libtool:keepla \
		pathfix pkgconfig tar:xz
USE_GNOME=	gnomeprefix gtksourceview3 intlhack introspection:build \
		libxml2 py3gobject3
USE_XORG=	sm
GNU_CONFIGURE=	yes
USE_PYTHON=	3
CONFIGURE_ARGS=	--disable-updater
CONFIGURE_ARGS+=--disable-zeitgeist \
		--enable-python
CPPFLAGS+=	-I${LOCALBASE}/include -Wno-error=format-nonliteral
CFLAGS+=	-I${LOCALBASE}/include -Wno-error=format-nonliteral
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB=	VERSION="3.12"

GLIB_SCHEMAS=	org.gnome.gedit.enums.xml \
		org.gnome.gedit.plugins.externaltools.gschema.xml \
		org.gnome.gedit.gschema.xml \
		org.gnome.gedit.plugins.filebrowser.enums.xml \
		org.gnome.gedit.plugins.filebrowser.gschema.xml \
		org.gnome.gedit.plugins.pythonconsole.gschema.xml \
		org.gnome.gedit.plugins.time.enums.xml \
		org.gnome.gedit.plugins.time.gschema.xml

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gedit/plugins/lib*.so

.include <bsd.port.mk>
