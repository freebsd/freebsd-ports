# All *-sbcl ports and any other port with SBCL fasl files must get a
# PORTREVISION bump when lang/sbcl is updated.  The compiled fasl files are
# pinned to exact versions of everything used to build them.

PORTNAME=	sbcl
DISTVERSION=	2.5.7
DISTVERSIONSUFFIX=	-source
PORTEPOCH=	1
CATEGORIES=	lang lisp
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION} \
		SF/${PORTNAME}/${PORTNAME}/${BOOTVERSION}:binaries
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Common Lisp development system derived from the CMU CL system
WWW=		https://sbcl.sourceforge.io/

LICENSE=	BSD2CLAUSE PD
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr
RUN_DEPENDS=	cl-freebsd-asdf-init>=0:devel/cl-freebsd-asdf-init

USES=		gmake makeinfo tar:bzip2

SUB_FILES=	sbclrc

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	*

# All options explained into file: ${WRKSRC}/base-target-features.lisp-expr
OPTIONS_DEFINE=		COMPRESSION GARBAGE_COLLECTOR DOCS LINKABLE_RUNTIME QSHOW SAFEPOINT SIMD \
			THREADS UNICODE XREF
OPTIONS_DEFAULT=	COMPRESSION SBCL THREADS UNICODE

OPTIONS_SINGLE=			BOOTSTRAP
OPTIONS_SINGLE_BOOTSTRAP=	ABCL CCL CMUCL SBCL
OPTIONS_EXCLUDE=		ABCL CMUCL

ABCL_DESC=		Armed Bear Common Lisp
BOOTSTRAP_DESC=		Supported languages of the build host
CCL_DESC=		Clozure Common Lisp
CMUCL_DESC=		Carnegie Mellon University Common Lisp
COMPRESSION_DESC=	Enable core compression
GARBAGE_COLLECTOR_DESC=	Enable mark-region parallel garbage collector
LINKABLE_RUNTIME_DESC=	Enable SB-LINKABLE-RUNTIME feature (experimental)
QSHOW_DESC=		C runtime with low-level debugging output
SAFEPOINT_DESC=		Using safepoints instead of signals
SBCL_DESC=		Steel Bank Common Lisp
SIMD_DESC=		Enable SB-SIMD (requires CPUs supporting AVX2)
XREF_DESC=		XREF data for SBCL internals

ABCL_BUILD_DEPENDS=	abcl:lang/abcl
ABCL_VARS=		XC_HOST="abcl"

CCL_BUILD_DEPENDS=	ccl:lang/ccl
CCL_VARS=		XC_HOST="ccl --no-init --batch --quiet"

CMUCL_BUILD_DEPENDS=	lisp:lang/cmucl
CMUCL_VARS=		XC_HOST="lisp -nositeinit -noinit -batch -quiet"

COMPRESSION_LIB_DEPENDS=	libzstd.so:archivers/zstd
COMPRESSION_USES=		localbase:ldflags
COMPRESSION_VARS=		MAKE_SH_ARGS+="--with-sb-core-compression"
COMPRESSION_VARS_OFF=		MAKE_SH_ARGS+="--without-sb-core-compression"

DOCS_VARS=	INFO="asdf sbcl"

GARBAGE_COLLECTOR_VARS=		MAKE_SH_ARGS+="--without-gencgc --with-mark-region-gc"
GARBAGE_COLLECTOR_VARS_OFF=	MAKE_SH_ARGS+="--with-gencgc --without-mark-region-gc"

LINKABLE_RUNTIME_VARS=		MAKE_SH_ARGS+="--with-sb-linkable-runtime"
LINKABLE_RUNTIME_VARS_OFF=	MAKE_SH_ARGS+="--without-sb-linkable-runtime"

QSHOW_VARS=	MAKE_SH_ARGS+="--with-sb-qshow"
QSHOW_VARS_OFF=	MAKE_SH_ARGS+="--without-sb-qshow"

SAFEPOINT_IMPLIES=	THREADS
SAFEPOINT_VARS=		MAKE_SH_ARGS+="--with-sb-safepoint --with-sb-thruption --with-sb-wtimer"
SAFEPOINT_VARS_OFF=	MAKE_SH_ARGS+="--without-sb-safepoint --without-sb-thruption --without-sb-wtimer"

SBCL_DISTFILES=	${PORTNAME}-${SBCL_BOOT_LIST:M${ARCHOS_PATTERN}}-binary${EXTRACT_SUFX}:binaries
SBCL_VARS=	XC_HOST="${BOOT_WRKSRC}/src/runtime/sbcl --core ${BOOT_WRKSRC}/output/sbcl.core --noinform --disable-debugger --no-sysinit --no-userinit"

