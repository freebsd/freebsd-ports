# New ports collection makefile for:	p5-Log-Dispatch-Perl
# Date created:				Sun Feb  1 14:18:26 GMT 2004
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	Log-Dispatch-Perl
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Log
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A Log::Dispatch plug-in using core Perl functions for logging

BUILD_DEPENDS=	${SITE_PERL}/Log/Dispatch.pm:${PORTSDIR}/devel/p5-Log-Dispatch \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Log::Dispatch::Perl.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		"requires perl 5.6.x or later. Install lang/perl5 and try again"
.endif

.include <bsd.port.post.mk>
