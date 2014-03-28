# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Return-Type
PORTVERSION=	0.003
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOBYINK
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Specify a return type for a function (optionally with coercion)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Scope-Upper>=0:${PORTSDIR}/devel/p5-Scope-Upper \
		p5-Sub-Identify>=0:${PORTSDIR}/devel/p5-Sub-Identify \
		p5-Sub-Name>=0:${PORTSDIR}/devel/p5-Sub-Name \
		p5-Type-Tiny>=0:${PORTSDIR}/devel/p5-Type-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
