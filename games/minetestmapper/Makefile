PORTNAME=	minetestmapper
PORTVERSION=	20200328
CATEGORIES=	games graphics

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Generate an overview image of a minetest map

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgd.so:graphics/gd \
		libsqlite3.so:databases/sqlite3

USES=		cmake compiler:c11 pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	minetest

DATADIR=	${PREFIX}/share/minetest

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS
OPTIONS_GROUP=		DATABASE
DATABASE_DESC=		Database support
OPTIONS_GROUP_DATABASE= PGSQL LEVELDB REDIS

PGSQL_USES=		pgsql
PGSQL_CMAKE_BOOL=	ENABLE_POSTGRESQL
LEVELDB_DESC=		Enable LevelDB backend
LEVELDB_CMAKE_BOOL=	ENABLE_LEVELDB
LEVELDB_LIB_DEPENDS=	libleveldb.so:databases/leveldb
REDIS_DESC=		Enable Redis backend
REDIS_CMAKE_BOOL=	ENABLE_REDIS
REDIS_LIB_DEPENDS=	libhiredis.so:databases/hiredis

post-patch:
	@${REINPLACE_CMD} -e '/install.*COPYING/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
