# New ports collection makefile for:	p5-Test-CPAN-Meta-YAML
# Date created:		2012-06-01
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-CPAN-Meta-YAML
PORTVERSION=	0.21
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Validate a META.yml file within a CPAN distribution

BUILD_DEPENDS=	p5-Test-YAML-Valid>=0.03:${PORTSDIR}/devel/p5-Test-YAML-Valid
RUN_DEPENDS=	p5-Test-YAML-Valid>=0.03:${PORTSDIR}/devel/p5-Test-YAML-Valid

PERL_CONFIGURE=	yes

MAN3=		Test::CPAN::Meta::YAML.3 \
		Test::CPAN::Meta::YAML::Version.3

.include <bsd.port.mk>
