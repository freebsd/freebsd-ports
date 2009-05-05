# New ports collection makefile for:	osgg
# Date created:		29 Dec 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	osgg
PORTVERSION=	0.99
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	OldSkool Gravity Game

USE_BZIP2=	yes
USE_SDL=	sdl image ttf mixer
USE_GL=		yes

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${RM} -f ${WRKSRC}/osgg
	@${REINPLACE_CMD} -e 's|"[a-z]*.txt"|DATADIR&|; s|endian.h|sys/&|' \
		${WRKSRC}/main.cpp

do-build:
	cd ${WRKSRC} && ${CXX} ${CXXFLAGS} `${SDL_CONFIG} --libs --cflags` \
		-lGL -lSDL_image -lSDL_ttf -lSDL_mixer -o osgg \
		-DDATADIR="\"${DATADIR}/\"" \
	       	main.cpp text.cpp sound.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/osgg ${PREFIX}/bin/
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${WRKSRC}/*.ogg ${WRKSRC}/Bandal.ttf \
		${WRKSRC}/icon.png ${DATADIR}
	${MKDIR} ${DATADIR}/levels
	${INSTALL_DATA} ${WRKSRC}/levels/* ${DATADIR}/levels

.include <bsd.port.mk>
