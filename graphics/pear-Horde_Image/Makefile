# Ports collection makefile for:  pear-Horde_Image
# Date created:			  7 July 2011
# Whom:				  Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	Horde_Image
DISTVERSION=	1.0.5
CATEGORIES=	graphics www pear
PKGNAMEPREFIX=	pear-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Image API

OPTIONS=	GD "Depend on PHP gd extension" Off

USE_HORDE_RUN=	Horde_Exception Horde_Support Horde_Translation Horde_Util

.include <bsd.port.pre.mk>

.if defined(WITH_GD)
USE_PHP+=	gd
.endif

.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
