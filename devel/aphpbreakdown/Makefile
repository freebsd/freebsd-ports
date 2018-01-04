# $FreeBSD$

PORTNAME=	aphpbreakdown
DISTVERSION=	1.0.0
CATEGORIES=	devel www
MASTER_SITES=	http://phar.code-mesa.com/
EXTRACT_SUFX=	.phar

MAINTAINER=	freebsd@code-mesa.com
COMMENT=	Code-Analyzer for PHP for Compatibility Check-UP

LICENSE=	BSD2CLAUSE

USES=	php
USE_PHP=	tokenizer phar hash

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/aphpbreakdown

# Download isn't compressed or aggregated, it's just the single file
do-extract:
	${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
