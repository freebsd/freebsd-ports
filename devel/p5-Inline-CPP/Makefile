# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Inline-CPP
PORTVERSION=	0.74
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Write Perl subroutines and classes in C++

LICENSE=	ART10

BUILD_DEPENDS=	p5-Inline>=0.78:devel/p5-Inline \
		p5-Inline-C>=0.67:devel/p5-Inline-C \
		p5-Parse-RecDescent>=0:devel/p5-Parse-RecDescent
RUN_DEPENDS:=	${BUILD_DEPENDS}
BUILD_DEPENDS+=	p5-ExtUtils-CppGuess>=0.11:devel/p5-ExtUtils-CppGuess

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
