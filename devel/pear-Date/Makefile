# Ports collection makefile for:  pear-Date
# Date created:			  28 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Date
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	devel www
MASTER_SITES=	http://pear.php.net/get/
PKGNAMEPREFIX=	pear-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PEAR

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR Date and Time Zone Classes

BUILD_DEPENDS=	${PEARDIR}.DIST_PHP:${PORTSDIR}/devel/pear-install
RUN_DEPENDS=	${BUILD_DEPENDS}

NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/php-config)
PHP_BASE!=	${LOCALBASE}/bin/php-config --prefix
.else
PHP_BASE=	${LOCALBASE}
.endif
PEAR=		${LOCALBASE}/bin/pear
LPHP_LIB=	lib/php
PEARDIR=	${PHP_BASE}/${LPHP_LIB}
PLIST_SUB=	PEARDIR=${LPHP_LIB}

MANIFEST=	Date Date.php

do-install:
	@${CP} -Rp ${WRKSRC}/* ${PEARDIR}
.for FILE in ${MANIFEST}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/${FILE}
.endfor

post-install:
# Register a new package
	@${PEAR} install -r -f ${WRKDIR}/package.xml

.include <bsd.port.post.mk>
