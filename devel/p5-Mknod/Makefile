# New ports collection makefile for:	p5-Mknod
# Date created:		3 November 2004
# Whom:			Sean Farley <sean-freebsd@farley.org>
#
# $FreeBSD$
#

PORTNAME=	Mknod
PORTVERSION=	0.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/R/RL/RLZWART
PKGNAMEPREFIX=	p5-

MAINTAINER=	sean-freebsd@farley.org
COMMENT=	Perl module interface to the mknod(2) system call

PERL_CONFIGURE=	yes

MANPREFIX=	${SITE_PERL}
MAN3=		Mknod.3

.include <bsd.port.pre.mk>

# This port requires PERL 5.6.x or later.
.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.x or later.  Install lang/perl5 then try again.
.endif

.include <bsd.port.post.mk>
