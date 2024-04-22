PORTNAME=	svg2pdf
PORTVERSION=	0.1.3
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Render an SVG image to a PDF file (using cairo)
WWW=		https://cairographics.org

LIB_DEPENDS=	libsvg-cairo.so:graphics/libsvg-cairo

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		pkgconfig
LDFLAGS+=	-lm

PLIST_FILES=	bin/svg2pdf \
		share/man/man1/svg2pdf.1.gz

.include <bsd.port.mk>
