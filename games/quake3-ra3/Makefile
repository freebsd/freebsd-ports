# New ports collection makefile for:	Q3 Mod: Rocket Arena 3
# Date created:				Sun Jun  3 00:53:00 EDT 2001
# Whom:					pat@databits.net
#
# $FreeBSD$
#

PORTNAME=	ra3
PORTVERSION=	1.76
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.clanbase.com/pub/ \
		ftp://ftp.mirrors.degnet.de/pub/misc/PlanetQuake3.net/modifications/rocketarena3/ \
		http://freebsd.unixfreunde.de/sources/
PKGNAMEPREFIX=	${Q3PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Quake III Arena Mod: Rocket Arena 3

NO_PACKAGE=	"Package will be 102MB, set FORCE_PACKAGE if you really want to build it"

WRKSRC=		${WRKDIR}/arena

USE_ZIP=	yes
USE_CRLF=	yes
NO_BUILD=	yes

DATADIR=	${Q3DIR}/${PORTNAME}

do-install:
	@${MKDIR} ${DATADIR}
.for f in *.cfg *.pk3
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
.endif

.include "${.CURDIR}/../quake3-data/Makefile.include"

.include <bsd.port.mk>
