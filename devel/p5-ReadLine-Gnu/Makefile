# New ports collection makefile for:	p5-ReadLine-Gnu
# Date created:				19 February 1998
# Whom:	      				Matthew Hunt <mph@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	ReadLine-Gnu
PORTVERSION=	1.09
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Term
PKGNAMEPREFIX=	p5-
DISTNAME=	Term-${PORTNAME}-${PORTVERSION}

MAINTAINER=	mph@freebsd.org

USE_PERL5=	yes

MAN3=		Term::ReadLine::Gnu.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

# We override LDDLFLAGS and LDFLAGS to keep it from adding -L/usr/local/lib
# automatically.  There is sometimes an old libreadline in /usr/local/lib
# and this module won't work with it.
do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL \
			CC="${CC}" CCFLAGS="${CFLAGS}" \
			LDDLFLAGS=-shared LDFLAGS=-L/usr/lib

.include <bsd.port.mk>
