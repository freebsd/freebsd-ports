# New ports collection makefile for:    p5-DBD-PgSPI
# Date created:				17 April 2003
# Whom:	      				mat
#
# $FreeBSD$
#

PORTNAME=	DBD-PgSPI
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Provides access to PostgreSQL db through DBI within pl/perl functions

BUILD_DEPENDS=	${RUN_DEPENDS} \
		${NONEXISTENT}:${PORTSDIR}/${POSTGRESQL_PORT}:configure
RUN_DEPENDS=	${LOCALBASE}/lib/postgresql/plperl.so:${PORTSDIR}/databases/p5-postgresql-plperl \
		${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
LIB_DEPENDS=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}

PERL_CONFIGURE=	yes

MAN3=		DBD::PgSPI.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
.else
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
.endif

POSTGRESQL_PORT?=	databases/postgresql-client
PGSQL_PORTDIR?=		${PORTSDIR}/${POSTGRESQL_PORT}
PGSQL_WRKSRC!=		cd ${PGSQL_PORTDIR} && ${MAKE} -V WRKSRC

CONFIGURE_ENV=	POSTGRES_HOME="${PGSQL_WRKSRC}/src" \
	        LOCALBASE="${LOCALBASE}"

post-clean:
	@cd ${PGSQL_PORTDIR} && ${MAKE} clean

.include <bsd.port.post.mk>
