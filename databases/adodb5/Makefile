# Created by: mm@FreeBSD.org
# $FreeBSD$

PORTNAME=	adodb
DISTVERSION=	5.20.7
CATEGORIES=	databases www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-php5-only/${PORTNAME}-520-for-php5
PKGNAMESUFFIX=	5

MAINTAINER=	dem.procopiou@gmail.com
COMMENT=	Database library for PHP

LICENSE=	BSD4CLAUSE LGPL21
LICENSE_COMB=	dual

CONFLICTS=	adodb-4.*

USES=		php
USE_PHP=	pcre

WRKSRC=		${WRKDIR}/${PORTNAME}5
NO_BUILD=	yes
NO_ARCH=	yes
SUB_FILES=	pkg-message

ADODB_SUBDIRS=	contrib datadict drivers lang pear perf session xsl

OPTIONS_DEFINE=	TESTS DOCS
OPTIONS_SUB=	yes

TESTS_DESC=	Install tests

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${FIND} ${ADODB_SUBDIRS} -type d \
		-exec ${MKDIR} ${STAGEDIR}${DATADIR}/{} \;
	cd ${WRKSRC} && ${FIND} . ! -path './*/*' -type f \( -name '*.php' -or -name '*.dtd' -or -name '*.zip' \) \
		-exec ${INSTALL_DATA} ${WRKSRC}/{} ${STAGEDIR}${DATADIR}/{} \;
	cd ${WRKSRC} && ${FIND} ${ADODB_SUBDIRS} -type f \
		-exec ${INSTALL_DATA} ${WRKSRC}/{} ${STAGEDIR}${DATADIR}/{} \;

do-install-TESTS-on:
	@${MKDIR} ${STAGEDIR}${DATADIR}/tests
	cd ${WRKSRC} && ${FIND} tests -type f \
		-exec ${INSTALL_DATA} ${WRKSRC}/{} ${STAGEDIR}${DATADIR}/{} \;

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DOCSDIR}/cute_icons_for_site
	cd ${WRKSRC} && ${FIND} . ! -path './*/*' -type f -name '*.txt' \
		-exec ${INSTALL_DATA} ${WRKSRC}/{} ${STAGEDIR}${DOCSDIR}/{} \;
	cd ${WRKSRC}/docs && ${FIND} . -type f \
		-exec ${INSTALL_DATA} ${WRKSRC}/docs/{} ${STAGEDIR}${DOCSDIR}/{} \;
	cd ${WRKSRC} && ${FIND} cute_icons_for_site -type f \
		-exec ${INSTALL_DATA} ${WRKSRC}/{} ${STAGEDIR}${DOCSDIR}/{} \;

.include <bsd.port.mk>
