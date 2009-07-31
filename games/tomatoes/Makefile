# New ports collection makefile for:	tomatoes
# Date created:				2005 07 Feb
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tomatoes
PORTVERSION=	1.5
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF
DISTFILES=	${PORTNAME}-linux-src-${PORTVERSION}5${EXTRACT_SUFX} \
		${PORTNAME}-linux-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Tomato-smashing, Q-Bert style

WRKSRC=		${WRKDIR}/tomatoes-${PORTVERSION}5
TDATA=		${WRKDIR}/tomatoes-${PORTVERSION}

USE_BZIP2=	yes
USE_SDL=	mixer image
USE_GL=		gl
USE_GMAKE=	yes
MAKEFILE=	makefile
MAKE_ARGS=	CC="${CXX}" \
		MPKDIR="${DATADIR}/" \
		MUSICDIR="${DATADIR}/music/" \
		HISCOREDIR="${DATADIR}/" \
		CONFIGDIR="${DATADIR}/" \
		CFLAGS="${CXXFLAGS} ${SDL_CFLAGS}" \
		LDFLAGS="${SDL_LDFLAGS}"

PLIST_FILES=	bin/tomatoes \
		%%DATADIR%%/config.cfg \
		%%DATADIR%%/music/IHaveNoTomatoes.it \
		%%DATADIR%%/tomatoes.mpk
PLIST_DIRS=	%%DATADIR%%/music \
		%%DATADIR%%

SDL_CFLAGS=	`${SDL_CONFIG} --cflags` -I${LOCALBASE}/include
SDL_LDFLAGS=	`${SDL_CONFIG} --libs` -lSDL_image -lSDL_mixer \
		-L${LOCALBASE}/lib -lGL -lGLU

.include <bsd.port.pre.mk>

post-patch:
.for file in include/font.h
	cd ${WRKSRC} && ${CP} ${file} ${file}.bak \
		&& ${TR} -d '\r' < ${file}.bak > ${file}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}/music
	${INSTALL_DATA} ${TDATA}/config.cfg ${DATADIR}
	${INSTALL_DATA} ${TDATA}/tomatoes.mpk ${DATADIR}
	${INSTALL_DATA} ${TDATA}/music/IHaveNoTomatoes.it ${DATADIR}/music

.include <bsd.port.post.mk>
