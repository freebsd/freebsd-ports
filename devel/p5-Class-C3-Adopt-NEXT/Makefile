# Created by: Denis Pokataev <catone@cpan.org>
# $FreeBSD$

PORTNAME=	Class-C3-Adopt-NEXT
PORTVERSION=	0.13
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	catone@cpan.org
COMMENT=	Make NEXT suck less

RUN_DEPENDS=	p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
