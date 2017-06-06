# Created by: Denis Pokataev <catone@cpan.org>
# $FreeBSD$

PORTNAME=	Event-Join
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Join multiple "events" into one

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Moose>=0.94:devel/p5-Moose
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>0:devel/p5-Test-Exception

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
