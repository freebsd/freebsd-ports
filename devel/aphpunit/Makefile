# $FreeBSD$

PORTNAME=	aphpunit
DISTVERSION=	1.9
CATEGORIES=	devel www
MASTER_SITES=	http://phar.toco-domains.de/
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}
EXTRACT_SUFX=	.phar

MAINTAINER=	tz@FreeBSD.org
COMMENT=	Testing framework for unit tests

LICENSE=	BSD2CLAUSE

USES=		php:flavors
USE_PHP=	mbstring pcntl phar posix sysvmsg

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/aphpunit

# Download isn't compressed or aggregated, it's just the single file
do-extract:
	${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} \
			${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
