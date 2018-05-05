# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	JSON-Path
PORTVERSION=	0.420
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Search nested hashref/arrayref structures using JSONPath

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Carp-Assert>=0:devel/p5-Carp-Assert \
		p5-Exporter-Easy>=0:devel/p5-Exporter-Easy \
		p5-Exporter-Tiny>=0:devel/p5-Exporter-Tiny \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-LV>=0:devel/p5-LV \
		p5-Readonly>=0:devel/p5-Readonly \
		p5-Scalar-List-Utils>=1.48:lang/p5-Scalar-List-Utils \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-JSON>=0:converters/p5-JSON \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Most>=0:devel/p5-Test-Most \
		p5-Test2-Suite>=0:devel/p5-Test2-Suite \
		p5-Tie-IxHash>=0:devel/p5-Tie-IxHash

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
