PORTNAME=	Proc-Find-Parents
PORTVERSION=	0.631
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Find parents of a process (up to the root)

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Proc-ProcessTable>=0:devel/p5-Proc-ProcessTable
TEST_DEPENDS=	p5-File-Which>=0:sysutils/p5-File-Which

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
