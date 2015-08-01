# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME=	pypy
PORTVERSION=	2.6.0
PORTREVISION=	2
CATEGORIES=	lang python
MASTER_SITES=	https://bitbucket.org/pypy/pypy/get/ LOCAL/dbn/pypy
DISTNAME=	release-${DISTVERSION}
DIST_SUBDIR=	pypy

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Fast, compliant implementation of the Python language

LICENSE=	MIT PSFL
LICENSE_COMB=	multi

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2 \
		libffi.so:${PORTSDIR}/devel/libffi

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
USES=		compiler:c11 gettext-runtime tar:bzip2
WRKSRC=		${WRKDIR}/pypy-pypy-295ee98b6928

PYPY_DIR=	pypy-${DISTVERSION:C|([0-9])\.([0-9]).*|\1.\2|}
PLIST_SUB+=	PYPY_DIR=${PYPY_DIR}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYPY} || defined(PYTHON_CMD)
PYTHON_CMD?=	${LOCALBASE}/bin/pypy
.elif ${PORT_OPTIONS:MPYPY_MINMEM}
PYTHON_CMD?=	"${SETENV} PYPY_GC_MAX_DELTA=200MB ${LOCALBASE}/bin/pypy --jit loop_longevity=300"
.else
USES+=		python:2,build
.endif

# Translate FreeBSD ARCH types to PyPy ARCH types
# Pypy officially only supports i386 and amd64, the other platforms are
# untested (and do not have jit support).
.if ${ARCH} == "i386"
PYPY_ARCH=	x86_32
PYPY_BITS=	32
.elif ${ARCH} == "amd64"
PYPY_ARCH=	x86_64
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

pre-build: ${BUILD_WRKSRC}/Makefile

${BUILD_WRKSRC}/Makefile:
	${RM} -r ${WRKDIR}/build
	${MKDIR} ${WRKDIR}/build
	(cd ${WRKSRC}/pypy/goal; \
		${SETENV} ${MAKE_ENV} TMPDIR=${WRKDIR}/build \
		${PYTHON_CMD} ../../rpython/bin/rpython --source -Ojit targetpypystandalone.py)
	${REINPLACE_CMD} -e 's|^%.o: %.c$$|.c.o:|g' ${BUILD_WRKSRC}/Makefile

post-build:
	${CP} ${BUILD_WRKSRC}/pypy-c ${BUILD_WRKSRC}/libpypy-c.so ${WRKSRC}/pypy/goal/

do-install:
	${SETENV} TMPDIR=${WRKDIR}/build \
		${PYTHON_CMD} ${WRKSRC}/pypy/tool/release/package.py --without-cffi --builddir ${WRKDIR}/build --archive-name ${PYPY_DIR}
	${EXTRACT_CMD} -C ${STAGEDIR}${PREFIX} -xf ${WRKDIR}/build/${PYPY_DIR}.tar.bz2
	${LN} -s ../${PYPY_DIR}/bin/pypy ${STAGEDIR}${PREFIX}/bin/pypy

regression-test: build
	(cd ${WRKSRC}; \
		${SETENV} ${MAKE_ENV} TMPDIR=${WRKDIR}/build \
		${WRKSRC}/pypy/goal/pypy-c pypy/test_all.py --basetemp ${WRKDIR}/build pypy lib-python)

pkg-plist: build
	${TAR} -tf ${WRKDIR}/build/${PYPY_DIR}.tar.bz2 > ${WRKDIR}/.plist-files-gen
	${REINPLACE_CMD} -e 's|^${PYPY_DIR}|%%PYPY_DIR%%|g' \
		-e 's|${PYPY_ARCH}|%%PYPY_ARCH%%|g' \
		-e 's|_${PYPY_BITS}_|_%%PYPY_BITS%%_|g' \
		-e '/\/$$/d' \
			${WRKDIR}/.plist-files-gen
	${ECHO} bin/pypy > ${WRKDIR}/pkg-plist
	${SORT} ${WRKDIR}/.plist-files-gen >> ${WRKDIR}/pkg-plist
	${CP} ${WRKDIR}/pkg-plist ${.CURDIR}/pkg-plist

.include <bsd.port.mk>
