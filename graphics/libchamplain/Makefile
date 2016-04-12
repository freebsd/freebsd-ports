# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libchamplain
PORTVERSION=	0.12.13
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	C library aimed to provide a Gtk+ widget to display rasterized maps and markers

LIB_DEPENDS=	libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libsoup-gnome-2.4.so:devel/libsoup-gnome

USES=		gmake gnome libtool pathfix pkgconfig sqlite tar:xz
USE_GNOME=	gtk30 introspection:build
USE_GL=		gl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-gtk-doc-html=no
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION=0.12

.include <bsd.port.mk>
