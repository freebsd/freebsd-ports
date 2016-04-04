# $FreeBSD$

PORTNAME=	Module-Functions
PORTVERSION=	2.1.3
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to get function list from package

RUN_DEPENDS=	\
	p5-Sub-Identify>=0.04:devel/p5-Sub-Identify
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
