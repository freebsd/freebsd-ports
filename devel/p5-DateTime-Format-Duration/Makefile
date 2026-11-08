PORTNAME=	DateTime-Format-Duration
DISTVERSION=	1.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ETHER
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Format and parse DateTime::Durations
WWW=		https://metacpan.org/release/DateTime-Format-Duration

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DateTime>=0:devel/p5-DateTime
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:C/a$//}

.include <bsd.port.mk>
