# Created by: mm@FreeBSD.org
# $FreeBSD$

PORTNAME=	adodb
PORTVERSION=	5.21.0
DISTVERSIONPREFIX=	v
CATEGORIES=	databases www
PKGNAMESUFFIX=	5${PHP_PKGNAMESUFFIX}

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Database library for PHP

LICENSE=	BSD3CLAUSE LGPL21+
LICENSE_COMB=	dual

USES=		php:flavors
USE_PHP=	pcre

USE_GITHUB=	yes
GH_PROJECT=	ADOdb

CONFLICTS=	adodb-4.*

NO_BUILD=	yes
NO_ARCH=	yes
SUB_FILES=	pkg-message

ADODB_SUBDIRS=	datadict drivers lang pear perf session xsl

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

# 5.21.0 have not contains test suite
#TESTS_DESC=	Install tests

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${FIND} ${ADODB_SUBDIRS} -type d \
		-exec ${MKDIR} ${STAGEDIR}${DATADIR}/{} \;
	cd ${WRKSRC} && ${FIND} . ! -path './*/*' -type f \( -name '*.php' -or -name '*.dtd' -or -name '*.zip' \) \
		-exec ${INSTALL_DATA} ${WRKSRC}/{} ${STAGEDIR}${DATADIR}/{} \;
	cd ${WRKSRC} && ${FIND} ${ADODB_SUBDIRS} -type f \
		-exec ${INSTALL_DATA} ${WRKSRC}/{} ${STAGEDIR}${DATADIR}/{} \;

#do-install-TESTS-on:
#	@${MKDIR} ${STAGEDIR}${DATADIR}/tests
#	cd ${WRKSRC} && ${FIND} tests -type f \
#		-exec ${INSTALL_DATA} ${WRKSRC}/{} ${STAGEDIR}${DATADIR}/{} \;

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${FIND} . ! -path './*/*' -type f -name '*.txt' \
		-exec ${INSTALL_DATA} ${WRKSRC}/{} ${STAGEDIR}${DOCSDIR} \;
	cd ${WRKSRC} && ${FIND} docs -type f \
		-exec ${INSTALL_DATA} ${WRKSRC}/{} ${STAGEDIR}${DOCSDIR} \;

.include <bsd.port.mk>
