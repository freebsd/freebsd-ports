# New ports collection Makefile for:	pypy
# Date created:				2011/05/17
# Whom:					David Naylor <naylor.b.david@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pypy
DISTVERSION=	1.9
PORTREVISION=	2
CATEGORIES=	lang python java
MASTER_SITES=	https://bitbucket.org/pypy/pypy/get/
DISTNAME=	release-${DISTVERSION}
DIST_SUBDIR=	pypy

MAINTAINER=	naylor.b.david@gmail.com
COMMENT=	PyPy is a fast, compliant implementation of the Python language

LICENSE=	MIT PSFL
LICENSE_COMB=	multi

LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2 \
		ffi:${PORTSDIR}/devel/libffi

OPTIONS_DEFINE=	SANDBOX
SANDBOX_DESC=	"Translate a sandboxed pypy"

BUILD_WRKSRC=	${WRKDIR}
USE_BZIP2=	yes
USE_ICONV=	yes
USE_GETTEXT=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
WRKSRC=		${WRKDIR}/pypy-pypy-341e1e3821ff

PYPY_VER=	${DISTVERSION}
PYTHON_IMPL_VER=	2.7
PYPY_LIBDIR=	lib/pypy${PYPY_VER}
PYPY_INCLUDEDIR=	include/pypy${PYPY_VER}
PYPYDIRS=	${PYPY_INCLUDEDIR} ${PYPY_LIBDIR}

PLIST_SUB+=	PYPY_LIBDIR=${PYPY_LIBDIR} \
		PYPY_INCLUDEDIR=${PYPY_INCLUDEDIR}

MAKE_ENV+=	PYPY_LOCALBASE=${LOCALBASE}
.if exists(/usr/bin/clang)
MAKE_ARGS+=	CC=clang
MAKE_JOBS_SAFE=	yes
.endif

# XXX !.include <bsd.port.pre.mk> as USE_* need to be set prior
.include <bsd.port.options.mk>
.include "${.CURDIR}/files/bsd.pypy.inst.mk"

.if defined(PACKAGE_BUILDING)
MANUAL_PACKAGE_BUILD=	fails to finish compilation on pointyhat, reason unknown
.endif

# List of PyPy instances
.if !defined(PYPY_INST)
PYPY_INST=	DEFAULT

.if ${PORT_OPTIONS:MSANDBOX}
PYPY_INST+=	SANDBOX
.endif

.endif # !defined(PYPY_INST)

PYPY_NAMES=
.for inst in ${PYPY_INST}

PYPY_NAMES+=	${PYPY_${inst}_NAME}
PYPY_PRIMARY?=	${PYPY_${inst}_NAME}

# Check if the boehm GC will be used
.if ${PYPY_${inst}_OPT} == 0 || ${PYPY_${inst}_OPT} == 1 || ${PYPY_${inst}_OPT} == size
WITH_BOEHM_GC=	yes
.endif

# Check if the CLI (mono) backend will be used
.if !empty(PYPY_${inst}_TRANSLATE_ARGS:M--backend=cli)
WITH_CLI=	yes
.endif

# Check if the JVM (java) backend will be used
.if !empty(PYPY_${inst}_TRANSLATE_ARGS:M--backend=jvm)
WITH_JVM=	yes
.endif

.endfor # inst in ${PYPY_INST}

# Use pypy if it is installed, else use python (to translate)
.if !defined(PY)
.if !defined(PYPY)
.if ${PYPY_PRIMARY} == pypy
PYPY!=		${WHICH} ${PYPY_PRIMARY} 2> /dev/null || true
.else
PYPY!=		${WHICH} ${PYPY_PRIMARY} 2> /dev/null || ${WHICH} pypy 2> /dev/null || true
.endif
.endif # !defined(PYPY)

.if exists(${PYPY})
PY=		${PYPY}
.else
USE_PYTHON_BUILD=	2.5+
PY=		${PYTHON_CMD}
.endif
.endif # !defined(PY)

.if defined(WITH_BOEHM_GC)
LIB_DEPENDS+=	gc.1:${PORTSDIR}/devel/boehm-gc
.endif

.if defined(WITH_CLI)
BUILD_DEPENDS+=	mono:${PORTSDIR}/lang/mono
RUN_DEPENDS+=	mono:${PORTSDIR}/lang/mono
ONLY_FOR_ARCHS=	i386 powerpc
ONLY_FOR_ARCHS_REASON=	only translates on 32bit systems
BROKEN=		CLI backend broken, unsupported upstream
.endif

.if defined(WITH_JVM)
USE_JAVA=	yes
JAVA_VERSION=	1.5+
ONLY_FOR_ARCHS=	i386 powerpc
ONLY_FOR_ARCHS_REASON=	only translates on 32bit systems
BROKEN=		JVM backend broken, partially supported upstream
.endif

