# New ports collection makefile for:    p5-Mysql-modules
# Version required:			1.1833
# Date created:				September 29th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $Id: Makefile,v 1.5 1998/07/04 19:07:02 steve Exp $
#

DISTNAME=	Msql-Mysql-modules-1.1833
PKGNAME=	p5-Mysql-modules-1.1833
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD

MAINTAINER=	jfitz@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/mysql/libmysqlclient.a:${PORTSDIR}/databases/mysql/ \
		${PREFIX}/lib/perl5/site_perl/5.005/Data/ShowTable.pm:${PORTSDIR}/devel/p5-Data-ShowTable/ \
		${PREFIX}/lib/perl5/site_perl/5.005/i386-freebsd/DBI.pm:${PORTSDIR}/databases/p5-DBI/

CONFIGURE_ENV+=	PREFIX=${PREFIX} MYSQL_HOME=${PREFIX} IN_MYSQL_DISTRIBUTION=1
USE_PERL5=	YES

MAN1=		pmysql.1 dbimon.1
MAN3=		Bundle::Msql.3 Bundle::Mysql.3 DBD::mSQL.3 DBD::mysql.3 \
		Msql.3 Mysql.3
MAN3PREFIX=	${PREFIX}/lib/perl5/5.00501

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
