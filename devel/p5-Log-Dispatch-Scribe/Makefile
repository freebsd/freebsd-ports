# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Log-Dispatch-Scribe
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Log
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Logging via Facebook\'s Scribe server software

BUILD_DEPENDS=	p5-Log-Dispatch>0:${PORTSDIR}/devel/p5-Log-Dispatch
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-MockObject>=0:${PORTSDIR}/devel/p5-Test-MockObject \
		p5-Test-Timer>=0:${PORTSDIR}/devel/p5-Test-Timer

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