# Translate FreeBSD ARCH types to PyPy ARCH types
# Pypy officially only supports i386 and amd64, the other platforms are
# untested (and do not have jit support).
.if ${ARCH} == "i386"
PYPY_ARCH=	x86_32
PYPY_JITTABLE=	YES
.elif ${ARCH} == "amd64"
PYPY_ARCH=	x86_64
PYPY_JITTABLE=	YES
.elif ${ARCH} == "powerpc"
PYPY_ARCH=	ppc_32
.elif ${ARCH} == "powerpc64"
PYPY_ARCH=	ppc_64
.else
PYPY_ARCH=	${ARCH}
.endif
PLIST_SUB+=	PYPY_ARCH="${PYPY_ARCH}"

.if !defined(PYPY_JITTABLE)
.for inst in ${PYPY_INST}
.if ${PYPY_${inst}_OPT} == jit
PYPY_${inst}_OPT=	2
.endif
.endfor # inst in ${PYPY_INST}
.endif # !defined(PYPY_JITTABLE)

pre-fetch:
	@${ECHO} "PyPy requires a large amount of free RAM and time to translate and compile."
	@${ECHO}
	@${ECHO} "To translate, PyPy requires on 32bit 3G (min 2G) free RAM and on 64bit"
	@${ECHO} "6G (min 4G) free RAM.  Also, to compile, PyPy on amd64 gcc requires an"
	@${ECHO} "extra 4G however clang only requires 400M (CC=clang) but clang is slower"
	@${ECHO} "in compiling PyPy."
	@${ECHO}
	@${ECHO} "If memory is in short supply consider using a lower optimisation level"
	@${ECHO} "(e.g. PYPY_DEFAULT_OPT=2) however that makes PyPy much slower.  Also,"
	@${ECHO} "consider forcing the build to use python (-DPYPY) however that makes the"
	@${ECHO} "build much slower."
	@${ECHO}
	@${ECHO} "PyPy supports a large number of parameters and customisations.  This port"
	@${ECHO} "supports building multiple instances of PyPy, for example:"
	@${ECHO} "PYPY_INST=	SANDBOX CUSTOM"
	@${ECHO} "PYPY_CUSTOM_NAME=		pypy-custom"
	@${ECHO} "PYPY_CUSTOM_TRANSLATE_ARGS=	--gcrootfinder=shadowstack --gc=generation"
	@${ECHO} "PYPY_CUSTOM_OPT=		0"
	@${ECHO} "PYPY_CUSTOM_OBJSPACE_ARGS=	--no-objspace-usepycfiles --objspace=thunk"
	@${ECHO} "will produce two binaries named 'pypy-sandbox' (SANDBOX instance) and"
	@${ECHO} "'pypy-custom' (CUSTOM instance)."
	@${ECHO} "See for a list of parameters:"
	@${ECHO} "	http://readthedocs.org/docs/pypy/latest/config/index.html"
	@${ECHO} "See for predefined instances:"
	@${ECHO} "	${.CURDIR}/files/bsd.pypy.inst.mk"
	@${ECHO}
	@${ECHO} "On a fast machine PyPy takes around 45 minutes to translate and compile,"
	@${ECHO} "however an average machine takes in excess of 4 hours, per instance."
.if !defined(PYPY_IGNORE_MEM) && (${PYPY_ARCH} == "x86_32" || ${PYPY_ARCH} == "ppc_32")
	@if [ $$((`sysctl -n hw.physmem` / 1024 / 1024)) -le 2000 ]; then \
		${ECHO}; \
		${ECHO} "err: this system has insufficient memory, expected at least 2G RAM",; \
		${ECHO} "err: to overwrite this error define -DPYPY_IGNORE_MEM and try again"; \
		exit 1; \
	fi
.elif !defined(PYPY_IGNORE_MEM)
	@if [ $$((`sysctl -n hw.physmem` / 1024 / 1024)) -le 4000 ]; then \
		${ECHO}; \
		${ECHO} "err: this system has insufficient memory, expected at least 4G RAM",; \
		${ECHO} "err: to overwrite this error define -DPYPY_IGNORE_MEM and try again"; \
		exit 1; \
	fi
.endif
	@sleep 1

post-extract:
	${MKDIR} ${WRKSRC}/lib
	${MV} ${WRKSRC}/lib-python/${PYTHON_IMPL_VER} ${WRKSRC}/${PYPY_LIBDIR}
	${MV} ${WRKSRC}/lib_pypy ${WRKSRC}/${PYPY_LIBDIR}/

post-patch:
	${FIND} ${WRKSRC}/lib -name '*.orig' -delete

