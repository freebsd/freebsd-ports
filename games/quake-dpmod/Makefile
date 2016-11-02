# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	dpmod
PORTVERSION=	20071120
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://icculus.org/twilight/darkplaces/files/
PKGNAMEPREFIX=	${Q1PKGNAMEPREFIX}
DISTNAME=	darkplacesmod${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quake 1 modification (for DarkPlaces)

RUN_DEPENDS=	darkplaces>=0:games/darkplaces

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${Q1DIR}/${PORTNAME}

post-extract:
# Remove CVS directories
	@${FIND} ${WRKSRC} -type d -name CVS -print0 | ${XARGS} -0 ${RM} -r

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -a ${WRKSRC}/dpmod/* ${STAGEDIR}${DATADIR}

.include "${.CURDIR}/../quake-data/Makefile.include"
.include <bsd.port.mk>
