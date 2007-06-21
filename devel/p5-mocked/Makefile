# New ports collection makefile for:	devel/p5-mocked
# Date created:				21 June 2007
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mocked
PORTVERSION=	0.06
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/L/LU/LUKEC
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	mocked - use mocked libraries in unit tests

RUN_DEPENDS=	p5-Test-Exception>0:${PORTSDIR}/devel/p5-Test-Exception
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	mocked.3

.include <bsd.port.mk>
