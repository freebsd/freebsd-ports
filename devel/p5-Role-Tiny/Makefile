# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Role-Tiny
PORTVERSION=	2.000001
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:HAARG
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Roles, like a nouvelle cusine portion size slice of Moose

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Method-Modifiers>=1.05:devel/p5-Class-Method-Modifiers
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0.003:devel/p5-Test-Fatal \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean \
		p5-strictures>=0:devel/p5-strictures

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
