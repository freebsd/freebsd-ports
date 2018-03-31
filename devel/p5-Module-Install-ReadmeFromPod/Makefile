# $FreeBSD$

PORTNAME=	Module-Install-ReadmeFromPod
PORTVERSION=	0.30
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	des@FreeBSD.org
COMMENT=	Automatically generate README from POD during installation

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Module-Install>=1.00:devel/p5-Module-Install \
		p5-IO-All>=0:devel/p5-IO-All \
		p5-Pod-Markdown>=2.0:textproc/p5-Pod-Markdown
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Capture-Tiny>=0.05:devel/p5-Capture-Tiny \
		p5-Test-InDistDir>=0:devel/p5-Test-InDistDir

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	--skip

.include <bsd.port.mk>
