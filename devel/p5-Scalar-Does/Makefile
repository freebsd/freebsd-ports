# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Scalar-Does
PORTVERSION=	0.010
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Like ref() but useful

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-IO-Detect>=0.001:${PORTSDIR}/devel/p5-IO-Detect \
		p5-PadWalker>=0:${PORTSDIR}/devel/p5-PadWalker \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-namespace-clean>=0.19:${PORTSDIR}/devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-MooseX-Types>=0:${PORTSDIR}/devel/p5-MooseX-Types \
		p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings

# It requires UNIVERSAL::DOES on Perl 5.8
PERL_CONFIGURE=	yes

MAN3=		Scalar::Does.3 \
		Scalar::Does::MooseTypes.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
BUILD_DEPENDS+=	p5-Scalar-List-Utils>=1.20:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS+=	p5-Scalar-List-Utils>=1.20:${PORTSDIR}/lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
