# Created by: Mikhail T. <michael@fun-box.ru>
# $FreeBSD$

PORTNAME=	memcache
PORTVERSION=	1.4.1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby bindings for libmemcached

LIB_DEPENDS=	memcached:${PORTSDIR}/databases/libmemcached

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

GEM_ENV	+=EXTERNAL_LIB="YES"
CONFIGURE_ARGS=	"--with-opt-dir=${LOCALBASE}"

.include <bsd.port.mk>
