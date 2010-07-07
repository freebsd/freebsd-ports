# New ports collection makefile for:	p5-Test-YAML-Meta
# Date created:		2008-02-13
# Whom:			Felippe de Meirelles Motta <lippemail@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Test-YAML-Meta
PORTVERSION=	0.16
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	Validation of the META.yml file in a distribution

BUILD_DEPENDS+=	${SITE_PERL}/Test/YAML/Valid.pm:${PORTSDIR}/devel/p5-Test-YAML-Valid \
		${SITE_PERL}/Test/Pod.pm:${PORTSDIR}/devel/p5-Test-Pod \
		${SITE_PERL}/Test/Pod/Coverage.pm:${PORTSDIR}/devel/p5-Test-Pod-Coverage
RUN_DEPENDS+=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::YAML::Meta::Version.3 \
		Test::YAML::Meta.3

.include <bsd.port.mk>
