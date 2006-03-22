# New ports collection makefile for:	php5-propel
# Date Created:				9 Nov, 2005
# Whom:					Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	propel
PORTVERSION=	1.1.1
CATEGORIES=	databases
MASTER_SITES=	http://dist.bsdlab.org/
#MASTER_SITES=	http://propel.phpdb.org/files/
PKGNAMEPREFIX=	php5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Full-service object persistence and query toolkit for PHP

USE_PHP=	yes
DEFAULT_PHP_VER=5
WRKSRC=		${WRKDIR}

do-build:
	${SED} -e "s|@DATA-DIR@/propel_generator|${PREFIX}/share/propel/generator/pear|" ${WRKSRC}/generator/pear/pear-propel-gen > ${WRKSRC}/propel-gen

do-install:
	cd ${WRKSRC}/runtime/classes; \
	for d in `${FIND} propel -type d`; do \
		${INSTALL} -d ${PREFIX}/lib/php/$$d; \
	done; \
	for i in `${FIND} propel -type f`; do \
		${INSTALL_DATA} $$i ${PREFIX}/lib/php/$$i; \
	done
	cd ${WRKSRC}; \
	for d in `${FIND} generator -type d`; do \
		${INSTALL} -d ${PREFIX}/share/propel/$$d; \
	done; \
	for i in `${FIND} generator -type f`; do \
		${INSTALL_DATA} $$i ${PREFIX}/share/propel/$$i; \
	done
	${INSTALL_SCRIPT} ${WRKSRC}/propel-gen ${PREFIX}/bin

.include <bsd.port.mk>
