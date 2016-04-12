# Created by: Radim Kolar
# $FreeBSD$

PORTNAME=	zgv
PORTVERSION=	5.9
PORTREVISION=	8
CATEGORIES=	graphics
MASTER_SITES=	SUNSITE/apps/graphics/viewers/svga

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphics viewer for SVGAlib

LICENSE=	GPLv2+

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff

OPTIONS_DEFINE=	SDL DOCS

USES=		gmake jpeg makeinfo
ALL_TARGET=	zgv info
INFO=		zgvrc

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	sdl
MAKE_ENV+=	BACKEND=SDL
CPPFLAGS+=	$$(${SDL_CONFIG} --cflags)
LDFLAGS+=	$$(${SDL_CONFIG} --libs)
.else
LIB_DEPENDS+=	libvga.so:graphics/svgalib
MAKE_ENV+=	BACKEND=SVGALIB
ONLY_FOR_ARGS=	i386 amd64
.endif

post-extract:
	@${RM} ${WRKSRC}/doc/zgv

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
	(cd ${WRKSRC}/src && ${INSTALL_PROGRAM} zgv \
		${STAGEDIR}${PREFIX}/bin/zgv)
	(cd ${WRKSRC}/doc && ${INSTALL_MAN} zgv.1 \
		${STAGEDIR}${MANPREFIX}/man/man1/zgv.1)
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} sample.zgvrc \
		${STAGEDIR}${PREFIX}/etc/zgvrc.sample)
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} zgv \
		${STAGEDIR}${PREFIX}/${INFO_PATH}/zgvrc.info)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in NEWS README SECURITY TODO INSTALL
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
