# Created by: Matthew Seaman <matthew@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Set-Tiny
PORTVERSION=	0.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Simple sets of strings

USES=		perl5
USE_PERL5=	configure

regression-test: build
	@cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
