# Created by: Matthew Seaman <matthew@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Role-Basic
PORTVERSION=	0.13
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:OVID
PKGNAMEPREFIX=	p5-

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Just roles. Nothing else

USES=		perl5
USE_PERL5=	configure

regression-test: build
	@cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
