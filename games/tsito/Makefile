# Created by: Kuang-che Wu <kcwu@csie.org>
# $FreeBSD$

PORTNAME=	tsito
PORTVERSION=	0.8.4
CATEGORIES=	games
MASTER_SITES=	SF/xiangqi-engine/xiangqi-engine/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chinese chess (Xiangqi) program

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-lcompat"
CONFIGURE_ARGS=	--prefix="${PREFIX}"

.include <bsd.port.mk>
