# New ports collection makefile for:    p5-Msql-modules
# Version required:			1.1808
# Date created:				September 29th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.13 1997/07/14 13:23:27 jfitz Exp $
#

DISTNAME=	Msql-modules-1.1808
PKGNAME=	p5-Msql-modules-1.1808
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Msql

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/libmsql.a:${PORTSDIR}/databases/msql/ \
		${PREFIX}/lib/perl5/site_perl/Data/ShowTable.pm:${PORTSDIR}/misc/p5-Data/ShowTable/ \
		${PREFIX}/lib/perl5/site_perl/DBI.pm:${PORTSDIR}/databases/p5-DBI/
CONFIGURE_ENV+=	PREFIX=${PREFIX} MSQL_HOME=${PREFIX}

USE_PERL5=	YES

MAN1=		pmsql.1 dbimon.1
MAN3=		Msql.3 DBD::mSQL.3
MAN3PREFIX=	${PREFIX}/lib/perl5

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
