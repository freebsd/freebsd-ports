PORTNAME=	ghc
PORTVERSION=	${GHC_VERSION}
CATEGORIES=	lang haskell
MASTER_SITES=	https://www.haskell.org/ghc/dist/${PORTVERSION}/:source \
		LOCAL/arrowd/:boot
DISTFILES=	ghc-${PORTVERSION}-src${EXTRACT_SUFX}:source

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Compiler for the functional language Haskell

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		aarch64 amd64 armv6 armv7 i386

USES=			autoreconf compiler:c11 gmake iconv:patch,translit \
			localbase:ldflags ncurses perl5 python:build shebangfix \
			tar:xz

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--docdir=${DOCSDIR}
INSTALL_TARGET=		install-strip
USE_LOCALE=		en_US.UTF-8
USE_PERL5=		build
NO_CCACHE=		yes
OPTIONS_SUB=		yes
SHEBANG_FILES=		boot

OPTIONS_DEFINE?=	DYNAMIC GMP PROFILE DOCS
OPTIONS_DEFAULT=	DYNAMIC PROFILE GMP

OPTIONS_GROUP=		BOOTSTRAP
BOOTSTRAP_DESC=		Bootsrap using installed ghc
OPTIONS_GROUP_BOOTSTRAP=BOOT

BOOT_DESC=		Use installed GHC for bootstrapping
DOCS_DESC=		Install HTML documentation
DYNAMIC_DESC=		Add support for dynamic linking
GMP_DESC=		Use GNU Multi-precision Library from Ports
PROFILE_DESC=		Add support for performance profiling

BOOT_CONFIGURE_ENV=	GHC=${LOCALBASE}/bin/ghc
BOOT_CONFIGURE_ENV_OFF=	GHC=${BOOT_GHC}

DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
DOCS_VARS=		enable_docs=YES
DOCS_VARS_OFF=		enable_docs=NO

DYNAMIC_CONFIGURE_WITH=	system-libffi \
			ffi-includes=${LOCALBASE}/include \
			ffi-libraries=${LOCALBASE}/lib
DYNAMIC_LIB_DEPENDS=	libffi.so:devel/libffi
DYNAMIC_VARS=		enable_dynamic=YES
DYNAMIC_VARS_OFF=	enable_dynamic=NO

GMP_CONFIGURE_WITH=	gmp-includes=${LOCALBASE}/include \
			gmp-libraries=${LOCALBASE}/lib
GMP_LIB_DEPENDS=	libgmp.so:math/gmp

PROFILE_VARS=		enable_profile=YES
PROFILE_VARS_OFF=	enable_profile=NO

GHC_VERSION?=		9.2.4
LLVM_VERSION?=		12
BOOT_GHC_VERSION=	8.10.7
# LLVM version that bootstrap compiler uses
BOOT_LLVM_VERSION=	10

BASE_PACKAGES?=		Cabal-3.6.3.0 array-0.5.4.0 base-4.16.3.0 binary-0.8.9.0 \
			bytestring-0.11.3.1 containers-0.6.5.1 deepseq-1.4.6.1 \
			directory-1.3.6.2 exceptions-0.10.4 filepath-1.4.2.2 \
			ghc-${GHC_VERSION} ghc-bignum-1.2 ghc-compact-0.1.0.0 \
			ghc-prim-0.8.0 haskeline-0.8.2 hpc-0.6.1.0 \
			integer-gmp-1.1 mtl-2.2.2 parsec-3.1.15.0 pretty-1.3.3.6 \
			process-1.6.13.2 stm-2.5.0.2 template-haskell-2.18.0.0 \
			terminfo-0.4.1.5 text-1.2.5.0 time-1.11.1.1 \
			transformers-0.5.6.2 unix-2.7.2.2 xhtml-3000.2.2.1

