PORTNAME=	laminas-stdlib
DISTVERSION=	3.22.0
CATEGORIES=	devel
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	SPL extensions, array utilities, and more for Laminas
WWW=		https://docs.laminas.dev/laminas-stdlib/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		php:flavors
USE_GITHUB=	yes
GH_ACCOUNT=	laminas
IGNORE_WITH_PHP=	86

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/pear/Laminas/Stdlib
	(cd ${WRKSRC}/src && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/pear/Laminas/Stdlib)

.include <bsd.port.mk>
