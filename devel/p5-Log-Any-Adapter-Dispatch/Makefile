# $FreeBSD$

PORTNAME=	Log-Any-Adapter-Dispatch
PORTVERSION=	0.06
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for adapter to use Log::Dispatch with Log::Any

RUN_DEPENDS=	\
	p5-Log-Any>0:devel/p5-Log-Any \
	p5-Log-Dispatch>=2.26:devel/p5-Log-Dispatch
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
