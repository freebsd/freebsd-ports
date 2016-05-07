# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MooseX-Types-DateTime-MoreCoercions
PORTVERSION=	0.15
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extensions to MooseX::Types::DateTime

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-DateTime>=0.43.02:devel/p5-DateTime \
		p5-DateTimeX-Easy>=0.085:devel/p5-DateTimeX-Easy \
		p5-Moose>=0.41:devel/p5-Moose \
		p5-MooseX-Types>=0.04:devel/p5-MooseX-Types \
		p5-MooseX-Types-DateTime>=0.06:devel/p5-MooseX-Types-DateTime \
		p5-Time-Duration-Parse>=0.06:devel/p5-Time-Duration-Parse \
		p5-namespace-clean>=0.19:devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal

NO_ARCH=	yes
USE_PERL5=	modbuildtiny
USES=		perl5

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502200
TEST_DEPENDS+=	p5-Test-Simple>=1.001.014:devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
