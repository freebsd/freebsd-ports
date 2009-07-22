# New ports collection makefile for:	devel/p5-Cache
# Date created:				13 December 2004
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Cache
PORTVERSION=	2.04
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A Perl Cache interface

RUN_DEPENDS=	p5-Digest-SHA1>=2.01:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-File-NFSLock>=1.2:${PORTSDIR}/devel/p5-File-NFSLock \
		p5-Heap>=0.01:${PORTSDIR}/devel/p5-Heap \
		p5-IO-String>=1.02:${PORTSDIR}/devel/p5-IO-String \
		p5-TimeDate>=2.24:${PORTSDIR}/devel/p5-TimeDate

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

.include <bsd.port.mk>
