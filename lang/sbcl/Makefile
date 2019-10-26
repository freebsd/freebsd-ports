# $FreeBSD$

# All *-sbcl ports and any other port with SBCL fasl files must get a
# PORTREVISION bump when lang/sbcl is updated.  The compiled fasl files are
# pinned to exact versions of everything used to build them.

PORTNAME=	sbcl
DISTVERSION=	1.5.8
DISTVERSIONSUFFIX=	-source
PORTEPOCH=	1
CATEGORIES=	lang lisp
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION} \
		SF/${PORTNAME}/${PORTNAME}/${BOOTVERSION}:binaries
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Common Lisp development system derived from the CMU CL system

LICENSE=	PD BSD2CLAUSE
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr
RUN_DEPENDS=	cl-asdf>=0:devel/cl-asdf

USES=		gmake makeinfo tar:bzip2

BOOTVERSION=	1.2.7
SBCL_BOOT_LIST=	${BOOTVERSION}-x86-64-freebsd \
		${BOOTVERSION}-x86-freebsd \
		${BOOTVERSION}-x86-64-dragonfly

CONMODULES=	asdf sb-aclrepl sb-bsd-sockets sb-cltl2 sb-concurrency \
		sb-cover sb-executable sb-gmp sb-grovel sb-introspect \
		sb-md5 sb-mpfr sb-posix sb-queue sb-rotate-byte sb-rt \
		sb-simple-streams sb-sprof

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAKE_SH_ARGS?=	--prefix="${PREFIX}" \
		--xc-host="${XC_HOST}"

# You can use the DYNAMIC_SPACE_SIZE knob to change the size of SBCL dynamically-allocated memory.
# Default for arch: i386 = 512Mb, amd64 = 1Gb.
.if defined(DYNAMIC_SPACE_SIZE)
MAKE_SH_ARGS+=	--dynamic-space-size=${DYNAMIC_SPACE_SIZE}
.endif

SUB_FILES=	pkg-message sbclrc

# All options explained into file: ${WRKSRC}/base-target-features.lisp-expr
OPTIONS_DEFINE=	DOCS QSHOW RENAME SAFEPOINT THREADS UNICODE XREF ZLIB
OPTIONS_DEFAULT=	RENAME SBCL THREADS UNICODE

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

# On this moment CMUCL doesn't builds sbcl correctly
# ABCL - I haven't tested. Welcome volunteers.
OPTIONS_EXCLUDE=	ABCL CMUCL

ABCL_VARS=		XC_HOST="abcl"
ABCL_BUILD_DEPENDS=	abcl:lang/abcl

CCL_VARS=		XC_HOST="ccl --no-init --batch --quiet"
CCL_BUILD_DEPENDS=	ccl:lang/ccl

CMUCL_VARS=		XC_HOST="lisp -nositeinit -noinit -batch -quiet"
CMUCL_BUILD_DEPENDS=	lisp:lang/cmucl

DOCS_VARS=		INFO="asdf sbcl"

QSHOW_VARS=		MAKE_SH_ARGS+="--with-sb-qshow"
QSHOW_VARS_OFF=		MAKE_SH_ARGS+="--without-sb-qshow"

RENAME_PLIST_SUB=	CORE_SUFFIX="_core"
RENAME_PLIST_SUB_OFF=	CORE_SUFFIX=".core"

SAFEPOINT_VARS=		MAKE_SH_ARGS+="--with-sb-safepoint --with-sb-thruption --with-sb-wtimer"
SAFEPOINT_VARS_OFF=	MAKE_SH_ARGS+="--without-sb-safepoint --without-sb-thruption --without-sb-wtimer"
SAFEPOINT_IMPLIES=	THREADS

SBCL_VARS=		XC_HOST="${BOOT_WRKSRC}/src/runtime/sbcl --core ${BOOT_WRKSRC}/output/${CORE} --noinform --disable-debugger --no-sysinit --no-userinit"
SBCL_DISTFILES=		${PORTNAME}-${SBCL_BOOT_LIST:M${ARCHOS_PATTERN}}-binary${EXTRACT_SUFX}:binaries

THREADS_VARS=		MAKE_SH_ARGS+="--with-sb-thread --with-restore-fs-segment-register-from-tls"
THREADS_VARS_OFF=	MAKE_SH_ARGS+="--without-sb-thread --without-restore-fs-segment-register-from-tls"

UNICODE_VARS=		MAKE_SH_ARGS+="--with-sb-unicode"
UNICODE_VARS_OFF=	MAKE_SH_ARGS+="--without-sb-unicode"

XREF_VARS=		MAKE_SH_ARGS+="--with-sb-xref-for-internals"
XREF_VARS_OFF=		MAKE_SH_ARGS+="--without-sb-xref-for-internals"

ZLIB_VARS=		MAKE_SH_ARGS+="--with-sb-core-compression"
ZLIB_VARS_OFF=		MAKE_SH_ARGS+="--without-sb-core-compression"

PORTDOCS=	*

.include <bsd.port.options.mk>

ARCHOS_PATTERN=	*-${ARCH:S/amd64/x86-64/:S/i386/x86/}-${OPSYS:tl}*
BOOT_WRKSRC=	${WRKDIR}/${PORTNAME}-${SBCL_BOOT_LIST:M${ARCHOS_PATTERN}}

# for port maintenance, invoke "make makesum PLUS_BOOTSTRAPS=1"
.if defined (PLUS_BOOTSTRAPS)
. for B in ${SBCL_BOOT_LIST}
.  if ! ${DISTFILES:Msbcl-${B}-*}
DISTFILES:=	${DISTFILES} ${PORTNAME}-${B}-binary${EXTRACT_SUFX}:binaries
.  endif
. endfor
.endif

# Old FreeBSD bootstraps feature the older core name for SBCL bootstrap
.if ${OPSYS} == FreeBSD
CORE=	sbcl.core
.else
CORE=	sbcl_core
.endif

post-patch-RENAME-on:
	${GREP} -Frl '.core' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e 's|\.core|_core|g'

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|' \
		${WRKSRC}/src/code/toplevel.lisp \
		${WRKSRC}/doc/${PORTNAME}.1 \
		${WRKSRC}/doc/manual/start-stop.texinfo

do-build:
	(cd ${WRKSRC} && ${SH} make.sh ${MAKE_SH_ARGS})

do-install:
	(cd ${WRKSRC} && ${SETENV} \
	INSTALL_ROOT="${STAGEDIR}${PREFIX}" \
	MAN_DIR="${STAGEDIR}${MANPREFIX}/man" \
	INFO_DIR="${STAGEDIR}${PREFIX}/${INFO_PATH}" \
	DOC_DIR="${STAGEDIR}${DOCSDIR}" \
	${SH} install.sh)
.for M in ${CONMODULES}
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${M}
	${INSTALL_DATA} ${WRKSRC}/contrib/${M}/*.[la]* \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${M}/
.endfor
	${INSTALL_DATA} ${WRKDIR}/sbclrc ${STAGEDIR}${PREFIX}/etc/sbclrc.sample

post-build-DOCS-on:
	${DO_MAKE_BUILD} -C ${WRKSRC}/doc/manual info html

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	${RM} ${STAGEDIR}${PREFIX}/${INFO_PATH}/dir # don't requered with INFO=
	${RM} -r ${STAGEDIR}${DOCSDIR}/html # empty directory created by install.sh

check regression-test test: build
	(cd ${WRKSRC}/tests && ${SH} run-tests.sh)

.include <bsd.port.mk>
