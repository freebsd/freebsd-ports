# $FreeBSD$

PORTNAME=	libphutil
PORTVERSION=	20161003
CATEGORIES=	devel
PKGNAMEPREFIX=	php5-

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Collection of PHP utility classes

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PHP_DESTDIR=	lib/php/libphutil
USES=		php
USE_PHP=	xml
USE_GITHUB=	yes
NO_BUILD=	yes
NO_ARCH=	yes
GH_ACCOUNT=	phacility
GH_TAGNAME=	4b12a4f

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}
	cd ${WRKSRC} ; ${PAX} -rw * ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}

.include <bsd.port.mk>
