# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	heroes
PORTVERSION=	0.21
PORTREVISION=	14
CATEGORIES=	games
MASTER_SITES=	SF \
		SF/${PORTNAME}/${PORTNAME}-data/${DATAVERSION}:data \
		SF/${PORTNAME}/${PORTNAME}-sound-effects/${SOUNDVERSION}:sound \
		SF/${PORTNAME}/${PORTNAME}-sound-tracks/${MUSICVERSION}:music
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${DATADISTNAME}${EXTRACT_SUFX}:data \
		${SOUNDISTNAME}${EXTRACT_SUFX}:sound \
		${MUSICDISTNAME}${EXTRACT_SUFX}:music

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Game of yore similar to the "Tron" and "Nibbles"

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DATAVERSION=	1.5
SOUNDVERSION=	1.0
MUSICVERSION=	1.0
DATADISTNAME=	${PORTNAME}-data-${DATAVERSION}
SOUNDISTNAME=	${PORTNAME}-sound-effects-${SOUNDVERSION}
MUSICDISTNAME=	${PORTNAME}-sound-tracks-${MUSICVERSION}
DATASRC=	${WRKDIR}/${DATADISTNAME}
SOUNDSRC=	${WRKDIR}/${SOUNDISTNAME}
MUSICSRC=	${WRKDIR}/${MUSICDISTNAME}

USE_SDL=	mixer sdl
USES=		gettext gmake iconv
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"
CONFIGURE_ARGS=	--with-sdl_mixer=${LOCALBASE} --without-gii --without-ggi

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS

OPTIMIZED_CFLAGS_CONFIGURE_ENABLE=	optimizations

INFO=		heroes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib -lsmpeg -lm ${PTHREAD_LIBS}

post-patch:
	@for dir in ${DATASRC} ${SOUNDSRC} ${MUSICSRC}; do \
		${FIND} $${dir} -name "Makefile*" | ${XARGS} ${RM}; \
	done
	@${RM} -f ${WRKSRC}/lib/getopt.h
	@${RM} -f ${WRKSRC}/doc/*.info*

post-install:
.for dir in levels pics tilesets
	@${MKDIR} ${STAGEDIR}${DATADIR}/${dir}
	${INSTALL_DATA} ${DATASRC}/${dir}/* ${STAGEDIR}${DATADIR}/${dir}
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}/sfx
	${INSTALL_DATA} ${SOUNDSRC}/*.wav ${SOUNDSRC}/sfx.conf ${STAGEDIR}${DATADIR}/sfx
	@${MKDIR} ${STAGEDIR}${DATADIR}/mod
	${INSTALL_DATA} ${MUSICSRC}/*.xm ${MUSICSRC}/sound.conf ${STAGEDIR}${DATADIR}/mod

.include <bsd.port.mk>
