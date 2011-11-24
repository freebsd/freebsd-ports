# Ports collection makefile for:  horde4-timeobjects
# Date created:			  7 July 2011
# Whom:				  Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	timeobjects
PORTVERSION=	1.0.4
CATEGORIES=	devel www pear
PKGNAMEPREFIX=	horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde timeobjects application

CONFLICTS=	horde-3*

LATEST_LINK=	horde4-${PORTNAME}

USE_PHP=	gettext
USE_HORDE_BUILD=	Horde_Role
USE_HORDE_RUN=	Horde_Role \
		Horde_Core \
		Horde_Date \
		Horde_Exception \
		Horde_Url \
		Horde_Util

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
