# New ports collection makefile for:	heroes
# Date created:				15 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	heroes
PORTVERSION=	0.9
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${DATADISTNAME}${EXTRACT_SUFX} \
		${SOUNDISTNAME}${EXTRACT_SUFX} \
		${MUSICDISTNAME}${EXTRACT_SUFX}
#PATCH_SITES=	ftp://heroes.sourceforge.net/pub/heroes/patches/
#PATCHFILES=	heroes-0.7-errata.patch

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

DATAVERSION=	1.0
SOUNDVERSION=	1.0
MUSICVERSION=	1.0
DATADISTNAME=	${PORTNAME}-data-${DATAVERSION}
SOUNDISTNAME=	${PORTNAME}-sound-effects-${SOUNDVERSION}
MUSICDISTNAME=	${PORTNAME}-sound-tracks-${MUSICVERSION}
DATASRC=	${WRKDIR}/${DATADISTNAME}
SOUNDSRC=	${WRKDIR}/${SOUNDISTNAME}
MUSICSRC=	${WRKDIR}/${MUSICDISTNAME}
INSTPREFIX=	${PREFIX}/share/heroes

SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-sdl_mixer=${LOCALBASE}
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib -lgnugetopt ${PTHREAD_LIBS} -lsmpeg" \
		CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

MAN6=		heroes.6

pre-patch:
	@for dir in ${DATASRC} ${SOUNDSRC} ${MUSICSRC}; do \
		find $${dir} -name "Makefile*" | xargs ${RM}; \
	done
	@${RM} -f ${WRKSRC}/lib/getopt.h
	@${LN} -sf ${LOCALBASE}/include/getopt.h ${WRKSRC}/lib/getopt.h

post-install:
.for dir in levels pics tilesets
	${MKDIR} ${INSTPREFIX}/${dir}
	${INSTALL_DATA} ${DATASRC}/${dir}/* ${INSTPREFIX}/${dir}
.endfor
	${MKDIR} ${INSTPREFIX}/sfx
	${INSTALL_DATA} ${SOUNDSRC}/*.wav ${SOUNDSRC}/sfx.conf ${INSTPREFIX}/sfx
	${MKDIR} ${INSTPREFIX}/mod
	${INSTALL_DATA} ${MUSICSRC}/*.xm ${MUSICSRC}/sound.conf ${INSTPREFIX}/mod
	@install-info --section="X11 Games" \
		--entry="* heroes: (heroes).           Game of yore similar to the "Tron" and "Nibbles"" \
		${PREFIX}/info/heroes.info ${PREFIX}/info/dir

.include <bsd.port.mk>
