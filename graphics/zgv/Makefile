PORTNAME=	zgv
PORTVERSION=	5.9
PORTREVISION=	11
CATEGORIES=	graphics
MASTER_SITES=	SUNSITE/apps/graphics/viewers/svga

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphics viewer for SVGAlib
WWW=		https://www.svgalib.org/rus/zgv/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		gmake jpeg localbase:ldflags
ALL_TARGET=	zgv
INFO=		zgvrc

OPTIONS_DEFINE=	SDL DOCS

SDL_LIB_DEPENDS_OFF=	libvga.so:graphics/svgalib
SDL_USES=	sdl
SDL_USE=	SDL=sdl
SDL_MAKE_ENV=	BACKEND=SDL
SDL_MAKE_ENV_OFF=	BACKEND=SVGALIB
SDL_CPPFLAGS=	$$(${SDL_CONFIG} --cflags)
SDL_LDFLAGS=	$$(${SDL_CONFIG} --libs)

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MSDL)
ONLY_FOR_ARCHS=	amd64 i386
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CC=|#CC=|g ; \
		 s|^CFLAGS=|#CFLAGS=|g ; \
		 s|^BACKEND=|#BACKEND=|g ; \
		 s|^PREFIX=|#PREFIX=|g ; \
		 s|/usr/X11R6|$${LOCALBASE}|g' ${WRKSRC}/config.mk
	@${REINPLACE_CMD} -e \
		's|-I/usr/local/include|$${CPPFLAGS}|g ; \
		 s|-L/usr/local/lib|$${LDFLAGS}|g ; \
		 s|=-lSDL|=|g' ${WRKSRC}/src/Makefile
	@${GREP} -lR "SDL/SDL" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		 's|SDL/SDL|SDL|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/zgv ${STAGEDIR}${PREFIX}/bin/zgv
	${INSTALL_MAN} ${WRKSRC}/doc/zgv.1 ${STAGEDIR}${PREFIX}/share/man/man1/zgv.1
	${INSTALL_DATA} ${WRKSRC}/doc/sample.zgvrc ${STAGEDIR}${PREFIX}/etc/zgvrc.sample
	${INSTALL_DATA} ${WRKSRC}/doc/zgv ${STAGEDIR}${PREFIX}/${INFO_PATH}/zgvrc.info

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in NEWS README SECURITY TODO INSTALL
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
