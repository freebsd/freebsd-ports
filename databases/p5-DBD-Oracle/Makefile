# New ports collection makefile for:	DBD::Oracle
# Date created:		28 May 2002
# Whom:			Sergey Skvortsov <skv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBD-Oracle
PORTVERSION=	1.14
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	DBI driver for Oracle RDBMS server

BUILD_DEPENDS=	${LOCALBASE}/oracle7/rdbms/demo/oracle.mk:${PORTSDIR}/databases/oracle7-client
RUN_DEPENDS=	${BUILD_DEPENDS}

ORACLE_HOME=	${LOCALBASE}/oracle7
PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	-m ${ORACLE_HOME}/rdbms/demo/oracle.mk
CONFIGURE_ENV=	ORACLE_HOME="${ORACLE_HOME}"

MAN1=		ora_explain.1
MAN1PREFIX=	${PREFIX}
MAN3=		DBD::Oracle.3 DBD::Oraperl.3

post-patch:
	@${PERL} -pi -e 's!\(void\*\)(SvOK)!$$1!g' ${WRKSRC}/oci7.c

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/Oracle.ex/Readme 	${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/Oracle.ex/*.pl	${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/Oracle.ex/japh	${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/Oracle.ex/sql	${EXAMPLESDIR}
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
