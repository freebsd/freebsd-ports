PORTNAME=	DateTimeX-Easy
PORTVERSION=	0.092
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parse a date/time string using the best method available
WWW=		https://metacpan.org/release/DateTimeX-Easy

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_GPLv1+ =	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DateTime>=0:devel/p5-DateTime \
		p5-DateTime-Format-DateManip>=0:devel/p5-DateTime-Format-DateManip \
		p5-DateTime-Format-Flexible>=0:devel/p5-DateTime-Format-Flexible \
		p5-DateTime-Format-ICal>=0:devel/p5-DateTime-Format-ICal \
		p5-DateTime-Format-Natural>=0:devel/p5-DateTime-Format-Natural \
		p5-DateTime-TimeZone>=2.63,1:devel/p5-DateTime-TimeZone \
		p5-TimeDate>=0,1:devel/p5-TimeDate \
		p5-YAML>=0:textproc/p5-YAML
TEST_DEPENDS=	p5-Test-Most>=0:devel/p5-Test-Most

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
