# $FreeBSD$

PORTNAME=	libphutil
PORTVERSION=	20190831
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Collection of PHP utility classes

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PHP_DESTDIR=	lib/php/libphutil
USES=		php:flavors
USE_PHP=	xml
USE_GITHUB=	yes
NO_BUILD=	yes
NO_ARCH=	yes
PORTSCOUT=	ignore:1
GH_ACCOUNT=	phacility
GH_TAGNAME=	794ded9

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}
	cd ${WRKSRC} ; ${PAX} -rw * ${STAGEDIR}${PREFIX}/${PHP_DESTDIR}

.include <bsd.port.mk>
