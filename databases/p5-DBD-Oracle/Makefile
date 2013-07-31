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

BUILD_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	OCI8 EXAMPLES
OCI8_DESC=	Use OCI8

USES=		perl5
USE_PERL5=	configure patch
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
PLIST_SUB+=	MKTA=''
.else
PORTVERSION=	1.14
ORACLE_HOME=	${LOCALBASE}/oracle7
BUILD_DEPENDS+=	${ORACLE_HOME}/rdbms/demo/oracle.mk:${PORTSDIR}/databases/oracle7-client
CONFIGURE_ARGS=	-m ${ORACLE_HOME}/rdbms/demo/oracle.mk
PLIST_SUB+=	MKTA='@comment '
.endif

post-patch:
.if ${PORT_OPTIONS:MOCI8}
	@${MV} ${WRKSRC}/Oracle.ex/README ${WRKSRC}/Oracle.ex/Readme
.else
	@${PERL} -pi -e 's!\(void\*\)(SvOK)!$$1!g' ${WRKSRC}/oci7.c
.endif
	@${REINPLACE_CMD} -E -e 's!([, ][&!]?)na\)!\1PL_na)!g' \
		-e 's!([, =][,&]?)sv_(undef|yes|no)!\1PL_sv_\2!g' \
		-e 's!dirty!PL_dirty!g' -e 's!dowarn!PL_dowarn!g' \
		${WRKSRC}/dbdimp.c ${WRKSRC}/Oracle.xs ${WRKSRC}/oci[78].c

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/Oracle.ex/Readme 	${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/Oracle.ex/*.pl	${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/Oracle.ex/japh	${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/Oracle.ex/sql	${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
