# New ports collection makefile for:	glpuzzle
# Date created:				09 Jan 2006
# Whom:					Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	glpuzzle
PORTVERSION=	0.2
CATEGORIES=	games
MASTER_SITES=	http://www.iua.upf.es/~mdeboer/resorama/glpuzzle/
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@mail.ru
COMMENT=	An OpenGL jigsaw puzzle game

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_X_PREFIX=	yes
USE_SDL=	sdl mixer
USE_GL=		yes
USE_GMAKE=	yes
USE_GCC=	3.4+

MAKE_ENV=	CXX="${CXX}" \
		CPPFLAGS="`${SDL_CONFIG} --cflags` -I${X11BASE}/include" \
		LDFLAGS="`${SDL_CONFIG} --libs` -L${X11BASE}/lib"

post-patch:
.for i in font image puzzles sound
	@${REINPLACE_CMD} -e "s|${i}/|${DATADIR}/${i}/|g" ${WRKSRC}/main.cxx
.endfor
	@${REINPLACE_CMD} -e "s|g++|${CXX}|g" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s|INCLFLAGS|CPPFLAGS|" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "/^include.*DEPENDS/ d" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glpuzzle ${PREFIX}/bin
.for i in font image puzzles sound
	${MKDIR} ${DATADIR}/${i}
	${INSTALL_DATA} ${WRKSRC}/${i}/* ${DATADIR}/${i}
.endfor

.ifndef (NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
