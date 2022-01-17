PORTNAME=	GraphQL
PORTVERSION=	0.53
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ETJ
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Perl implementation of GraphQL

LICENSE=	ART20

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Moo>=0:devel/p5-Moo \
		p5-Type-Tiny>=0:devel/p5-Type-Tiny \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Function-Parameters>=2.001001:devel/p5-Function-Parameters \
		p5-Return-Type>=0:devel/p5-Return-Type \
		p5-Pegex>=0.64:devel/p5-Pegex \
		p5-Pod-Markdown>=0:textproc/p5-Pod-Markdown \
		p5-MooX-Thunking>=0.07:devel/p5-MooX-Thunking \
		p5-JSON-MaybeXS>=1.003009:converters/p5-JSON-MaybeXS \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-DateTime-Format-ISO8601>=0:devel/p5-DateTime-Format-ISO8601 \
		p5-Devel-StrictMode>=0:devel/p5-Devel-StrictMode \
		p5-Import-Into>=1.002003:devel/p5-Import-Into \
		p5-curry>=0:devel/p5-curry
TEST_DEPENDS=	p5-Test-Exception>=0.42:devel/p5-Test-Exception \
		p5-Test-Deep>=1.127:devel/p5-Test-Deep

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
