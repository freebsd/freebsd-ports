# New ports collection makefile for:	PostGIS
# Date created:		June 09, 2004
# Whom:			Anderson Soares Ferreira <anderson@cnpm.embrapa.br>
#
# $FreeBSD$
#

PORTNAME=	postgis
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://postgis.refractions.net/
DISTNAME=	postgis-${PORTVERSION}

MAINTAINER=	anderson@cnpm.embrapa.br
COMMENT=	Adds support for geographic objects to PostgreSQL databases

BUILD_DEPENDS=	${PGSQL_SRC}/src/Makefile.global:${PORTSDIR}/databases/postgresql7:configure
LIB_DEPENDS=	proj.5:${PORTSDIR}/graphics/proj	\
		pq:${PORTSDIR}/databases/postgresql7

USE_GMAKE=	yes
USE_PERL5_BUILD=	yes
MAKE_ARGS=	PGSQL_SRC=${PGSQL_SRC}

OPTIONS=	GEOS "Include GEOS - the OpenGIS 'Simple Features for SQL'" off

PGSQL_PORTDIR=	${WRKDIR}/../../../databases/postgresql7
WRKSRC=		${WRKDIR}/postgis-${PORTVERSION}
PGSQL_SRC=	${PGSQL_PORTDIR}/work/postgresql-7.4.6
INSTALL_TARGET=	install

.if defined(WITH_GEOS)
LIB_DEPENDS+=	geos.2:${PORTSDIR}/graphics/geos
.endif

post-extract:
.if ! defined(WITH_GEOS)
	@ ${CP} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.orig ; \
	${CAT} ${WRKSRC}/Makefile.orig | \
	${SED} "s|USE_GEOS=1|USE_GEOS=0|g" > ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
