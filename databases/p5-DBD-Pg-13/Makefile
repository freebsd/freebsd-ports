# New ports collection makefile for:    p5-DBD-Pg
# Date created:				June 17th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBD-Pg
PORTVERSION=	1.22
PORTREVISION=	3
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD
PKGNAMEPREFIX=	p5-

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Provides access to PostgreSQL databases through the DBI

LIB_DEPENDS=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}

POSTGRESQL_PORT?=	databases/postgresql-client

PERL_CONFIGURE=	yes

MAN3=		DBD::Pg.3 DBD::dbd-pg.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
.endif

.if defined(WITH_OLD_LAYOUT)
CONFIGURE_ENV+=	POSTGRES_INCLUDE=${LOCALBASE}/include/pgsql \
		POSTGRES_LIB=${LOCALBASE}/lib
.else
.if exists(${LOCALBASE}/pgsql/bin/pg_config)
PG_CONFIG=	${LOCALBASE}/pgsql/bin/pg_config
.else
PG_CONFIG=	${LOCALBASE}/bin/pg_config
.endif
CONFIGURE_ENV+=	POSTGRES_INCLUDE=`${PG_CONFIG} --includedir` \
		POSTGRES_LIB=`${PG_CONFIG} --libdir`
.endif

.include <bsd.port.post.mk>
