PORTNAME=	B-Hooks-AtRuntime
PORTVERSION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lower blocks from compile time to runtime
WWW=		https://metacpan.org/dist/B-Hooks-AtRuntime

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Exporter-Tiny>=0:devel/p5-Exporter-Tiny \
		p5-Sub-Name>=0.05,1:devel/p5-Sub-Name
TEST_DEPENDS=	p5-Test-Exception>=0.31:devel/p5-Test-Exception \
		p5-Test-Warn>=0.22:devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	modbuild

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/B/Hooks/AtRuntime/AtRuntime.so

.include <bsd.port.mk>
