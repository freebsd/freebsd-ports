# New ports collection makefile for:	PostGIS
# Date created:		June 09, 2004
# Whom:			Anderson Soares Ferreira <anderson@cnpm.embrapa.br>
#
# $FreeBSD$
#

PORTNAME=	postgis
DISTVERSION=	1.0.6
CATEGORIES=	databases
MASTER_SITES=	http://postgis.refractions.net/download/

MAINTAINER=	anderson@cnpm.embrapa.br
COMMENT=	Adds support for geographic objects to PostgreSQL databases

BUILD_DEPENDS=	${NONEXISTENT}:${PGSQL_PORTDIR}:configure
LIB_DEPENDS=	proj.5:${PORTSDIR}/graphics/proj

USE_PGSQL=	yes
USE_GMAKE=	yes
USE_BISON=	yes
USE_PERL5_BUILD=	yes

MAN1=		pgsql2shp.1 shp2pgsql.1

INSTALL_TARGET=	install
INSTALLS_SHLIB=	no

OPTIONS=	GEOS "Include GEOS - the OpenGIS 'Simple Features for SQL'" off \
		UTF8 "UTF-8 support for shp2pgsql. (needs libiconv)" off

MAKE_ARGS=	PGSQL_SRC="${PGSQL_SRC}" \
		USE_PROJ=1 \
		DATADIR="${PREFIX}/share/postgis" \
		INSTALL_DATA="${INSTALL_DATA}" \
		BINDIR="${PREFIX}/bin" \
		LIBDIR="${PREFIX}/lib"

.include <bsd.port.pre.mk>

#Setting/finding PostgreSQL version we want.
.if exists(${LOCALBASE}/bin/postmaster)
PGSQL_VER!=	${LOCALBASE}/bin/postmaster -V | \
		${SED} -n 's/postmaster.*PostgreSQL[^0-9]*\([0-9][0-9]*\)\.\([0-9][0-9]*\)\..*/\1\2/p'
.elif exists(${LOCALBASE}/bin/pg_config)
PGSQL_VER!=	${LOCALBASE}/bin/pg_config --version | ${SED} -n 's/PostgreSQL[^0-9]*\([0-9][0-9]*\)\.\([0-9][0-9]*\)\..*/\1\2/p'
.else
PGSQL_VER=	${DEFAULT_PGSQL_VER}
.endif

PGSQL_PORTDIR=	${PORTSDIR}/databases/postgresql${PGSQL_VER}-server
PGSQL_SRC!=	cd ${PGSQL_PORTDIR} && ${MAKE} -V WRKSRC

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
LIB_DEPENDS+=	geos:${PORTSDIR}/graphics/geos
MAKE_ARGS+=	USE_GEOS=1
.else
MAKE_ARGS+=	USE_GEOS=0
.endif

pre-everything::
	@${SH} ${PKGINSTALL} ${PORTNAME} MESSAGE

post-install:
	@ ${MKDIR} ${PREFIX}/lib/postgresql
	@ ${LN} ${PREFIX}/lib/liblwgeom.so.1 ${PREFIX}/lib/postgresql
	@ ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME} POST-INSTALL

post-deinstall:
	@ ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDEINSTALL} ${PORTNAME} POST-DEINSTALL

.include <bsd.port.post.mk>
