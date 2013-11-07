# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME=	pypy
DISTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	lang python java
MASTER_SITES=	http://cdn.bitbucket.org/pypy/pypy/downloads/
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Fast, compliant implementation of the Python language

LICENSE=	MIT PSFL
LICENSE_COMB=	multi

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2 \
		libffi.so:${PORTSDIR}/devel/libffi \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3

CLI_DESC=	(BROKEN) Translate a CLI (.NET) based pypy
JVM_DESC=	(BROKEN) Translate a JVM (Java) based pypy
PYTHON_DESC=	Use Python-2.7 to translate (slowest)
PYPY_DESC=	Use PyPy to translate (fastest, highest memory usage)
PYPY_MINMEM_DESC=	Use PyPy to translate (lowest memory usage)
PYINST_DESC=	Translation method
SANDBOX_DESC=	Translate a sandboxed pypy
.if !defined(PYPY_INST)
OPTIONS_DEFINE+=	CLI JVM SANDBOX
.endif
LOCALBASE?=	/usr/local
.if exists(${LOCALBASE}/bin/pypy)
OPTIONS_SINGLE=	PYINST
OPTIONS_SINGLE_PYINST=	PYTHON PYPY PYPY_MINMEM
OPTIONS_DEFAULT+=	PYPY_MINMEM
.endif

CONFLICTS_INSTALL=	pypy-devel-[0-9]*

ALL_TARGET=	${PYPY_NAMES}
BUILD_WRKSRC=	${WRKDIR}
USE_BZIP2=	yes
USES=		compiler:c11 gettext iconv
MAKEFILE=	${FILESDIR}/Makefile
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
WRKSRC=		${WRKDIR}/${DISTNAME}

PYPY_VER=	${DISTVERSION:C|([0-9])\.([0-9]).*|\1.\2|}
PYTHON_IMPL_VER=	2.7
PYPY_LIBDIR=	lib/pypy-${PYPY_VER}
PYPY_INCLUDEDIR=	include/pypy-${PYPY_VER}
PYPYDIRS=	${PYPY_INCLUDEDIR} ${PYPY_LIBDIR}

PLIST_SUB+=	PYPY_LIBDIR=${PYPY_LIBDIR} \
		PYPY_INCLUDEDIR=${PYPY_INCLUDEDIR}

MAKE_ENV+=	DISTVERSION=${DISTVERSION} PYTHON_CMD=${PYTHON_CMD} \
		WRKSRC=${WRKSRC} PYPY_LOCALBASE=${LOCALBASE}

LOCALBASE_REFIX=	\
		${PYPY_LIBDIR}/lib_pypy/_sqlite3.py

.include <bsd.port.options.mk>
.include "${MASTERDIR}/files/bsd.pypy.inst.mk"

.if ${PORT_OPTIONS:MPYPY} || defined(PYTHON_CMD)
PYTHON_CMD?=	${LOCALBASE}/bin/pypy
.elif ${PORT_OPTIONS:MPYPY_MINMEM}
PYTHON_CMD?=	"${SETENV} PYPY_GC_MAX_DELTA=200MB ${LOCALBASE}/bin/pypy --jit loop_longevity=300"
.else
USE_PYTHON_BUILD=	-2.7
.endif

# List of PyPy instances
.if !defined(PYPY_INST)
PYPY_INST=	DEFAULT

.if ${PORT_OPTIONS:MSANDBOX}
PYPY_INST+=	SANDBOX
.endif

.if ${PORT_OPTIONS:MCLI}
PYPY_INST+=	CLI
.endif

.if ${PORT_OPTIONS:MJVM}
PYPY_INST+=	JVM
.endif

.endif # !defined(PYPY_INST)

MAKE_ENV+=	PYPY_INST="${PYPY_INST}"

.for inst in ${PYPY_INST}

PYPY_NAMES+=	${PYPY_${inst}_NAME}
PYPY_PRIMARY?=	${PYPY_${inst}_NAME}
MAKE_ENV+=	PYPY_${inst}_NAME="${PYPY_${inst}_NAME}" \
		PYPY_${inst}_OBJSPACE_ARGS="${PYPY_${inst}_OBJSPACE_ARGS}" \
		PYPY_${inst}_OPT="${PYPY_${inst}_OPT}" \
		PYPY_${inst}_TRANSLATE_ARGS="${PYPY_${inst}_TRANSLATE_ARGS}"

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

