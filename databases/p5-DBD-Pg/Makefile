# New ports collection makefile for:    p5-DBD-Pg
# Version required:			0.3
# Date created:				June 17th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id$
#

DISTNAME=	DBD-Pg-0.3
PKGNAME=	p5-DBD-Pg-0.3
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS+=	perl5.004:${PORTSDIR}/lang/perl5 \
		${PREFIX}/lib/perl5/site_perl/DBI.pm:${PORTSDIR}/database/p5-DBI \
		${PREFIX}/pgsql/lib/libpq.so.1.0:${PORTSDIR}/databases/postgresql
RUN_DEPENDS=	perl5.004:${PORTSDIR}/lang/perl5

MANPREFIX=	${PREFIX}/lib/perl5
MAN3=		DBD::Pg.3

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
