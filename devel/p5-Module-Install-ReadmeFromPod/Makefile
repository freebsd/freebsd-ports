# $FreeBSD$

PORTNAME=	Module-Install-ReadmeFromPod
PORTVERSION=	0.26
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	des@FreeBSD.org
COMMENT=	Automatically generate README from POD during installation

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Module-Install>=1.00:devel/p5-Module-Install \
		p5-Capture-Tiny>=0.05:devel/p5-Capture-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	--skip

.include <bsd.port.mk>
