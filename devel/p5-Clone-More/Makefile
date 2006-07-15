# New ports collection makefile for:	p5-Clone-More
# Date created:		2006-07-14
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Clone-More
PORTVERSION=	0.90.2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Clone
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Perl module for natively copying Perl data structures

PERL_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN3=		Clone::More.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500805
IGNORE=		requires perl 5.8.5 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
