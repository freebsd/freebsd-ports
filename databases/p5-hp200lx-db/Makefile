# New ports collection makefile for:	p5-hp200lx-db
# Version required:			0.07
# Date created:				January 2nd 2000
# Whom:	      				Gerhard Gonter <g.gonter@ieee.org>
#
# $FreeBSD$
#

DISTNAME=	hp200lx-db-0.07
PKGNAME=	p5-hp200lx-db-0.07
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HP200LX

MAINTAINER=	g.gonter@ieee.org

USE_PERL5=	YES

# MAN3=		HP200LX::DB.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@( cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL )

.include <bsd.port.mk>
