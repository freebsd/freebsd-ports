PORTNAME=	msgpack
PORTVERSION=	3.0.1
CATEGORIES=	devel

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Provides API for communicating with MessagePack serialization
WWW=		https://pecl.php.net/package/msgpack

LICENSE=	BSD3CLAUSE
LICENSE_FILE=   ${WRKSRC}/LICENSE

USES=		php:pecl
IGNORE_WITH_PHP=	86

OPTIONS_DEFINE=		APCU
OPTIONS_DEFAULT=	APCU
APCU_DESC=		Register as a serializer for APCu

APCU_BUILD_DEPENDS=	${LOCALBASE}/include/php/ext/apcu/apc_serializer.h:devel/pecl-APCu@${PHP_FLAVOR}
APCU_CONFIGURE_ENABLE=	apcu

.include <bsd.port.mk>
