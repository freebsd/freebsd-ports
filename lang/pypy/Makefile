# New ports collection Makefile for:	pypy
# Date created:				2011/05/17
# Whom:					David Naylor <naylor.b.david@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pypy
DISTVERSION=	1.7
CATEGORIES=	lang python
MASTER_SITES=	https://bitbucket.org/pypy/pypy/get/
DISTNAME=	release-${DISTVERSION}
DIST_SUBDIR=	pypy

MAINTAINER=	naylor.b.david@gmail.com
COMMENT=	PyPy is a fast, compliant implementation of the Python language

LICENSE=	MIT PSFL
LICENSE_COMB=	multi

LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2 \
		ffi:${PORTSDIR}/devel/libffi

OPTIONS=	SANDBOX "Translate a sandboxed pypy" OFF

BUILD_WRKSRC=	${WRKDIR}
USE_BZIP2=	yes
USE_ICONV=	yes
USE_GETTEXT=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
WRKSRC=		${WRKDIR}/pypy-pypy-release-${DISTVERSION}

PYPYDIRS=	include lib-python lib_pypy site-packages
PYPYPREFIX?=	${PREFIX}/${PORTNAME}-${DISTVERSION}
PLIST_SUB+=	PYPYPREFIX="${PYPYPREFIX:S|^${PREFIX}/||g}" \
		DISTVERSION="${DISTVERSION}"

MAKE_ENV+=	PYPY_LOCALBASE=${LOCALBASE}

.include <${.CURDIR}/files/bsd.pypy.inst.mk>
.include <bsd.port.options.mk>

# List of PyPy instances
.if !defined(PYPY_INST)
PYPY_INST=	DEFAULT

.if defined(WITH_SANDBOX)
PYPY_INST+=	SANDBOX
.endif
.endif

PYPY_NAMES=
.for inst in ${PYPY_INST}

PYPY_NAMES+=	${PYPY_${inst}_NAME}
PYPY_PRIMARY?=	${PYPY_${inst}_NAME}

.if ${PYPY_${inst}_OPT} == 0 || ${PYPY_${inst}_OPT} == 1 || ${PYPY_${inst}_OPT} == size
WITH_BOEHM_GC=	yes
.endif

.endfor

# Use pypy if it is installed, else use python (to translate)
.if !defined(PY)
.if !defined(PYPY)
PYPY!=		${WHICH} ${PYPY_PRIMARY} 2> /dev/null || true
.endif
.if exists(${PYPY})
PY=		${PYPY}
.else
USE_PYTHON_BUILD=	2.5+
PY=		${PYTHON_CMD}
.endif
.endif

.if defined(WITH_BOEHM_GC)
LIB_DEPENDS+=	gc.1:${PORTSDIR}/devel/boehm-gc
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
.endfor
.endif

pre-fetch:
	@${ECHO} "PyPy requires a large amount of free RAM and time to translate and compile."
	@${ECHO}
	@${ECHO} "To translate, PyPy requires on i386 3G (min 2G) free RAM and on amd64"
	@${ECHO} "6G (min 4G) free RAM.  Also, to compile, PyPy on amd64 gcc requires an"
	@${ECHO} "extra 4G however clang only requires 400M (CC=clang) but clang is slower"
	@${ECHO} "in compiling PyPy."
	@${ECHO}
	@${ECHO} "If memory is in short supply consider using a lower optimisation level"
	@${ECHO} "(e.g. PYPY_DEFAULT_OPT=2) however that makes PyPy much slower.  Also,"
	@${ECHO} "consider forcing the build to use python (-DPYPY) however that makes the"
	@${ECHO} "build much slower."
	@${ECHO}
	@${ECHO} "PyPy supports a large number of paramaters and customisations.  This port"
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
	@sleep 1

