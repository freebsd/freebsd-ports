# Created by: Timur I. Bakeyev <bat@cpan.org>
# $FreeBSD$

PORTNAME=	DateTime-Format-Natural
PORTVERSION=	1.02
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Create machine readable date/time with natural parsing logic

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-boolean>=0:${PORTSDIR}/devel/p5-boolean \
		p5-Clone>=0:${PORTSDIR}/devel/p5-Clone \
		p5-Date-Calc>=0:${PORTSDIR}/devel/p5-Date-Calc \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Module-Util>=0:${PORTSDIR}/devel/p5-Module-Util \
		p5-Test-MockTime>=0:${PORTSDIR}/devel/p5-Test-MockTime
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-MockTime>=0:${PORTSDIR}/devel/p5-Test-MockTime

USES=		perl5
USE_PERL5=	modbuild

regression-test: build
	@cd ${WRKSRC} && ./Build test

.include <bsd.port.mk>
