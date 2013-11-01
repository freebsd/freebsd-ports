# $FreeBSD$

PORTNAME=	MooX-late
PORTVERSION=	0.014
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to easily translate Moose code to Moo

RUN_DEPENDS=	\
	p5-Moo>=1.003000:${PORTSDIR}/devel/p5-Moo \
	p5-Type-Tiny>=0.016:${PORTSDIR}/devel/p5-Type-Tiny
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
