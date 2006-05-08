# New ports collection makefile for:	xmms-modplug
# Date created:		8 January 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	modplug
PORTVERSION=	2.0.5
PORTREVISION=	2
CATEGORIES?=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}-${PKGNAMEPREFIX:S/-//}
PKGNAMEPREFIX=	xmms-
DISTNAME=	${PORTNAME}${PKGNAMEPREFIX}2.05

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	A modplug-based plugin for XMMS

LIB_DEPENDS?=	xmms.4:${PORTSDIR}/multimedia/xmms
LIB_DEPENDS+=	modplug.0:${PORTSDIR}/audio/libmodplug

USE_X_PREFIX=	yes
HAS_CONFIGURE=	yes
PLUGDIR?=	lib/xmms/Input
PLIST_FILES=	${PLUGDIR}/libmodplugxmms.so

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on FreeBSD 4.x
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/modplugxmms/.libs/libmodplugxmms.so ${PREFIX}/${PLUGDIR}/

.include <bsd.port.post.mk>
