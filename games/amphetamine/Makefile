# New ports collection makefile for:	amphetamine
# Date created:				6 March 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	amphetamine
PORTVERSION=	0.8.10
CATEGORIES=	games
MASTER_SITES=	http://www.dataway.ch/~lukasl/amph/files/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-data-${DATAVERSION}${EXTRACT_SUFX}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=  	SDL-1.1.5:${PORTSDIR}/devel/sdl12

DATAVERSION=	0.8.6

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

post-install:
	@(cd ${WRKDIR}/amph && ${TAR} -c -f - * ) \
		| (cd ${PREFIX}/share/amph && ${TAR} --unlink -x -f -)

.include <bsd.port.mk>
