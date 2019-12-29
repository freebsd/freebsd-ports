# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rb-inotify
PORTVERSION=	0.10.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby wrapper for libinotify, using ffi

LICENSE=	MIT

LIB_DEPENDS=	libinotify.so:devel/libinotify
RUN_DEPENDS=	rubygem-ffi>=1.0<2:devel/rubygem-ffi

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
