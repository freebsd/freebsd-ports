# New ports collection makefile for:    abridge
# Date created:         19.05.2003
# Whom: Janos Mohacsi <janos.mohacsi@bsd.hu>
#
# $FreeBSD$

PORTNAME=	abridge
PORTVERSION=	0.4.0
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://www.abridgegame.org/debian/unstable/
DISTFILES=	${PORTNAME}_${PORTVERSION}-1${EXTRACT_SUFX}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Bridge game

USE_WX=		2.4
WX_CONF_ARGS=	absolute
GNU_CONFIGURE=	yes

MAN1=		abridge.1
PLIST_FILES=	bin/abridge

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		Does not compile on !i386
.endif

.include <bsd.port.post.mk>
