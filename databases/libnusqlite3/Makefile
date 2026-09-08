PORTNAME=	libnusqlite3
DISTVERSION=	1.12
CATEGORIES=	databases
MASTER_SITES=	https://bitbucket.org/alekseyt/nunicode/get/${DISTVERSION}${EXTRACT_SUFX}?dummy=/
DISTNAME=	nunicode-${DISTVERSION}

MAINTAINER=	michaeljohnson@ahze.net
COMMENT=	SQLite3 extension with Unicode collation, case mapping, and unaccent
WWW=		https://bitbucket.org/alekseyt/nunicode

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/sqlite3ext.h:databases/sqlite3

USES=		cmake
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DSQLITE3_INCLUDE_DIR=${LOCALBASE}/include
CMAKE_ON=	NU_BUILD_SQLITE3_EXT
ALL_TARGET=	nusqlite3

WRKSRC=		${WRKDIR}/alekseyt-nunicode-5d3279b1399d

PLIST_FILES=	lib/libnusqlite3.so

do-install:
	${INSTALL_LIB} ${BUILD_WRKSRC}/sqlite3/libnusqlite3.so \
		${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
