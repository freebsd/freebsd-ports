# New ports collection makefile for:    p5-Mysql-modules
# Date created:				September 29th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Mysql-modules
PORTVERSION=	1.2215
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD
PKGNAMEPREFIX=	p5-
DISTNAME=	Msql-Mysql-modules-${PORTVERSION}

MAINTAINER=	jedgar@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Data/ShowTable.pm:${PORTSDIR}/devel/p5-Data-ShowTable \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	PREFIX=${PREFIX} CC="${CC}" CCFLAGS="${CFLAGS}" \
		--noprompt --mysql-install --nomsql-install
CONFIGURE_ENV=	MYSQL_HOME=${PREFIX} IN_MYSQL_DISTRIBUTION=1

MAN1=		dbimon.1
MAN3=		Bundle::DBD::mysql.3 \
		DBD::mysql.3 \
		Mysql.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

pre-configure:
		@${PERL} -p -i -e 's| -lgz||' ${WRKSRC}/lib/DBD/mysql/Install.pm

.include <bsd.port.mk>
