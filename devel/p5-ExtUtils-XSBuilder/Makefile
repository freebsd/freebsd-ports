# New ports collection makefile for:	ExtUtils::XSBuilder
# Date created:				11 Sep 2003
# Whom:                			vanilla
#
# $FreeBSD$
#

PORTNAME=	ExtUtils-XSBuilder
PORTVERSION=	0.28
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Autogenerating XS-glue Code

RUN_DEPENDS=	${SITE_PERL}/Tie/IxHash.pm:${PORTSDIR}/devel/p5-Tie-IxHash
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		ExtUtils::XSBuilder.3 ExtUtils::XSBuilder::C::grammar.3 \
		ExtUtils::XSBuilder::PODTemplate.3 \
		ExtUtils::XSBuilder::ParseSource.3 \
		ExtUtils::XSBuilder::WrapXS.3 ExtUtils::xsbuilder.osc2002.3

.include <bsd.port.mk>
