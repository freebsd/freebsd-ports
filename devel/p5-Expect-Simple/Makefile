# New ports collection makefile for:	Expect-Simple
# Date created:				23 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Expect-Simple
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/D/DJ/DJERIUS
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Wrapper around the Expect module

BUILD_DEPENDS=	${SITE_PERL}/Expect.pm:${PORTSDIR}/lang/p5-Expect
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	Expect::Simple.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	requires at least Perl 5.8.0.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
