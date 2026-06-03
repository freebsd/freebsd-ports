PORTNAME=	sqlite-jdbc
DISTVERSION=	3.53.1.0
CATEGORIES=	databases java
MASTER_SITES+=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/releases/download/${DISTVERSION}/:jar
DISTFILES+=	${DISTJAR}:jar
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	michaelo@FreeBSD.org
COMMENT=	JDBC driver for SQLite
WWW=		https://github.com/xerial/sqlite-jdbc

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${JAVAJARDIR}/slf4j-api.jar:devel/slf4j
LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

USES=		gmake java:build
USE_GITHUB=	yes
GH_ACCOUNT=	xerial

MAKE_ARGS+=	SQLITE_OBJ="${LOCALBASE}/lib/libsqlite3.so" \
			SQLITE_HEADER="${LOCALBASE}/include/sqlite3.h" \
			JAVA_CLASSPATH="${JAVAJARDIR}/slf4j-api.jar"
MAKE_ENV+=	JAVA_HOME="${JAVA_HOME}"
ALL_TARGET=	native

DISTJAR=	${PORTNAME}-${DISTVERSION}-without-natives.jar

PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}.jar lib/libsqlitejdbc.so

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTJAR} \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	${FIND} ${WRKSRC}/target/classes -name libsqlitejdbc.so \
		-exec ${INSTALL_LIB} {} ${STAGEDIR}${PREFIX}/lib/ \;

.include <bsd.port.mk>
