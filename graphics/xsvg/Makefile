PORTNAME=	xsvg
PORTVERSION=	0.2.1
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	X11 SVG viewer
WWW=		https://cairographics.org/

DEPRECATED=	Depends on deprecated library graphics/libsvg-cairo
EXPIRATION_DATE=2024-07-31

LIB_DEPENDS=	libsvg-cairo.so:graphics/libsvg-cairo

USES=		pkgconfig xorg
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
LDFLAGS+=	-L${LOCALBASE}/lib -lX11 -lXrender -lm
USE_XORG=	x11 xrender

PLIST_FILES=	bin/xsvg share/man/man1/xsvg.1.gz

.include <bsd.port.mk>
