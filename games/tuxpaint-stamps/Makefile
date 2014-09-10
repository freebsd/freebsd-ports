# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	tuxpaint-stamps
PORTVERSION=	2009.06.28
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/tuxpaint/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TuxPaint Stamps

RUN_DEPENDS=	tuxpaint:${PORTSDIR}/games/tuxpaint

NO_BUILD=	yes
INSTALL_TARGET=	install-all

DATADIR=	${PREFIX}/share/tuxpaint

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' \
		-e 's|DATA_PREFIX)|DESTDIR)$$(&|' \
		${WRKSRC}/${MAKEFILE}

.include <bsd.port.mk>
