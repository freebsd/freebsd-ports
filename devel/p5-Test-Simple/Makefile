# New ports collection makefile for:	p5-Test-Simple
# Date Created:				12 Aug 2001
# Whom:					Shell Hung <shell@shellhung.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Simple
PORTVERSION=	0.60
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Basic utilities for writing tests in perl

BUILD_DEPENDS=	${SITE_PERL}/Test/Harness.pm:${PORTSDIR}/devel/p5-Test-Harness
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Test::Builder.3 Test::More.3 Test::Simple.3 Test::Tutorial.3

.include <bsd.port.mk>
