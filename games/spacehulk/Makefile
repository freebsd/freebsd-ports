# New ports collection makefile for:	spacehulk
# Date created:			Mon May  5 14:21:44 CEST 2003
# Whom:				Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$

PORTNAME=	spacehulk
PORTVERSION=	1.5.b1
PORTREVISION=	10
CATEGORIES=	games kde
MASTER_SITES=	http://r.vinot.free.fr/spacehulk/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b1/-beta1/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Science-fiction board game in the world of Warhammer 40000

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=3

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
