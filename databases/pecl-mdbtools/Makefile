# Created by: Ditesh Shashikant Gathani <ditesh@gathani.org>
# $FreeBSD$

PORTNAME=	mdbtools
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	databases pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A PECL extension for the mdbtools library

LICENSE=	LGPL21

USES=		pkgconfig
USE_PHP=	yes
USE_PHPEXT=	yes
USE_PHP_BUILD=	yes
DEFAULT_PHP_VER=53
IGNORE_WITH_PHP=5
BUILD_DEPENDS=	${LOCALBASE}/lib/libmdb.a:${PORTSDIR}/databases/mdbtools
RUN_DEPENDS=	${LOCALBASE}/lib/libmdb.a:${PORTSDIR}/databases/mdbtools

CONFIGURE_ARGS=	--with-mdbtools=${LOCALBASE}

NO_STAGE=	yes

post-extract:
	@${REINPLACE_CMD} -e 's|MDB_SDATETIME|MDB_DATETIME|g' \
		${WRKSRC}/mdbtools.c

.include <bsd.port.mk>
