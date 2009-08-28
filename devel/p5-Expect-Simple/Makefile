# New ports collection makefile for:	Expect-Simple
# Date created:				23 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Expect-Simple
PORTVERSION=	0.04
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Wrapper around the Expect module

BUILD_DEPENDS=	${SITE_PERL}/Expect.pm:${PORTSDIR}/lang/p5-Expect
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=		Expect::Simple.3

PERL_CONFIGURE=	5.8.0+

.include <bsd.port.mk>
