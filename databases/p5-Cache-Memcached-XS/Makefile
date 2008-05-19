# New ports collection makefile for:	Cache-Memcached-XS
# Date created:	   8 September 2006
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Cache-Memcached-XS
PORTVERSION=	0.01
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Client library for memcached using libmemcache

LIB_DEPENDS=	memcache.4:${PORTSDIR}/databases/libmemcache
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.6+
CONFIGURE_ARGS=	INC="-I${LOCALBASE}/include"

MAN3=		Cache::Memcached::XS.3

.include <bsd.port.mk>
