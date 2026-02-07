PORTNAME=	Syntax-Keyword-Junction
PORTVERSION=	0.003009
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl6 style Junction operators in Perl5
WWW=		https://metacpan.org/release/Syntax-Keyword-Junction

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Sub-Exporter-Progressive>=0.001006:devel/p5-Sub-Exporter-Progressive
TEST_DEPENDS=	p5-Test-Needs>=0.002006:devel/p5-Test-Needs

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