do-configure:
	${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%PYPY_NAMES%%|${PYPY_NAMES}|g' \
		-e 's|%%PYPY_VER%%|${PYPY_VER}|g' \
		${FILESDIR}/use.pypy > ${WRKDIR}/use.pypy
	${CP} ${WRKDIR}/use.pypy ${PKGINSTALL}
	${CP} ${WRKDIR}/use.pypy ${PKGDEINSTALL}
	${ECHO} "all: ${PYPY_NAMES}" > ${WRKDIR}/Makefile
	${ECHO} >> ${WRKDIR}/Makefile
.for inst in ${PYPY_INST}
	${ECHO} "${PYPY_${inst}_NAME}: build_${PYPY_${inst}_NAME}/usession-release-${DISTVERSION}-0/testing_1/pypy-c" >> ${WRKDIR}/Makefile
	${ECHO} "	${CP} build_${PYPY_${inst}_NAME}/usession-release-${DISTVERSION}-0/testing_1/pypy-c ${PYPY_${inst}_NAME}" >> ${WRKDIR}/Makefile
	${ECHO} >> ${WRKDIR}/Makefile
	${ECHO} ".done_translate_${PYPY_${inst}_NAME}:" >> ${WRKDIR}/Makefile
	${ECHO} "	${RM} -rf build_${PYPY_${inst}_NAME}" >> ${WRKDIR}/Makefile
	${ECHO} "	${MKDIR} build_${PYPY_${inst}_NAME}" >> ${WRKDIR}/Makefile
	${ECHO} "	(cd ${WRKSRC}/pypy/translator/goal; \
				${SETENV} TMPDIR=${WRKDIR}/build_${PYPY_${inst}_NAME} \
				${PY} translate.py --source ${PYPY_${inst}_TRANSLATE_ARGS} -O${PYPY_${inst}_OPT} \
					targetpypystandalone.py ${PYPY_${inst}_OBJSPACE_ARGS} )" >> ${WRKDIR}/Makefile
	${ECHO} "	${TOUCH} .done_translate_${PYPY_${inst}_NAME}" >> ${WRKDIR}/Makefile
	${ECHO} >> ${WRKDIR}/Makefile
	${ECHO} "build_${PYPY_${inst}_NAME}/usession-release-${DISTVERSION}-0/testing_1/pypy-c: .done_translate_${PYPY_${inst}_NAME}" >> ${WRKDIR}/Makefile
	${ECHO} "	${REINPLACE_CMD} -e 's|^%.o: %.c\$$\$$|.c.o:|g' build_${PYPY_${inst}_NAME}/usession-release-${DISTVERSION}-0/testing_1/Makefile" >> ${WRKDIR}/Makefile
	${ECHO} "	${MAKE} -C build_${PYPY_${inst}_NAME}/usession-release-${DISTVERSION}-0/testing_1 pypy-c" >> ${WRKDIR}/Makefile
	${ECHO} >> ${WRKDIR}/Makefile
.endfor

post-build:
	-${FIND} ${WRKSRC}/${PYPY_LIBDIR} -type d | \
		${SETENV} PYTHON_PATH=${WRKSRC} ${XARGS} \
		${WRKDIR}/${PYPY_PRIMARY} -m compileall -fl
	${MV} ${WRKSRC}/include ${WRKSRC}/include~
	${MKDIR} ${WRKSRC}/include
	${MV} ${WRKSRC}/include~ ${WRKSRC}/${PYPY_INCLUDEDIR}

do-install:
.for dir in ${PYPYDIRS}
	(cd ${WRKSRC}/${dir}; ${COPYTREE_SHARE} . ${PREFIX}/${dir})
.endfor
.for name in ${PYPY_NAMES:O}
	${INSTALL_PROGRAM} ${WRKDIR}/${name} ${PREFIX}/bin/${name}${PYPY_VER}
	${ECHO} bin/${name}${DISTVERSION} >> ${TMPPLIST}
.endfor

post-install:
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

test: patch
.for inst in ${PYPY_INST}
	@${WHICH} ${PYPY_${inst}_NAME} > /dev/null 2>&1 || (${ECHO} "Unable to find ${PYPY_${inst}_NAME}, please install port first!"; exit 1)
	(${CD} ${PYPY_LIBDIR}; ${PYPY_${inst}_NAME} ../../pypy/test_all.py)
.endfor

pkg-plist: build
	${RM} -f ${WRKDIR}/.plist-files-gen ${WRKDIR}/.plist-dirs-gen
.for dir in ${PYPYDIRS}
	cd ${WRKSRC} && ${FIND} ${dir} -type f >> ${WRKDIR}/.plist-files-gen
	cd ${WRKSRC} && ${FIND} ${dir} -type d >> ${WRKDIR}/.plist-dirs-gen
.endfor
	${REINPLACE_CMD} -e 's|^${PYPY_LIBDIR}|%%PYPY_LIBDIR%%|g' \
		-e 's|^${PYPY_INCLUDEDIR}|%%PYPY_INCLUDEDIR%%|g' \
		-e 's|${PYPY_ARCH}|%%PYPY_ARCH%%|g' \
			${WRKDIR}/.plist-files-gen
	${REINPLACE_CMD} -e 's|^${PYPY_LIBDIR}|@dirrm %%PYPY_LIBDIR%%|g' \
		-e 's|^${PYPY_INCLUDEDIR}|@dirrm %%PYPY_INCLUDEDIR%%|g' \
			${WRKDIR}/.plist-dirs-gen
	${SORT} ${WRKDIR}/.plist-files-gen > ${WRKDIR}/pkg-plist
	${SORT} -r ${WRKDIR}/.plist-dirs-gen >> ${WRKDIR}/pkg-plist
	${CP} ${WRKDIR}/pkg-plist ${.CURDIR}/pkg-plist

.include <bsd.port.mk>
