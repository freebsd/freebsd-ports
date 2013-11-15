# $FreeBSD$

PORTNAME=	Log-Any-Adapter-Callback
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Perl extension adapter for Log::Any with callbacks

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS:=	p5-Log-Any-Adapter>0:${PORTSDIR}/devel/p5-Log-Any-Adapter
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
