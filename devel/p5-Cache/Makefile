# New ports collection makefile for:	devel/p5-Cache
# Date created:				13 December 2004
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Cache
PORTVERSION=	2.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Cache
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A Perl Cache interface

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/IO/String.pm:${PORTSDIR}/devel/p5-IO-String \
		${SITE_PERL}/Heap/Fibonacci.pm:${PORTSDIR}/devel/p5-Heap \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/File/NFSLock.pm:${PORTSDIR}/devel/p5-File-NFSLock \
		${SITE_PERL}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Cache.3 \
		Cache::Entry.3 \
		Cache::File.3 \
		Cache::File::Entry.3 \
		Cache::File::Handle.3 \
		Cache::File::Heap.3 \
		Cache::IOString.3 \
		Cache::Memory.3 \
		Cache::Memory::Entry.3 \
		Cache::Memory::HeapElem.3 \
		Cache::Null.3 \
		Cache::Null::Entry.3 \
		Cache::RemovalStrategy.3 \
		Cache::RemovalStrategy::FIFO.3 \
		Cache::RemovalStrategy::LRU.3 \
		Cache::Tester.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500600
IGNORE=		This port requires perl 5.6.0 or later. Install lang/perl5 then try again
.endif
.include <bsd.port.post.mk>
