# New ports collection makefile for:	urban-sounds
# Date created:			25 Jan 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		urban-sounds
PORTVERSION=		1.5.2
CATEGORIES=		games
MASTER_SITES=		http://urban.worldonline.nl/files/linux/
DISTNAME=		sound
DIST_SUBDIR=		urban

MAINTAINER=		jylefort@brutele.be
COMMENT=		The sounds for use with URBAN

RUN_DEPENDS=		urban:${PORTSDIR}/games/urban

USE_X_PREFIX=		yes
NO_WRKSUBDIR=		yes
NO_BUILD=		yes

do-install:
	${CP} -R ${WRKSRC}/snd ${PREFIX}/share/urban

.include <bsd.port.mk>
