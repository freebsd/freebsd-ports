# Created by: Jona Joachim <walkingshadow@grummel.net>
# $FreeBSD$

PORTNAME=	sdl_sge
PORTVERSION=	0.030809
PORTREVISION=	12
CATEGORIES=	devel graphics
MASTER_SITES=	http://www.digitalfanatics.org/cal/sge/files/ \
		http://www.sourcefiles.org/Programming/Libraries/Graphics/
DISTNAME=	sge030809

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphic library for the Simple DirectMedia Layer (SDL)

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

OPTIONS_DEFINE=	SDL FREETYPE DOCS EXAMPLES
OPTIONS_DEFAULT=	SDL FREETYPE
SDL_dESC=	Enable support for SDL_image

USE_SDL=	sdl
USE_GMAKE=	yes
USE_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFREETYPE}
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
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
		's|PREFIX =PREFIX|PREFIX =${PREFIX}|g ; \
		 s|PREFIX_H =PREFIX_H|PREFIX_H =${PREFIX}/include/SDL|g ; \
		 s|sdl-config|${SDL_CONFIG}|g' ${WRKSRC}/Makefile.conf

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
