# Created by: Thomas Hurst <freaky@aagh.net>
# $FreeBSD$

PORTNAME=	optipng
PORTVERSION=	0.7.4
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/OptiPNG/${PORTNAME}-${PORTVERSION}

MAINTAINER=	tom@hur.st
COMMENT=	An optimizer for PNG files

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

OPTIONS_DEFINE=	BUNDLED_LIBPNG BUNDLED_ZLIB

BUNDLED_LIBPNG_DESC=	Use bundled libpng
BUNDLED_ZLIB_DESC=	Use bundled zlib

HAS_CONFIGURE=	yes
PLIST_FILES=	bin/optipng man/man1/optipng.1.gz
PORTDOCS=	history.txt optipng.man.html optipng.man.pdf optipng.man.txt \
		png_optimization.html todo.txt

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MBUNDLED_LIBPNG)
CONFIGURE_ARGS+=	--with-system-libpng
CFLAGS+=	"-I${LOCALBASE}/include"
LDFLAGS+=	"-L${LOCALBASE}/lib"
LIB_DEPENDS+=	libpng15.so:${PORTSDIR}/graphics/png
.endif

.if empty(PORT_OPTIONS:MBUNDLED_ZLIB)
CONFIGURE_ARGS+=	--with-system-zlib
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/optipng/optipng ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/src/optipng/man/optipng.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

post-install:
	${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
