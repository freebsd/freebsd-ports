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

ONLY_FOR_ARCHS=		aarch64 amd64

BUILD_DEPENDS=		${LOCALBASE}/lib/libgmp.so:math/gmp

USES=			autoreconf compiler:c11 gmake \
			ncurses perl5 python:build shebangfix \
			tar:xz

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--docdir=${DOCSDIR}
CONFIGURE_ENV=		ALEX=/usr/bin/true HAPPY=/usr/bin/true
USE_LOCALE=		en_US.UTF-8
NO_CCACHE=		yes
OPTIONS_SUB=		yes
SHEBANG_FILES=		${BOOT_SCRIPT}

OPTIONS_DEFINE?=	DYNAMIC GMP PROFILE DOCS PDFDOCS
OPTIONS_DEFAULT=	DYNAMIC PROFILE GMP

OPTIONS_GROUP=		BOOTSTRAP
BOOTSTRAP_DESC=		Bootsrap using installed ghc
OPTIONS_GROUP_BOOTSTRAP=BOOT

BOOT_DESC=		Use installed GHC for bootstrapping
DOCS_DESC=		Build and install HTML documentation
PDFDOCS_DESC=		Build and install PDF documentation
DYNAMIC_DESC=		Add support for dynamic linking
GMP_DESC=		Use GNU Multi-precision Library from Ports
PROFILE_DESC=		Add support for performance profiling

BOOT_CONFIGURE_ENV=	GHC=${LOCALBASE}/bin/ghc
BOOT_CONFIGURE_ENV_OFF=	GHC=${BOOT_GHC} LLC=llc${BOOT_LLVM_VERSION} OPT=opt${BOOT_LLVM_VERSION}

DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx
DOCS_VARS=		enable_docs=YES hadrian_docs_arg=--docs=no-sphinx-pdfs
DOCS_VARS_OFF=		enable_docs=NO hadrian_docs_arg=--docs=none

PDFDOCS_IMPLIES=	DOCS
PDFDOCS_BUILD_DEPENDS=	xelatex:print/tex-xetex \
			${LOCALBASE}/share/fonts/dejavu/DejaVuSans.ttf:x11-fonts/dejavu
PDFDOCS_VARS=		hadrian_docs_arg=

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

GHC_VERSION?=		9.8.4
LLVM_VERSION?=		15
BOOT_GHC_VERSION?=	9.6.7
# LLVM version that bootstrap compiler uses
BOOT_LLVM_VERSION?=	12

BASE_PACKAGES?=		Cabal-3.10.3.0 array-0.5.8.0 base-4.19.2.0 binary-0.8.9.1 \
			bytestring-0.12.1.0 containers-0.6.8 deepseq-1.5.1.0 \
			directory-1.3.8.5 exceptions-0.10.7 filepath-1.4.301.0 \
			ghc-${GHC_VERSION} ghc-bignum-1.3 ghc-compact-0.1.0.0 \
			ghc-prim-0.11.0 haskeline-0.8.2.1 hpc-0.7.0.0 \
			integer-gmp-1.1 mtl-2.3.1 parsec-3.1.17.0 pretty-1.1.3.6 \
			process-1.6.25.0 stm-2.5.3.1 semaphore-compat-1.0.0 \
			template-haskell-2.21.0.0 terminfo-0.4.1.6 text-2.1.1 \
			time-1.12.2 transformers-0.6.1.0 unix-2.8.6.0 \
			xhtml-3000.2.2.1

