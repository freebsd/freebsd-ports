# New ports collection makefile for:	tuxpaint-stamps
# Date created:				15 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	tuxpaint
DISTVERSION=	2005.11.25
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-stamps
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	TuxPaint Stamps

RUN_DEPENDS=	tuxpaint:${PORTSDIR}/games/tuxpaint

NO_BUILD=	yes

do-install:
	@${CP} -R ${WRKSRC}/stamps ${DATADIR}

.include <bsd.port.mk>
