# Created by: Gerrit Beine <tux@pinguru.net>
# $FreeBSD$

PORTNAME=	memcache
PORTVERSION=	4.0.5.1
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Unofficial Memcached extension

LICENSE=	PHP30
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	EXAMPLES

USES=		dos2unix php:pecl
USE_PHP=	session:build zlib:build

CONFIGURE_ARGS=	--with-zlib-dir=/usr
USE_CSTD=	gnu89

USE_GITHUB=	yes
GH_ACCOUNT=	websupport-sk
GH_PROJECT=	pecl-memcache

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/example.php ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
