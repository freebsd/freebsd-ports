PORTNAME=	memcache
PORTVERSION=	8.2
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Memcached extension
WWW=		https://pecl.php.net/package/memcache \
		https://github.com/websupport-sk/pecl-memcache

LICENSE=	PHP30
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		dos2unix php:pecl
USE_PHP=	session:build zlib:build

CONFIGURE_ARGS=	--with-zlib-dir=/usr
USE_CSTD=	gnu89

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/example.php ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
