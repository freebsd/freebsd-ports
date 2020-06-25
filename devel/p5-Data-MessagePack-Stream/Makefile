# $FreeBSD$

PORTNAME=	Data-MessagePack-Stream
PORTVERSION=	0.07
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for yet another messagepack streaming deserializer

BROKEN_mips=		fails to build: atomic operations are not found
BROKEN_mips64=		fails to build: atomic operations are not found
BROKEN_sparc64=		fails to build: atomic operations are not found

BUILD_DEPENDS=	p5-Data-MessagePack>0:devel/p5-Data-MessagePack

USES=		perl5
USE_PERL5=	configure
MAKE_JOBS_UNSAFE=	yes

CFLAGS_aarch64=	-fPIC
CFLAGS_armv7=	-fPIC
CFLAGS_i386=	-fPIC
CFLAGS_powerpc=	-fPIC

.include <bsd.port.mk>
