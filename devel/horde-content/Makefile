PORTNAME=	content
PORTVERSION=	2.0.6
CATEGORIES=	devel www pear
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde tagging application
WWW=		https://pear.horde.org

IGNORE_WITH_PHP=80 81 82

USES=		horde php cpe
USE_HORDE_BUILD=	Horde_Role
USE_HORDE_RUN=	Horde_Role \
		Horde_Core \
		Horde_Date \
		Horde_Exception \
		Horde_Db \
		Horde_Injector \
		Horde_Rdo \
		Horde_Util
USE_PHP=	gettext json

CONFLICTS_INSTALL=	php*-horde-content

.include <bsd.port.mk>
