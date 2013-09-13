# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rb-inotify
PORTVERSION=	0.9.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby wrapper for libinotify, using ffi

LICENSE=	MIT

LIB_DEPENDS=	libinotify.so:${PORTSDIR}/devel/libinotify
RUN_DEPENDS=	rubygem-ffi>=0.5.0:${PORTSDIR}/devel/rubygem-ffi

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
