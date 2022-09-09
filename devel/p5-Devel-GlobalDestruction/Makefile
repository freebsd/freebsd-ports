PORTNAME=	Devel-GlobalDestruction
PORTVERSION=	0.14
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Expose PL_dirty, the flag which marks global destruction
WWW=		https://metacpan.org/release/Devel-GlobalDestruction

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Sub-Exporter-Progressive>=0.001011:devel/p5-Sub-Exporter-Progressive

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