.if defined(WITH_BOEHM_GC)
LIB_DEPENDS+=	libgc.so:${PORTSDIR}/devel/boehm-gc
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
PYPY_BITS=	32
.elif ${ARCH} == "amd64"
PYPY_ARCH=	x86_64
PYPY_JITTABLE=	YES
PYPY_BITS=	64
.elif ${ARCH} == "powerpc"
PYPY_ARCH=	ppc_32
PYPY_BITS=	32
.elif ${ARCH} == "powerpc64"
PYPY_ARCH=	ppc_64
PYPY_BITS=	64
.else
PYPY_ARCH=	${ARCH}
PYPY_BITS=	32
.endif
PLIST_SUB+=	PYPY_ARCH="${PYPY_ARCH}"
PLIST_SUB+=	PYPY_BITS="${PYPY_BITS}"

.if !defined(PYPY_JITTABLE)
.for inst in ${PYPY_INST}
.if ${PYPY_${inst}_OPT} == jit
PYPY_${inst}_OPT=	2
.endif
.endfor # inst in ${PYPY_INST}
.endif # !defined(PYPY_JITTABLE)

# Translating requires a large amount of memory, with a two by two matrix
# requirement (bitness vs PYTHON_CMD).  A more refined matrix is possible based
# on optimisation level however this assumes "jit" is the preferred optimisation
# level.
#
.if ${PYPY_ARCH:M*64}
.  if ${PORT_OPTIONS:MPYPY}
# 64bit + pypy = 5.9 GiB
PYPY_TRANSLATION_MEMORY=	6138872
.  elif ${PORT_OPTIONS:MPYPY_MINMEM}
# 64bit + pypy (minimum memory) = 3.6GiB
PYPY_TRANSLATION_MEMORY=	3855204
.  else
# 64bit + python = 4.7 GiB
PYPY_TRANSLATION_MEMORY=	4957688
.  endif
# 64bit system += 366 MiB
PYPY_MINIMUM_MEMORY=	$$((${PYPY_TRANSLATION_MEMORY} + 374784))
.else
.  if ${PORT_OPTIONS:MPYPY}
# 32bit + pypy = 2.3GiB
PYPY_TRANSLATION_MEMORY=	2689508
.  elif ${PORT_OPTIONS:MPYPY_MINMEM}
# 32bit + pypy (minimum memory) = 2.2GiB
PYPY_TRANSLATION_MEMORY=	2329256
# 32bit + python = 2.3 GiB
PYPY_TRANSLATION_MEMORY=	2372640
.  endif
# 32bit system += 168 MiB
PYPY_MINIMUM_MEMORY=	$$((${PYPY_TRANSLATION_MEMORY} + 171787))
.endif

.if !defined(DISABLE_MAKE_JOBS) && ${PYPY_PRIMARY} != ${PYPY_NAMES}
PYPY_MEMORY_MULTIPLY=	`echo ${PYPY_NAMES} | wc -w`
.else
PYPY_MEMORY_MULTIPLY=	1
.endif

PYPY_IGNORE_MEMORY=	Memory checks non-fatal until revised figures are obtained.
PYPY_MEM_WARNING=	\
	${ECHO} "warn: this system has insufficient memory, expected at least $$((${PYPY_MINIMUM_MEMORY} / 1024 * ${PYPY_MEMORY_MULTIPLY} + 1))MiB RAM"
.if defined(PYTHON_CMD) && ${PYTHON_CMD:M*pypy*}
PYPY_MEM_WARNING+=	;\
	${ECHO} "warn: pypy is being used for translation, consider using cpython as it uses less memory"
.endif
.if ${PYPY_MEMORY_MULTIPLY} != 1
PYPY_MEM_WARNING+=	;\
	${ECHO} "warn: consider using -DDISABLE_MAKE_JOBS to serialise builds and to conserve memory"
.endif
.if !defined(PYPY_IGNORE_MEMORY)
PYPY_MEM_WARNING+=	;\
	${ECHO} "err: memory warnings are terminal, to overwrite this error define -DPYPY_IGNORE_MEMORY and try again"; \
	exit 1
.else
PYPY_MEM_WARNING+=	;\
	${ECHO} "warn: THIS SYSTEM MAY END UP SWAP THRASHING AD INFINITUM"
.endif

usage:
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
	@${ECHO} "	${FILESDIR}/bsd.pypy.inst.mk"
	@${ECHO}
	@${ECHO} "On a fast machine PyPy takes around 45 minutes to translate and compile,"
	@${ECHO} "however an average machine takes in excess of 4 hours, per instance."

