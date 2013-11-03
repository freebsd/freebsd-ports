# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Cache-Memcached-XS
PORTVERSION=	0.01
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Client library for memcached using libmemcache

LIB_DEPENDS=	memcache.4:${PORTSDIR}/databases/libmemcache
BUILD_DEPENDS=	p5-Storable>=0:${PORTSDIR}/devel/p5-Storable
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	INC="-I${LOCALBASE}/include"

.include <bsd.port.mk>
