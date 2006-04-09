# New ports collection makefile for:	php5-phing
# Date Created:				9 Nov, 2005
# Whom:					Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	phing
PORTVERSION=	2.1.1
CATEGORIES=	devel
MASTER_SITES=	http://dist.bsdlab.org/
#MASTER_SITES=	http://www.tigris.org/files/documents/995/25833/
PKGNAMEPREFIX=	php5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Project build system based on Apache Ant

USE_PHP=	yes
DEFAULT_PHP_VER=5
WANT_PHP_CLI=	yes
WANT_PHP_PEAR=	yes
NO_BUILD=	yes

do-install:
	cd ${WRKSRC}/classes; \
	for d in `${FIND} phing -type d`; do \
		${INSTALL} -d ${PREFIX}/lib/php/$$d; \
	done; \
	for i in `${FIND} phing -type f`; do \
		${INSTALL_DATA} $$i ${PREFIX}/lib/php/$$i; \
	done
	${SED} -e "s|/opt/phing|${PREFIX}/lib/php/phing|" \
		-e "s|@@PHP_LIB@@|${PREFIX}/lib/php|" \
		-e "s|@@PEAR_LIB@@|${PREFIX}/share/pear|" \
		${WRKSRC}/bin/phing > ${WRKSRC}/bin/phing.new
	${INSTALL_SCRIPT} ${WRKSRC}/bin/phing.new ${PREFIX}/bin/phing
	${INSTALL_DATA} ${WRKSRC}/bin/phing.php ${PREFIX}/bin/phing.php

.include <bsd.port.mk>
