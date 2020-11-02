# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rb-kqueue
PORTVERSION=	0.2.5
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PATCH_SITES=	https://github.com/mat813/rb-kqueue/commit/
PATCHFILES=	144ee7bb7963c77fc219ba736df7ee952d50ab19.patch:-p1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby wrapper for BSD kqueue, using FFI

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-ffi>=0.5.0:devel/rubygem-ffi

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
