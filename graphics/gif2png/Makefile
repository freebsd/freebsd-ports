# Created by: saper@system.pl
# $FreeBSD$

PORTNAME=	gif2png
PORTVERSION=	2.5.11
CATEGORIES=	graphics
MASTER_SITES=	http://www.catb.org/~esr/gif2png/

MAINTAINER=	saper@saper.info
COMMENT=	Converts GIF images to a PNG format

LICENSE=	ZLIB

LIB_DEPENDS=	libpng.so:graphics/png
BUILD_DEPENDS=	png>0:graphics/png \
		gzip:archivers/gzip

USES=		python:2.7,run shebangfix
SHEBANG_FILES=	web2png

PLIST_FILES=	bin/gif2png bin/web2png \
		man/man1/gif2png.1.gz \
		man/man1/web2png.1.gz

MAKE_ARGS=	CFLAGS="${CFLAGS}" prefix=${STAGEDIR}${PREFIX}
CFLAGS+=	-I${PREFIX}/include/libpng16 -L${PREFIX}/lib

pre-build:
	${REINPLACE_CMD} -e 's|"gif2png " VERSION|" gif2png " ; VERSION|' ${WRKSRC}/version.c

.include <bsd.port.mk>
