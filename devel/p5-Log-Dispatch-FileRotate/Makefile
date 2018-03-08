# Created by: Lars Thegler <lars@thegler.dk>
# $FreeBSD$

PORTNAME=	Log-Dispatch-FileRotate
PORTVERSION=	1.35
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Log::Dispatch plug-in for files that archive/rotate themselves

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Date-Manip>=0:devel/p5-Date-Manip \
		p5-Log-Dispatch>=0:devel/p5-Log-Dispatch
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Path-Tiny>=0.018:devel/p5-Path-Tiny \
		p5-Test-Warn>=0:devel/p5-Test-Warn

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
