# $FreeBSD$

PORTNAME=	Class-Accessor-Constructor
PORTVERSION=	1.111590
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for constructor generator

RUN_DEPENDS=	\
	p5-Class-Accessor>0:devel/p5-Class-Accessor \
	p5-Class-Accessor-Complex>0:devel/p5-Class-Accessor-Complex \
	p5-Class-Accessor-Installer>=1.100880:devel/p5-Class-Accessor-Installer \
	p5-Data-Inherited>0:devel/p5-Data-Inherited
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