do-configure:
	${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%PYPYPREFIX%%|${PYPYPREFIX}|g' \
		-e 's|%%PYPY_NAMES%%|${PYPY_NAMES}|g' \
		${FILESDIR}/use.pypy > ${WRKDIR}/use.pypy
	${CP} ${WRKDIR}/use.pypy ${PKGINSTALL}
	${CP} ${WRKDIR}/use.pypy ${PKGDEINSTALL}
	${ECHO} "all: ${PYPY_NAMES}" > ${WRKDIR}/Makefile
	${ECHO} >> ${WRKDIR}/Makefile
.for inst in ${PYPY_INST}
	${ECHO} "${PYPY_${inst}_NAME}: build_${PYPY_${inst}_NAME}/usession-unknown-0/testing_1/pypy-c" >> ${WRKDIR}/Makefile
	${ECHO} "	${CP} build_${PYPY_${inst}_NAME}/usession-unknown-0/testing_1/pypy-c ${PYPY_${inst}_NAME}" >> ${WRKDIR}/Makefile
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
	${ECHO} "build_${PYPY_${inst}_NAME}/usession-unknown-0/testing_1/pypy-c: .done_translate_${PYPY_${inst}_NAME}" >> ${WRKDIR}/Makefile
	${ECHO} "	${REINPLACE_CMD} -e 's|^%.o: %.c\$$\$$|.c.o:|g' build_${PYPY_${inst}_NAME}/usession-unknown-0/testing_1/Makefile" >> ${WRKDIR}/Makefile
	${ECHO} "	${MAKE} -C build_${PYPY_${inst}_NAME}/usession-unknown-0/testing_1 pypy-c" >> ${WRKDIR}/Makefile
	${ECHO} >> ${WRKDIR}/Makefile
.endfor

post-build:
	-${FIND} ${PYPYDIRS:S|^|${WRKSRC}/|g} -type d | ${SETENV} PYTHON_PATH=${WRKSRC} ${XARGS} ${WRKDIR}/${PYPY_PRIMARY} -m compileall -fl

do-install:
	${MKDIR} ${PYPYPREFIX} ${PYPYPREFIX}/bin
.for dir in ${PYPYDIRS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${PYPYPREFIX}
.endfor
.for file in LICENSE README
	${INSTALL_DATA} ${WRKSRC}/${file} ${PYPYPREFIX}/${file}
.endfor
.for name in ${PYPY_NAMES:O}
	${INSTALL_PROGRAM} ${WRKDIR}/${name} ${PYPYPREFIX}/bin/${name}
	${LN} -fs ${PYPYPREFIX}/bin/${name} ${PREFIX}/bin/${name}${DISTVERSION}
	${ECHO} bin/${name}${DISTVERSION} >> ${TMPPLIST}.prefix
.endfor
.for name in ${PYPY_NAMES:O}
	${ECHO} ${PYPYPREFIX:S|${PREFIX}/||}/bin/${name} >> ${TMPPLIST}.prefix
.endfor
	${CAT} ${TMPPLIST} >> ${TMPPLIST}.prefix
	${MV} ${TMPPLIST}.prefix ${TMPPLIST}

post-install:
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

test: patch
.for inst in ${PYPY_INST}
	@${WHICH} ${PYPY_${inst}_NAME} > /dev/null 2>&1 || (${ECHO} "Unable to find ${PYPY_${inst}_NAME}, please install port first!"; exit 1)
	(${CD} ${WRKSRC}/lib-python; ${PYPY_${inst}_NAME} ../pypy/test_all.py)
.endfor

pkg-plist: build
	${RM} -f ${WRKDIR}/.plist-files-gen ${WRKDIR}/.plist-dirs-gen
.for dir in ${PYPYDIRS}
	cd ${WRKSRC} && ${FIND} ${dir} -type f >> ${WRKDIR}/.plist-files-gen
	cd ${WRKSRC} && ${FIND} ${dir} -type d >> ${WRKDIR}/.plist-dirs-gen
.endfor
.for file in LICENSE README
	${ECHO} ${file} >> ${WRKDIR}/.plist-files-gen
.endfor
	${ECHO} 'bin' >> ${WRKDIR}/.plist-dirs-gen
	${REINPLACE_CMD} -e 's|^|%%PYPYPREFIX%%/|g' -e 's|${PYPY_ARCH}|%%PYPY_ARCH%%|g' ${WRKDIR}/.plist-files-gen
	${REINPLACE_CMD} -e 's|^|@dirrm %%PYPYPREFIX%%/|g' ${WRKDIR}/.plist-dirs-gen
	${ECHO} '@dirrm %%PYPYPREFIX%%' >> ${WRKDIR}/.plist-dirs-gen
	${SORT} ${WRKDIR}/.plist-files-gen > ${WRKDIR}/pkg-plist
	${SORT} -r ${WRKDIR}/.plist-dirs-gen >> ${WRKDIR}/pkg-plist
	${CP} ${WRKDIR}/pkg-plist ${.CURDIR}/pkg-plist

.include <bsd.port.mk>