SIMD_VARS=	MAKE_SH_ARGS+="--with-sb-simd"
SIMD_VARS_OFF=	MAKE_SH_ARGS+="--without-sb-simd"

THREADS_VARS=		MAKE_SH_ARGS+="--with-sb-thread"
THREADS_VARS_OFF=	MAKE_SH_ARGS+="--without-sb-thread"

UNICODE_VARS=		MAKE_SH_ARGS+="--with-sb-unicode"
UNICODE_VARS_OFF=	MAKE_SH_ARGS+="--without-sb-unicode"

XREF_VARS=	MAKE_SH_ARGS+="--with-sb-xref-for-internals"
XREF_VARS_OFF=	MAKE_SH_ARGS+="--without-sb-xref-for-internals"

BOOTVERSION=	1.2.7
CONMODULES=	asdf sb-aclrepl sb-bsd-sockets sb-cltl2 sb-concurrency sb-cover \
		sb-executable sb-gmp sb-grovel sb-introspect sb-md5 sb-mpfr \
		sb-posix sb-queue sb-rotate-byte sb-rt sb-simple-streams \
		sb-sprof
MAKE_SH_ARGS?=	--prefix="${PREFIX}" --xc-host="${XC_HOST}"
# You can use the DYNAMIC_SPACE_SIZE knob to change the size of SBCL dynamically-allocated memory.
# Default for arch: i386 = 512Mb, amd64 = 1Gb.
.if defined(DYNAMIC_SPACE_SIZE)
MAKE_SH_ARGS+=	--dynamic-space-size=${DYNAMIC_SPACE_SIZE}
.endif
SBCL_BOOT_LIST=	${BOOTVERSION}-x86-64-freebsd ${BOOTVERSION}-x86-freebsd \
		${BOOTVERSION}-x86-64-dragonfly

.include <bsd.port.options.mk>

ARCHOS_PATTERN=	*-${ARCH:S/amd64/x86-64/:S/i386/x86/}-${OPSYS:tl}*
BOOT_WRKSRC=	${WRKDIR}/${PORTNAME}-${SBCL_BOOT_LIST:M${ARCHOS_PATTERN}}

.if ${PORT_OPTIONS:MLINKABLE_RUNTIME}
PLIST_SUB+=	LINKABLE_RUNTIME=""
.else
PLIST_SUB+=	LINKABLE_RUNTIME="@comment "
.endif

.if ${PORT_OPTIONS:MSIMD}
PLIST_SUB+=	SIMD=""
.else
PLIST_SUB+=	SIMD="@comment "
.endif

# for port maintenance, invoke "make makesum PLUS_BOOTSTRAPS=1"
.if defined (PLUS_BOOTSTRAPS)
. for B in ${SBCL_BOOT_LIST}
.  if !${DISTFILES:Msbcl-${B}-*}
DISTFILES:=	${DISTFILES} \
		${PORTNAME}-${B}-binary${EXTRACT_SUFX}:binaries
.  endif
. endfor
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|' \
		${WRKSRC}/src/code/toplevel.lisp \
		${WRKSRC}/doc/${PORTNAME}.1 \
		${WRKSRC}/doc/manual/start-stop.texinfo

do-build:
	(cd ${WRKSRC} && ${SH} make.sh ${MAKE_SH_ARGS})

post-build-DOCS-on:
	${DO_MAKE_BUILD} -C ${WRKSRC}/doc/manual info html

do-install:
	(cd ${WRKSRC} && ${SETENV} \
	INSTALL_ROOT="${STAGEDIR}${PREFIX}" \
	MAN_DIR="${STAGEDIR}${PREFIX}/share/man" \
	INFO_DIR="${STAGEDIR}${PREFIX}/${INFO_PATH}" \
	DOC_DIR="${STAGEDIR}${DOCSDIR}" \
	SBCL_HOME="" \
	${SH} install.sh)
.for M in ${CONMODULES}
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${M}
	${INSTALL_DATA} ${WRKSRC}/contrib/${M}/*.[la]* \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${M}/
.endfor
.if ${PORT_OPTIONS:MSIMD}
# sb-simd has its code in './code'
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/sb-simd
	${INSTALL_DATA} ${WRKSRC}/contrib/sb-simd/code/*.[la]* \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}/sb-simd/
.endif
	${INSTALL_DATA} ${WRKDIR}/sbclrc ${STAGEDIR}${PREFIX}/etc/sbclrc.sample

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	${RM} ${STAGEDIR}${PREFIX}/${INFO_PATH}/dir # don't requered with INFO=
	${RM} -r ${STAGEDIR}${DOCSDIR}/html # empty directory created by install.sh

check regression-test test: build
	(cd ${WRKSRC}/tests && ${SH} run-tests.sh)

.include <bsd.port.mk>