.for pkg in ${BASE_PACKAGES}
PLIST_SUB+=	${pkg:C/-([0-9.])+//:tu}_VERSION=${pkg:C/^([^\.]*-)+//}
.endfor

.include <bsd.port.pre.mk>

BOOT_SCRIPT?=	./boot.source

.if ${SLAVE_PORT} != "yes"
PORTDOCS=		*
HADRIAN_PLAN=		${PATCHDIR}/plan-bootstrap-${BOOT_GHC_VERSION:C/\./_/g}.json
.else
HADRIAN_DOCS_ARG=	--docs=none
HADRIAN_PLAN=		${MASTERDIR}/files/plan-bootstrap-${BOOT_GHC_VERSION:C/\./_/g}.json
PLIST_SUB+=		GMP=
.endif

LIB_DEPENDS+=		libffi.so:devel/libffi
.undef DYNAMIC_CONFIGURE_WITH
CONFIGURE_ARGS+=	--with-system-libffi --with-ffi-includes=${LOCALBASE}/include --with-ffi-libraries=${LOCALBASE}/lib
CONFIGURE_ENV+=		CC=${CC} CXX=${CXX}
SHEBANG_FILES+=		hadrian/bootstrap/bootstrap.py
HADRIAN_CMD=		${WRKSRC}/hadrian/bootstrap/_build/bin/hadrian ${HADRIAN_DOCS_ARG} ${HADRIAN_GMP_ARG}
DO_MAKE_BUILD=		${SETENVI} ${WRK_ENV} ${HADRIAN_CMD} ${_MAKE_JOBS} --flavour=ports
ALL_TARGET=		binary-dist-dir
INSTALL_WRKSRC=		${WRKSRC}/_build/bindist/ghc-${GHC_VERSION}-${CONFIGURE_TARGET}

.if (empty(PORT_OPTIONS:MDYNAMIC) || empty(PORT_OPTIONS:MPROFILE))
IGNORE=			Building with Hadrian requires both DYNAMIC and PROFILE for now
.endif

GHC_ARCH=		${ARCH:S/amd64/x86_64/:C/armv.*/arm/}
CONFIGURE_TARGET=	${GHC_ARCH}-portbld-${OPSYS:tl}
BOOT_DIR=		${WRKDIR}/ghc-${BOOT_GHC_VERSION}-${CONFIGURE_TARGET}
BOOT_INSTALL_DIR=	${WRKDIR}/ghc-boot-install
BOOT_GHC=		${BOOT_INSTALL_DIR}/bin/ghc-${BOOT_GHC_VERSION}

PLIST_SUB+=		GHC_ARCH=${GHC_ARCH}

.if empty(PORT_OPTIONS:MBOOT)
DISTFILES+=		ghc-${BOOT_GHC_VERSION}-boot-${ARCH}-freebsd${EXTRACT_SUFX}:boot
.endif # MBOOT

.if !defined(IGNORE_MISSING_HADRIAN)
DISTFILES+=		hadrian-${GHC_VERSION}-boot.tar.gz:boot
.endif

.if ${ARCH} == aarch64
CONFIGURE_TARGET=	${ARCH}-unknown-freebsd${"${ARCH:Maarch64}" != "":?:-gnueabihf}
CONFIGURE_ARGS+=	--host=${CONFIGURE_TARGET}
.endif

post-patch:
	${SED} -e 's|%%DYNAMIC%%|${HADRIAN_SETTING_DYNAMIC}|' \
		-e 's|%%PROFILE%%|${HADRIAN_SETTING_PROFILE}|' \
		${PATCHDIR}/UserSettings.hs > ${WRKSRC}/hadrian/src/UserSettings.hs

pre-configure:
	# Call the bootstrap script
	cd ${WRKSRC}/ && ${BOOT_SCRIPT}
# If we are using bootstrap compiler, configure and install it into ${BOOT_DIR}
.if empty(PORT_OPTIONS:MBOOT)
	cd ${BOOT_DIR} && ${CONFIGURE_CMD} ${CONFIGURE_ENV} --prefix=${BOOT_INSTALL_DIR}
	cd ${BOOT_DIR} && ${SETENVI} ${WRK_ENV} ${GMAKE} PACKAGES='' install
.endif
# Compile Hadrian
	cd ${WRKSRC}/hadrian/bootstrap && \
		./bootstrap.py -w ${BOOT_GHC} -s ${DISTDIR}/hadrian-${GHC_VERSION}-boot.tar.gz

pre-install:
	cd ${INSTALL_WRKSRC} && ${CONFIGURE_CMD} ${CONFIGURE_ENV} --prefix=${PREFIX}

post-install:
# Hadrian doesn't have --docdir
	${MV} ${STAGEDIR}${DOCSDIR}-${GHC_VERSION} ${STAGEDIR}${DOCSDIR}
# These includes are duplicated in lib/ghc-X.Y.Z/lib/<triple>/rts-X.Y.Z/include
	${RM} -r ${STAGEDIR}${PREFIX}/include/*
	${FIND} ${STAGEDIR}${DOCSDIR} -name .buildinfo -delete
	${FIND} ${STAGEDIR}${PREFIX}/lib/ghc-${GHC_VERSION} -type f -perm +111 -exec ${STRIP_CMD} {} +
	${FIND} ${STAGEDIR}${PREFIX}/lib/ghc-${GHC_VERSION} -name '*.so' -exec ${STRIP_CMD} {} +
	${RM} ${STAGEDIR}${PREFIX}/bin/haddock
.if ${SLAVE_PORT} == "yes"
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

# Create a bootstrap compiler tar ball: run this in an interactive poudriere jail
# Set all OPTIONS to OFF when generating bootstraps
.PHONY: create-bootstrap
create-bootstrap:
	cd ${WRKSRC} \
		&& ${HADRIAN_CMD} binary-dist-xz \
		&& ${MV} ${WRKSRC}/_build/bindist/ghc-${GHC_VERSION}-${CONFIGURE_TARGET}.tar.xz /tmp/ghc-${GHC_VERSION}-boot-${ARCH}-freebsd.tar.xz
	@cd /tmp \
		&& sha256 ghc-${GHC_VERSION}-boot-${ARCH}-freebsd.tar.xz \
		&& ${ECHO_CMD} -n "SIZE (ghc-${GHC_VERSION}-boot-${ARCH}-freebsd.tar.xz) = " \
		&& ${STAT} -f %z ghc-${GHC_VERSION}-boot-${ARCH}-freebsd.tar.xz

# Much like create-bootstrap, just different naming and output format
# Set DYNAMIC, GMP and PROFILE to ON, and DOCS to OFF when generating Stack bindist
.PHONY: create-stack-bindist
create-stack-bindist:
	cd ${WRKSRC} \
		&& ${HADRIAN_CMD} binary-dist-xz \
		&& ${MV} ${WRKSRC}/_build/bindist/ghc-${GHC_VERSION}-${GHC_ARCH}-portbld-freebsd.tar.xz /tmp/
	@cd /tmp \
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
# Compile Hadrian
	cd ${WRKSRC}/hadrian/bootstrap && \
		./bootstrap.py -w ${BOOT_GHC} -s /tmp/hadrian-${GHC_VERSION}-boot.tar.gz

.include <bsd.port.post.mk>
