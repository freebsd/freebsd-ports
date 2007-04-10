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

DEPRECATED=	Use databases/p5-DBD-Pg instead
EXPIRATION_DATE=	2007-05-10

CONFLICTS=	p5-DBD-Pg-1.[4-9]*
LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}-13

USE_PGSQL=	yes

PERL_CONFIGURE=	yes

MAN3=		DBD::Pg.3

.include <bsd.port.pre.mk>

PG_CONFIG=	${LOCALBASE}/bin/pg_config
CONFIGURE_ENV+=	POSTGRES_INCLUDE=`${PG_CONFIG} --includedir` \
		POSTGRES_LIB=`${PG_CONFIG} --libdir`

.include <bsd.port.post.mk>
