# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libdbusmenu
PORTVERSION=	12.10.2
CATEGORIES=	devel
MASTER_SITES=	https://launchpadlibrarian.net/118249592/ \
	https://launchpad.net/${PORTNAME}/${PORTVERSION:R}/${PORTVERSION}/+download/

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	GLib and Gtk Implementation of the DBusMenu protocol

LICENSE=	GPLv3 LGPL21 LGPL3
LICENSE_COMB=	multi
LICENSE_DISTFILES=	${WRKSRC}/COPYING-GPL3 ${WRKSRC}/COPYING.2.1 \
	${WRKSRC}/COPYING

BUILD_DEPENDS=	vapigen:${PORTSDIR}/lang/vala-vapigen \
	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS=	libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib

GNU_CONFIGURE=	yes
USES=	gmake pkgconfig pathfix libtool
USE_GNOME=	glib20 intltool intlhack libxslt introspection:build
USE_XORG=	x11
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="0.4"

OPTIONS_SINGLE=	GTK
OPTIONS_SINGLE_GTK=	GTK2 GTK3
OPTIONS_DEFAULT=	GTK3

CONFIGURE_ARGS=	--disable-scrollkeeper \
	--disable-dumper \
	--disable-tests \
	--disable-massivedebugging \
	--enable-introspection=yes \
	--disable-nls \
	--enable-vala \
	--without-omf-dir \
	--without-help-dir

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME+=	gtk20
CONFIGURE_ARGS+=--enable-gtk --with-gtk=2
PLIST_SUB+=	GTK2=""
PLIST_SUB+=	GTK3="@comment "
.endif

.if ${PORT_OPTIONS:MGTK3}
USE_GNOME+=	gtk30
CONFIGURE_ARGS+=--enable-gtk --with-gtk=3
PLIST_SUB+=	GTK2="@comment "
PLIST_SUB+=	GTK3=""
.endif

.include <bsd.port.mk>
