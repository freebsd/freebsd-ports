# $FreeBSD$

PORTNAME=	MooX-late
PORTVERSION=	0.015
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to easily translate Moose code to Moo

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Moo>=1.006000:devel/p5-Moo \
	p5-Test-Requires>=0.06:devel/p5-Test-Requires \
	p5-Type-Tiny>=1.000001:devel/p5-Type-Tiny
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
