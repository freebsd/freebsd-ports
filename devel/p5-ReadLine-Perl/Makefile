# New ports collection makefile for:	p5-ReadLine-Perl
# Version required:			0.9904
# Date created:				20 February 1998
# Whom:	      				Matthew Hunt <mph@pobox.com>
#
# $FreeBSD$
#

DISTNAME=	Term-ReadLine-Perl-0.9904
PKGNAME=	p5-ReadLine-Perl-0.9904
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Term

MAINTAINER=	mph@freebsd.org

USE_PERL5=	YES

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
