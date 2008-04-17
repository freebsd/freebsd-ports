# New ports collection makefile for:	p5-Code-Perl
# Date created:				26 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Code-Perl
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/F/FD/FDALY
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Produce Perl code from a tree

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Class/MethodMaker.pm:${PORTSDIR}/devel/p5-Class-MethodMaker \
		${SITE_PERL}/Test/Deep.pm:${PORTSDIR}/devel/p5-Test-Deep
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Code::Perl.3 Code::Perl::Expr.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
