# New ports collection makefile for:	Test-Expect
# Date created:				23 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Test-Expect
PORTVERSION=	0.30
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Automated driving and testing of terminal-based programs

BUILD_DEPENDS=	${SITE_PERL}/Class/Accessor/Chained/Fast.pm:${PORTSDIR}/devel/p5-Class-Accessor-Chained \
		${SITE_PERL}/Expect/Simple.pm:${PORTSDIR}/devel/p5-Expect-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Test::Expect.3

PERL_CONFIGURE=	5.8.0+

.include <bsd.port.mk>
