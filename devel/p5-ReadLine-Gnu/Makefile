# New ports collection makefile for:	p5-ReadLine-Gnu
# Version required:			0.09
# Date created:				19 February 1998
# Whom:	      				Matthew Hunt <mph@pobox.com>
#
# $Id$
#

DISTNAME=	Term-ReadLine-Gnu-0.09
PKGNAME=	p5-ReadLine-Gnu-0.09
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Term

MAINTAINER=	mph@pobox.com

USE_PERL5=	YES

MAN3=		Term::ReadLine::Gnu.3
MANPREFIX=	${PREFIX}/lib/perl5

# We override LDDLFLAGS and LDFLAGS to keep it from adding -L/usr/local/lib
# automatically.  There is sometimes an old libreadline in /usr/local/lib
# and this module won't work with it.
do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL LDDLFLAGS=-Bshareable LDFLAGS=-L/usr/lib

.include <bsd.port.mk>