.for pkg in ${BASE_PACKAGES}
PLIST_SUB+=	${pkg:C/-([0-9.])+//:tu}_VERSION=${pkg:C/^([^\.]*-)+//}
.endfor

BUILD_MK=		DYNAMIC_GHC_PROGRAMS=${ENABLE_DYNAMIC} \
			BUILD_PROF_LIBS=${ENABLE_PROFILE} \
			HADDOCK_DOCS=YES \
			BUILD_SPHINX_HTML=${ENABLE_DOCS} \
			BUILD_SPHINX_PDF=NO \
			SRC_HC_OPTS+="-I${NCURSESINC} -L${NCURSESLIB} -I${LOCALBASE}/include -L${LOCALBASE}/lib" \
			SRC_CC_OPTS+="${CFLAGS}" \
			EXTRA_HSC2HS_OPTS+="-I${LOCALBASE}/include --lflag=-L${LOCALBASE}/lib" \
			EXTRA_LD_OPTS+="-L${LOCALBASE}/lib" \
			libraries/terminfo_CONFIGURE_OPTS+="--configure-option=--with-curses-libraries=${NCURSESLIB}" \
			${SLAVE_BUILD_MK} \
			V=0

.include <bsd.port.pre.mk>

.if ${SLAVE_PORT} != "yes"
PORTDOCS=		*
.endif

GHC_ARCH=		${ARCH:S/amd64/x86_64/:C/armv.*/arm/}
CONFIGURE_TARGET=	${GHC_ARCH}-portbld-${OPSYS:tl}
BOOT_DIR=		${WRKDIR}/ghc-${BOOT_GHC_VERSION}-boot
BOOT_GHC=		${BOOT_DIR}/bin/ghc-${BOOT_GHC_VERSION}

# This version of ncurses is needed by bootstrap compiler
.if ${OSVERSION} > 1300078 && empty(PORT_OPTIONS:MBOOT)
BUILD_DEPENDS+=	${LOCALBASE}/lib/compat/libncursesw.so.8:misc/compat12x
.endif

.if empty(PORT_OPTIONS:MBOOT)
DISTFILES+=		ghc-${BOOT_GHC_VERSION}-boot-${ARCH}-freebsd${EXTRACT_SUFX}:boot
.endif # MBOOT

.if ${ARCH} == aarch64 || ${ARCH:Marmv*}
# ghc-8.10.x on arm requires devel/llvm10
# CONFIGURE_TARGET must to be the same as the llvm triple
CONFIGURE_TARGET=	${ARCH}-unknown-freebsd${"${ARCH:Maarch64}" != "":?:-gnueabihf}
CONFIGURE_ARGS+=	--host=${CONFIGURE_TARGET}
BUILD_DEPENDS+=		llc${LLVM_VERSION}:devel/llvm${LLVM_VERSION}
RUN_DEPENDS+=		llc${LLVM_VERSION}:devel/llvm${LLVM_VERSION}

# When GHC being compiled and GHC used for bootstrapping support different
# LLVM versions, we have to pull in both. Luckily, this is relatively rare.
.  if ${BOOT_LLVM_VERSION} != ${LLVM_VERSION}
BUILD_DEPENDS+=		llc${BOOT_LLVM_VERSION}:devel/llvm${BOOT_LLVM_VERSION}
.  endif
.endif

post-patch:
#	Generate the build.mk file
	${RM} -f ${WRKSRC}/mk/build.mk
.for line in ${BUILD_MK}
	${ECHO_CMD} ${line} >> ${WRKSRC}/mk/build.mk
.endfor

# TODO: remove this after rerolling all bootstraps
post-patch-BOOT-off:
	@${REINPLACE_CMD} -e '/^mandir/d' ${BOOT_DIR}/mk/build.mk
	@${REINPLACE_CMD} -e '/^infodir/d' ${BOOT_DIR}/mk/build.mk
	@${REINPLACE_CMD} -e '/^docdir/d' ${BOOT_DIR}/mk/build.mk
	@${REINPLACE_CMD} -e '/^htmldir/d' ${BOOT_DIR}/mk/build.mk

pre-configure:
	# Call the bootstrap script
	cd ${WRKSRC}/ && ./boot
# If we are using bootstrap compiler, configure and install it into ${BOOT_DIR}
.if empty(PORT_OPTIONS:MBOOT)
	cd ${BOOT_DIR} && ${CONFIGURE_ENV} ${CONFIGURE_CMD} --prefix=${BOOT_DIR}
	cd ${BOOT_DIR} && PACKAGES='' ${MAKE_CMD} install
.endif

post-install:
	${FIND} ${STAGEDIR}${DOCSDIR}/html -name .buildinfo -delete
# For some reason, INSTALL_TARGET=install-strip doesn't cause libraries to be stripped
# Run strip on them manually
	${FIND} ${STAGEDIR}${PREFIX}/lib/ghc-${GHC_VERSION} -name '*.so' -exec ${STRIP_CMD} {} +
	${RM} ${STAGEDIR}${PREFIX}/bin/haddock
.if ${SLAVE_PORT} == "yes"
	${MV} ${STAGEDIR}${PREFIX}/bin/hsc2hs ${STAGEDIR}${PREFIX}/bin/hsc2hs-ghc-${GHC_VERSION}
	${FIND} ${STAGEDIR}${PREFIX}/bin -not -type d -not -regex '.*-${GHC_VERSION}' -delete
	${RM} -r ${STAGEDIR}${PREFIX}/lib/ghc-${GHC_VERSION}/html
	${RM} -r ${STAGEDIR}${PREFIX}/lib/ghc-${GHC_VERSION}/latex
.endif

post-install-DOCS-off:
# Docs for Haskell libraries are generated by Haddock, not sphinx, so we have
# to pass WITH_HADDOCK=no to the build.mk to skip their generation.
# However, we don't want to do that because this would cause Haddock itself not
# to be built.
	${RM} -r ${STAGEDIR}${DOCSDIR}/html

.if exists(${BOOT_DIR}/bin/runhaskell)
RUNHASKELL?=	${BOOT_DIR}/bin/runhaskell
.else
RUNHASKELL?=	${LOCALBASE}/bin/runhaskell
.endif

.PHONY: fixup-plist
fixup-plist:
	${RUNHASKELL} ${PATCHDIR}/fixup-plist.hs ${.CURDIR}/pkg-plist

# Create a bootstrap compiler tar ball: run this in an interactive poudriere jail
# Set all OPTIONS to OFF when generating bootstraps
.PHONY: create-bootstrap
create-bootstrap:
	cd ${WRKSRC} \
		&& ${ECHO} "BIN_DIST_NAME=ghc-${GHC_VERSION}-boot" >> mk/build.mk \
		&& ${ECHO} "BIN_DIST_TAR=ghc-${GHC_VERSION}-boot.tar" >> mk/build.mk \
		&& ${ECHO} "HADDOCK_DOCS=NO" >> mk/build.mk \
		&& ${GMAKE} binary-dist TAR_COMP=xz \
		&& ${MV} ${WRKSRC}/ghc-${GHC_VERSION}-boot-${GHC_ARCH}-portbld-freebsd.tar.xz /tmp/ghc-${GHC_VERSION}-boot-${ARCH}-freebsd.tar.xz

	cd /tmp \
		&& sha256 ghc-${GHC_VERSION}-boot-${ARCH}-freebsd.tar.xz \
		&& ${ECHO} -n "SIZE (ghc-${GHC_VERSION}-boot-${ARCH}-freebsd.tar.xz) = " \
		&& ${STAT} -f %z ghc-${GHC_VERSION}-boot-${ARCH}-freebsd.tar.xz

# Much like create-bootstrap, just different naming and output format
# Set DYNAMIC, GMP and PROFILE to ON, and DOCS to OFF when generating Stack bindist
.PHONY: create-stack-bindist
create-stack-bindist:
	cd ${WRKSRC} \
		&& ${GMAKE} binary-dist TAR_COMP=xz \
		&& ${MV} ${WRKSRC}/ghc-${GHC_VERSION}-${GHC_ARCH}-portbld-freebsd.tar.xz /tmp/

	cd /tmp \
		&& ${ECHO} "${GHC_VERSION}:" \
		&& ${ECHO} "url: \"http://distcache.FreeBSD.org/local-distfiles/arrowd/stack-bindists/ghc-${GHC_VERSION}-${GHC_ARCH}-portbld-freebsd.tar.xz\"" \
		&& ${ECHO} -n "content-length: " \
		&& ${STAT} -f %z ghc-${GHC_VERSION}-${GHC_ARCH}-portbld-freebsd.tar.xz \
		&& ${ECHO} -n "sha1: " \
		&& sha1 -q ghc-${GHC_VERSION}-${GHC_ARCH}-portbld-freebsd.tar.xz \
		&& ${ECHO} -n "sha256: " \
		&& sha256 -q ghc-${GHC_VERSION}-${GHC_ARCH}-portbld-freebsd.tar.xz

.include <bsd.port.post.mk>
