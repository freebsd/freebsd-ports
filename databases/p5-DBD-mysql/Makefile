# New ports collection makefile for:    p5-Mysql-modules
# Version required:			1.2016
# Date created:				September 29th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	Msql-Mysql-modules-1.2210
PKGNAME=	p5-Mysql-modules-1.2210
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD

MAINTAINER=	jedgar@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Data/ShowTable.pm:${PORTSDIR}/devel/p5-Data-ShowTable \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	mysqlclient.6:${PORTSDIR}/databases/mysql322-client

Y2K=		http://forteviot.symbolstone.org/technology/perl/DBI/doc/faq.html

CONFIGURE_ARGS=	PREFIX=${PREFIX} --noprompt --mysql-install --nomsql-install
CONFIGURE_ENV=	MYSQL_HOME=${PREFIX} IN_MYSQL_DISTRIBUTION=1
USE_PERL5=	YES

MAN1=		dbimon.1
MAN3=		Bundle::DBD::mysql.3 \
		DBD::mysql.3 \
		Mysql.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${PERL5} Makefile.PL ${CONFIGURE_ARGS}

.include <bsd.port.mk>
