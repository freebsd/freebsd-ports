# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME=	pypy
PORTVERSION=	4.0.1	# Also update bsd.pypy.cffi.mk
CATEGORIES=	lang python
MASTER_SITES=	https://bitbucket.org/pypy/pypy/get/ LOCAL/dbn/pypy
DISTNAME=	release-${DISTVERSION}
DIST_SUBDIR=	pypy

MAINTAINER=	python@FreeBSD.org
COMMENT=	Fast, compliant implementation of the Python language

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2 \
		libffi.so:${PORTSDIR}/devel/libffi

ONLY_FOR_ARCHS=	i386 amd64 armv6 powerpc64
ONLY_FOR_ARCHS_REASON=	PyPy JIT only supported on these architectures

PYTHON_DESC=	Use Python-2.7 to translate (slowest)
PYPY_DESC=	Use PyPy to translate (fastest, highest memory usage)
PYPY_MINMEM_DESC=	Use PyPy to translate (lowest memory usage)
TRANS_DESC=	Translation method
LOCALBASE?=	/usr/local
.if exists(${LOCALBASE}/bin/pypy)
OPTIONS_SINGLE=	TRANS
OPTIONS_SINGLE_TRANS=	PYTHON PYPY PYPY_MINMEM
OPTIONS_DEFAULT+=	PYPY_MINMEM
.endif

CONFLICTS_INSTALL=	pypy3-[0-9]*

ALL_TARGET=	pypy-c
BUILD_WRKSRC=	${WRKDIR}/build/usession-release-${DISTVERSION}-0/testing_1
MAKE_ENV+=	PYPY_LOCALBASE=${LOCALBASE}
USE_LDCONFIG=	${PREFIX}/${PYPY_DIR}/bin
USES=		gettext-runtime tar:bzip2
WRKSRC=		${WRKDIR}/pypy-pypy-5f8302b8bf9f

.include ".${CURDIR}/bsd.pypy.mk"
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYPY} || defined(PYTHON_CMD)
PYTHON_CMD?=	${LOCALBASE}/bin/pypy
.elif ${PORT_OPTIONS:MPYPY_MINMEM}
PYTHON_CMD?=	${SETENV} PYPY_GC_MAX_DELTA=200MB ${LOCALBASE}/bin/pypy --jit loop_longevity=300
.else # if ${PORT_OPTIONS:MPYTHON}
USES+=		python:2,build
.endif

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
		${REINPLACE_CMD} -e 's|^%.o: %.c$$|.c.o:|g' ${BUILD_WRKSRC}/Makefile; \
	fi

post-build:
	${CP} ${BUILD_WRKSRC}/pypy-c ${BUILD_WRKSRC}/libpypy-c.so ${WRKSRC}/pypy/goal/

do-install:
	${SETENV} TMPDIR=${WRKDIR}/build \
		${PYTHON_CMD} ${WRKSRC}/pypy/tool/release/package.py --builddir ${WRKDIR}/build --archive-name ${PYPY_DIR} \
		--without-gdbm --without-sqlite3 --without-tk
	${EXTRACT_CMD} -C ${STAGEDIR}${PREFIX} -xf ${WRKDIR}/build/${PYPY_DIR}.tar.bz2
	${LN} -fs ../${PYPY_DIR}/bin/pypy ${STAGEDIR}${PREFIX}/bin/pypy

regression-test: build
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

pkg-plist: build
	${TAR} -tf ${WRKDIR}/build/${PYPY_DIR}.tar.bz2 > ${WRKDIR}/.plist-files-gen
	${REINPLACE_CMD} -e 's|^${PYPY_DIR}|%%PYPY_DIR%%|g' \
		-e 's|_${PYPY_BITS}_|_%%PYPY_BITS%%_|g' \
		-e 's|-${PYPY_CFFI_VER}|-%%PYPY_CFFI_VER%%|g' \
		-e '/\/$$/d' \
			${WRKDIR}/.plist-files-gen
	${ECHO} bin/pypy > ${WRKDIR}/pkg-plist
	${SORT} ${WRKDIR}/.plist-files-gen >> ${WRKDIR}/pkg-plist
	${CP} ${WRKDIR}/pkg-plist ${.CURDIR}/pkg-plist

.include <bsd.port.mk>
