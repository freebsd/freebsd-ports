# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Module-Implementation
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Loads one of several alternate underlying implementations for a module

LICENSE=	ART20

BUILD_DEPENDS=	p5-Module-Runtime>=0.012:${PORTSDIR}/devel/p5-Module-Runtime \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0.006:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-NoTabs>=0:${PORTSDIR}/devel/p5-Test-NoTabs \
		p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires \
		p5-Test-Taint>=0:${PORTSDIR}/devel/p5-Test-Taint

PERL_CONFIGURE=	yes

MAN3=		Module::Implementation.3

.include <bsd.port.mk>
