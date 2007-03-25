# New ports collection makefile for:	p5-threads
# Date created:		2006-07-22
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	threads
PORTVERSION=	1.61
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/J/JD/JDHEDDEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl interpreter-based threads

PERL_CONFIGURE=	yes

MAN3=		threads.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires perl 5.8.0 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
