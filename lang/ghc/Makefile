PORTNAME=	ghc
PORTVERSION=	${GHC_VERSION}
PORTREVISION?=	0
CATEGORIES=	lang haskell
MASTER_SITES=	https://www.haskell.org/ghc/dist/${PORTVERSION}/:source \
		LOCAL/arrowd/:boot
DISTFILES=	ghc-${PORTVERSION}-src${EXTRACT_SUFX}:source

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Compiler for the functional language Haskell
WWW=		https://www.haskell.org/ghc/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		aarch64 amd64 i386

BUILD_DEPENDS=		${LOCALBASE}/lib/libgmp.so:math/gmp

USES=			autoreconf compiler:c11 gmake \
			ncurses perl5 python:build shebangfix \
			tar:xz

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--docdir=${DOCSDIR}
CONFIGURE_ENV=		ALEX=/usr/bin/true HAPPY=/usr/bin/true
INSTALL_TARGET=		install-strip
USE_LOCALE=		en_US.UTF-8
USE_PERL5=		build
NO_CCACHE=		yes
OPTIONS_SUB=		yes
SHEBANG_FILES=		${BOOT_SCRIPT}

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
BOOT_CONFIGURE_ENV_OFF=	GHC=${BOOT_GHC} LLC=llc${BOOT_LLVM_VERSION} OPT=opt${BOOT_LLVM_VERSION}

DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx \
			xelatex:print/tex-xetex \
			${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf:x11-fonts/dejavu
DOCS_VARS=		enable_docs=YES
DOCS_VARS_OFF=		enable_docs=NO hadrian_docs_arg=--docs=none

DYNAMIC_CONFIGURE_WITH=	system-libffi \
			ffi-includes=${LOCALBASE}/include \
			ffi-libraries=${LOCALBASE}/lib
DYNAMIC_LIB_DEPENDS=	libffi.so:devel/libffi
DYNAMIC_VARS=		enable_dynamic=YES hadrian_setting_dynamic=True
DYNAMIC_VARS_OFF=	enable_dynamic=NO hadrian_setting_dynamic=False

# do not replace this with GMP_CONFIGURE_WITH
# it adds "--without-gmp-*" when the option is OFF, which results in "no" value
# to be used as directory name
GMP_CONFIGURE_ON=	--with-gmp-includes=${LOCALBASE}/include \
			--with-gmp-libraries=${LOCALBASE}/lib
GMP_LIB_DEPENDS=	libgmp.so:math/gmp
GMP_VARS_OFF=		hadrian_gmp_arg=--bignum=native

PROFILE_VARS=		enable_profile=YES hadrian_setting_profile=True
PROFILE_VARS_OFF=	enable_profile=NO hadrian_setting_profile=False

GHC_VERSION?=		9.4.7
LLVM_VERSION?=		13
BOOT_GHC_VERSION?=	9.2.8
# LLVM version that bootstrap compiler uses
BOOT_LLVM_VERSION?=	12

BASE_PACKAGES?=		Cabal-3.8.1.0 array-0.5.4.0 base-4.17.2.0 binary-0.8.9.1 \
			bytestring-0.11.5.2 containers-0.6.7 deepseq-1.4.8.0 \
			directory-1.3.7.1 exceptions-0.10.5 filepath-1.4.2.2 \
			ghc-${GHC_VERSION} ghc-bignum-1.3 ghc-compact-0.1.0.0 \
			ghc-prim-0.9.1 haskeline-0.8.2 hpc-0.6.1.0 \
			integer-gmp-1.1 mtl-2.2.2 parsec-3.1.16.1 pretty-1.1.3.6 \
			process-1.6.17.0 stm-2.5.1.0 template-haskell-2.19.0.0 \
			terminfo-0.4.1.5 text-2.0.2 time-1.12.2 \
			transformers-0.5.6.2 unix-2.7.3 xhtml-3000.2.2.1

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

.if ${GHC_VERSION:C/\..*//g} >= 9 && ${ARCH} != i386
# hadrian build on i386 fails due to https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=269570
# relocation R_386_TLS_LE cannot be used with -shared
USE_HADRIAN=		yes
.endif

.if ${GHC_VERSION:C/\..*//g} >= 9 && ${GHC_VERSION:C/[^\.]*\.//:C/\..*//g} >= 4
BOOT_SCRIPT=	./boot.source
IGNORE_i386=	requires Hadrian build which doesn't work on i386
.else
BOOT_SCRIPT=	./boot
.endif

.if ${SLAVE_PORT} != "yes"
PORTDOCS=		*
HADRIAN_PLAN=		${PATCHDIR}/plan-bootstrap-${BOOT_GHC_VERSION:C/\./_/g}.json
.else
HADRIAN_DOCS_ARG=	--docs=none
HADRIAN_PLAN=		${MASTERDIR}/files/plan-bootstrap-${BOOT_GHC_VERSION:C/\./_/g}.json
PLIST_SUB+=		GMP=
.endif

.ifdef USE_HADRIAN
LIB_DEPENDS+=		libffi.so:devel/libffi
.undef DYNAMIC_CONFIGURE_WITH
CONFIGURE_ARGS+=	--with-system-libffi --with-ffi-includes=${LOCALBASE}/include --with-ffi-libraries=${LOCALBASE}/lib
CONFIGURE_ENV+=		CC=${CC} CXX=${CXX}
SHEBANG_FILES+=		hadrian/bootstrap/bootstrap.py
HADRIAN_CMD=		${WRKSRC}/hadrian/bootstrap/_build/bin/hadrian ${HADRIAN_DOCS_ARG} ${HADRIAN_GMP_ARG}
DO_MAKE_BUILD=		${SETENV} ${MAKE_ENV} ${HADRIAN_CMD} ${_MAKE_JOBS} --flavour=ports
ALL_TARGET=		binary-dist-dir
INSTALL_WRKSRC=		${WRKSRC}/_build/bindist/ghc-${GHC_VERSION}-${CONFIGURE_TARGET}
INSTALL_TARGET=		install
PLIST?=			${.CURDIR}/pkg-plist.hadrian

.  if (empty(PORT_OPTIONS:MDYNAMIC) || empty(PORT_OPTIONS:MPROFILE))
IGNORE=			Building with Hadrian requires both DYNAMIC and PROFILE for now
.  endif
.endif

GHC_ARCH=		${ARCH:S/amd64/x86_64/:C/armv.*/arm/}
CONFIGURE_TARGET=	${GHC_ARCH}-portbld-${OPSYS:tl}
BOOT_DIR=		${WRKDIR}/ghc-${BOOT_GHC_VERSION}-boot
BOOT_INSTALL_DIR=	${WRKDIR}/ghc-boot-install
BOOT_GHC=		${BOOT_INSTALL_DIR}/bin/ghc-${BOOT_GHC_VERSION}

PLIST_SUB+=		GHC_ARCH=${GHC_ARCH}

.if ${BOOT_GHC_VERSION:C/\..*//g} >= 9
BOOT_DIR=		${WRKDIR}/ghc-${BOOT_GHC_VERSION}-${CONFIGURE_TARGET}
.endif

# this is hacky but 92 is special as it is compiled with autotools on i386 and with Hadrian elsewhere
.if ${SLAVE_PORT} == "yes" && ${PKGNAMESUFFIX} == "92"
.  ifdef USE_HADRIAN
PLIST=			${.CURDIR}/../ghc92/pkg-plist.hadrian
.  else
PLIST=			${.CURDIR}/../ghc92/pkg-plist
.  endif
.endif

# This version of ncurses is needed by bootstrap compiler
.if empty(PORT_OPTIONS:MBOOT)
BUILD_DEPENDS+=	${LOCALBASE}/lib/compat/libncursesw.so.8:misc/compat12x
.endif

.if empty(PORT_OPTIONS:MBOOT)
DISTFILES+=		ghc-${BOOT_GHC_VERSION}-boot-${ARCH}-freebsd${EXTRACT_SUFX}:boot
.   if !defined(IGNORE_MISSING_HADRIAN) && defined(USE_HADRIAN)
DISTFILES+=		hadrian-${GHC_VERSION}-boot.tar.gz:boot
.   endif
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
.ifdef USE_HADRIAN
	${SED} -e 's|%%DYNAMIC%%|${HADRIAN_SETTING_DYNAMIC}|' \
		-e 's|%%PROFILE%%|${HADRIAN_SETTING_PROFILE}|' \
		${PATCHDIR}/UserSettings.hs > ${WRKSRC}/hadrian/src/UserSettings.hs
.endif

pre-configure:
	# Call the bootstrap script
	cd ${WRKSRC}/ && ${BOOT_SCRIPT}
# If we are using bootstrap compiler, configure and install it into ${BOOT_DIR}
.if empty(PORT_OPTIONS:MBOOT)
	cd ${BOOT_DIR} && ${CONFIGURE_CMD} ${CONFIGURE_ENV} --prefix=${BOOT_INSTALL_DIR}
	cd ${BOOT_DIR} && ${MAKE_CMD} PACKAGES='' install
.endif
.ifdef USE_HADRIAN
# Compile Hadrian
	cd ${WRKSRC}/hadrian/bootstrap && \
		./bootstrap.py -w ${BOOT_GHC} -s ${DISTDIR}/hadrian-${GHC_VERSION}-boot.tar.gz
.endif

.ifdef USE_HADRIAN
pre-install:
	cd ${INSTALL_WRKSRC} && ${CONFIGURE_CMD} ${CONFIGURE_ENV} --prefix=${PREFIX}
.endif

post-install:
.ifdef USE_HADRIAN
# Hadrian doesn't have --docdir
	${MV} ${STAGEDIR}${DOCSDIR}-${GHC_VERSION} ${STAGEDIR}${DOCSDIR}
# These includes are duplicated in lib/ghc-X.Y.Z/lib/<triple>/rts-X.Y.Z/include
	${RM} -r ${STAGEDIR}${PREFIX}/include/*
.endif
	${FIND} ${STAGEDIR}${DOCSDIR} -name .buildinfo -delete
# For some reason, INSTALL_TARGET=install-strip doesn't cause libraries to be stripped
# Run strip on them manually
	${FIND} ${STAGEDIR}${PREFIX}/lib/ghc-${GHC_VERSION} -type f -perm +111 -exec ${STRIP_CMD} {} +
	${FIND} ${STAGEDIR}${PREFIX}/lib/ghc-${GHC_VERSION} -name '*.so' -exec ${STRIP_CMD} {} +
	${RM} ${STAGEDIR}${PREFIX}/bin/haddock
.if ${SLAVE_PORT} == "yes"
.  ifndef USE_HADRIAN
	${MV} ${STAGEDIR}${PREFIX}/bin/hsc2hs ${STAGEDIR}${PREFIX}/bin/hsc2hs-ghc-${GHC_VERSION}
.  endif
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

.if exists(${BOOT_INSTALL_DIR}/bin/runhaskell)
RUNHASKELL?=	${BOOT_INSTALL_DIR}/bin/runhaskell
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
.ifndef USE_HADRIAN
	cd ${WRKSRC} \
		&& ${ECHO_CMD} "BIN_DIST_NAME=ghc-${GHC_VERSION}-boot" >> mk/build.mk \
		&& ${ECHO_CMD} "BIN_DIST_TAR=ghc-${GHC_VERSION}-boot.tar" >> mk/build.mk \
		&& ${ECHO_CMD} "HADDOCK_DOCS=NO" >> mk/build.mk \
		&& ${GMAKE} binary-dist TAR_COMP=xz \
		&& ${MV} ${WRKSRC}/ghc-${GHC_VERSION}-boot-${GHC_ARCH}-portbld-freebsd.tar.xz /tmp/ghc-${GHC_VERSION}-boot-${ARCH}-freebsd.tar.xz
.else
	cd ${WRKSRC} \
		&& ${HADRIAN_CMD} binary-dist-xz \
		&& ${MV} ${WRKSRC}/_build/bindist/ghc-${GHC_VERSION}-${CONFIGURE_TARGET}.tar.xz /tmp/ghc-${GHC_VERSION}-boot-${ARCH}-freebsd.tar.xz
.endif

	@cd /tmp \
		&& sha256 ghc-${GHC_VERSION}-boot-${ARCH}-freebsd.tar.xz \
		&& ${ECHO_CMD} -n "SIZE (ghc-${GHC_VERSION}-boot-${ARCH}-freebsd.tar.xz) = " \
		&& ${STAT} -f %z ghc-${GHC_VERSION}-boot-${ARCH}-freebsd.tar.xz

# Much like create-bootstrap, just different naming and output format
# Set DYNAMIC, GMP and PROFILE to ON, and DOCS to OFF when generating Stack bindist
.PHONY: create-stack-bindist
create-stack-bindist:
.ifndef USE_HADRIAN
	cd ${WRKSRC} \
		&& ${GMAKE} binary-dist TAR_COMP=xz \
		&& ${MV} ${WRKSRC}/ghc-${GHC_VERSION}-${GHC_ARCH}-portbld-freebsd.tar.xz /tmp/
.else
	cd ${WRKSRC} \
		&& ${HADRIAN_CMD} binary-dist-xz \
		&& ${MV} ${WRKSRC}/_build/bindist/ghc-${GHC_VERSION}-${GHC_ARCH}-portbld-freebsd.tar.xz /tmp/
.endif

	cd /tmp \
		&& ${ECHO_CMD} "${GHC_VERSION}:" \
		&& ${ECHO_CMD} "url: \"http://distcache.FreeBSD.org/local-distfiles/arrowd/stack-bindists/ghc-${GHC_VERSION}-${GHC_ARCH}-portbld-freebsd.tar.xz\"" \
		&& ${ECHO_CMD} -n "content-length: " \
		&& ${STAT} -f %z ghc-${GHC_VERSION}-${GHC_ARCH}-portbld-freebsd.tar.xz \
		&& ${ECHO_CMD} -n "sha1: " \
		&& sha1 -q ghc-${GHC_VERSION}-${GHC_ARCH}-portbld-freebsd.tar.xz \
		&& ${ECHO_CMD} -n "sha256: " \
		&& sha256 -q ghc-${GHC_VERSION}-${GHC_ARCH}-portbld-freebsd.tar.xz

.PHONY: create-hadrian-bootstrap
create-hadrian-bootstrap:
.if !empty(PORT_OPTIONS:MBOOT)
	@${ECHO_CMD} "Generating Hadrian bootstrap without bootstrap GHC isn't supported"
	${FALSE}
.endif
	${MAKE} -C ${.CURDIR} patch build-depends USE_PACKAGE_DEPENDS_ONLY=yes IGNORE_MISSING_HADRIAN=yes
# We always would need to create our own plan.json file and put it into PATCHDIR:
# Predefined plans use integer-gmp, while we build bootstraps with integer-simple
# Predefined plans aren't pretty-printed, so we can't easily patch them
	cd ${WRKSRC}/hadrian/bootstrap && \
		./bootstrap.py -w ${BOOT_GHC} --deps ${HADRIAN_PLAN} fetch -o /tmp/hadrian-${GHC_VERSION}-boot

	@cd /tmp \
		&& sha256 hadrian-${GHC_VERSION}-boot.tar.gz \
		&& ${ECHO_CMD} -n "SIZE (hadrian-${GHC_VERSION}-boot.tar.gz) = " \
		&& ${STAT} -f %z hadrian-${GHC_VERSION}-boot.tar.gz
	@${ECHO_CMD}
	@${ECHO_CMD} "Remember to check that hadrian bootstrap builds fine by running \"make check-hadrian-bootstrap\""

.PHONY: check-hadrian-bootstrap
check-hadrian-bootstrap:
.if !empty(PORT_OPTIONS:MBOOT)
	@${ECHO_CMD} "Generating Hadrian bootstrap without bootstrap GHC isn't supported"
	${FALSE}
.endif
# Install bootstrap GHC
	${MAKE} -C ${.CURDIR} pre-configure
# Compile Hadrian
	cd ${WRKSRC}/hadrian/bootstrap && \
		./bootstrap.py -w ${BOOT_GHC} -s /tmp/hadrian-${GHC_VERSION}-boot.tar.gz

.include <bsd.port.post.mk>
