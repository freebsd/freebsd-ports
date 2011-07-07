# Ports collection makefile for:  horde4-content
# Date created:			  Mon May 23, 2011
# Whom:				  Beech Rintoul (<beech@FreeBSD.org>)
#
# $FreeBSD$
#

PORTNAME=	content
PORTVERSION=	1.0.0
CATEGORIES=	devel www pear
PKGNAMEPREFIX=	horde-

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Horde tagging application

CONFLICTS=	horde-3*

USE_PHP=	gettext
USE_HORDE_BUILD=	Horde_Role
USE_HORDE_RUN=	Horde_Role \
		Horde_Core \
		Horde_Date \
		Horde_Exception \
		Horde_Db \
		Horde_Injector \
		Horde_Rdo \
		Horde_Util

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
