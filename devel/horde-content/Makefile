PORTNAME=	content
PORTVERSION=	2.0.6
CATEGORIES=	devel www pear
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde tagging application

USES=		horde php cpe
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

CONFLICTS_INSTALL=	php*-horde-content

.include <bsd.port.mk>
