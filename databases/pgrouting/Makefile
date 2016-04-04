# Created by: lbartoletti <coder@tuxfamily.org>
# $FreeBSD$

PORTNAME=	pgrouting
PORTVERSION=	2.0.0
DISTVERSIONPREFIX=	v
PORTREVISION=	4
CATEGORIES=	databases geography

MAINTAINER=	coder@tuxfamily.org
COMMENT=	Extension to PostGIS to provide geospatial routing functionality

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_system.so:devel/boost-libs\
		libCGAL.so:math/cgal \
		libgmp.so:math/gmp
RUN_DEPENDS=	${LOCALBASE}/share/postgresql/contrib/postgis-2.1/postgis.sql:databases/postgis21

USES=		compiler:features cmake pgsql pkgconfig
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	pgRouting

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang && ${COMPILER_VERSION} < 36
BUILD_DEPENDS+=	clang36:lang/clang36
CPP=		clang-cpp36
CC=		clang36
CXX=		clang++36
.endif

.if ${PGSQL_VER} >= 9.1
PLIST_SUB+=	OLDPG="@comment " NEWPG=""


post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/postgresql/extension
.for f in pgrouting--2.0.0.sql pgrouting.control pgrouting_dd_legacy.sql \
	pgrouting--2.0.0.sql.in pgrouting.sql pgrouting_legacy.sql
	${INSTALL_DATA} ${WRKSRC}/lib/${f} ${STAGEDIR}${PREFIX}/share/postgresql/extension/
.endfor

.else
PLIST_SUB+=	OLDPG="" NEWPG="@comment "
.endif

.include <bsd.port.post.mk>
