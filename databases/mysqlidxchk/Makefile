# New ports collection makefile for:	mysqlidxchk
# Date created:				29 April 2009
# Whom:					Andrey Ignatov <rdna@rdna.ru>
#
# $FreeBSD$
#

PORTNAME=	mysqlidxchk
PORTVERSION=	1.0
CATEGORIES=	databases
MASTER_SITES=	http://hackmysql.com/scripts/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rdna@rdna.ru
COMMENT=	Checks MySQL databases/tables for unused indexes

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql

NO_WRKSUBDIR=	yes

USE_PERL5=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/mysqlidxchk
PORTDOCS=	mysqlidxchkdoc.html mysqlidxchkguide.html

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/mysqlidxchk ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
