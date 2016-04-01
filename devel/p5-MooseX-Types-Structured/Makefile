# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	MooseX-Types-Structured
PORTVERSION=	0.35
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Moose Type Constraint classes for Structured Types

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Devel-PartialDump>=0.13:devel/p5-Devel-PartialDump \
		p5-Moose>=1.08:devel/p5-Moose \
		p5-MooseX-Types>=0.22:devel/p5-MooseX-Types \
		p5-Sub-Exporter>=0.982:devel/p5-Sub-Exporter \
		p5-namespace-clean>=0.19:devel/p5-namespace-clean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-DateTime>=0:devel/p5-DateTime \
		p5-MooseX-Types-DateTime>=0:devel/p5-MooseX-Types-DateTime \
		p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Requires>=0:devel/p5-Test-Requires

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502200
BUILD_DEPENDS+=	p5-JSON-PP>=2.27300:converters/p5-JSON-PP
RUN_DEPENDS+=	p5-JSON-PP>=2.27300:converters/p5-JSON-PP
.endif

.include <bsd.port.post.mk>
