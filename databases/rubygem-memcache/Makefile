PORTNAME=	memcache
PORTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby bindings for libmemcached
WWW=		https://github.com/ninjudd/memcache

LICENSE=	MIT

LIB_DEPENDS=	libmemcached.so:databases/libmemcached

CONFIGURE_ARGS=	--with-opt-dir=${LOCALBASE}
GEM_ENV=	EXTERNAL_LIB="yes"
USES=		gem

.include <bsd.port.mk>
