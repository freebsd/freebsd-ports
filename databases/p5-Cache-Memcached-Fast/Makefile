# New ports collection makefile for:	databases/p5-Cache-Memcached-Fast
# Date created:				17 December 2007
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Cache-Memcached-Fast
PORTVERSION=	0.06
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Cache
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Fast Perl client for memcached, a distributed memory cache daemon

BUILD_DEPENDS=	p5-Storable>0:${PORTSDIR}/devel/p5-Storable
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Cache::Memcached::Fast.3

.include <bsd.port.mk>
