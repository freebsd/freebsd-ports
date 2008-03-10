# New ports collection makefile for:	mysqlsla
# Date created:			2006-11-23
# Whom:				Alexander Zhuravlev <zaa@zaa.pp.ru>
#
# $FreeBSD$

PORTNAME=	mysqlsla
PORTVERSION=	1.7a
CATEGORIES=	databases
MASTER_SITES=	http://hackmysql.com/scripts/
EXTRACT_SUFX=	.tgz

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	Mysqlsla analyzes general, slow, and raw MySQL statement logs

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long \
		${SITE_PERL}/Class/DBI.pm:${PORTSDIR}/databases/p5-Class-DBI-mysql \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes

USE_PERL5=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/mysqlsla
PORTDOCS=	mysqlsladoc.html

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/mysqlsla ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
