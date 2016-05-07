# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	IO-Prompter
PORTVERSION=	0.004014
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Prompt for input, read it, clean it, return it

BUILD_DEPENDS=	devel/p5-Contextual-Return>0:devel/p5-Contextual-Return
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

regression-test: build
	(cd ${WRKSRC}/ && ${MAKE} test)

.include <bsd.port.mk>
