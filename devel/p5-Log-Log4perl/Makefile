# $FreeBSD$

PORTNAME=	Log-Log4perl
PORTVERSION=	1.42
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Log4j implementation for Perl

USES=		perl5
USE_PERL5=	configure

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} test

.include <bsd.port.mk>
