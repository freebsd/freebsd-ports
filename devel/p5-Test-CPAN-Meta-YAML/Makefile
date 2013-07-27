# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-CPAN-Meta-YAML
PORTVERSION=	0.22
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Validate a META.yml file within a CPAN distribution

LICENSE=	ART20

BUILD_DEPENDS=	p5-Test-YAML-Valid>=0.03:${PORTSDIR}/devel/p5-Test-YAML-Valid
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::CPAN::Meta::YAML.3 \
		Test::CPAN::Meta::YAML::Version.3

.include <bsd.port.mk>
