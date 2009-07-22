# New ports collection makefile for:	devel/p5-Cache-Cache
# Date created:				29 April 2001
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Cache-Cache
PORTVERSION=	1.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Cache::Cache -- Perl Cache interface

RUN_DEPENDS=	p5-Cache>=0:${PORTSDIR}/devel/p5-Cache \
		p5-Digest-SHA1>=2.02:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-Error>=0.15:${PORTSDIR}/lang/p5-Error \
		p5-IPC-ShareLite>=0.09:${PORTSDIR}/devel/p5-IPC-ShareLite

PERL_CONFIGURE=	yes

MAN3=	Cache::BaseCache.3 \
	Cache::BaseCacheTester.3 \
	Cache::Cache.3 \
	Cache::CacheMetaData.3 \
	Cache::CacheSizer.3 \
	Cache::CacheTester.3 \
	Cache::CacheUtils.3 \
	Cache::FileBackend.3 \
	Cache::FileCache.3 \
	Cache::MemoryBackend.3 \
	Cache::MemoryCache.3 \
	Cache::NullCache.3 \
	Cache::Object.3 \
	Cache::SharedMemoryBackend.3 \
	Cache::SharedMemoryCache.3 \
	Cache::SizeAwareCache.3 \
	Cache::SizeAwareCacheTester.3 \
	Cache::SizeAwareFileCache.3 \
	Cache::SizeAwareMemoryCache.3 \
	Cache::SizeAwareSharedMemoryCache.3

.include <bsd.port.mk>
