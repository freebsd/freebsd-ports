# New ports collection makefile for:	quake-dpmod
# Date created:				14 Sep 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	dpmod
PORTVERSION=	20071120
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://offload1.icculus.org/twilight/darkplaces/files/
PKGNAMEPREFIX=	${Q1PKGNAMEPREFIX}
DISTNAME=	darkplacesmod${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Quake 1 modification (for DarkPlaces)

RUN_DEPENDS=	${LOCALBASE}/share/darkplaces/dummy:${PORTSDIR}/games/darkplaces

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${Q1DIR}/${PORTNAME}

post-extract:
# Remove CVS directories
	@${FIND} ${WRKDIR} -type d -name CVS -print0 | \
		${XARGS} -0 ${RM} -rf

# Fix permissions
	@${CHMOD} go-w ${WRKDIR}/dpmod/progs.dat

do-install:
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/dpmod/* ${DATADIR}

.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.mk>
