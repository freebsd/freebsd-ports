# $FreeBSD$

PORTNAME=	B-Hooks-OP-Check-EntersubForCV
PORTVERSION=	0.09
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to invoke callback on construction of entersub OPs

RUN_DEPENDS=	\
	p5-B-Hooks-OP-Check>=0.19:devel/p5-B-Hooks-OP-Check \
	p5-B-Utils>0:devel/p5-B-Utils
BUILD_DEPENDS=	\
	p5-B-Hooks-OP-Check>=0.19:devel/p5-B-Hooks-OP-Check \
	p5-B-Utils>0:devel/p5-B-Utils \
	p5-ExtUtils-Depends>0:devel/p5-ExtUtils-Depends

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
