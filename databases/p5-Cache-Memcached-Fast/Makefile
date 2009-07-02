# New ports collection makefile for:	databases/p5-Cache-Memcached-Fast
# Date created:				17 December 2007
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Cache-Memcached-Fast
PORTVERSION=	0.16
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Fast Perl client for memcached, a distributed memory cache daemon

BUILD_DEPENDS=	p5-Compress-Zlib>0:${PORTSDIR}/archivers/p5-Compress-Zlib
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.2+

MAN3=	Cache::Memcached::Fast.3

.include <bsd.port.mk>
