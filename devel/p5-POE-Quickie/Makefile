# Created by: Takefu
# $FreeBSD$

PORTNAME=	POE-Quickie
PORTVERSION=	0.18
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	takefu@airport.fm
COMMENT=	Lazy way to wrap blocking code and programs

LICENSE=	GPLv1 ART10
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-POE>=1.350:devel/p5-POE
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Capture-Tiny>=0.07:devel/p5-Capture-Tiny \
		p5-Test-Deep>=0:devel/p5-Test-Deep

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${RM} ${WRKSRC}/lib/POE/Quickie.pm.orig

.include <bsd.port.mk>
