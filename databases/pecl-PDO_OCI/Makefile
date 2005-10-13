# Ports collection makefile for:	pecl-PDO_OCI
# Date created:				2005-10-10
# Whom:					Simun Mikecin <numisemis@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	PDO_OCI
DISTVERSION=	1.0RC1
CATEGORIES=	databases www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	numisemis@yahoo.com
COMMENT=	Oracle OCI 8 Interface driver for PDO

BUILD_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo.so:${PORTSDIR}/databases/pecl-PDO
BUILD_DEPENDS+=	${LOCALBASE}/oracle8-client/lib/libclntsh.a:${PORTSDIR}/databases/oracle8-client
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PHP=	yes
USE_PHPIZE=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=5
PHP_MODNAME=	pdo_oci

CONFIGURE_ARGS+=	--with-pdo-oci=${LOCALBASE}/oracle8-client
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
PTHREAD_STATIC=	/usr/lib/libc_r
.else
PTHREAD_STATIC=	/usr/lib/libpthread
.endif

pre-configure:
	@cd ${WRKSRC}; \
	for lib in ${LOCALBASE}/oracle8-client/lib/libclntsh ${PTHREAD_STATIC}; do \
		/usr/bin/ar x $${lib}.a; \
	done; \
	/usr/bin/ar rcs liboci8.a *.o

.include <bsd.port.post.mk>
