# New ports collection makefile for:	tuxpaint-stamps
# Date created:				15 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	tuxpaint-stamps
PORTVERSION=	2009.06.28
CATEGORIES=	games
MASTER_SITES=	SF/tuxpaint/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TuxPaint Stamps

RUN_DEPENDS=	tuxpaint:${PORTSDIR}/games/tuxpaint

NO_BUILD=	yes
INSTALL_TARGET=	install-all

DATADIR=	${PREFIX}/share/tuxpaint

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/${MAKEFILE}

.include <bsd.port.mk>
