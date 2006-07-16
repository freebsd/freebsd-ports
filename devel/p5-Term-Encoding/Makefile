# New ports collection makefile for:	p5-Term-Encoding
# Date created:		2006-07-13
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Term-Encoding
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Term
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Detect encoding of the current terminal

PERL_CONFIGURE=	yes

MAN3=		Term::Encoding.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500702
IGNORE=		requires perl 5.7.2 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
