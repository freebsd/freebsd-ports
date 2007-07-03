# New ports collection makefile for:	DBD::Oracle
# Date created:		28 May 2002
# Whom:			Sergey Skvortsov <skv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBD-Oracle
PORTVERSION=	1.19
PORTREVISION=	3
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	DBI driver for Oracle RDBMS server

OPTIONS=	OCI8 "Use OCI8" off

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ENV=	ORACLE_HOME="${ORACLE_HOME}"

MAN1=		ora_explain.1
MAN3=		DBD::Oracle.3 DBD::Oraperl.3

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

.ifdef WITH_OCI8
PORTVERSION=	1.19
WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}
ORACLE_HOME=	${LOCALBASE}/oracle8-client
BUILD_DEPENDS+=	${ORACLE_HOME}/lib/libclntst8.a:${PORTSDIR}/databases/oracle8-client
CONFIGURE_ARGS=	-V 8.1.7
.else
PORTVERSION=	1.14
ORACLE_HOME=	${LOCALBASE}/oracle7
BUILD_DEPENDS+=	${ORACLE_HOME}/rdbms/demo/oracle.mk:${PORTSDIR}/databases/oracle7-client
CONFIGURE_ARGS=	-m ${ORACLE_HOME}/rdbms/demo/oracle.mk
.endif

post-patch:
.ifdef WITH_OCI8
	@${MV} ${WRKSRC}/Oracle.ex/README ${WRKSRC}/Oracle.ex/Readme
.else
	@${PERL} -pi -e 's!\(void\*\)(SvOK)!$$1!g' ${WRKSRC}/oci7.c
.endif

.include <bsd.port.post.mk>
