# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Module-Build-Pluggable-ReadmeMarkdownFromPod
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Make README.mkdn from POD

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor-Lite>=0:devel/p5-Class-Accessor-Lite \
		p5-Module-Build-Pluggable>=0.09:devel/p5-Module-Build-Pluggable \
		p5-Pod-Markdown>=0:textproc/p5-Pod-Markdown
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	modbuild
USES=		perl5

.include <bsd.port.mk>
