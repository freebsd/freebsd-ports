PORTNAME=	content
PORTVERSION=	2.0.6
CATEGORIES=	devel www pear
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde tagging application
WWW=		https://pear.horde.org

DEPRECATED=	Requires php74
EXPIRATION_DATE=	2023-03-31
BROKEN=	runtime error with php80

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
IGNORE_WITH_PHP=81 82

CONFLICTS_INSTALL=	php*-horde-content

.include <bsd.port.mk>
