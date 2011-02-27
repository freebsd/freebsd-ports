# New ports collection makefile for:	annelid
# Date created:				11 Aug 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	annelid
PORTVERSION=	1
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://www.garthgillespie.com/annelid/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pav
DISTFILES=	${PORTNAME}-src${EXTRACT_SUFX} \
		${PORTNAME}-media${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Remake of the ubiquitous "Snake" and "Worm" games

RESTRICTED=	No redistribution allowed

USE_ZIP=	yes
USE_GMAKE=	yes
USE_SDL=	sdl
USE_GL=		gl
NO_WRKSUBDIR=	yes

OPTIONS=	OPTIMIZED_CFLAGS "Enable compilation optimizations" on

SUB_FILES=	${PORTNAME}-sh

DATAFILES=	annelid.dat apple.tga apple.wav backd.tga backn.tga font.dat \
		font.tga front.tga grow.wav head.tga powerup.tga readme.txt \
		score.wav segment.tga shrink.wav slow.wav speed.wav title.tga \
		vortex.wav

.include <bsd.port.pre.mk>

post-patch:
# Fix Makefile.
	@${REINPLACE_CMD} -e 's|%%CFLAGS%%|${CFLAGS}| ; \
		s|%%LOCALBASE%%|${LOCALBASE}| ; \
		s|sdl-config|${SDL_CONFIG}|' \
		${WRKSRC}/${MAKEFILE}

# Fix SDL include statement.
	@${REINPLACE_CMD} -e 's|\(#include.*\)SDL/\(SDL.*\)|\1\2|' \
		${WRKSRC}/*.cpp ${WRKSRC}/*.h

# Enable/disable compilation optimizations.
.if defined(WITHOUT_OPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -e 's|$$(OPT)||' ${WRKSRC}/${MAKEFILE}
.endif

do-install:
# Script.
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-sh ${PREFIX}/bin/${PORTNAME}

# Program.
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/libexec

# Data.
	${MKDIR} ${DATADIR}
.for f in ${DATAFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor

.include <bsd.port.post.mk>
