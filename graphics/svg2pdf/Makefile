PORTNAME=	svg2pdf
PORTVERSION=	0.1.3
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Render an SVG image to a PDF file (using cairo)

LIB_DEPENDS=	libsvg-cairo.so:graphics/libsvg-cairo

GNU_CONFIGURE=	yes
USES=		pkgconfig
LDFLAGS+=	-lm

PLIST_FILES=	bin/svg2pdf \
		man/man1/svg2pdf.1.gz

.include <bsd.port.mk>
