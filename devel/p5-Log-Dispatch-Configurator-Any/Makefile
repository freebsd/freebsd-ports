PORTNAME=	Log-Dispatch-Configurator-Any
PORTVERSION=	1.122640
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Configurator implementation with Config::Any

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Config-Any>=0.15:devel/p5-Config-Any \
		p5-Log-Dispatch>=2.23:devel/p5-Log-Dispatch \
		p5-Log-Dispatch-Config>=0:devel/p5-Log-Dispatch-Config
TEST_DEPENDS=	p5-Config-Tiny>=0:devel/p5-Config-Tiny \
		p5-Test-Pod>=1.14:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=1.04:devel/p5-Test-Pod-Coverage \
		p5-YAML-LibYAML>=0:textproc/p5-YAML-LibYAML

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
