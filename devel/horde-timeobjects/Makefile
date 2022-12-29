PORTNAME=	timeobjects
PORTVERSION=	2.1.4
CATEGORIES=	devel www pear
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde timeobjects application
WWW=		https://www.horde.org/

LICENSE=	BSD2CLAUSE

DEPRECATED=	Requires php74
EXPIRATION_DATE=	2023-03-31
BROKEN=	runtime error with php80

USES=		cpe horde php
CPE_VENDOR=	horde
USE_HORDE_BUILD=	Horde_Role
USE_HORDE_RUN=	Horde_Role \
		Horde_Core \
		Horde_Date \
		Horde_Exception \
		Horde_Url \
		Horde_Util
USE_PHP=	gettext
IGNORE_WITH_PHP=81 82

.include <bsd.port.mk>
