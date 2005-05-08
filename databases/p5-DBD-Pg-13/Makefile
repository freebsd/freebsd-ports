# New ports collection makefile for:    p5-DBD-Pg
# Date created:				June 17th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBD-Pg
PORTVERSION=	1.32
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provides access to PostgreSQL databases through the DBI

CONFLICTS=	p5-DBD-Pg-1.[4-9]*

USE_PGSQL=	yes

PERL_CONFIGURE=	yes

MAN3=		DBD::Pg.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
post-patch:
	@${PERL} -i -pe '$$_ = "" if /5.006001/' \
		${WRKSRC}/Pg.pm ${WRKSRC}/Makefile.PL
.else
IGNORE=		You should use databases/p5-DBD-Pg.
.endif

PG_CONFIG=	${LOCALBASE}/bin/pg_config
CONFIGURE_ENV+=	POSTGRES_INCLUDE=`${PG_CONFIG} --includedir` \
		POSTGRES_LIB=`${PG_CONFIG} --libdir`

.include <bsd.port.post.mk>
