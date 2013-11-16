# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME=	pypy
DISTVERSION=	2.2
CATEGORIES=	lang python
MASTER_SITES=	http://cdn.bitbucket.org/pypy/pypy/downloads/ https://bitbucket.org/pypy/pypy/downloads/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Fast, compliant implementation of the Python language

LICENSE=	MIT PSFL
LICENSE_COMB=	multi

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2 \
		libffi.so:${PORTSDIR}/devel/libffi \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3

PYTHON_DESC=	Use Python-2.7 to translate (slowest)
PYPY_DESC=	Use PyPy to translate (fastest, highest memory usage)
PYPY_MINMEM_DESC=	Use PyPy to translate (lowest memory usage)
PYINST=		PyPy instances
SANDBOX_DESC=	Translate a sandboxed pypy
TRANS_DESC=	Translation method
.if !defined(PYPY_INST)
OPTIONS_GROUP=	PYINST
OPTIONS_GROUP_PYINST=	SANDBOX
.endif
LOCALBASE?=	/usr/local
.if exists(${LOCALBASE}/bin/pypy)
OPTIONS_SINGLE=	TRANS
OPTIONS_SINGLE_TRANS=	PYTHON PYPY PYPY_MINMEM
OPTIONS_DEFAULT+=	PYPY_MINMEM
.endif

CONFLICTS_INSTALL=	pypy-[0-9]*
LATEST_LINK=	${PORTNAME}-devel

ALL_TARGET=	${PYPY_NAMES}
BUILD_WRKSRC=	${WRKDIR}
DATE=		20130810
USE_BZIP2=	yes
USES=		compiler:c11 gettext iconv
MAKEFILE=	${FILESDIR}/Makefile
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

PYPY_VER=	${DISTVERSION:C|([0-9])\.([0-9]).*|\1.\2|}
PYTHON_IMPL_VER=	2.7
PYPY_LIBDIR=	lib/${PORTNAME}-${PYPY_VER}
PYPY_INCLUDEDIR=	include/${PORTNAME}-${PYPY_VER}
PYPYDIRS=	lib-python/${PYTHON_IMPL_VER}:${PYPY_LIBDIR} \
		lib_pypy:${PYPY_LIBDIR}/lib_pypy \
		include:${PYPY_INCLUDEDIR}

PLIST_SUB+=	PYPY_LIBDIR=${PYPY_LIBDIR} \
		PYPY_INCLUDEDIR=${PYPY_INCLUDEDIR}

MAKE_ENV+=	DISTVERSION=${DISTVERSION} PYTHON_CMD=${PYTHON_CMD} \
		WRKSRC=${WRKSRC} PYPY_LOCALBASE=${LOCALBASE}

LOCALBASE_REFIX=	\
		lib_pypy/_sqlite3.py

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

.endfor # inst in ${PYPY_INST}

.if defined(WITH_BOEHM_GC)
LIB_DEPENDS+=	libgc.so:${PORTSDIR}/devel/boehm-gc
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
PLIST_SUB+=	PYPY_VER="${PYPY_VER:C/\.//}"

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
PYPY_TRANSLATION_MEMORY=	6062436
.  elif ${PORT_OPTIONS:MPYPY_MINMEM}
# 64bit + pypy (minimum memory) = 3.6GiB
PYPY_TRANSLATION_MEMORY=	3729228
.  else
# 64bit + python = 4.7 GiB
PYPY_TRANSLATION_MEMORY=	4662460
.  endif
# 64bit system += 366 MiB
PYPY_MINIMUM_MEMORY=	$$((${PYPY_TRANSLATION_MEMORY} + 374784))
.else
.  if ${PORT_OPTIONS:MPYPY}
# 32bit + pypy = 2.3GiB
PYPY_TRANSLATION_MEMORY=	2523868
.  elif ${PORT_OPTIONS:MPYPY_MINMEM}
# 32bit + pypy (minimum memory) = 2.2GiB
PYPY_TRANSLATION_MEMORY=	2246768
# 32bit + python = 2.3 GiB
PYPY_TRANSLATION_MEMORY=	2523868
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
.if ${PORT_OPTIONS:MPYPY}
PYPY_MEM_WARNING+=	;\
	${ECHO} "warn: PyPy is being used for translation, consider using Python or PyPy (minimum memory) as it uses less memory"
