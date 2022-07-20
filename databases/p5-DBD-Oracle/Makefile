PORTNAME=	DBD-Oracle
PORTVERSION=	1.19
PORTREVISION=	6
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	eugen@FreeBSD.org
COMMENT=	DBI driver for Oracle RDBMS server

BUILD_DEPENDS=	p5-DBI>=0:databases/p5-DBI
RUN_DEPENDS=	p5-DBI>=0:databases/p5-DBI

OPTIONS_DEFINE=	EXAMPLES

USES=		perl5 shebangfix
USE_PERL5=	configure patch
CONFIGURE_ENV=	ORACLE_HOME="${ORACLE_HOME}"
LDFLAGS_i386=	-Wl,-znotext

SHEBANG_FILES=	Oracle.ex/*

.include <bsd.port.options.mk>

ORACLE_HOME=	${LOCALBASE}/oracle8-client
BUILD_DEPENDS+=	${ORACLE_HOME}/lib/libclntst8.a:databases/oracle8-client
CONFIGURE_ARGS=	-V 8.1.7

.if ${ARCH} == "i386"
CONFIGURE_ARGS+= LDDLFLAGS="`${PERL} -MConfig -e 'print $$Config{lddlflags}'` \
		${LDFLAGS_i386}"
.endif

post-patch:
	@${MV} ${WRKSRC}/Oracle.ex/README ${WRKSRC}/Oracle.ex/Readme
	@${REINPLACE_CMD} -E -e 's!([, ][&!]?)na\)!\1PL_na)!g' \
		-e 's!([, =][,&]?)sv_(undef|yes|no)!\1PL_sv_\2!g' \
		-e 's!dirty!PL_dirty!g' -e 's!dowarn!PL_dowarn!g' \
		${WRKSRC}/dbdimp.c ${WRKSRC}/Oracle.xs ${WRKSRC}/oci[78].c

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/DBD/Oracle/Oracle.so
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/Oracle.ex/Readme	${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/Oracle.ex/*.pl	${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/Oracle.ex/japh	${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/Oracle.ex/sql	${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
