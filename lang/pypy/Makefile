# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME?=	pypy
CATEGORIES=	lang python
MASTER_SITES=	https://bitbucket.org/pypy/pypy/downloads/ http://buildbot.pypy.org/mirror/
DISTNAME?=	${PORTNAME}2-v${DISTVERSION}-src

MAINTAINER=	python@FreeBSD.org
COMMENT=	Fast, compliant implementation of the Python language

LICENSE=	MIT PSFL
LICENSE_COMB=	multi
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libffi.so:devel/libffi
TEST_DEPENDS=	${LOCALBASE}/${PYPY_DIR}/lib_pypy/_gdbm_cffi.${PYPY_CFFI_VER}.so:databases/pypy-gdbm \
		${LOCALBASE}/${PYPY_DIR}/lib_pypy/_sqlite3_cffi.${PYPY_CFFI_VER}.so:databases/pypy-sqlite3 \
		${LOCALBASE}/${PYPY_DIR}/lib_pypy/_tkinter/tklib_cffi.${PYPY_CFFI_VER}.so:x11-toolkits/pypy-tkinter

ONLY_FOR_ARCHS?=	amd64 armv6 armv7 i386 powerpc64
ONLY_FOR_ARCHS_REASON?=	PyPy JIT only supported on these architectures

BROKEN_armv6=		fails to package: pypy_objspace_std.c: Crash in JIT!
BROKEN_armv7=		fails to package: pypy_objspace_std.c: Crash in JIT!
BROKEN_powerpc64=	fails to compile: platcheck_109.c: fatal error: linux/auxvec.h: No such file or directory

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

ALL_TARGET=	${PORTNAME}-c
BUILD_WRKSRC?=	${WRKDIR}/build/usession-release-pypy2.7-v${DISTVERSION}-0/testing_1
MAKE_ENV+=	PYPY_LOCALBASE=${LOCALBASE} LDSHARED="${CC} -shared"
PACKAGE_ARGS?=	--without-gdbm --without-sqlite3 --without-tk
USE_LDCONFIG=	${PREFIX}/${PYPY_DIR}/bin
USES=		gettext-runtime gmake shebangfix ssl tar:bzip2
SHEBANG_FILES?=	lib-python/2.7/plat-mac/appletrunner.py \
		lib-python/2.7/plat-mac/bundlebuilder.py \
		lib-python/2.7/keyword.py \
		lib-python/2.7/test/regrtest.py \
		lib-python/2.7/test/pystone.py \
		lib-python/2.7/test/curses_tests.py \
		lib-python/2.7/test/re_tests.py \
		lib-python/2.7/test/crashers/recursive_call.py \
		lib-python/2.7/UserString.py \
		lib-python/2.7/pdb.py \
		lib-python/2.7/mimify.py \
		lib-python/2.7/pydoc.py \
		lib-python/2.7/uu.py \
		lib-python/2.7/trace.py \
		lib-python/2.7/platform.py \
		lib-python/2.7/profile.py \
		lib-python/2.7/tabnanny.py \
		lib-python/2.7/lib2to3/tests/pytree_idempotency.py \
		lib-python/2.7/lib2to3/tests/data/false_encoding.py \
		lib-python/2.7/lib2to3/tests/data/different_encoding.py \
		lib-python/2.7/lib2to3/pgen2/token.py \
		lib-python/2.7/encodings/rot_13.py \
		lib-python/2.7/base64.py \
		lib-python/2.7/webbrowser.py \
		lib-python/2.7/idlelib/PyShell.py \
		lib-python/2.7/cgi.py \
		lib-python/2.7/symbol.py \
		lib-python/2.7/cProfile.py \
		lib-python/2.7/smtpd.py \
		lib-python/2.7/quopri.py \
		lib-python/2.7/timeit.py \
		lib-python/2.7/smtplib.py

python_OLD_CMD=	/usr/local/bin/python
python_CMD=	${PREFIX}/bin/${PORTNAME}

.if ${PORTNAME} != pypy
PYPY_BUILD_DEPENDS=	pypy:lang/pypy
PYPY_MINMEM_BUILD_DEPENDS=	pypy:lang/pypy
.endif
PYPY_VARS=	PYTHON_CMD=${LOCALBASE}/bin/pypy
PYPY_MINMEM_VARS=	PYTHON_CMD="${SETENV} PYPY_GC_MAX_DELTA=200MB ${LOCALBASE}/bin/pypy --jit loop_longevity=300"
PYTHON_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycparser>=2.10:devel/py-pycparser@${PY_FLAVOR}
PYTHON_USES=	python:2.7,build

DESCR=		${.CURDIR}/pkg-descr
DISTINFO_FILE=	${.CURDIR}/distinfo
MASTERDIR?=	${.CURDIR}
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/bsd.pypy.mk"
.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && (${OSVERSION} < 1100000 || (${ARCH} != i386 && ${ARCH} != amd64))
PYPY_ARGS=	--withoutmod-_vmprof
.else
LIB_DEPENDS+=	libunwind.so:devel/libunwind
.endif

post-extract:
	${FIND} ${WRKSRC} -name '*.swn' -delete

pre-build:
	if [ ! -f ${BUILD_WRKSRC}/Makefile ]; then \
		${RM} -r ${WRKDIR}/build; \
		${MKDIR} ${WRKDIR}/build; \
		(cd ${WRKSRC}/pypy/goal; \
			${SETENV} ${MAKE_ENV} TMPDIR=${WRKDIR}/build \
			${PYTHON_CMD} ../../rpython/bin/rpython --source -Ojit targetpypystandalone.py ${PYPY_ARGS}); \
	fi

post-build:
	${CP} ${BUILD_WRKSRC}/${PORTNAME}-c ${BUILD_WRKSRC}/lib${PORTNAME}-c.so ${WRKSRC}/pypy/goal/

do-install:
	${SETENV} ${MAKE_ENV} TMPDIR=${WRKDIR}/build \
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

pkg-plist: stage
	${TAR} -tf ${WRKDIR}/build/${PYPY_DIR}.tar.bz2 > ${WRKDIR}/.plist-files-gen
	${REINPLACE_CMD} -e 's|^${PYPY_DIR}|%%PYPY_DIR%%|g' \
		-e 's|${PYPY_CFFI_VER}|%%PYPY_CFFI_VER%%|g' \
		-e 's/\(.*\/__pycache__\)\/$$/@dir \1/g' \
		-e '/\/$$/d' \
			${WRKDIR}/.plist-files-gen
	${ECHO} bin/${PORTNAME} > ${WRKDIR}/pkg-plist
	${SORT} ${WRKDIR}/.plist-files-gen | ${GREP} -v '\.orig' >> ${WRKDIR}/pkg-plist
	${CP} ${WRKDIR}/pkg-plist ${.CURDIR}/pkg-plist

.include <bsd.port.post.mk>
