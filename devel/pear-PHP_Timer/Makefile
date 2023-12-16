PORTNAME=	PHP_Timer
PORTVERSION=	6.0.0
CATEGORIES=	devel pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utility class for timing
WWW=		https://github.com/sebastianbergmann/php-timer

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		pear:env

NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	sebastianbergmann
GH_PROJECT=	php-timer

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/src/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
