# New ports collection makefile for:	p5-AutoLoader
# Date created:				Jan 18 2007
# Whom:					Rong-En Fan <rafan@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	AutoLoader
PORTVERSION=	5.69
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Load subroutines only on demand

PERL_CONFIGURE=	yes

MAN3=		AutoLoader.3 AutoSplit.3

regression-test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
