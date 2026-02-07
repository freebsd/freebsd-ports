PORTNAME=	Test2-Tools-PDL
PORTVERSION=	0.0010
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SLOYD
PKGNAMEPREFIX=	p5-
DISTNAME=	Test2-Tools-PDL-${PORTVERSION:S|0$||}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Test2 tools for verifying Perl Data Language piddles
WWW=		https://metacpan.org/dist/Test2-Tools-PDL

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-PDL>=0:math/p5-PDL \
		p5-Safe-Isa>=0:devel/p5-Safe-Isa \
		p5-Test-Simple>=1.302200:devel/p5-Test-Simple
TEST_DEPENDS=	p5-Data-Frame>=0:devel/p5-Data-Frame \
		p5-PDL-DateTime>=0:math/p5-PDL-DateTime

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
