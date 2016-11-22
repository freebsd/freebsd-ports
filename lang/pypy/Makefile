# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME?=	pypy
DISTVERSION?=	5.6.0	# Also update bsd.pypy.cffi.mk
CATEGORIES=	lang python
MASTER_SITES=	https://bitbucket.org/pypy/pypy/downloads/ http://buildbot.pypy.org/mirror/
DISTNAME?=	${PORTNAME}2-v${PORTVERSION}-src

MAINTAINER=	python@FreeBSD.org
COMMENT=	Fast, compliant implementation of the Python language

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libffi.so:devel/libffi
TEST_DEPENDS=	${PREFIX}/${PYPY_DIR}/lib_pypy/_gdbm_cffi.${PYPY_CFFI_VER}.so:databases/pypy-gdbm \
		${PREFIX}/${PYPY_DIR}/lib_pypy/_sqlite3_cffi.${PYPY_CFFI_VER}.so:databases/pypy-sqlite3 \
		${PREFIX}/${PYPY_DIR}/lib_pypy/_tkinter/tklib_cffi.${PYPY_CFFI_VER}.so:x11-toolkits/pypy-tkinter

ONLY_FOR_ARCHS=	i386 amd64 armv6 powerpc64
ONLY_FOR_ARCHS_REASON=	PyPy JIT only supported on these architectures

OPTIONS_SINGLE=	TRANS
OPTIONS_SINGLE_TRANS=	PYTHON
PYTHON_DESC=	Use Python-2.7 to translate (slowest)
PYPY_DESC=	Use PyPy to translate (fastest, highest memory usage)
PYPY_MINMEM_DESC=	Use PyPy to translate (lowest memory usage)
TRANS_DESC=	Translation method
LOCALBASE?=	/usr/local
.if exists(${LOCALBASE}/bin/pypy) || ${PORTNAME} != pypy
OPTIONS_SINGLE_TRANS+=	PYPY PYPY_MINMEM
. if exists(${LOCALBASE}/bin/pypy)
OPTIONS_DEFAULT=	PYPY_MINMEM
. else
OPTIONS_DEFAULT=	PYTHON
. endif
.else
OPTIONS_SLAVE=	PYTHON
.endif

ALL_TARGET=	pypy-c
BUILD_WRKSRC?=	${WRKDIR}/build/usession-release-pypy2.7-v${PORTVERSION}-0/testing_1
MAKE_ENV+=	PYPY_LOCALBASE=${LOCALBASE}
PACKAGE_ARGS?=	--without-gdbm --without-sqlite3 --without-tk
USE_LDCONFIG=	${PREFIX}/${PYPY_DIR}/bin
USES=		gettext-runtime gmake ssl tar:bzip2

.if ${PORTNAME} != pypy
PYPY_BUILD_DEPENDS=	pypy:lang/pypy
PYPY_MINMEM_BUILD_DEPENDS=	pypy:lang/pypy
.endif
PYPY_VARS=	PYTHON_CMD=${LOCALBASE}/bin/pypy
PYPY_MINMEM_VARS=	PYTHON_CMD="${SETENV} PYPY_GC_MAX_DELTA=200MB ${LOCALBASE}/bin/pypy --jit loop_longevity=300"
PYTHON_USES=	python:2,build

DESCR=		${.CURDIR}/pkg-descr
DISTINFO_FILE=	${.CURDIR}/distinfo
MASTERDIR?=	${.CURDIR}
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/bsd.pypy.mk"
.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" || ${ARCH} == "armv6"
PYPY_BITS=	32
.elif ${ARCH} == "amd64" || ${ARCH} == "powerpc64"
PYPY_BITS=	64
.endif
PLIST_SUB+=	PYPY_BITS="${PYPY_BITS}"

pre-build:
	if [ ! -f ${BUILD_WRKSRC}/Makefile ]; then \
		${RM} -r ${WRKDIR}/build; \
		${MKDIR} ${WRKDIR}/build; \
		(cd ${WRKSRC}/pypy/goal; \
			${SETENV} ${MAKE_ENV} TMPDIR=${WRKDIR}/build \
			${PYTHON_CMD} ../../rpython/bin/rpython --source -Ojit targetpypystandalone.py); \
	fi

post-build:
	${CP} ${BUILD_WRKSRC}/pypy-c ${BUILD_WRKSRC}/libpypy-c.so ${WRKSRC}/pypy/goal/

do-install:
	${SETENV} TMPDIR=${WRKDIR}/build \
		${PYTHON_CMD} ${WRKSRC}/pypy/tool/release/package.py --builddir ${WRKDIR}/build --archive-name ${PYPY_DIR} \
			${PACKAGE_ARGS}
	${EXTRACT_CMD} -C ${STAGEDIR}${PREFIX} -xf ${WRKDIR}/build/${PYPY_DIR}.tar.bz2
	${LN} -fs ../${PYPY_DIR}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${FIND} ${STAGEDIR}${PREFIX}/${PYPY_DIR}/lib_pypy/ -name '*.so' | ${XARGS} ${STRIP_CMD}

do-test:
	# See https://bitbucket.org/pypy/buildbot/src/default/bot2/pypybuildbot/builds.py?at=default#builds.py-386
	# add_translated_tests()
	(cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} TMPDIR=${WRKDIR}/build PYTHONPATH=${WRKSRC} \
		${WRKSRC}/pypy/goal/pypy-c testrunner/runner.py --root pypy --logfile=pytest-A.log \
			--parallel-runs ${MAKE_JOBS_NUMBER} \
			--config pypy/pytest-A.cfg --config pypy/pytest-A.py)
.for dir in lib-python pypy/module/pypyjit/test
	(cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} TMPDIR=${WRKDIR}/build PYTHONPATH=${WRKSRC} \
		${WRKSRC}/pypy/goal/pypy-c pypy/test_all.py --basetemp ${WRKDIR}/build --pypy pypy/goal/pypy-c \
			${dir} )
.endfor
	(cd ${WRKSRC}/lib-python/2.7/test; \
		${SETENV} ${MAKE_ENV} TMPDIR=${WRKDIR}/build PYTHONPATH=${WRKSRC} \
		${WRKSRC}/pypy/goal/pypy-c regrtest.py -vvu all)

pkg-plist: build
	${TAR} -tf ${WRKDIR}/build/${PYPY_DIR}.tar.bz2 > ${WRKDIR}/.plist-files-gen
	${REINPLACE_CMD} -e 's|^${PYPY_DIR}|%%PYPY_DIR%%|g' \
		-e 's|_${PYPY_BITS}_|_%%PYPY_BITS%%_|g' \
		-e 's|${PYPY_CFFI_VER}|%%PYPY_CFFI_VER%%|g' \
		-e '/\/$$/d' \
			${WRKDIR}/.plist-files-gen
	${ECHO} bin/${PORTNAME} > ${WRKDIR}/pkg-plist
	${SORT} ${WRKDIR}/.plist-files-gen >> ${WRKDIR}/pkg-plist
	${CP} ${WRKDIR}/pkg-plist ${.CURDIR}/pkg-plist

.include <bsd.port.post.mk>
