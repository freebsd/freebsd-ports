# New ports collection makefile for:	p5-Test-LongString
# Date created:				2004-04-26
# Whom:	      				aturetta@commit.it
#
# $FreeBSD$
#

PORTNAME=	Test-LongString
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	fbsdports@commit.it
COMMENT=	A library to test long strings

PERL_CONFIGURE=	yes

MAN3=		Test::LongString.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.x or later. Install lang/perl5 and try again
.endif

.include <bsd.port.post.mk>
