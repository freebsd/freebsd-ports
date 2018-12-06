# Created by: Alex Kiesel <kiesel@schlund.de>
# $FreeBSD$

PORTNAME=	svn
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	devel pear

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	PECL extension to the libsvn library

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	PHP301

LIB_DEPENDS=	libsvn_client-1.so:devel/subversion

USES=		php:pecl
IGNORE_WITH_PHP=	71 72 73
USE_CSTD=	c99

.include <bsd.port.mk>
