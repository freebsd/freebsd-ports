# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cffi
PORTVERSION=	1.11.2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Foreign Function Interface for Python calling C code

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libffi.so:devel/libffi
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycparser>=2.10:devel/py-pycparser@${FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${FLAVOR}

# Actually 2.6-2.7,3.2-3.5
USES=		localbase python compiler
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1100000
.if ${COMPILER_TYPE:Mclang}
CFLAGS+=	-Wno-shift-negative-value
.endif
.endif

# Tests assume gcc, and fail on pure clang systems
# Fixed in https://bitbucket.org/cffi/cffi/issues/271
post-patch:
	${REINPLACE_CMD} -e 's|gcc|${CC}|g' ${WRKSRC}/testing/cffi0/test_ownlib.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_cffi_backend.so

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
		${PYDISTUTILS_SETUP} build_ext -i)
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -rs)

.include <bsd.port.post.mk>
