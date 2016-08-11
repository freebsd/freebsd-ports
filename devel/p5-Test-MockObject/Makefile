# $FreeBSD$

PORTNAME=	Test-MockObject
PORTVERSION=	1.20150527
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Tests remote URLs or local web files

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-UNIVERSAL-can>=1.20110617:devel/p5-UNIVERSAL-can \
		p5-UNIVERSAL-isa>=1.20110614:devel/p5-UNIVERSAL-isa
RUN_DEPENDS=	p5-UNIVERSAL-can>=1.20110617:devel/p5-UNIVERSAL-can \
		p5-UNIVERSAL-isa>=1.20110614:devel/p5-UNIVERSAL-isa
TEST_DEPENDS=	p5-Test-Exception>=0.31:devel/p5-Test-Exception \
		p5-Test-Warn>=0.23:devel/p5-Test-Warn

USES=		perl5
USE_PERL5=	configure
INSTALL_TARGET=	pure_install
NO_ARCH=	YES

.include <bsd.port.mk>
