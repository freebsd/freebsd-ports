# New ports collection makefile for:	PostGIS
# Date created:		June 09, 2004
# Whom:			Anderson Soares Ferreira <anderson@cnpm.embrapa.br>
#
# $FreeBSD$
#

PORTNAME=	postgis
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://postgis.refractions.net/
DISTNAME=	postgis-${PORTVERSION}

MAINTAINER=	anderson@cnpm.embrapa.br
COMMENT=	Adds support for geographic objects to PostgreSQL databases

LIB_DEPENDS=	proj.5:${PORTSDIR}/graphics/proj

USE_GMAKE=	yes
USE_PERL5_BUILD=	yes

PKGMESSAGE=	pkg-message
WRKSRC=		${WRKDIR}/postgis-${PORTVERSION}
PGSQL_SRC=	${WRKDIR}/pgsql/postgresql

INSTALL_TARGET=	install
INSTALLS_SHLIB=	no

OPTIONS=	PGSQL8 "Use PostgreSQL 8 instead of PostgreSQL 7.4" off \
		GEOS "Include GEOS - the OpenGIS 'Simple Features for SQL'" off \

.include <bsd.port.pre.mk>

MAKE_ARGS=	PGSQL_SRC="${PGSQL_SRC}" \
		DATADIR="${PREFIX}/share/postgis" \
		BINDIR="${PREFIX}/bin" \
		LIBDIR="${PREFIX}/lib"

.if defined(WITH_PGSQL8)
PGSQL_PORTDIR=	${PORTSDIR}/databases/postgresql-devel
.else
PGSQL_PORTDIR=	${PORTSDIR}/databases/postgresql7
.endif

LIB_DEPENDS+=	pq.3:${PGSQL_PORTDIR}

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/html/chunk.xsl:${PORTSDIR}/textproc/docbook-xsl 
MAKE_ARGS+=	WITH-DOC=yes \
		DOCSDIR="${DOCSDIR}"
PORTDOCS=	*
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
	@ ${INSTALL_SCRIPT} ${FILESDIR}/updatedb.default ${PREFIX}/share/postgis
	@ ${INSTALL_SCRIPT} ${FILESDIR}/UPDATE ${PREFIX}/share/postgis
	@ ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME} POST-INSTALL
	@ ${CAT} ${PKGMESSAGE}

post-deinstall:
	@ ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGDEINSTALL} ${PORTNAME} POST-DEINSTALL

.include <bsd.port.post.mk>
