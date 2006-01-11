# New ports collection makefile for:	glpuzzle
# Date created:				09 Jan 2006
# Whom:					Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	glpuzzle
PORTVERSION=	0.1.2
CATEGORIES=	games
MASTER_SITES=	http://www.iua.upf.es/~mdeboer/resorama/glpuzzle/
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@mail.ru
COMMENT=	An OpenGL jigsaw puzzle game

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_X_PREFIX=	yes
USE_SDL=	sdl
USE_GL=		yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

MAKE_ENV=	CXX="${CXX}" \
		CPPFLAGS="`${SDL_CONFIG} --cflags` -I${X11BASE}/include" \
		LDFLAGS="`${SDL_CONFIG} --libs` -L${X11BASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e "s|font/|${DATADIR}/font/|g" ${WRKSRC}/main.cxx
	@${REINPLACE_CMD} -e "s|puzzle-preview/|${DATADIR}/puzzle-preview/|g" ${WRKSRC}/main.cxx
	@${REINPLACE_CMD} -e "s|puzzle-maps/|${DATADIR}/puzzle-maps/|g" ${WRKSRC}/puzzle-preview/preview.map
	@${RM} -f ${WRKSRC}/puzzle-preview/preview.map.bak

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glpuzzle ${PREFIX}/bin
.for i in font puzzle-maps puzzle-preview
	${MKDIR} ${DATADIR}/${i}
	${INSTALL_DATA} ${WRKSRC}/${i}/* ${DATADIR}/${i}
.endfor

.ifndef (NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
