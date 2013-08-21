# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Scalar-Does
PORTVERSION=	0.200
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Like ref() but useful

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Type-Tiny>=0.004:${PORTSDIR}/devel/p5-Type-Tiny \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-lexical-underscore>=0:${PORTSDIR}/devel/p5-lexical-underscore \
		p5-namespace-clean>=0.19:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-IO-All>=0:${PORTSDIR}/devel/p5-IO-All \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-Path-Tiny>=0:${PORTSDIR}/devel/p5-Path-Tiny \
		p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires

CONFLICTS_INSTALL=	p5-IO-Detect-[0-9]*

USE_PERL5=	configure
USES=		perl5

MAN3=		IO::Detect.3 \
		Scalar::Does.3 \
		Scalar::Does::MooseTypes.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501601
BUILD_DEPENDS+=	p5-Scalar-List-Utils>=1.24:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS+=	p5-Scalar-List-Utils>=1.24:${PORTSDIR}/lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
