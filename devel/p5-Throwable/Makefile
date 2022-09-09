PORTNAME=	Throwable
PORTVERSION=	1.000
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easy-to-use class for error objects
WWW=		https://metacpan.org/release/Throwable

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Devel-StackTrace>=1.32:devel/p5-Devel-StackTrace \
		p5-Module-Runtime>=0.002:devel/p5-Module-Runtime \
		p5-Moo>=1.000001:devel/p5-Moo

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
