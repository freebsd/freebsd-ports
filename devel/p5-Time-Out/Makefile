PORTNAME=	Time-Out
PORTVERSION=	0.24
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easily timeout long running operations
WWW=		https://metacpan.org/release/Time-Out

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-App-cpanminus>=1.7046:devel/p5-App-cpanminus \
		p5-ExtUtils-MakeMaker-CPANfile>=0.09:devel/p5-ExtUtils-MakeMaker-CPANfile \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-Try-Tiny>=0:lang/p5-Try-Tiny
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Needs>=0:devel/p5-Test-Needs

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
