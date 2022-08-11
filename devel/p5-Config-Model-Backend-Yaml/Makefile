PORTNAME=	Config-Model-Backend-Yaml
PORTVERSION=	2.134
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Read and write config as a YAML data structure

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Config-Model>=2.131:devel/p5-Config-Model \
		p5-Log-Log4perl>=0:devel/p5-Log-Log4perl \
		p5-YAML-LibYAML>=0.69:textproc/p5-YAML-LibYAML
TEST_DEPENDS=	p5-Config-Model-Tester>=4.001:devel/p5-Config-Model-Tester \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-Test-Memory-Cycle>=0:devel/p5-Test-Memory-Cycle

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
