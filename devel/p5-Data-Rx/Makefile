PORTNAME=	Data-Rx
PORTVERSION=	0.200008
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl implementation of Rx schema system
WWW=		https://metacpan.org/release/Data-Rx

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-Find-Rule>=0:devel/p5-File-Find-Rule \
		p5-JSON>=2:converters/p5-JSON \
		p5-Number-Tolerant>=0:devel/p5-Number-Tolerant
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
