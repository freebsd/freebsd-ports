# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Params-Validate-Dependencies
PORTVERSION=	1.21
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Validate combinations of parameters

BUILD_DEPENDS=	p5-Data-Domain>=1.02:${PORTSDIR}/devel/p5-Data-Domain \
		p5-PadWalker>=1.96:${PORTSDIR}/devel/p5-PadWalker \
		p5-Params-Validate>=1.07:${PORTSDIR}/devel/p5-Params-Validate
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=1:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1:${PORTSDIR}/devel/p5-Test-Pod-Coverage

USE_PERL5=	configure
USES=		perl5

MAN3=		Data::Domain::Dependencies.3 \
		Params::Validate::Dependencies.3 \
		Params::Validate::Dependencies::Extending.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501601
BUILD_DEPENDS+=	p5-Scalar-List-Utils>=1.25:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS+=	p5-Scalar-List-Utils>=1.25:${PORTSDIR}/lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
