# New ports collection makefile for:	p5-Pg
# Date created:				October 19th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Pg
PORTVERSION=	2.1.1
PORTEPOCH=	1
CATEGORIES=	databases perl5
MASTER_SITES=	ftp://gborg.postgresql.org/pub/pgperl/stable/
PKGNAMEPREFIX=	p5-
DIST_SUBDIR=	postgresql

MAINTAINER=	girgen@pingpong.net
COMMENT=	An interface for using perl5 to access PostgreSQL databases

POSTGRESQL_PORT?=	databases/postgresql7
LIB_DEPENDS=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}

USE_PERL5=	yes

MAN3=		Pg.3

PERL_CONFIGURE=	YES
CONFIGURE_ENV=	POSTGRES_INCLUDE=${LOCALBASE}/include POSTGRES_LIB=${LOCALBASE}/lib

.include <bsd.port.mk>
