PORTNAME=	mysql-shell
DISTVERSION=	9.7.1
CATEGORIES=	databases
MASTER_SITES=	https://downloads.mysql.com/archives/get/p/43/file/:shell \
		https://downloads.mysql.com/archives/get/p/23/file/:server
DISTFILES=	mysql-shell-${DISTVERSION}-src.tar.gz:shell \
		mysql-${DISTVERSION}.tar.gz:server

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Advanced client and code editor for MySQL
WWW=		https://dev.mysql.com/doc/mysql-shell/9.7/en/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

# Only 64-bit systems are supported
NOT_FOR_ARCHS=	armv6 armv7 i386 powerpc

LIB_DEPENDS=	libantlr4-runtime.so:devel/libantlr4 \
		libcurl.so:ftp/curl \
		libssh.so:security/libssh \
		libunwind.so:devel/libunwind
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}antlr4-python3-runtime>0:devel/py-antlr4-python3-runtime@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oci>=0:devel/py-oci@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}svg_py>0:graphics/py-svg.py@${PY_FLAVOR}

USES=		bison:build cmake:noninja cpe pkgconfig python:3.12+ shebangfix ssl

CPE_VENDOR=	oracle
CPE_PRODUCT=	mysql_shell

SHEBANG_FILES=	${WRKSRC}/plugins/external/migration_plugin/scripts/build.sh \
		${WRKSRC}/plugins/external/mrs_plugin/scripts/*sh \
		${WRKSRC}/plugins/external/util_plugin/visual/explain.py

CMAKE_ARGS=	-DBUNDLED_ANTLR_DIR=${LOCALBASE} \
		-DHAVE_PYTHON=1 \
		-DMYSQL_BUILD_DIR=${WRKDIR}/mysql-${DISTVERSION}/build \
		-DMYSQL_SOURCE_DIR=${WRKDIR}/mysql-${DISTVERSION}
CMAKE_BUILD_TYPE=	Release

WRKSRC=		${WRKDIR}/mysql-shell-${DISTVERSION}-src

post-patch:
	@cd ${WRKDIR}/mysql-${DISTVERSION} && ${PATCH} -s < ${FILESDIR}/mysql-server.patch

pre-configure:
	@${MKDIR} ${WRKDIR}/mysql-${DISTVERSION}/build
	@cd ${WRKDIR}/mysql-${DISTVERSION}/build && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} .. \
			-DWITH_SSL=system \
			-DWITH_UNIT_TESTS=OFF \
			-DCMAKE_INSTALL_PREFIX=${WRKDIR}/mysql && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} -j${MAKE_JOBS_NUMBER} install

.include <bsd.port.mk>
