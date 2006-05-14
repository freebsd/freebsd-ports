# New ports collection makefile for:	trimines
# Date created:		02 May 2006
# Whom:			Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	trimines
PORTVERSION=	1.3.0
CATEGORIES=	games
MASTER_SITES=	http://www.freewebs.com/trimines/

MAINTAINER=	amdmi3@mail.ru
COMMENT=	Mine sweeper game that uses triangles instead of squares

USE_SDL=	sdl
USE_GCC=	3.4+
USE_X_PREFIX=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|data/|${DATADIR}/|' ${WRKSRC}/src/gfx.c

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} src/main.c -o ./trimines \
		`${SDL_CONFIG} --cflags --libs`

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/trimines ${PREFIX}/bin
.for dir in counter menu misc triangles
	${MKDIR} ${DATADIR}/${dir}
	${INSTALL_DATA} ${WRKSRC}/data/${dir}/* ${DATADIR}/${dir}
.endfor

.include <bsd.port.mk>
