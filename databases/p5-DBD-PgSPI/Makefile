# New ports collection makefile for:    p5-DBD-PgSPI
# Date created:				17 April 2003
# Whom:	      				mat
#
# $FreeBSD$
#

PORTNAME=	DBD-PgSPI
PORTVERSION=	0.02
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Provides access to PostgreSQL db through DBI within pl/perl functions

BUILD_DEPENDS=	${RUN_DEPENDS} \
		${NONEXISTENT}:${PORTSDIR}/${POSTGRESQL_PORT}:configure
RUN_DEPENDS=	${LOCALBASE}/lib/postgresql/plperl.so:${PORTSDIR}/databases/p5-postgresql-plperl

USE_PGSQL=	yes
PERL_CONFIGURE=	yes

MAN3=		DBD::PgSPI.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README
.endif

POSTGRESQL_PORT?=	databases/postgresql${PGSQL_VER}-server
PGSQL_PORTDIR?=		${PORTSDIR}/${POSTGRESQL_PORT}
PGSQL_WRKSRC_CMD=	cd ${PGSQL_PORTDIR} && ${MAKE} -V WRKSRC

.include <bsd.port.pre.mk>
# Setting/finding PostgreSQL version we want.
.if exists(${LOCALBASE}/bin/postmaster)
PGSQL_VER!=	${LOCALBASE}/bin/postmaster -V | \
		${SED} -n 's/postmaster.*PostgreSQL[^0-9]*\([0-9][0-9]*\)\.\([0-9][0-9]*\)\..*/\1\2/p'
.elif exists(${LOCALBASE}/bin/pg_config)
PGSQL_VER!=	${LOCALBASE}/bin/pg_config --version | ${SED} -n 's/PostgreSQL[^0-9]*\([0-9][0-9]*\)\.\([0-9][0-9]*\)\..*/\1\2/p'
.else
PGSQL_VER=	${DEFAULT_PGSQL_VER}
.endif

.if ${PERL_LEVEL} < 500600
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137 \
		${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg-13
.else
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.endif

CONFIGURE_ENV=	POSTGRES_HOME="`${PGSQL_WRKSRC_CMD}`/src" \
	        LOCALBASE="${LOCALBASE}"

post-patch:
	@${PERL} -i -pe '$$_ = "" if /ppport.h/' \
		${WRKSRC}/PgSPI.h

post-clean:
	@cd ${PGSQL_PORTDIR} && ${MAKE} clean

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.post.mk>
