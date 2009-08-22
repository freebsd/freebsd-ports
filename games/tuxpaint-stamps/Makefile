# New ports collection makefile for:	tuxpaint-stamps
# Date created:				15 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	tuxpaint
PORTVERSION=	2008.06.30
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-stamps/${PORTVERSION}
PKGNAMESUFFIX=	-stamps
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	TuxPaint Stamps

RUN_DEPENDS=	tuxpaint:${PORTSDIR}/games/tuxpaint

NO_BUILD=	yes
INSTALL_TARGET=	install-all

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/${MAKEFILE}

.include <bsd.port.mk>
