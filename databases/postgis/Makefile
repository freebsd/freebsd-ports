# New ports collection makefile for:	PostGIS
# Date created:		June 09, 2004
# Whom:			Anderson Soares Ferreira <anderson@cnpm.embrapa.br>
#
# $FreeBSD$
#

PORTNAME=	postgis
PORTVERSION=	0.8.2
CATEGORIES=	databases
MASTER_SITES=	http://postgis.refractions.net/
DISTNAME=	postgis-${PORTVERSION}

MAINTAINER=	anderson@cnpm.embrapa.br
COMMENT=	Adds support for geographic objects to PostgreSQL databases

LIB_DEPENDS=	proj.3:${PORTSDIR}/graphics/proj
BUILD_DEPENDS=	postmaster:${PORTSDIR}/databases/postgresql7
RUN_DEPENDS=	postmaster:${PORTSDIR}/databases/postgresql7

USE_GMAKE=	yes
USE_PERL5_BUILD=	yes
MAKE_ARGS=	PGSQL_SRC=${PGSQL_SRC}

PGSQL_PORTDIR=	${PORTSDIR}/databases/postgresql7
WRKSRC=		${WRKDIR}/postgis-${PORTVERSION}
PGSQL_SRC=	${PGSQL_PORTDIR}/work/postgresql-7.4.2
INSTALL_TARGET=	install

.if defined(WITH_GEOS)
LIB_DEPENDS+=	geos.1:${PORTSDIR}/graphics/geos
.endif

pre-extract:
	@if [ ! -d ${PGSQL_SRC} ] ; then \
	${ECHO_MSG} "===>  Extracting and configuring PostgreSQL source" ; \
	cd ${PGSQL_PORTDIR} ; \
	${MAKE} configure ; \
	fi

post-extract:
.if ! defined(WITH_GEOS)
	@ ${CP} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.orig ; \
	${CAT} ${WRKSRC}/Makefile.orig | \
	${SED} "s|USE_GEOS=1|USE_GEOS=0|g" > ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
