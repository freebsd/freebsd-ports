# New ports collection makefile for: triplane
# Date created:	01 Jan 2011
# Whom:		Ganael Laplanche <ganael.laplanche@martymac.org>
#
# $FreeBSD$
#

PORTNAME=	triplane
PORTVERSION=	1.04.r20110114
CATEGORIES=	games
MASTER_SITES=	http://contribs.martymac.org/FreeBSD-ports/distfiles/ \
		SF/${PORTNAME}
DISTNAME=	${PORTNAME}-classic-${PORTVERSION}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Port of the original Triplane Turmoil game

LICENSE=	GPLv3

USE_SDL=	sdl mixer
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}

CFLAGS+=	-DTRIPLANE_DATA=\\\"${DATADIR}\\\"
MAKE_ENV=	DATADIR="${DATADIR}"

ALL_TARGET=	depend all

.include <bsd.port.mk>
