# Ports collection makefile for:	rubygem-memchache
# Date created:				2010-12-25
# Whom:					Mikhail T. <michael@fun-box.ru>
#
# $FreeBSD$

PORTNAME=	memcache
PORTVERSION=	1.2.13
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Ruby bindings for libmemcached

LIB_DEPENDS=	memcached:${PORTSDIR}/databases/libmemcached

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

GEM_ENV	+=EXTERNAL_LIB="YES"
CONFIGURE_ARGS=	"--with-opt-dir=${LOCALBASE}"

.include <bsd.port.mk>
