# New ports collection makefile for:    p5-DBD-Pg
# Version required:			0.62
# Date created:				June 17th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.3 1997/06/24 18:43:10 jfitz Exp $
#

DISTNAME=	DBD-Pg-0.62
PKGNAME=	p5-DBD-Pg-0.62
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/perl5/site_perl/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${PREFIX}/pgsql/lib/libpq.so.1.0:${PORTSDIR}/databases/postgresql

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5
MAN3=		DBD::Pg.3

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
