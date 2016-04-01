# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Module-Build-Pluggable
PORTVERSION=	0.10
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Module::Build meets plugins

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor-Lite>=0:devel/p5-Class-Accessor-Lite \
		p5-Class-Method-Modifiers>=0:devel/p5-Class-Method-Modifiers \
		p5-Data-OptList>=0:devel/p5-Data-OptList \
		p5-Test-SharedFork>=0:devel/p5-Test-SharedFork
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	modbuild
USES=		perl5

.include <bsd.port.mk>
