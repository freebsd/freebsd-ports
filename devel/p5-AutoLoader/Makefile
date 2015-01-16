# Created by: Rong-En Fan <rafan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	AutoLoader
PORTVERSION=	5.73
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Load subroutines only on demand

USES=		perl5
USE_PERL5=	configure

regression-test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
