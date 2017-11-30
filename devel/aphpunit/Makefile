# $FreeBSD$

PORTNAME=	aphpunit
DISTVERSION=	1.3
CATEGORIES=	devel www
MASTER_SITES=	http://phar.toco-domains.de/
EXTRACT_SUFX=	.phar

MAINTAINER=	tz@FreeBSD.org
COMMENT=	Testing framework for unit tests

LICENSE=	BSD2CLAUSE

USES=	php
USE_PHP=	pcntl phar posix sysvmsg

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
