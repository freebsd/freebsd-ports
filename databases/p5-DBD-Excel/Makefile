# New ports collection makefile for:	DBD::Excel
# Date created:				24 Jan 2002
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	DBD-Excel
PORTVERSION=	0.06
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD
PKGNAMEPREFIX=	p5-

MAINTAINER=	svenasse@polaris.ca
COMMENT=	A class for DBI drivers that acts on Excel files

BUILD_DEPENDS=	${SITE_PERL}/SQL/Statement.pm:${PORTSDIR}/databases/p5-SQL-Statement \
		${SITE_PERL}/Spreadsheet/ParseExcel.pm:${PORTSDIR}/textproc/p5-Spreadsheet-ParseExcel \
		${SITE_PERL}/Spreadsheet/WriteExcel.pm:${PORTSDIR}/textproc/p5-Spreadsheet-WriteExcel
RUN_DEPENDS=	${BUILD_DEPENDS}

EXAMPLESDIR?=	${PREFIX}/share/examples/${PORTNAME}
PERL_CONFIGURE=	yes

MAN3=		DBD::Excel.3

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/sample/* ${EXAMPLESDIR}
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
.endif

.include <bsd.port.post.mk>
