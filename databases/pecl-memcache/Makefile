# New ports collection makefile for:	pecl-memcache
# Date created:			10 August 2004
# Whom:				Gerrit Beine <tux@pinguru.net>
#
# $FreeBSD$
#

PORTNAME=	memcache
PORTVERSION=	1.4
CATEGORIES=	databases
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	tux@pinguru.net
COMMENT=	Memcached extension

RUN_DEPENDS=	memcached:${PORTSDIR}/databases/memcached

USE_PHP=	zlib
USE_PHPEXT=	yes
PHP_MODNAME=	memcache

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example.php ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
