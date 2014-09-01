# $FreeBSD$

PORTNAME=	libphutil
PORTVERSION=	20140828
CATEGORIES=	devel
PKGNAMEPREFIX=	php5-

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Collection of PHP utility classes

LICENSE=	APACHE20

PHP_DESTDIR=	lib/php/libphutil
USE_PHP=	xml
USE_GITHUB=	yes
NO_BUILD=	yes
GH_ACCOUNT=	phacility
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	ae43ce5

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}
	cd ${WRKSRC} ; ${PAX} -rw * ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}

.include <bsd.port.mk>
