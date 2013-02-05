# Created by: Sergey Skvortsov <skv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBD-Oracle
PORTVERSION=	1.19
PORTREVISION=	3
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DBI driver for Oracle RDBMS server

OPTIONS_DEFINE=	OCI8 DOCS
OCI8_DESC=	Use OCI8

BUILD_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS:=	${BUILD_DEPENDS}

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-03-05
BROKEN=		Does not build

PERL_CONFIGURE=	yes
CONFIGURE_ENV=	ORACLE_HOME="${ORACLE_HOME}"

MAN1=		ora_explain.1
MAN3=		DBD::Oracle.3 DBD::Oraperl.3

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOCI8}
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

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/Oracle.ex/Readme 	${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/Oracle.ex/*.pl	${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/Oracle.ex/japh	${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/Oracle.ex/sql	${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
