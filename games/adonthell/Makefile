# New ports collection makefile for:	adonthell
# Date created:		Sat May 10 15:26:09 CEST 2003
# Whom:			Miguel Mendez <flynn@energyhq.es.eu.org>
#
# $FreeBSD$
#

PORTNAME=	adonthell
PORTVERSION=	0.3.3
CATEGORIES=	games
MASTER_SITES=	http://savannah.nongnu.org/download/${PORTNAME}/src/
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
	   	wastesedge-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	flynn@energyhq.es.eu.org
COMMENT=	A free role playing game

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12 \
		SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer \
		vorbis.2:${PORTSDIR}/audio/libvorbis

USE_PYTHON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-py-debug
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	SDL_CONFIG=${LOCALBASE}/bin/sdl11-config \
		LDFLAGS=-L${LOCALBASE}/lib

post-install:
		cd ${WRKDIR}/wastesedge-${PORTVERSION} && \
		${SETENV} ${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS} \
		--with-adonthell-binary=${PREFIX}/bin/${PORTNAME} \
		${CONFIGURE_TARGET}
		cd ${WRKDIR}/wastesedge-${PORTVERSION} && ${GMAKE}
		cd ${WRKDIR}/wastesedge-${PORTVERSION} && ${GMAKE} install

.include <bsd.port.mk>
