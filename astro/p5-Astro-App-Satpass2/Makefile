PORTNAME=	Astro-App-Satpass2
PORTVERSION=	0.057
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Forecast satellite visibility
WWW=		https://metacpan.org/release/Astro-App-Satpass2

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Astro-SIMBAD-Client>=0:astro/p5-Astro-SIMBAD-Client \
		p5-Astro-satpass>=0.077:astro/p5-Astro-satpass \
		p5-Clone>=0:devel/p5-Clone \
		p5-File-HomeDir>=0.93:devel/p5-File-HomeDir \
		p5-IPC-System-Simple>=0:devel/p5-IPC-System-Simple \
		p5-Template-Toolkit>=2.21:www/p5-Template-Toolkit \
		p5-YAML>=0:textproc/p5-YAML
TEST_DEPENDS=	p5-DateTime>=0:devel/p5-DateTime \
		p5-Test-Simple>=1.302200:devel/p5-Test-Simple \
		p5-Test2-Tools-Explain>=0:devel/p5-Test2-Tools-Explain \
		p5-Test2-Tools-LoadModule>=0:devel/p5-Test2-Tools-LoadModule

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
