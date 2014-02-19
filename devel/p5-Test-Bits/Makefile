# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-Bits
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provides a bits_is() subroutine for testing binary data

LICENSE=	ART20

BUILD_DEPENDS=	p5-List-AllUtils>=0:${PORTSDIR}/devel/p5-List-AllUtils
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0:${PORTSDIR}/devel/p5-Test-Fatal \
		p5-Test-Tester>=0:${PORTSDIR}/devel/p5-Test-Tester

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
