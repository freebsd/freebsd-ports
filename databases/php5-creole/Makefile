# $FreeBSD$

PORTNAME=	creole
PORTVERSION=	1.0.2
CATEGORIES=	databases pear
MASTER_SITES=	http://creole.tigris.org/files/documents/996/22124/ \
		http://dist.bsdlab.org/
PKGNAMEPREFIX=	php5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Database abstraction layer for PHP5

USE_PHP=	yes
PHP_DEFAULT=	5.4
NO_BUILD=	yes

do-install:
	cd ${WRKSRC}/classes; \
	for d in `${FIND} creole jargon -type d`; do \
		${INSTALL} -d ${STAGEDIR}${PREFIX}/lib/php/$$d; \
	done; \
	for i in `${FIND} creole jargon -type f`; do \
		${INSTALL_DATA} $$i ${STAGEDIR}${PREFIX}/lib/php/$$i; \
	done

.include <bsd.port.mk>
