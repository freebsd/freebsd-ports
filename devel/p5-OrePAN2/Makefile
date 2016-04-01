# $FreeBSD$

PORTNAME=	OrePAN2
PORTVERSION=	0.40
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:OALDERS
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for yet another DarkPAN manager

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Archive-Extract>=0.72:archivers/p5-Archive-Extract \
	p5-Class-Accessor-Lite>=0.05:devel/p5-Class-Accessor-Lite \
	p5-File-pushd>0:devel/p5-File-pushd \
	p5-IO-File-AtomicChange>=0:devel/p5-IO-File-AtomicChange \
	p5-IO-Socket-SSL>=1.42:security/p5-IO-Socket-SSL \
	p5-List-Compare>0:misc/p5-List-Compare \
	p5-MetaCPAN-Client>=1.006:devel/p5-MetaCPAN-Client \
	p5-Moo>=1.007000:devel/p5-Moo \
	p5-MooX-Options>0:devel/p5-MooX-Options \
	p5-Parse-CPAN-Packages>=2.39:devel/p5-Parse-CPAN-Packages \
	p5-Parse-LocalDistribution>=0.14:devel/p5-Parse-LocalDistribution \
	p5-Parse-PMFile>=0.29:devel/p5-Parse-PMFile \
	p5-Path-Tiny>0:devel/p5-Path-Tiny \
	p5-Try-Tiny>0:lang/p5-Try-Tiny \
	p5-Type-Tiny>=0:devel/p5-Type-Tiny \
	p5-Types-URI>=0:devel/p5-Types-URI
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuildtiny
NO_ARCH=	YES

.include <bsd.port.mk>
