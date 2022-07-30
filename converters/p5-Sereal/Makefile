PORTNAME=	Sereal
PORTVERSION=	4.025
CATEGORIES=	converters perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:YVES
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for fast, compact, powerful binary (de-)serialization

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Sereal-Decoder>=${PORTVERSION}:converters/p5-Sereal-Decoder \
		p5-Sereal-Encoder>=${PORTVERSION}:converters/p5-Sereal-Encoder
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Differences>=0,1:devel/p5-Test-Differences \
		p5-Test-LongString>=0:devel/p5-Test-LongString \
		p5-Test-Warn>=0:devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	configure

MAKE_JOBS_UNSAFE=	yes
NO_ARCH=	yes

.include <bsd.port.mk>
