# New ports collection makefile for:	pecl-memcache
# Date created:			10 August 2004
# Whom:				Gerrit Beine <tux@pinguru.net>
#
# $FreeBSD$
#

PORTNAME=	memcache
PORTVERSION=	2.0.0
CATEGORIES=	databases
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	tux@pinguru.net
COMMENT=	Memcached extension

USE_REINPLACE=	yes
USE_PHP=	zlib
USE_PHPEXT=	yes
PHP_MODNAME=	memcache

CONFIGURE_ARGS=	--with-zlib-dir=/usr

post-extract:
	@${FIND} -E ${WRKDIR} -type f -iregex ".*\.(c|cpp|h|txt|php)" -print0 | \
		${XARGS} -0 ${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//'

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example.php ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
