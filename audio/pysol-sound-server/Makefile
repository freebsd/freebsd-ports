# New ports collection makefile for:	pysol-sound-server
# Date created:		7 January 2000
# Whom:			Maxim Sobolev
#
# $FreeBSD$
#

PORTNAME=	pysol-sound-server
PORTVERSION=	2.20
CATEGORIES=	audio games
MASTER_SITES=	http://wildsau.idv.uni-linz.ac.at/mfx/download/pysol/pysol-sound-server/

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	SDL-1.1.2:${PORTSDIR}/devel/sdl-devel \
		smpeg.0:${PORTSDIR}/graphics/smpeg \
		SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_PYTHON=	yes
HAS_CONFIGURE=	yes
ALL_TARGET=	pysolsoundservermodule.so

.include <bsd.port.mk>
