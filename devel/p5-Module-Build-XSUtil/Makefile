# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Module-Build-XSUtil
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Module::Build class for building XS modules

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Devel-CheckCompiler>=0.02:${PORTSDIR}/devel/p5-Devel-CheckCompiler
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	modbuild
USES=		perl5

.include <bsd.port.mk>