.elif ${PORT_OPTIONS:MPYTHON}
PYPY_MEM_WARNING+=	;\
	${ECHO} "warn: Python is being used for translation, consider using PyPy (minimum memory) as it uses less memory"
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
.for _path in ${PYPYDIRS}
	${MKDIR} ${WRKDIR}/`${DIRNAME} ${_path:C/.*://}`
	${LN} -s ${WRKSRC}/${_path:C/:.*//} ${WRKDIR}/${_path:C/.*://}
.endfor
	${LN} -s ${WRKDIR}/lib ${WRKSRC}/lib

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
# UPDATING: check pypy/tool/release/package.py for list of cffi modules
.for mod in _sqlite3 _curses syslog
	${WRKDIR}/${PYPY_PRIMARY} -c 'import ${mod}'
.endfor
	${STRIP_CMD} ${WRKDIR}/${PYPY_LIBDIR}/lib_pypy/__pycache__/_cffi__*.pypy-${PYPY_VER:C/\.//}.so
.for _path in ${PYPYDIRS}
	-${FIND} ${WRKDIR}/${_path:C/.*://}/ -type d | \
		${XARGS} -n1 ${WRKDIR}/${PYPY_PRIMARY} -m compileall -fl
	${FIND} ${WRKDIR}/${_path:C/.*://}/ -name '*.orig' -delete -or \
		-name '*.bak' -delete -or \
		-name '*.c' -delete -or \
		-name '*.o' -delete
	${FIND} ${WRKDIR}/${_path:C/.*://}/ -name __pycache__ | \
		${XARGS} -n1 -I {} ${FIND} {} -depth 1 -type d | \
		${XARGS} ${RM} -r
.endfor

do-install:
.for _path in ${PYPYDIRS}
	${RM} -f ${STAGEDIR}${PREFIX}/${_path:C/.*://}
	(cd ${WRKSRC}/${_path:C/:.*//}; ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${_path:C/.*://})
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
	(cd ${WRKSRC}; ${PYPY_${inst}_NAME} pypy/test_all.py lib_pypy/pypy_test pypy/module)
.endfor

pkg-plist: build
	${RM} -f ${WRKDIR}/.plist-files-gen ${WRKDIR}/.plist-dirs-gen
.for path in ${PYPYDIRS}
	cd ${WRKDIR} && ${FIND} ${path:C/.*://}/ -type f >> ${WRKDIR}/.plist-files-gen
	cd ${WRKDIR} && ${FIND} ${path:C/.*://}/ -type d | ${SED} 's|/$$||' >> ${WRKDIR}/.plist-dirs-gen
.endfor
	${REINPLACE_CMD} -e 's|^${PYPY_LIBDIR}|%%PYPY_LIBDIR%%|g' \
		-e 's|^${PYPY_INCLUDEDIR}|%%PYPY_INCLUDEDIR%%|g' \
		-e 's|${PYPY_ARCH}|%%PYPY_ARCH%%|g' \
		-e 's|_${PYPY_BITS}_|_%%PYPY_BITS%%_|g' \
		-e 's|-${PYPY_VER:C/\.//}\.|-%%PYPY_VER%%.|g' \
			${WRKDIR}/.plist-files-gen
	${REINPLACE_CMD} -e 's|^${PYPY_LIBDIR}|@dirrm %%PYPY_LIBDIR%%|g' \
		-e 's|^${PYPY_INCLUDEDIR}|@dirrm %%PYPY_INCLUDEDIR%%|g' \
			${WRKDIR}/.plist-dirs-gen
	${SORT} ${WRKDIR}/.plist-files-gen > ${WRKDIR}/pkg-plist
	${SORT} -r ${WRKDIR}/.plist-dirs-gen >> ${WRKDIR}/pkg-plist
	${REINPLACE_CMD} \
		-e 's|^@dirrm %%PYPY_LIBDIR%%/site-packages$$|@dirrmtry %%PYPY_LIBDIR%%/site-packages|' \
		-e 's|^@dirrm %%PYPY_LIBDIR%%$$|@dirrmtry %%PYPY_LIBDIR%%|' \
		-e 's|^@dirrm %%PYPY_INCLUDEDIR%%$$|@dirrmtry %%PYPY_INCLUDEDIR%%|' \
			${WRKDIR}/pkg-plist
	${CP} ${WRKDIR}/pkg-plist ${.CURDIR}/pkg-plist

.include <bsd.port.mk>
