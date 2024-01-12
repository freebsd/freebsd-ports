PORTNAME=	libbson
DISTVERSION=	1.25.4
CATEGORIES=	devel

MAINTAINER=	ports@bsdserwis.com
COMMENT=	BSON utility library
WWW=		https://github.com/mongodb/mongo-c-driver

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake cpe python:env pkgconfig
CPE_VENDOR=	mongodb
USE_GITHUB=	yes
GH_ACCOUNT=	mongodb
GH_PROJECT=	mongo-c-driver
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBSON_HAVE_STRINGS_H=0
CMAKE_OFF=	BUILD_TESTING \
		ENABLE_EXAMPLES \
		ENABLE_ICU \
		ENABLE_MONGOC \
		ENABLE_TESTS \
		ENABLE_UNINSTALL \
		ENABLE_ZLIB \
		ENABLE_ZSTD

DOCSDIR=	${PREFIX}/share/doc/mongo-c-driver

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}furo>0:textproc/py-furo@${PY_FLAVOR}
DOCS_CMAKE_ON=		-DENABLE_HTML_DOCS=ON -DENABLE_MAN_PAGES=ON

post-extract:
	${ECHO} "${DISTVERSION}" > ${WRKSRC}/VERSION_CURRENT

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/share/mongo-c-driver

.include <bsd.port.mk>
