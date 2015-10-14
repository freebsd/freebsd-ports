# Created by: Felippe de Meirelles Motta <lippemail@gmail.com>
# $FreeBSD$

PORTNAME=	Test-YAML-Meta
PORTVERSION=	0.20
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Validation of the META.yml file in a distribution

BUILD_DEPENDS=	p5-Test-YAML-Valid>=0:${PORTSDIR}/devel/p5-Test-YAML-Valid \
		p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
		p5-Test-CPAN-Meta-YAML>=0.17:${PORTSDIR}/devel/p5-Test-CPAN-Meta-YAML
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
