# New ports collection makefile for:	heroes
# Date created:				15 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	heroes
PORTVERSION=	0.21
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${DATADISTNAME}${EXTRACT_SUFX} \
		${SOUNDISTNAME}${EXTRACT_SUFX} \
		${MUSICDISTNAME}${EXTRACT_SUFX}
#PATCH_SITES=	ftp://heroes.sourceforge.net/pub/heroes/patches/
#PATCHFILES=	heroes-0.7-errata.patch

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A game of yore similar to the "Tron" and "Nibbles"

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

DATAVERSION=	1.5
SOUNDVERSION=	1.0
MUSICVERSION=	1.0
DATADISTNAME=	${PORTNAME}-data-${DATAVERSION}
SOUNDISTNAME=	${PORTNAME}-sound-effects-${SOUNDVERSION}
MUSICDISTNAME=	${PORTNAME}-sound-tracks-${MUSICVERSION}
DATASRC=	${WRKDIR}/${DATADISTNAME}
SOUNDSRC=	${WRKDIR}/${SOUNDISTNAME}
MUSICSRC=	${WRKDIR}/${MUSICDISTNAME}

USE_X_PREFIX=	yes
USE_SDL=	mixer sdl
USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		MAKEINFO="makeinfo --no-split"
CONFIGURE_ARGS=	--with-sdl_mixer=${LOCALBASE} --without-gii

MAN6=		heroes.6 heroeslvl.6
INFO=		heroes

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -lsmpeg ${PTHREAD_LIBS}

post-patch:
	@for dir in ${DATASRC} ${SOUNDSRC} ${MUSICSRC}; do \
		${FIND} $${dir} -name "Makefile*" | ${XARGS} ${RM}; \
	done
	@${RM} -f ${WRKSRC}/lib/getopt.h
	@${RM} -f ${WRKSRC}/doc/*.info*

post-install:
.for dir in levels pics tilesets
	${MKDIR} ${DATADIR}/${dir}
	${INSTALL_DATA} ${DATASRC}/${dir}/* ${DATADIR}/${dir}
.endfor
	${MKDIR} ${DATADIR}/sfx
	${INSTALL_DATA} ${SOUNDSRC}/*.wav ${SOUNDSRC}/sfx.conf ${DATADIR}/sfx
	${MKDIR} ${DATADIR}/mod
	${INSTALL_DATA} ${MUSICSRC}/*.xm ${MUSICSRC}/sound.conf ${DATADIR}/mod

.include <bsd.port.mk>
