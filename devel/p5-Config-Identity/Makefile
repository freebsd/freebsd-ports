PORTNAME=	Config-Identity
PORTVERSION=	0.0019
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Load (and optionally decrypt via GnuPG) user/pass identity information

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-HomeDir>=0:devel/p5-File-HomeDir \
		p5-File-Which>=0:sysutils/p5-File-Which \
		p5-IPC-Run>=0:devel/p5-IPC-Run
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
