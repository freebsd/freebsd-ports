# New ports collection makefile for:    p5-Mysql-modules
# Version required:			1.1831
# Date created:				September 29th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.4 1997/09/17 13:58:57 jfitz Exp $
#

DISTNAME=	Msql-Mysql-modules-1.1831
PKGNAME=	p5-Mysql-modules-1.1831
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/mysql/libmysqlclient.a:${PORTSDIR}/databases/mysql/ \
		${PREFIX}/lib/perl5/site_perl/Data/ShowTable.pm:${PORTSDIR}/devel/p5-Data-ShowTable/ \
		${PREFIX}/lib/perl5/site_perl/DBI.pm:${PORTSDIR}/databases/p5-DBI/
CONFIGURE_ENV+=	PREFIX=${PREFIX} MSQL_HOME=${PREFIX}

IS_INTERACTIVE=	YES
USE_PERL5=	YES

MAN1=		pmysql.1 dbimon.1
MAN3=		Bundle::Msql.3 Bundle::Mysql.3 DBD::mSQL.3 DBD::mysql.3 \
		Msql.3 Mysql.3
MAN3PREFIX=	${PREFIX}/lib/perl5

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
