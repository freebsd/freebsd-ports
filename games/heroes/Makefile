# New ports collection makefile for:	heroes
# Date created:				15 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	heroes
PORTVERSION=	0.21
PORTREVISION=	13
CATEGORIES=	games
MASTER_SITES=	SF
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${DATADISTNAME}${EXTRACT_SUFX} \
		${SOUNDISTNAME}${EXTRACT_SUFX} \
		${MUSICDISTNAME}${EXTRACT_SUFX}
#PATCH_SITES=	ftp://heroes.sourceforge.net/pub/heroes/patches/
#PATCHFILES=	heroes-0.7-errata.patch

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A game of yore similar to the "Tron" and "Nibbles"

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
USE_GMAKE=	yes
USE_ICONV=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		MAKEINFO="makeinfo --no-split"
CONFIGURE_ARGS=	--with-sdl_mixer=${LOCALBASE} --without-gii --without-ggi

.if defined(WITH_OPTIMIZED_CFLAGS)
CONFIGURE_ARGS+=--enable-optimizations
.else
CONFIGURE_ARGS+=--disable-optimizations
.endif

MAN6=		heroes.6 heroeslvl.6
INFO=		heroes

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -lsmpeg ${PTHREAD_LIBS}

pre-everything::
.ifndef(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} '>>>'
	@${ECHO_MSG} '>>> You can enable extra optimizations by defining WITH_OPTIMIZED_CFLAGS'
	@${ECHO_MSG} ">>> For example, 'make WITH_OPTIMIZED_CFLAGS=yes'"
	@${ECHO_MSG} '>>>'
.endif

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
