# New ports collection makefile for:    p5-DBD-Pg
# Version required:			0.72
# Date created:				June 17th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $Id: Makefile,v 1.8 1998/09/15 21:31:31 asami Exp $
#

DISTNAME=	DBD-Pg-0.72
PKGNAME=	p5-DBD-Pg-0.72
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/perl5/site_perl/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${PREFIX}/pgsql/lib/libpq.so.1.1:${PORTSDIR}/databases/postgresql

BROKEN_ELF=	depends on postgresql

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		DBD::Pg.3

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
