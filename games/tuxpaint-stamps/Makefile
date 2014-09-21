# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	tuxpaint-stamps
PORTVERSION=	2014.08.23
CATEGORIES=	games
MASTER_SITES=	SF/tuxpaint/${PORTNAME}/${PORTVERSION:S|.|-|g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TuxPaint Stamps

LICENSE=	GPLv2 # (or later)

RUN_DEPENDS=	tuxpaint:${PORTSDIR}/games/tuxpaint

NO_ARCH=	yes
NO_BUILD=	yes

MAKE_ARGS=	DATA_PREFIX="${STAGEDIR}${DATADIR}/"
INSTALL_TARGET=	install-all

DATADIR=	${PREFIX}/share/tuxpaint

.include <bsd.port.mk>
