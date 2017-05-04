# $FreeBSD$

PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=

BUILD_DEPENDS+=	pypy:lang/pypy
RUN_DEPENDS+=	pypy:lang/pypy

PLIST_FILES=	%%PYPY_DIR%%/lib_pypy/${CFFI_MODULE}_cffi.%%PYPY_CFFI_VER%%.so

CFFI_MODULE?=	_${PORTNAME}

PYTHON_IMPL=	pypy
PYTHON_PORTVERSION?=	5.7.1
PYTHON_PKGNAMEPREFIX=	pypy-
PYTHON_CMD=	${LOCALBASE}/bin/${PYTHON_IMPL}

.include "${.CURDIR}/../../lang/pypy/bsd.pypy.mk"

do-build:
	${CP} ${LOCALBASE}/${PYPY_DIR}/lib_pypy/${CFFI_MODULE}_build.py ${WRKDIR}/${PORTNAME}.py
	(cd ${WRKDIR}; \
		${PYTHON_CMD} -c "from ${PORTNAME} import ${CFFI_NAME} as ffi; ffi.compile('${WRKDIR}');")

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PYPY_DIR}/lib_pypy/`dirname ${CFFI_MODULE}`/
	${INSTALL_LIB} ${WRKDIR}/${CFFI_MODULE}_cffi.${PYPY_CFFI_VER}.so ${STAGEDIR}${PREFIX}/${PYPY_DIR}/lib_pypy/`dirname ${CFFI_MODULE}`/
