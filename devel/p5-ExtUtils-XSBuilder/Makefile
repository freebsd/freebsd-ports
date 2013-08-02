# Created by: vanilla
# $FreeBSD$

PORTNAME=	ExtUtils-XSBuilder
PORTVERSION=	0.28
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Autogenerating XS-glue Code

RUN_DEPENDS=	p5-Tie-IxHash>=0:${PORTSDIR}/devel/p5-Tie-IxHash
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		ExtUtils::XSBuilder.3 ExtUtils::XSBuilder::C::grammar.3 \
		ExtUtils::XSBuilder::PODTemplate.3 \
		ExtUtils::XSBuilder::ParseSource.3 \
		ExtUtils::XSBuilder::WrapXS.3 ExtUtils::xsbuilder.osc2002.3

.include <bsd.port.mk>
