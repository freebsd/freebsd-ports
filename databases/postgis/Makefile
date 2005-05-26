# New ports collection makefile for:	PostGIS
# Date created:		June 09, 2004
# Whom:			Anderson Soares Ferreira <anderson@cnpm.embrapa.br>
#
# $FreeBSD$
#

PORTNAME=	postgis
DISTVERSION=	1.0.1
CATEGORIES=	databases
MASTER_SITES=	http://postgis.refractions.net/download/

MAINTAINER=	anderson@cnpm.embrapa.br
COMMENT=	Adds support for geographic objects to PostgreSQL databases

LIB_DEPENDS=	proj.5:${PORTSDIR}/graphics/proj

USE_GMAKE=	yes
USE_BISON=	yes
USE_PERL5_BUILD=	yes

PGSQL_SRC=	${WRKDIR}/pgsql/postgresql

INSTALL_TARGET=	install
INSTALLS_SHLIB=	no

OPTIONS=	GEOS "Include GEOS - the OpenGIS 'Simple Features for SQL'" off \
		UTF8 "UTF-8 support for shp2pgsql. (needs libiconv)" off

USE_PGSQL=	YES

.include <bsd.port.pre.mk>

MAKE_ARGS=	PGSQL_SRC="${PGSQL_SRC}" \
		USE_PROJ=1 \
		DATADIR="${PREFIX}/share/postgis" \
		INSTALL_DATA="${INSTALL_DATA}" \
		BINDIR="${PREFIX}/bin" \
		LIBDIR="${PREFIX}/lib"

PGSQL_PORTDIR=	${PORTSDIR}/databases/postgresql${PGSQL_VER}-server

MAN1=		pgsql2shp.1 shp2pgsql.1

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/html/chunk.xsl:${PORTSDIR}/textproc/docbook-xsl
MAKE_ARGS+=	WITH-DOC=yes \
		DOCSDIR="${DOCSDIR}"
PORTDOCS=	*
.endif

.if defined(WITH_UTF8)
LIB_DEPENDS+=	iconv:${PORTSDIR}/converters/libiconv
MAKE_ARGS+=	USE_ICONV=1
.endif

.if defined(WITH_GEOS)
LIB_DEPENDS+=	geos.2:${PORTSDIR}/graphics/geos
MAKE_ARGS+=	USE_GEOS=1
.else
MAKE_ARGS+=	USE_GEOS=0
.endif

pre-everything::
	@${SH} ${PKGINSTALL} ${PORTNAME} MESSAGE

pre-configure:
	@([ -d ${WRKDIR}/pgsql ] || ${MKDIR} ${WRKDIR}/pgsql) && \
	cd ${PGSQL_PORTDIR} && \
	${MAKE} WRKDIR=${WRKDIR}/pgsql configure && \
	${MV} ${WRKDIR}/pgsql/postgresql* ${PGSQL_SRC} \

post-install:
	@ ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME} POST-INSTALL

post-deinstall:
	@ ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDEINSTALL} ${PORTNAME} POST-DEINSTALL

.include <bsd.port.post.mk>
