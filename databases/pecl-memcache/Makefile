# Created by: Gerrit Beine <tux@pinguru.net>
# $FreeBSD$

PORTNAME=	memcache
PORTVERSION=	3.0.8
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Memcached extension for PHP 5.6

LICENSE=	PHP30
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	EXAMPLES

CONFIGURE_ARGS=	--with-zlib-dir=/usr
IGNORE_WITH_PHP=70 71 72
USE_CSTD=	gnu89
USE_PHP=	session:build zlib:build
USES=		dos2unix php:pecl

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/example.php ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
