# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-InDistDir
PORTVERSION=	1.112071
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Test environment setup for development with IDE

USES=		perl5
USE_PERL5=	configure

regression-test: build
	cd ${WRKSRC}/ && ${MAKE} test

.include <bsd.port.mk>
