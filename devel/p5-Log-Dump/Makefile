# $FreeBSD$

PORTNAME=	Log-Dump
PORTVERSION=	0.14
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of simple logger mainly for debugging

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Data-Dump>0:devel/p5-Data-Dump \
	p5-Sub-Install>0:devel/p5-Sub-Install
BUILD_DEPENDS=	${RUN_DEPENDS} \
	p5-ExtUtils-MakeMaker-CPANfile>0:devel/p5-ExtUtils-MakeMaker-CPANfile

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
