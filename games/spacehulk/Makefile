# New ports collection makefile for:	spacehulk
# Date created:			Mon May  5 14:21:44 CEST 2003
# Whom:				Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$

PORTNAME=	spacehulk
PORTVERSION=	1.5.b1
PORTREVISION=	2
CATEGORIES=	games kde
MASTER_SITES=	http://r.vinot.free.fr/spacehulk/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b1/-beta1/}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Science-fiction board game in the world of Warhammer 40000

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=3

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
