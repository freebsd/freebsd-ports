# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Module-Implementation
PORTVERSION=	0.09
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Loads one of several alternate underlying implementations for a module

LICENSE=	ART20

BUILD_DEPENDS=	p5-Module-Runtime>=0.012:devel/p5-Module-Runtime \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0.006:devel/p5-Test-Fatal \
		p5-Test-NoTabs>=0:devel/p5-Test-NoTabs \
		p5-Test-Requires>=0:devel/p5-Test-Requires \
		p5-Test-Taint>=0:devel/p5-Test-Taint

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
