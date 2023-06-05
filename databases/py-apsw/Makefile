PORTNAME=	apsw
PORTVERSION=	3.42.0.0
CATEGORIES=	databases python
MASTER_SITES=	PYPI \
		https://sqlite.org/2023/:sqlite
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	apsw-${PORTVERSION}${EXTRACT_SUFX} \
		sqlite-autoconf-${PORTVERSION:C|\.([0-9])[[:>:]]|0\1|g:C|\.||g}.tar.gz:sqlite

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Another Python SQLite Wrapper
WWW=		https://rogerbinns.github.io/apsw/ \
		https://github.com/rogerbinns/apsw

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		localbase python:3.7+
USE_PYTHON=	autoplist concurrent distutils unittest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

OPTIONS_DEFINE=	EXTENSION
OPTIONS_DEFAULT=EXTENSION
EXTENSION_DESC=	Allow loadable extensions

EXTENSION_VARS=		PYDISTUTILS_BUILDARGS+=--enable=load_extension
EXTENSION_VARS_OFF=	PYDISTUTILS_BUILDARGS+=--omit=load_extension

post-patch:
	@${MV} ${WRKDIR}/sqlite-autoconf-${PORTVERSION:C|\.([0-9])[[:>:]]|0\1|g:C|\.||g} ${WRKSRC}/sqlite3

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
