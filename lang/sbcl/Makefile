# $FreeBSD$

PORTNAME=	sbcl
PORTVERSION=	1.3.13
DISTVERSIONSUFFIX=	-source
PORTEPOCH=	1
CATEGORIES=	lang lisp
MASTER_SITES=	SF/sbcl/sbcl/${PORTVERSION}

MAINTAINER=	pavelivolkov@gmail.com
COMMENT=	Common Lisp development system derived from the CMU CL system

LICENSE=	sbcl
LICENSE_NAME=	public domain | FreeBSD
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept dist-sell pkg-sell

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr

USES=		gmake makeinfo tar:bzip2

ONLY_FOR_ARCHS=	i386 amd64

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAKE_SH_ARGS?=	--prefix="${PREFIX}" \
		--xc-host="${XC_HOST}"

# You can use the DYNAMIC_SPACE_SIZE knob to change the size of SBCL dynamically-allocated memory.
# Default for arch: i386 = 512Mb, amd64 = 1Gb.
.if defined(DYNAMIC_SPACE_SIZE)
MAKE_SH_ARGS+=	--dynamic-space-size=${DYNAMIC_SPACE_SIZE}
.endif

# All options explained into file: ${WRKSRC}/base-target-features.lisp-expr
OPTIONS_DEFINE=	DOCS QSHOW RENAME SAFEPOINT THREADS UNICODE XREF ZLIB
OPTIONS_DEFAULT=CCL UNICODE

QSHOW_DESC=	C runtime with low-level debugging output
RENAME_DESC=	Rename suffix .core to _core
SAFEPOINT_DESC=	Using safepoints instead of signals
XREF_DESC=	XREF data for SBCL internals

OPTIONS_SINGLE=	BOOTSTRAP
OPTIONS_SINGLE_BOOTSTRAP=	ABCL CCL CMUCL SBCL

ABCL_DESC=	Armed Bear Common Lisp
BOOTSTRAP_DESC=	Supported languages of the build host
CCL_DESC=	Clozure Common Lisp
CMUCL_DESC=	Carnegie Mellon University Common Lisp
SBCL_DESC=	Steel Bank Common Lisp

# On this moment CMUCL - don't builds sbcl correctly, ABCL - I don't tested. Welcome volunteers.
OPTIONS_EXCLUDE=ABCL CMUCL

ABCL_VARS=	XC_HOST="abcl"
ABCL_BUILD_DEPENDS=	abcl:lang/abcl

CCL_VARS=	XC_HOST="ccl --no-init --batch --quiet"
CCL_BUILD_DEPENDS=	ccl:lang/ccl

CMUCL_VARS=	XC_HOST="lisp -nositeinit -noinit -batch -quiet"
CMUCL_BUILD_DEPENDS=	lisp:lang/cmucl

DOCS_VARS=	INFO="asdf sbcl"

QSHOW_VARS=	MAKE_SH_ARGS+="--with-sb-qshow"
QSHOW_VARS_OFF=	MAKE_SH_ARGS+="--without-sb-qshow"

RENAME_PLIST_SUB=	RENAME_DLM="_"
RENAME_PLIST_SUB_OFF=	RENAME_DLM="."
RENAME_VARS=	RENAME_DLM="_"
RENAME_VARS_OFF=RENAME_DLM="."

SAFEPOINT_VARS=	MAKE_SH_ARGS+="--with-sb-safepoint --with-sb-thruption --with-sb-wtimer"
SAFEPOINT_VARS_OFF=	MAKE_SH_ARGS+="--without-sb-safepoint --without-sb-thruption --without-sb-wtimer"
SAFEPOINT_IMPLIES=	THREADS

SBCL_VARS=	XC_HOST="sbcl --noinform --disable-debugger --no-sysinit --no-userinit"

THREADS_VARS=	MAKE_SH_ARGS+="--with-sb-thread --with-restore-fs-segment-register-from-tls"
THREADS_VARS_OFF=	MAKE_SH_ARGS+="--without-sb-thread --without-restore-fs-segment-register-from-tls"

UNICODE_VARS=	MAKE_SH_ARGS+="--with-sb-unicode"
UNICODE_VARS_OFF=	MAKE_SH_ARGS+="--without-sb-unicode"

XREF_VARS=	MAKE_SH_ARGS+="--with-sb-xref-for-internals"
XREF_VARS_OFF=	MAKE_SH_ARGS+="--without-sb-xref-for-internals"

ZLIB_VARS=	MAKE_SH_ARGS+="--with-sb-core-compression"
ZLIB_VARS_OFF=	MAKE_SH_ARGS+="--without-sb-core-compression"

PORTDOCS=	*

post-patch-RENAME-on:
	${GREP} -Frl '.core' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e 's|\.core|_core|g'

do-build:
	(cd ${WRKSRC} && ${SH} make.sh ${MAKE_SH_ARGS})

do-install:
	(cd ${WRKSRC} && ${SETENV} \
	INSTALL_ROOT="${STAGEDIR}${PREFIX}" \
	MAN_DIR="${STAGEDIR}${MANPREFIX}/man" \
	INFO_DIR="${STAGEDIR}${PREFIX}/${INFO_PATH}" \
	DOC_DIR="${STAGEDIR}${DOCSDIR}" \
	${SH} install.sh)

post-build-DOCS-on:
	${DO_MAKE_BUILD} -C ${WRKSRC}/doc/manual info html

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sbcl

post-install-DOCS-on:
	${RM} ${STAGEDIR}${PREFIX}/${INFO_PATH}/dir # don't requered with INFO=
	${RM} -r ${STAGEDIR}${DOCSDIR}/html # empty directory created by install.sh

check regression-test test: build
	(cd ${WRKSRC}/tests && ${SH} run-tests.sh)

.include <bsd.port.mk>