pre-fetch:
	@${ECHO} Please see http://wiki.FreeBSD.org/PyPy for more details on the port or 'make usage' for a summary
	@if [ $$((`sysctl -n hw.physmem` / 1024)) -le $$((${PYPY_MINIMUM_MEMORY} * ${PYPY_MEMORY_MULTIPLY})) ]; then ${PYPY_MEM_WARNING}; fi

post-extract:
	${MKDIR} ${WRKSRC}/lib
	${LN} -s ${WRKSRC}/lib ${WRKDIR}/lib
	${MV} ${WRKSRC}/lib-python/${PYTHON_IMPL_VER} ${WRKSRC}/${PYPY_LIBDIR}
	${MV} ${WRKSRC}/lib_pypy ${WRKSRC}/${PYPY_LIBDIR}/

post-patch:
.for file in ${LOCALBASE_REFIX}
	${REINPLACE_CMD} 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/${file}
.endfor

do-configure:
	${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%PYPY_NAMES%%|${PYPY_NAMES}|g' \
		-e 's|%%PYPY_VER%%|${PYPY_VER}|g' \
		${FILESDIR}/use.pypy > ${WRKDIR}/use.pypy
	${CP} ${WRKDIR}/use.pypy ${PKGINSTALL}
	${CP} ${WRKDIR}/use.pypy ${PKGDEINSTALL}

post-build:
	-${FIND} ${WRKSRC}/${PYPY_LIBDIR} -type d | \
		${SETENV} PYTHON_PATH=${WRKSRC} ${XARGS} \
		${WRKDIR}/${PYPY_PRIMARY} -m compileall -fl
# UPDATING: check pypy/tool/release/package.py for list of cffi modules
.for mod in _sqlite3 _curses syslog
	${WRKDIR}/${PYPY_PRIMARY} -c 'import ${mod}'
.endfor
	${FIND} ${WRKSRC}/lib -name '*.orig' -delete -or \
		-name '*.bak' -delete -or \
		-name '*.c' -delete -or \
		-name '*.o' -delete
	${FIND} ${WRKDIR}/${_path:C/.*://}/ -name __pycache__ | \
		${XARGS} -n1 -I {} ${FIND} {} -depth 1 -type d | \
		${XARGS} ${RM} -r
	${MV} ${WRKSRC}/include ${WRKSRC}/include~
	${MKDIR} ${WRKSRC}/include
	${MV} ${WRKSRC}/include~ ${WRKSRC}/${PYPY_INCLUDEDIR}

do-install:
.for dir in ${PYPYDIRS}
	(cd ${WRKSRC}/${dir}; ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${dir})
.endfor
.for name in ${PYPY_NAMES:O}
	${STRIP_CMD} ${WRKDIR}/${name}
	${INSTALL_PROGRAM} ${WRKDIR}/${name} ${STAGEDIR}${PREFIX}/bin/${name}-${PYPY_VER}
	${ECHO} bin/${name}-${PYPY_VER} >> ${TMPPLIST}
.endfor

post-install:
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

test: patch
.for inst in ${PYPY_INST}
	@${WHICH} ${PYPY_${inst}_NAME} > /dev/null 2>&1 || (${ECHO} "Unable to find ${PYPY_${inst}_NAME}, please install port first!"; exit 1)
	(cd ${WRKSRC}; ${PYPY_${inst}_NAME} pypy/test_all.py ${PYPY_LIBDIR}/lib_pypy/pypy_test pypy/module)
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
		-e 's|_${PYPY_BITS}_|_%%PYPY_BITS%%_|g' \
			${WRKDIR}/.plist-files-gen
	${REINPLACE_CMD} -e 's|^${PYPY_LIBDIR}|@dirrm %%PYPY_LIBDIR%%|g' \
		-e 's|^${PYPY_INCLUDEDIR}|@dirrm %%PYPY_INCLUDEDIR%%|g' \
			${WRKDIR}/.plist-dirs-gen
	${SORT} ${WRKDIR}/.plist-files-gen > ${WRKDIR}/pkg-plist
	${SORT} -r ${WRKDIR}/.plist-dirs-gen >> ${WRKDIR}/pkg-plist
	${CP} ${WRKDIR}/pkg-plist ${.CURDIR}/pkg-plist

.include <bsd.port.mk>
