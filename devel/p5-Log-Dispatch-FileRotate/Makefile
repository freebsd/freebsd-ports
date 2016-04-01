# Created by: Lars Thegler <lars@thegler.dk>
# $FreeBSD$

PORTNAME=	Log-Dispatch-FileRotate
PORTVERSION=	1.19
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Log::Dispatch plug-in for files that archive/rotate themselves

BUILD_DEPENDS=	p5-Log-Dispatch>=0:devel/p5-Log-Dispatch \
		p5-Date-Manip>=0:devel/p5-Date-Manip \
		p5-Params-Validate>=0:devel/p5-Params-Validate \
		p5-Log-Log4perl>=0:devel/p5-Log-Log4perl
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
