# New ports collection makefile for:	p5-ReadLine-Perl
# Date created:				20 February 1998
# Whom:	      				Matthew Hunt <mph@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	Term-ReadLine-Perl
PORTVERSION=	0.9907
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Term
PKGNAMEPREFIX=	p5-

MAINTAINER=	mph@freebsd.org

USE_PERL5=	YES

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
