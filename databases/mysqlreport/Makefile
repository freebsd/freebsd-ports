# New ports collection makefile for:	mysqlreport
# Date created:			2006-11-23
# Whom:				Alexander Zhuravlev <zaa@zaa.pp.ru>
#
# $FreeBSD$

PORTNAME=	mysqlreport
PORTVERSION=	3.4a
CATEGORIES=	databases
MASTER_SITES=	http://hackmysql.com/scripts/
EXTRACT_SUFX=	.tgz

MAINTAINER=	lippemail@gmail.com
COMMENT=	Mysqlreport makes a friendly report of important MySQL status values

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long \
		${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp \
		${SITE_PERL}/Class/DBI.pm:${PORTSDIR}/databases/p5-Class-DBI \
		${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql

USE_PERL5=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/mysqlreport
PORTDOCS=	COPYING mysqlreportguide.html mysqlreportdoc.html

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/mysqlreport ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
