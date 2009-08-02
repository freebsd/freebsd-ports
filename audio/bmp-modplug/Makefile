# New ports collection makefile for:	bmp-modplug
# Date created:		2 January 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	modplug
PORTVERSION=	2.0.5
PORTREVISION=	5
CATEGORIES?=	audio
MASTER_SITES=	ftp://ftp.osuosl.org/pub/FreeBSD/distfiles/ \
		http://ftp.osuosl.org/pub/FreeBSD/distfiles/ \
		ftp://ftp.dvo.ru/pub/distfiles/ \
		ftp://ftp.mtu.ru/pub/FreeBSD/distfiles/ \
		ftp://ftp.chg.ru/pub/FreeBSD/distfiles/
PKGNAMEPREFIX=	bmp-
DISTNAME=	${PORTNAME}${PKGNAMEPREFIX}2.05

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A modplug-based plugin for beep-media-player

LIB_DEPENDS?=	beep.2:${PORTSDIR}/multimedia/beep-media-player
LIB_DEPENDS+=	modplug.0:${PORTSDIR}/audio/libmodplug

USE_AUTOTOOLS=	libtool:22
USE_BZIP2=	yes
HAS_CONFIGURE=	yes
PLUGDIR?=	lib/bmp/Input
PLIST_FILES=	${PLUGDIR}/libmodplugbmp.so

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/modplugbmp/.libs/libmodplugbmp.so ${PREFIX}/${PLUGDIR}/

.include <bsd.port.mk>
