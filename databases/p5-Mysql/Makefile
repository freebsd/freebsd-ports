# New ports collection makefile for:    p5-Mysql-modules
# Version required:			1.2016
# Date created:				September 29th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $Id: Makefile,v 1.17 1999/01/21 17:54:48 vanilla Exp $
#

DISTNAME=	Msql-Mysql-modules-1.2016
PKGNAME=	p5-Mysql-modules-1.2016
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD

MAINTAINER=	vanilla@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/Data/ShowTable.pm:${PORTSDIR}/devel/p5-Data-ShowTable \
		${PREFIX}/lib/perl5/site_perl/${PERL_VER}/i386-freebsd/DBI.pm:${PORTSDIR}/databases/p5-DBI
LIB_DEPENDS=	mysqlclient.6:${PORTSDIR}/databases/mysql322

CONFIGURE_ARGS=	PREFIX=${PREFIX}
CONFIGURE_ENV=	MYSQL_HOME=${PREFIX} IN_MYSQL_DISTRIBUTION=1
USE_PERL5=	YES

MAN1=		dbimon.1
MAN3=		Bundle::Mysql.3 \
		DBD::mysql.3 \
		Mysql.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL ${CONFIGURE_ARGS}

.include <bsd.port.mk>
