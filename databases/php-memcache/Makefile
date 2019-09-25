# Created by: Gerrit Beine <tux@pinguru.net>
# $FreeBSD$

PORTNAME=	memcache
PORTVERSION=	4.0.4
CATEGORIES=	databases
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Memcached extension for PHP

LICENSE=	PHP30
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	EXAMPLES

PORTSCOUT=	skipv:start

USES=		dos2unix php:ext
USE_PHP=	session:build zlib:build

CONFIGURE_ARGS=	--with-zlib-dir=/usr

GH_ACCOUNT=	websupport-sk
GH_PROJECT=	pecl-${PORTNAME}
USE_GITHUB=	yes

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/example.php ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.options.mk>

.if ${FLAVOR} == php74
USES+=		compiler:c11
.endif

.include <bsd.port.mk>
