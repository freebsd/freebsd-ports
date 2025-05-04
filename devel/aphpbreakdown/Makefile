PORTNAME=	aphpbreakdown
DISTVERSION=	2.2.2
CATEGORIES=	devel www
MASTER_SITES=	http://phar.code-mesa.com/
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}
EXTRACT_SUFX=	.phar

MAINTAINER=	freebsd@code-mesa.com
COMMENT=	Code-Analyzer for PHP for Compatibility Check-UP
WWW=		https://gitlab.code-mesa.com/code-mesa/aphpbreakdown/

LICENSE=	BSD2CLAUSE

BROKEN=		Unfetchable
DEPRECATED=	Upstream is gone and last release in 2018
EXPIRATION_DATE=2025-05-31

USES=		php:flavors
USE_PHP=	tokenizer phar

NO_ARCH=	yes
NO_BUILD=	yes

CONFLICTS_INSTALL=	php*-aphpbreakdown

PLIST_FILES=	bin/aphpbreakdown

# Download isn't compressed or aggregated, it's just the single file
do-extract:
	${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
