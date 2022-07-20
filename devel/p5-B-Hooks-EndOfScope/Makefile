PORTNAME=	B-Hooks-EndOfScope
PORTVERSION=	0.26
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Execute code after a scope finished compilation

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENCE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Module-Implementation>=0.05:devel/p5-Module-Implementation \
		p5-Sub-Exporter-Progressive>=0.001006:devel/p5-Sub-Exporter-Progressive \
		p5-Variable-Magic>=0.48:devel/p5-Variable-Magic

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
