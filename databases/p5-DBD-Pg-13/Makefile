# New ports collection makefile for:    p5-DBD-Pg
# Version required:			0.72
# Date created:				June 17th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $Id: Makefile,v 1.5 1998/05/03 19:26:53 steve Exp $
#

DISTNAME=	DBD-Pg-0.72
PKGNAME=	p5-DBD-Pg-0.72
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/perl5/site_perl/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${PREFIX}/pgsql/lib/libpq.so.1.1:${PORTSDIR}/databases/postgresql

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5
MAN3=		DBD::Pg.3

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
