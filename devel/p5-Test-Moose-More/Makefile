# $FreeBSD$

PORTNAME=	Test-Moose-More
PORTVERSION=	0.050
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	More tools for testing Moose packages

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Data-OptList>=0:devel/p5-Data-OptList \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Moose>=0:devel/p5-Moose \
		p5-Sub-Exporter-Progressive>=0:devel/p5-Sub-Exporter-Progressive \
		p5-Syntax-Keyword-Junction>=0:devel/p5-Syntax-Keyword-Junction
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-TAP-SimpleOutput>=0.009:devel/p5-TAP-SimpleOutput \
		p5-Test-CheckDeps>=0.010:devel/p5-Test-CheckDeps \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502501
BUILD_DEPENDS+=	p5-Scalar-List-Utils>=1.45:lang/p5-Scalar-List-Utils
RUN_DEPENDS+=	p5-Scalar-List-Utils>=1.45:lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
