PORTNAME=	apsw
PORTVERSION=	3.38.5
DISTVERSIONSUFFIX=	-r1
CATEGORIES=	databases python
MASTER_SITES=	https://github.com/rogerbinns/apsw/releases/download/${PORTVERSION}${DISTVERSIONSUFFIX}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Another Python SQLite Wrapper

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	sqlite3>=${PORTVERSION:R},1:databases/sqlite3

USES=		localbase python:3.7+ sqlite:3 zip
USE_PYTHON=	autoplist concurrent distutils unittest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

OPTIONS_DEFINE=	EXTENSION
OPTIONS_DEFAULT=EXTENSION
EXTENSION_DESC=	Allow loadable extensions

EXTENSION_VARS=		PYDISTUTILS_BUILDARGS+=--enable=load_extension
EXTENSION_VARS_OFF=	PYDISTUTILS_BUILDARGS+=--omit=load_extension

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
