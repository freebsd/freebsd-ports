# New ports collection makefile for:	p5-Test-Number-Delta
# Date created:				2006-07-22
# Whom:					Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Test-Number-Delta
PORTVERSION=	1.01
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	tjs@cdpa.nsysu.edu.tw
COMMENT=	Compare the difference between two numbers within a specified amount

PERL_CONFIGURE=	yes

MAN3=	Test::Number::Delta.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500808
IGNORE=		requires perl 5.8.8 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
