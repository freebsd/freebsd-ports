# New ports collection makefile for:	devel/p5-Cache-Cache
# Date created:				29 April 2001
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Cache-Cache
PORTVERSION=	1.01
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Cache
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/IPC/ShareLite.pm:${PORTSDIR}/devel/p5-IPC-ShareLite \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Error.pm:${PORTSDIR}/lang/p5-Error
RUN_DEPENDS=	${BUILD_DEPENDS}

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
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
