PORTNAME=	Sys-Info-Driver-BSD
PORTVERSION=	0.7801
PORTREVISION=	1
CATEGORIES=	devel sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	BSD driver for Sys::Info

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-BSD-Sysctl>=0.08:sysutils/p5-BSD-Sysctl \
		p5-Sys-Info-Base>=0.7801:devel/p5-Sys-Info-Base \
		p5-Unix-Processors>=0:sysutils/p5-Unix-Processors
TEST_DEPENDS=	p5-Test-Pod>=0:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:devel/p5-Test-Pod-Coverage \
		p5-Test-Sys-Info>=0.20:devel/p5-Test-Sys-Info

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
