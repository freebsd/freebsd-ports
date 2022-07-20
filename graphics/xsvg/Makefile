PORTNAME=	xsvg
PORTVERSION=	0.2.1
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	X11 SVG viewer

LIB_DEPENDS=	libsvg-cairo.so:graphics/libsvg-cairo

USES=		pkgconfig xorg
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib -lX11 -lXrender -lm
USE_XORG=	x11 xrender

PLIST_FILES=	bin/xsvg man/man1/xsvg.1.gz

.include <bsd.port.mk>
