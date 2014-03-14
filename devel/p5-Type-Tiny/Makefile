# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Type-Tiny
PORTVERSION=	0.038
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOBYINK
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tiny, yet Moo(se)-compatible type constraint

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Exporter-Tiny>=0.026:${PORTSDIR}/devel/p5-Exporter-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Class-InsideOut>=0:${PORTSDIR}/devel/p5-Class-InsideOut \
		p5-Devel-StackTrace>=0:${PORTSDIR}/devel/p5-Devel-StackTrace \
		p5-Function-Parameters>=0:${PORTSDIR}/devel/p5-Function-Parameters \
		p5-JSON>=0:${PORTSDIR}/converters/p5-JSON \
		p5-Moo>=1.002001:${PORTSDIR}/devel/p5-Moo \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-MooseX-Types-Common>=0:${PORTSDIR}/devel/p5-MooseX-Types-Common \
		p5-Mouse>=0:${PORTSDIR}/devel/p5-Mouse \
		p5-MouseX-Types>=0:${PORTSDIR}/devel/p5-MouseX-Types \
		p5-Role-Tiny>=0:${PORTSDIR}/devel/p5-Role-Tiny \
		p5-Sub-Exporter-Lexical>=0:${PORTSDIR}/devel/p5-Sub-Exporter-Lexical \
		p5-Test-LeakTrace>=0:${PORTSDIR}/devel/p5-Test-LeakTrace \
		p5-Validation-Class>=0:${PORTSDIR}/devel/p5-Validation-Class

PORTSCOUT=	limit:[^_]*

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501600
BUILD_DEPENDS+=	p5-CPAN-Meta-Requirements>=2:${PORTSDIR}/devel/p5-CPAN-Meta-Requirements
RUN_DEPENDS+=	p5-CPAN-Meta-Requirements>=2:${PORTSDIR}/devel/p5-CPAN-Meta-Requirements
.endif

.include <bsd.port.post.mk>
