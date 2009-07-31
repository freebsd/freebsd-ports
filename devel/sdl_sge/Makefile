# New ports collection makefile for:   SGE
# Date created:        30 July 2006
# Whom:                Jona Joachim <walkingshadow@grummel.net>
#
# $FreeBSD$
#

PORTNAME=	sdl_sge
PORTVERSION=	0.030809
PORTREVISION=	6
CATEGORIES=	devel graphics
MASTER_SITES=	http://www.etek.chalmers.se/~e8cal1/sge/files/ \
		http://www.digitalfanatics.org/cal/sge/files/
DISTNAME=	sge030809

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphic library for the Simple DirectMedia Layer (SDL)

USE_GMAKE=	yes
USE_LDCONFIG=	yes

OPTIONS=	SDL_IMAGE "Enable support for SDL_IMAGE" On \
		FREETYPE "Enable FreeType support" On \
		DOCS "Install documentation" Off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_FREETYPE)
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2
.endif

.if defined(WITHOUT_SDL_IMAGE)
USE_SDL=	sdl
.else
USE_SDL=	image
.endif

.if !defined(WITH_DOCS)
NOPORTDOCS=	yes
.endif

post-patch:
.if defined(WITHOUT_SDL_IMAGE)
	@${REINPLACE_CMD} -e 's|#USE_IMG = n|USE_IMG = n|g' ${WRKSRC}/Makefile.conf
.else
	@${REINPLACE_CMD} -e 's|#USE_IMG = n|USE_IMG = y|g' ${WRKSRC}/Makefile.conf
.endif
.if defined(WITHOUT_FREETYPE)
	@${REINPLACE_CMD} -e 's|#USE_FT = n|USE_FT = n|g' ${WRKSRC}/Makefile.conf
.else
	@${REINPLACE_CMD} -e 's|#USE_FT = n|USE_FT = y|g' ${WRKSRC}/Makefile.conf
.endif
	@${REINPLACE_CMD} -e 's|PREFIX =PREFIX|PREFIX =${PREFIX}|g' ${WRKSRC}/Makefile.conf
	@${REINPLACE_CMD} -e 's|PREFIX_H =PREFIX_H|PREFIX_H =${PREFIX}/include/SDL|g' ${WRKSRC}/Makefile.conf
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|g' ${WRKSRC}/Makefile.conf

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/docs/* ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_MAN} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
