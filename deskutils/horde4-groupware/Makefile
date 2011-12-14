# Ports collection makefile for:  horde4-mnemo
# Date created:			  6 July 2011
# Whom:				  Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	groupware
PORTVERSION=	4.0.5
CATEGORIES=	deskutils www pear
PKGNAMEPREFIX=	horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Groupware

CONFLICTS=	horde-webmail-4*

LATEST_LINK=	horde4-${PORTNAME}

USE_HORDE_BUILD=	Horde_Role
USE_HORDE_RUN=	Horde_Role \
		content \
		horde \
		kronolith \
		mnemo \
		nag \
		timeobjects \
		turba \
		Horde_Core

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
