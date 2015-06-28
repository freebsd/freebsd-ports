# $FreeBSD$

PORTNAME=	propel
PORTVERSION=	1.1.1
CATEGORIES=	databases
MASTER_SITES=	http://dist.bsdlab.org/
#MASTER_SITES=	http://propel.phpdb.org/files/
PKGNAMEPREFIX=	php5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Full-service object persistence and query toolkit for PHP

USE_PHP=	yes
PHP_DEFAULT=	5.4
WRKSRC=		${WRKDIR}

do-build:
	${SED} -e "s|@DATA-DIR@/propel_generator|${PREFIX}/share/propel/generator/pear|" ${WRKSRC}/generator/pear/pear-propel-gen > ${WRKSRC}/propel-gen

do-install:
	cd ${WRKSRC}/runtime/classes; \
	for d in `${FIND} propel -type d`; do \
		${INSTALL} -d ${STAGEDIR}${PREFIX}/lib/php/$$d; \
	done; \
	for i in `${FIND} propel -type f`; do \
		${INSTALL_DATA} $$i ${STAGEDIR}${PREFIX}/lib/php/$$i; \
	done
	cd ${WRKSRC}; \
	for d in `${FIND} generator -type d`; do \
		${INSTALL} -d ${STAGEDIR}${PREFIX}/share/propel/$$d; \
	done; \
	for i in `${FIND} generator -type f`; do \
		${INSTALL_DATA} $$i ${STAGEDIR}${PREFIX}/share/propel/$$i; \
	done
	${INSTALL_SCRIPT} ${WRKSRC}/propel-gen ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
