PORTNAME=	apsw
PORTVERSION=	3.43.2.0
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Another Python SQLite Wrapper
WWW=		https://rogerbinns.github.io/apsw/ \
		https://github.com/rogerbinns/apsw

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		localbase python sqlite
USE_PYTHON=	autoplist concurrent distutils unittest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

OPTIONS_DEFINE=	EXTENSION
OPTIONS_DEFAULT=EXTENSION
EXTENSION_DESC=	Allow loadable extensions

EXTENSION_VARS=		PYDISTUTILS_BUILDARGS+=--enable=load_extension
EXTENSION_VARS_OFF=	PYDISTUTILS_BUILDARGS+=--omit=load_extension

post-patch:
	@${PRINTF} '[build_ext]\nuse_system_sqlite_config = True\n' > ${WRKSRC}/setup.apsw

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
