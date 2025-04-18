PORTNAME=	Test-Mini
PORTVERSION=	1.1.3
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Lightweight xUnit Testing for Perl
WWW=		https://metacpan.org/release/Test-Mini

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Data-Inspect>=0.03:devel/p5-Data-Inspect \
		p5-Exception-Class>=1.30:devel/p5-Exception-Class \
		p5-List-MoreUtils>=0.22:lang/p5-List-MoreUtils \
		p5-MRO-Compat>=0.10:devel/p5-MRO-Compat \
		p5-Text-Outdent>=0.01:devel/p5-Text-Outdent \
		p5-Try-Tiny>=0.04:lang/p5-Try-Tiny \
		p5-namespace-clean>=0.14:devel/p5-namespace-clean
TEST_DEPENDS=	p5-IO-Stringy>=2.110:devel/p5-IO-Stringy \
		p5-aliased>=0.30:devel/p5-aliased

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
