# New ports collection makefile for:	devel/p5-Cache-Cache
# Date created:				29 April 2001
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Cache-Cache
PORTVERSION=	1.04
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Cache
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Cache::Cache -- Perl Cache interface

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/IPC/ShareLite.pm:${PORTSDIR}/devel/p5-IPC-ShareLite \
		${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1
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

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
.endif
.if ${PERL_LEVEL} <= 500600
BUILD_DEPENDS+=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
RUN_DEPENDS+=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
.endif

.include <bsd.port.post.mk>
