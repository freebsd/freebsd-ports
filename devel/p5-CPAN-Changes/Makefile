PORTNAME=	CPAN-Changes
PORTVERSION=	0.500003
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Read and write CPAN Changes files
WWW=		https://metacpan.org/release/CPAN-Changes

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Moo>=1.006000:devel/p5-Moo \
		p5-Sub-Quote>=1.005000:devel/p5-Sub-Quote \
		p5-Type-Tiny>=0:devel/p5-Type-Tiny

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
