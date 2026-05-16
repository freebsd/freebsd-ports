PORTNAME=	mroonga
DISTVERSION=	15.25
CATEGORIES=	databases textproc
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Open-source fulltext search engine for MySQL
WWW=		https://mroonga.org/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${NONEXISTENT}:${_MYSQL_SERVER}:build \
		${LOCALBASE}/lib/groonga/plugins/normalizers/mysql.so:databases/groonga-normalizer-mysql
LIB_DEPENDS=	libgroonga.so:textproc/groonga

USES=		cmake compiler:c11 libtool mysql pkgconfig shebangfix
IGNORE_WITH_MYSQL=	105m 106m 1011m 81

SHEBANG_FILES=	data/rpm/post.sh data/rpm/preun.sh

CMAKE_ARGS=	-DMYSQL_BUILD_DIR="$$(cd ${PORTSDIR}/${_MYSQL_SERVER}; ${MAKE} -V BUILD_WRKSRC)" \
		-DMYSQL_CONFIG=${PREFIX}/bin/mysql_config \
		-DMYSQL_SOURCE_DIR="$$(cd ${PORTSDIR}/${_MYSQL_SERVER}; ${MAKE} -V WRKSRC)"

SUB_FILES=	pkg-message

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DOCS_CMAKE_BOOL=	MRN_WITH_DOC

post-patch:
	@${REINPLACE_CMD} -e 's| ja||g' ${WRKSRC}/doc/CMakeLists.txt

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/locale/en/man/mroonga.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
