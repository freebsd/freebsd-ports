# Created by: mat
# $FreeBSD$

PORTNAME=	DateTime-TimeZone
PORTVERSION=	1.94
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Time zone object base class and factory

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Singleton>=1.03:${PORTSDIR}/devel/p5-Class-Singleton \
		p5-List-AllUtils>0:${PORTSDIR}/devel/p5-List-AllUtils \
		p5-Module-Runtime>=0:${PORTSDIR}/devel/p5-Module-Runtime \
		p5-Params-Validate>=0.72:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Output>0:${PORTSDIR}/devel/p5-Test-Output

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
