# New ports collection makefile for:	spacehulk
# Date created:			Mon May  5 14:21:44 CEST 2003
# Whom:				Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$

PORTNAME=	spacehulk
PORTVERSION=	1.4
CATEGORIES=	games kde
MASTER_SITES=	http://savannah.nongnu.org/download/${PORTNAME}/main.pkg/1.4/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ponomarew@oberon.net
COMMENT=	Science-fiction board game in the world of Warhammer 40000

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=3

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/x11/kde3/Makefile.kde"
.include <bsd.port.post.mk>
