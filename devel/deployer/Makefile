PORTNAME=	deployer
DISTVERSION=	6.4.3
CATEGORIES=	devel
MASTER_SITES=	https://deployer.org/releases/v${DISTVERSION}/
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}
DISTNAME=	deployer
EXTRACT_SUFX=	.phar
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	tz@FreeBSD.org
COMMENT=	Deployment tool for PHP

LICENSE=	MIT

USES=		php:flavors
USE_PHP=	curl iconv json openssl pcntl phar posix zlib

CONFLICTS_INSTALL=	php*-deployer

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/deployer \
		bin/deployer.phar

do-extract:
	${MKDIR} ${WRKSRC}/
	${CP} ${_DISTDIR}/deployer.phar ${WRKSRC}/

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/deployer.phar ${STAGEDIR}${PREFIX}/bin/
	${LN} -s deployer.phar ${STAGEDIR}${PREFIX}/bin/deployer

.include <bsd.port.mk>
