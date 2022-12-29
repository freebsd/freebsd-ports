PORTNAME=	groupware
PORTVERSION=	5.2.22
CATEGORIES=	deskutils www pear
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}horde-

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Groupware
WWW=		https://www.horde.org/apps/groupware/

DEPRECATED=	Requires php74
EXPIRATION_DATE=	2023-03-31
BROKEN=	runtime error with php80

USES=		horde cpe php
USE_HORDE_BUILD=	Horde_Role
USE_HORDE_RUN=	Horde_Role \
		content \
		gollem \
		horde \
		kronolith \
		mnemo \
		nag \
		timeobjects \
		trean \
		turba
IGNORE_WITH_PHP=81 82

CONFLICTS=	horde-webmail-[456]*

.include <bsd.port.mk>
