# New ports collection makefile for:	p5-Pg
# Version required:			1.6.1
# Date created:				October 19th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.10 1997/06/24 18:43:30 jfitz Exp $
#

DISTNAME=	pgsql_perl5-1.6.1
PKGNAME=	p5-Pg-1.6.1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Pg

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS= 	${PREFIX}/pgsql/lib/libpq.a:${PORTSDIR}/databases/postgresql

USE_PERL5=	YES

MAN3=		Pg.3
MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
