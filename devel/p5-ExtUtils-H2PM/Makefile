PORTNAME=	ExtUtils-H2PM
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Automatically generate Perl modules to wrap C header files
WWW=		https://metacpan.org/dist/ExtUtils-H2PM

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Module-Build>=0.4004:devel/p5-Module-Build
TEST_DEPENDS=	p5-Test-Pod>=1.00:devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
