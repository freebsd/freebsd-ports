# Created by: Ditesh Shashikant Gathani <ditesh@gathani.org>
# $FreeBSD$

PORTNAME=	spl_types
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	devel pear
DISTNAME=	SPL_Types-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	PECL extension of a collection of special typehandling classes

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	PHP301

OPTIONS_DEFINE=	RE2C
RE2C_DESC=	Compile regular expression 2 C
RE2C_RUN_DEPENDS=	re2c:devel/re2c

USE_PHP=	spl
USES=		php:pecl
IGNORE_WITH_PHP=	71 72 73

CONFIGURE_ARGS=	--enable-spl-types
CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
