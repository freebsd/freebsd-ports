# New ports collection makefile for:    p5-Test-NoWarnings
# Date created:				May 12th 2004
# Whom:	      				Alex Kapranoff <alex@kapranoff.ru>
#
# $FreeBSD$
#

PORTNAME=	Test-NoWarnings
PORTVERSION=	0.084
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	alex@kapranoff.ru
COMMENT=	Hide and store warnings while running test scripts

PERL_CONFIGURE=	yes

MAN3=		Test::NoWarnings.3

OPTIONS=	DEVEL_STACKTRACE "Stack trace support" off

.include <bsd.port.pre.mk>

.if defined(WITH_DEVEL_STACKTRACE)
RUN_DEPENDS+=	p5-Devel-StackTrace>=0:${PORTSDIR}/devel/p5-Devel-StackTrace
.endif

.include <bsd.port.post.mk>
