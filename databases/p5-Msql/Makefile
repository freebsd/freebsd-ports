# New ports collection makefile for:    p5-Msql
# Version required:			0.91
# Date created:				September 29th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.12 1997/06/24 18:43:25 jfitz Exp $
#

DISTNAME=	Msql-modules-0.91
PKGNAME=	p5-Msql-0.91
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Msql

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/libmsql.a:${PORTSDIR}/databases/msql/ \
		${PREFIX}/lib/perl5/site_perl/DBI.pm:${PORTSDIR}/databases/p5-DBI/
CONFIGURE_ENV+=	PREFIX=${PREFIX} MSQL_HOME=${PREFIX}

USE_PERL5=	YES

MAN1=		pmsql.1
MAN3=		Msql.3 DBD::mSQL.3 Msql::Integrat.3
MAN3PREFIX=	${PREFIX}/lib/perl5

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
