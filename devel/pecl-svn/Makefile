# Created by: Alex Kiesel <kiesel@schlund.de>
# $FreeBSD$

PORTNAME=	svn
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	devel pear

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	PECL extension to the libsvn library

LICENSE=	PHP301

LIB_DEPENDS=	libsvn_client-1.so:devel/subversion

USE_CSTD=	c99
USES=		php:pecl
IGNORE_WITH_PHP=	70 71 72

.include <bsd.port.mk>
