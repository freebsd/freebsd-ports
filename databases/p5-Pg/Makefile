# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Pg
PORTVERSION=	2.1.1
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	databases perl5
MASTER_SITES=	PGSQL/projects/gborg/pgperl/stable
PKGNAMEPREFIX=	p5-
DIST_SUBDIR=	postgresql

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interface for using perl5 to access PostgreSQL databases

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5 pgsql
USE_PERL5=	configure

CONFIGURE_ENV=	POSTGRES_INCLUDE=${LOCALBASE}/include POSTGRES_LIB=${LOCALBASE}/lib

.include <bsd.port.mk>
