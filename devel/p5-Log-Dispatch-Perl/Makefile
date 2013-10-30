# Created by: Lars Thegler <lars@thegler.dk>
# $FreeBSD$

PORTNAME=	Log-Dispatch-Perl
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Log::Dispatch plug-in using core Perl functions for logging

BUILD_DEPENDS=	p5-Log-Dispatch>=0:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
