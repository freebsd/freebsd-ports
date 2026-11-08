PORTNAME=	Astro-Constants
DISTVERSION=	0.1500
CATEGORIES=	astro perl5 science
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DUFFEE
DISTNAME=	${PORTNAME}-${PORTVERSION:C|00$||}
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Physical constants for use in astronomy
WWW=		https://metacpan.org/release/Astro-Constants

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	p5-Test-Number-Delta>=0:devel/p5-Test-Number-Delta

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
