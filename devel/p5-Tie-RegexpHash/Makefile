# $FreeBSD$

PORTNAME=	Tie-RegexpHash
PORTVERSION=	0.16
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Use regular expressions as hash keys

USES=		perl5
USE_PERL5=	configure

regression-test: build
	@cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
