# New ports collection makefile for:	tsito
# Date created:		14 Oct 2004
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	tsito
PORTVERSION=	0.8.4
CATEGORIES=	games
MASTER_SITES=	SF/xiangqi-engine/xiangqi-engine/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Chinese chess (Xiangqi) program

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-lcompat"
CONFIGURE_ARGS=	--prefix="${PREFIX}"

MAN1=		tsito.1

.include <bsd.port.mk>
