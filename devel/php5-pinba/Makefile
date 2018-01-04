# Created by: raven428 <raven428@gmail.com>
# $FreeBSD$

PORTNAME=	pinba
PORTVERSION=	2012.03.20
PORTREVISION=	8
CATEGORIES=	devel
PKGNAMEPREFIX=	php5-

MAINTAINER=	komarov@valerka.net
COMMENT=	PHP-extension part of statistics server for PHP

LIB_DEPENDS=	libprotobuf.so:devel/protobuf

BROKEN_powerpc64=	fails to compile: class 'google::protobuf::internal::InternalMetadataWithArenaLite' does not have any field named 'InternalMetadataWithArenaBase'

USE_GITHUB=	yes
GH_ACCOUNT=	tony2001
GH_PROJECT=	pinba_extension
GH_TAGNAME=	f76b673

USES=		php:ext
IGNORE_WITH_PHP=	70 71

.include <bsd.port.mk>
