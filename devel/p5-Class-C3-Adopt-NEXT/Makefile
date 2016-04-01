# Created by: Denis Pokataev <catone@cpan.org>
# $FreeBSD$

PORTNAME=	Class-C3-Adopt-NEXT
PORTVERSION=	0.14
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Make NEXT suck less

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-MRO-Compat>=0:devel/p5-MRO-Compat
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0.27:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502000
BUILD_DEPENDS+=	p5-Scalar-List-Utils>=1.33:lang/p5-Scalar-List-Utils
RUN_DEPENDS+=	p5-Scalar-List-Utils>=1.33:lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
