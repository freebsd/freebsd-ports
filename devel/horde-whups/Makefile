# $FreeBSD$

PORTNAME=	whups
DISTVERSION=	3.0.12
CATEGORIES=	devel www pear
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde bug tracking/ticketing system

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe horde php
USE_PHP=	gettext json
USE_HORDE_BUILD=	Horde_Role
USE_HORDE_RUN=	Horde_Role \
		horde \
		Horde_Auth \
		Horde_Autoloader \
		Horde_Compress \
		Horde_Core \
		Horde_Date \
		Horde_Db \
		Horde_Exception \
		Horde_Form \
		Horde_Group \
		Horde_Mail \
		Horde_Mime \
		Horde_Mime_Viewer \
		Horde_Notification \
		Horde_Perms \
		Horde_Prefs \
		Horde_Scheduler \
		Horde_Share \
		Horde_Support \
		Horde_Text_Filter \
		Horde_Util \
		Horde_Vfs \
		Horde_View

.include <bsd.port.mk>
