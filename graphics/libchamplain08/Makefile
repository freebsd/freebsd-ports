# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/graphics/libchamplain08/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	libchamplain
PORTVERSION=	0.8.3
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C library aimed to provide a Gtk+ widget to display rasterized maps and markers

LIB_DEPENDS=	libclutter-gtk-0.10.so:${PORTSDIR}/graphics/clutter-gtk \
		libsoup-gnome-2.4.so:${PORTSDIR}/devel/libsoup-gnome

NO_STAGE=	yes
LATEST_LINK=	libchamplain08
USE_BZIP2=	yes
USES=		gmake pathfix pkgconfig
USE_GNOME=	gtk20 ltverhack:1 gnomehier
USE_GL=		gl
USE_AUTOTOOLS=	libtool
USE_SQLITE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION=0.8

# python bindings need to get ported
WITHOUT_PYTHON=yes

.if !defined(WITHOUT_PYTHON)
USE_PYTHON=	yes
PYCLUTTER_GTK=		${LOCALBASE}/libdata/pkgconfig/pyclutter-gtk-0.10.pc
BUILD_DEPENDS+=		${PYCLUTTER_GTK}:${PORTSDIR}/graphics/py-clutter-gtk
RUN_DEPENDS+=		${PYCLUTTER_GTK}:${PORTSDIR}/graphics/py-clutter-gtk
CONFIGURE_ARGS+=	--enable-python=yes
PLIST_SUB+=		PYTHON=""
.else
CONFIGURE_ARGS+=	--enable-python=no
PLIST_SUB+=		PYTHON="@comment "
.endif

.include <bsd.port.mk>
