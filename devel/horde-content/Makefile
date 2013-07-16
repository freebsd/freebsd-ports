# $FreeBSD$

PORTNAME=	content
PORTVERSION=	2.0.3
CATEGORIES=	devel www pear
PKGNAMEPREFIX=	horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde tagging application

LATEST_LINK=	horde-${PORTNAME}

USE_PHP=	gettext json
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
