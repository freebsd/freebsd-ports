# New ports collection makefile for:	quake-dpmod
# Date created:				14 Sep 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	dpmod
PORTVERSION=	20050818
CATEGORIES=	games
MASTER_SITES=	http://offload1.icculus.org/twilight/darkplaces/files/
PKGNAMEPREFIX=	${Q1PKGNAMEPREFIX}
DISTNAME=	darkplacesmod${PORTVERSION}

MAINTAINER=	alejandro@varnet.biz
COMMENT=	Quake 1 modification

RUN_DEPENDS=	darkplaces:${PORTSDIR}/games/darkplaces

USE_ZIP=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATDAIR=	${Q1DIR}/${PORTNAME}

post-extract:
# Remove CVS directories
	@${FIND} ${WRKDIR} -type d -name CVS -print0 | \
		${XARGS} -0 ${RM} -rf

# Fix permissions
	@${CHMOD} go-w ${WRKDIR}/dpmod/progs.dat

do-install:
	@${CP} -Rp ${WRKSRC}/dpmod ${DATADIR}

.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.mk>
