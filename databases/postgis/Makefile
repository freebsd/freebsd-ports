# New ports collection makefile for:	PostGIS
# Date created:		June 09, 2004
# Whom:			Anderson Soares Ferreira <anderson@cnpm.embrapa.br>
#
# $FreeBSD$
#

PORTNAME=	postgis
DISTVERSION=	1.1.2
CATEGORIES=	databases
MASTER_SITES=	http://postgis.refractions.net/download/

MAINTAINER=	anderson@cnpm.embrapa.br
COMMENT=	Adds support for geographic objects to PostgreSQL databases

LIB_DEPENDS=	proj.5:${PORTSDIR}/graphics/proj
RUN_DEPENDS=	postmaster:${PORTSDIR}/databases/postgresql${PGSQL_VER}-server

USE_PGSQL=	yes
USE_GMAKE=	yes
USE_BISON=	yes
USE_PERL5_BUILD=	yes

INSTALL_TARGET=	install
INSTALLS_SHLIB=	no

OPTIONS=	GEOS "Include GEOS - the OpenGIS 'Simple Features for SQL'" off \
		UTF8 "UTF-8 support for shp2pgsql. (needs libiconv)" off

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/postgis \
		--bindir=${PREFIX}/bin \
		--libdir=${PREFIX}/lib \
		--with-proj

.include <bsd.port.pre.mk>

#Setting/finding PostgreSQL version we want.
.if exists(${LOCALBASE}/bin/pg_config)
PGSQL_VER!=     ${LOCALBASE}/bin/pg_config --version | ${SED} -n 's/PostgreSQL[^0-9]*\([0-9][0-9]*\)\.\([0-9][0-9]*\)\..*/\1\2/p'
.else
PGSQL_VER=      ${DEFAULT_PGSQL_VER}
.endif


.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/html/chunk.xsl:${PORTSDIR}/textproc/docbook-xsl
MAKE_ARGS+=	WITH-DOC=yes
MAN1=		pgsql2shp.1 shp2pgsql.1
PORTDOCS=	*
.endif

.if defined(WITH_UTF8)
LIB_DEPENDS+=	iconv:${PORTSDIR}/converters/libiconv
MAKE_ENV+=	"LDFLAGS=-L${LOCALBASE}/lib"
.else
CONFIGURE_ARGS+=	--without-iconv
.endif

.if defined(WITH_GEOS)
LIB_DEPENDS+=	geos:${PORTSDIR}/graphics/geos
CONFIGURE_ARGS+=	--with-geos=${LOCALBASE}/bin/geos-config
.else
CONFIGURE_ARGS+=	--without-geos
.endif

pre-everything::
	@${SH} ${PKGINSTALL} ${PORTNAME} MESSAGE

post-install:
	@${MKDIR} ${PREFIX}/lib/postgresql
	@${LN} -s ${PREFIX}/lib/liblwgeom.so.1 ${PREFIX}/lib/postgresql
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME} POST-INSTALL

post-deinstall:
	@ ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDEINSTALL} ${PORTNAME} POST-DEINSTALL

.include <bsd.port.post.mk>
