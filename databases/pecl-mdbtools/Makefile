# Created by: Ditesh Shashikant Gathani <ditesh@gathani.org>
# $FreeBSD$

PORTNAME=	mdbtools
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	databases pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PECL extension for the mdbtools library

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/lib/libmdb.a:databases/mdbtools
RUN_DEPENDS=	${LOCALBASE}/lib/libmdb.a:databases/mdbtools

USES=		php:ext pkgconfig tar:tgz
IGNORE_WITH_PHP= 56 70

CONFIGURE_ARGS=	--with-mdbtools=${LOCALBASE}

post-extract:
	@${REINPLACE_CMD} -e 's|MDB_SDATETIME|MDB_DATETIME|g' \
		${WRKSRC}/mdbtools.c

.include <bsd.port.mk>
