PORTNAME=	msgpack
PORTVERSION=	3.0.1
PORTREVISION=	1
CATEGORIES=	devel

PATCH_SITES+=	https://github.com/msgpack/msgpack-php/pull/185/commits/
PATCHFILES+=	cf19b26b6be9b7b5af10fe469fdcd661615d1acb.patch:-p1

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Provides API for communicating with MessagePack serialization
WWW=		https://pecl.php.net/package/msgpack

LICENSE=	BSD3CLAUSE
LICENSE_FILE=   ${WRKSRC}/LICENSE

USES=		php:pecl

OPTIONS_DEFINE=		APCU
OPTIONS_DEFAULT=	APCU
APCU_DESC=		Register as a serializer for APCu

APCU_BUILD_DEPENDS=	${LOCALBASE}/include/php/ext/apcu/apc_serializer.h:devel/pecl-APCu@${PHP_FLAVOR}
APCU_CONFIGURE_ENABLE=	apcu

.include <bsd.port.mk>
