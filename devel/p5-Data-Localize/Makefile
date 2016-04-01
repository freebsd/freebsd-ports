# $FreeBSD$

PORTNAME=	Data-Localize
PORTVERSION=	0.00027
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DMAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for alternate data localization API

LICENSE=	MIT

RUN_DEPENDS=	\
	p5-Moo>=1.000008:devel/p5-Moo \
	p5-MooX-Types-MooseLike>0:devel/p5-MooX-Types-MooseLike \
	p5-Log-Minimal>=0.14:devel/p5-Log-Minimal
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=	perl5
USE_PERL5=	modbuild
NO_ARCH=	YES

.include <bsd.port.mk>
