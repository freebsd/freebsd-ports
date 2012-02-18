# New ports collection makefile for:   SGE
# Date created:        30 July 2006
# Whom:                Jona Joachim <walkingshadow@grummel.net>
#
# $FreeBSD$
#

PORTNAME=	sdl_sge
PORTVERSION=	0.030809
PORTREVISION=	11
CATEGORIES=	devel graphics
MASTER_SITES=	http://www.digitalfanatics.org/cal/sge/files/ \
		http://www.sourcefiles.org/Programming/Libraries/Graphics/
DISTNAME=	sge030809

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphic library for the Simple DirectMedia Layer (SDL)

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

OPTIONS=	SDL_IMAGE "Enable support for SDL_image" On \
		FREETYPE "Enable FreeType support" On \
		DOCS "Install documentation" On \
		EXAMPLES "Install examples" On

USE_SDL=	sdl
USE_GMAKE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

.if defined(WITHOUT_FREETYPE)
MAKE_ARGS+=	USE_FT=n
.else
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
MAKE_ARGS+=	USE_FT=y
.endif

.if defined(WITHOUT_SDL_IMAGE)
MAKE_ARGS+=	USE_IMG=n
.else
USE_SDL+=	image
MAKE_ARGS+=	USE_IMG=y
.endif

.if !defined(WITH_DOCS)
NOPORTDOCS=	yes
.endif

.if !defined(WITH_EXAMPLES)
NOPORTEXAMPLES=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|PREFIX =PREFIX|PREFIX =${PREFIX}|g ; \
		 s|PREFIX_H =PREFIX_H|PREFIX_H =${PREFIX}/include/SDL|g ; \
		 s|sdl-config|${SDL_CONFIG}|g' ${WRKSRC}/Makefile.conf

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
