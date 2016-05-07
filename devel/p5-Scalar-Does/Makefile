# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Scalar-Does
PORTVERSION=	0.202
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Like ref() but useful

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Exporter-Tiny>=0.026:devel/p5-Exporter-Tiny \
		p5-Type-Tiny>=0.004:devel/p5-Type-Tiny \
		p5-URI>=0:net/p5-URI \
		p5-lexical-underscore>=0:devel/p5-lexical-underscore \
		p5-namespace-clean>=0.19:devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-IO-All>=0:devel/p5-IO-All \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-Types>=0:devel/p5-MooseX-Types \
		p5-Path-Class>=0:devel/p5-Path-Class \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-Test-NoWarnings>=0:devel/p5-Test-NoWarnings \
		p5-Test-Requires>=0.06:devel/p5-Test-Requires

CONFLICTS_INSTALL=	p5-IO-Detect-[0-9]*

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
