# New ports collection makefile for:	p5-ReadLine-Gnu
# Version required:			1.01
# Date created:				19 February 1998
# Whom:	      				Matthew Hunt <mph@pobox.com>
#
# $Id: Makefile,v 1.4 1998/06/15 04:48:36 mph Exp $
#

DISTNAME=	Term-ReadLine-Gnu-1.01
PKGNAME=	p5-ReadLine-Gnu-1.01
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Term

MAINTAINER=	mph@freebsd.org

USE_PERL5=	YES

MAN3=		Term::ReadLine::Gnu.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

# We override LDDLFLAGS and LDFLAGS to keep it from adding -L/usr/local/lib
# automatically.  There is sometimes an old libreadline in /usr/local/lib
# and this module won't work with it.
do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL LDDLFLAGS=-Bshareable LDFLAGS=-L/usr/lib

.include <bsd.port.mk>
