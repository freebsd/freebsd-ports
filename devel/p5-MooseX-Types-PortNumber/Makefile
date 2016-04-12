# $FreeBSD$

PORTNAME=	MooseX-Types-PortNumber
PORTVERSION=	0.02
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Port number type for Moose classes by the IANA

BUILD_DEPENDS=	p5-MooseX-Types>=0:devel/p5-MooseX-Types \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
RUN_DEPENDS=	p5-MooseX-Types>=0:devel/p5-MooseX-Types \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
TEST_DEPENDS=	p5-Test-Exception>=0.31:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} test

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502200
TEST_DEPENDS+=	p5-Test-Simple>=1.001.014:devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
