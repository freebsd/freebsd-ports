# Ports collection makefile for:  pear-PEAR
# Date created:			  22 October 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	PEAR
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	devel www
MASTER_SITES=	http://pear.php.net/get/
PKGNAMEPREFIX=	pear-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PEAR

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${PEARDIR}.DIST_PHP:${PORTSDIR}/devel/pear-install
RUN_DEPENDS=	${BUILD_DEPENDS}

NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/php-config)
PHP_BASE!=	${LOCALBASE}/bin/php-config --prefix
.endif
LPHP_LIB=	lib/php
PEARDIR=	${PHP_BASE}/${LPHP_LIB}
PLIST_SUB=	PEARDIR=${LPHP_LIB}
MANIFEST=	OS PEAR PEAR.php System.php package.dtd scripts template.spec
TOBACKUP=	OS PEAR PEAR.php System.php

do-install:
.for FILE in ${TOBACKUP}
	@${MV} ${PEARDIR}/${FILE} ${PEARDIR}/${FILE}.dist
.endfor
	@${CP} -Rp ${WRKSRC}/* ${PEARDIR}
.for FILE in ${MANIFEST}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/${FILE}
.endfor

.include <bsd.port.post.mk>
