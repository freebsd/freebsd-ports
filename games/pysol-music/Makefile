# New ports collection makefile for:    PySol-Music
# Date created:         18 Sep 2000
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pysol-music
PORTVERSION=	4.40
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	arved

MAINTAINER=	serg@tmn.ru
COMMENT=	Collection of background music for use with PySol

RUN_DEPENDS=	pysol:${PORTSDIR}/games/pysol

USE_BZIP2=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/share/pysol
	(cd ${WRKSRC}/data; tar cf - *) | \
		(cd ${PREFIX}/share/pysol; tar xf -)

.include <bsd.port.mk>
