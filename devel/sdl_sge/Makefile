# Created by: Jona Joachim <walkingshadow@grummel.net>
# $FreeBSD$

PORTNAME=	sdl_sge
PORTVERSION=	0.030809
PORTREVISION=	14
CATEGORIES=	devel graphics
MASTER_SITES=	http://www.digitalfanatics.org/cal/sge/files/ \
		http://www.sourcefiles.org/Programming/Libraries/Graphics/
DISTNAME=	sge030809

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphic library for the Simple DirectMedia Layer (SDL)

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

USES=		gmake
USE_SDL=	sdl
USE_LDCONFIG=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	SDL FREETYPE DOCS EXAMPLES
OPTIONS_DEFAULT=SDL FREETYPE DOCS EXAMPLES
SDL_DESC=	Enable support for SDL_image

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFREETYPE}
LIB_DEPENDS+=	libfreetype.so:${PORTSDIR}/print/freetype2
MAKE_ARGS+=	USE_FT=y
.else
MAKE_ARGS+=	USE_FT=n
.endif

.if ${PORT_OPTIONS:MSDL}
USE_SDL+=	image
MAKE_ARGS+=	USE_IMG=y
.else
MAKE_ARGS+=	USE_IMG=n
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|PREFIX =PREFIX|PREFIX =${STAGEDIR}${PREFIX}|g ; \
		 s|PREFIX_H =PREFIX_H|PREFIX_H =${STAGEDIR}${PREFIX}/include/SDL|g ; \
		 s|sdl-config|${SDL_CONFIG}|g' ${WRKSRC}/Makefile.conf

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
