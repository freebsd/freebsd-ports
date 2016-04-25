# Created by: Jona Joachim <walkingshadow@grummel.net>
# $FreeBSD$

PORTNAME=	sdl_sge
PORTVERSION=	0.030809
PORTREVISION=	15
CATEGORIES=	devel graphics
MASTER_SITES=	http://ports-space.haiku-files.org/source/
DISTNAME=	sge030809

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphic library for the Simple DirectMedia Layer (SDL)

LICENSE=	LGPL20+ # LICENSE is LGPL21

USES=		gmake
USE_SDL=	sdl
USE_LDCONFIG=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	SDL FREETYPE DOCS EXAMPLES
OPTIONS_DEFAULT=SDL FREETYPE

FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2
FREETYPE_MAKE_ARGS=	USE_FT=y
FREETYPE_MAKE_ARGS_OFF=	USE_FT=n

SDL_DESC=	Enable support for SDL_image
SDL_USE=	SDL=image
SDL_MAKE_ARGS=	USE_IMG=y
SDL_MAKE_ARGS_OFF=	USE_IMG=n

post-patch:
	@${REINPLACE_CMD} -e \
		's|PREFIX =PREFIX|PREFIX =${STAGEDIR}${PREFIX}|g ; \
		 s|PREFIX_H =PREFIX_H|PREFIX_H =${STAGEDIR}${PREFIX}/include/SDL|g ; \
		 s|sdl-config|${SDL_CONFIG}|g' ${WRKSRC}/Makefile.conf

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libSGE.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
