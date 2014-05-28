# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	pgrouting
PORTVERSION=	2.0.0
PORTREVISION=	1
CATEGORIES=	databases geography
MASTER_SITES=	https://github.com/pgRouting/${PORTNAME}/archive/
DISTFILES=	v${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	coder@tuxfamily.org
COMMENT=	Extension to PostGIS to provide geospatial routing functionality

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_system.so:${PORTSDIR}/devel/boost-libs\
		libCGAL.so:${PORTSDIR}/math/cgal \
		libgmp.so:${PORTSDIR}/math/gmp
RUN_DEPENDS=	${LOCALBASE}/share/postgresql/contrib/postgis-2.1/postgis.sql:${PORTSDIR}/databases/postgis21

USES=		cmake pgsql pkgconfig
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PGSQL_VER=	${DEFAULT_PGSQL_VER}

.if ${PGSQL_VER} >= 91
EXT_FILES=	pgrouting--2.0.0.sql \
		pgrouting.control \
		pgrouting_dd_legacy.sql \
		pgrouting--2.0.0.sql.in \
		pgrouting.sql \
		pgrouting_legacy.sql
PLIST_DIRSTRY+=	share/postgresql/extension
.for f in ${EXT_FILES}
PLIST_FILES+=	share/postgresql/extension/${f}
.endfor
.endif

post-install:
.if ${PGSQL_VER} >= 91
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/postgresql/extension
.for f in ${EXT_FILES}
	${INSTALL_DATA} ${WRKSRC}/lib/${f} ${STAGEDIR}${PREFIX}/share/postgresql/extension/
.endfor
.endif

.include <bsd.port.mk>
