# New ports collection makefile for:	mysqlreport
# Date created:			2006-11-23
# Whom:				Alexander Zhuravlev <zaa@zaa.pp.ru>
#
# $FreeBSD$

PORTNAME=	mysqlreport
PORTVERSION=	3.0a
CATEGORIES=	databases
MASTER_SITES=	http://hackmysql.com/scripts/
EXTRACT_SUFX=	.tgz

MAINTAINER=	zaa@zaa.pp.ru
COMMENT=	Mysqlreport makes a friendly report of important MySQL status values

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql

USE_PERL5=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/mysqlreport
PORTDOCS=	mysqlreportguide.html mysqlreportdoc.html

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/mysqlreport ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
		@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
