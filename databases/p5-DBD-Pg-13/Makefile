# New ports collection makefile for:    p5-DBD-Pg
# Date created:				June 17th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBD-Pg
PORTVERSION=	1.13
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD
PKGNAMEPREFIX=	p5-

MAINTAINER=	fjoe@freebsd.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
LIB_DEPENDS=	pq.2:${PORTSDIR}/databases/postgresql7
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		DBD::Pg.3 DBD::dbd-pg.3

.include <bsd.port.mk>

.if exists(${LOCALBASE}/bin/pg_config)
PG_CONFIG=	${LOCALBASE}/bin/pg_config
.elif exists(${LOCALBASE}/pgsql/bin/pg_config)
PG_CONFIG=	${LOCALBASE}/pgsql/bin/pg_config
.endif
.if defined(PG_CONFIG)
CONFIGURE_ENV+=	POSTGRES_INCLUDE=`${PG_CONFIG} --includedir` \
		POSTGRES_LIB=`${PG_CONFIG} --libdir`
.else
CONFIGURE_ENV+=	POSTGRES_INCLUDE=${PREFIX}/include/pgsql \
		POSTGRES_LIB=${PREFIX}/lib
.endif
