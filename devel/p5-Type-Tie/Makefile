# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Type-Tie
PORTVERSION=	0.009
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOBYINK
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tie a variable to a type constraint

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Exporter-Tiny>=0.026:devel/p5-Exporter-Tiny \
		p5-Hash-FieldHash>=0:devel/p5-Hash-FieldHash
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-MooseX-Types>=0:devel/p5-MooseX-Types \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Requires>=0:devel/p5-Test-Requires \
		p5-Type-Tiny>=0.004:devel/p5-Type-Tiny

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
