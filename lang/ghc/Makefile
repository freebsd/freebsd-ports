# Created by: Simon Marlow <simonmar@microsoft.com>

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

ONLY_FOR_ARCHS=	amd64 i386 aarch64 armv6 armv7

USES=			autoreconf compiler:c11 gmake iconv:patch,translit \
			localbase:ldflags ncurses perl5 tar:xz

USE_LOCALE=		en_US.UTF-8
USE_PERL5=		build
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--docdir=${DOCSDIR}
NO_CCACHE=		yes

SUB_FILES=		build.mk
SUB_LIST=		NCURSESINC="${NCURSESBASE}/include" NCURSESLIB="${NCURSESLIB}" \
			CFLAGS="${CFLAGS}"

OPTIONS_DEFINE=		DYNAMIC GMP PROFILE DOCS
OPTIONS_DEFAULT=	DYNAMIC PROFILE GMP

OPTIONS_GROUP=		BOOTSTRAP
BOOTSTRAP_DESC=		Bootsrap using installed ghc
OPTIONS_GROUP_BOOTSTRAP=BOOT

BOOT_DESC=		Use installed GHC for bootstrapping
DOCS_DESC=		Install HTML documentation
DYNAMIC_DESC=		Add support for dynamic linking
GMP_DESC=		Use GNU Multi-precision Library from Ports
PROFILE_DESC=		Add support for performance profiling

DOCS_BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx

DYNAMIC_CONFIGURE_WITH=	system-libffi \
			ffi-includes=${LOCALBASE}/include \
			ffi-libraries=${LOCALBASE}/lib
DYNAMIC_LIB_DEPENDS=	libffi.so:devel/libffi
DYNAMIC_SUB_LIST=	WITH_DYNAMIC="YES"
DYNAMIC_SUB_LIST_OFF=	WITH_DYNAMIC="NO"
DYNAMIC_PLIST_SUB=	NODYNAMIC="@comment "
DYNAMIC_PLIST_SUB_OFF=	NODYNAMIC=""

GMP_CONFIGURE_WITH=	gmp-includes=${LOCALBASE}/include \
			gmp-libraries=${LOCALBASE}/lib
GMP_LIB_DEPENDS=	libgmp.so:math/gmp

# Append substitutions for build.mk
BOOT_SUB_LIST=		HSC2HS=${LOCALBASE}/bin/hsc2hs
BOOT_SUB_LIST_OFF=	HSC2HS=${BOOT_HSC2HS}

PROFILE_SUB_LIST=	WITH_PROFILE="YES"
PROFILE_SUB_LIST_OFF=	WITH_PROFILE="NO"

GHC_VERSION=		9.2.2
LLVM_VERSION=		12
BOOT_GHC_VERSION=	8.10.7
# LLVM version that bootstrap compiler uses
BOOT_LLVM_VERSION=	10

OPTIONS_SUB=		yes

BASE_PACKAGES=		Cabal:3.6.3.0 array:0.5.4.0 base:4.16.1.0 binary:0.8.9.0 \
			bytestring:0.11.3.0 containers:0.6.5.1 deepseq:1.4.6.1 \
			directory:1.3.6.2 exceptions:0.10.4 filepath:1.4.2.2 \
			ghc:${GHC_VERSION} ghc-bignum:1.2 ghc-boot:${GHC_VERSION} \
			ghc-boot-th:${GHC_VERSION} ghc-compact:0.1.0.0 \
			ghc-heap:${GHC_VERSION} ghc-prim:0.8.0 \
			ghci:${GHC_VERSION} haskeline:0.8.2 hpc:0.6.1.0 \
			integer-gmp:1.1 libiserv:${GHC_VERSION} mtl:2.2.2 \
			parsec:3.1.15.0 pretty:1.3.3.6 process:1.6.13.2 \
			stm:2.5.0.2 template-haskell:2.18.0.0 terminfo:0.4.1.5 \
			text:1.2.5.0 time:1.11.1.1 transformers:0.5.6.2 \
			unix:2.7.2.2 xhtml:3000.2.2.1

.for pkg in ${BASE_PACKAGES}
PLIST_SUB+=	${pkg:C/\:.*//:tu}_VERSION=${pkg:C/^[^\:]*(\:|\$)//}
.endfor

PORTDOCS=		*

.include <bsd.port.pre.mk>

CONFIGURE_TARGET=	${GHC_ARCH}-portbld-${OPSYS:tl}

# This version of ncurses is needed by bootstrap compiler
.if ${OSVERSION} > 1300078 && empty(PORT_OPTIONS:MBOOT)
BUILD_DEPENDS+=	${LOCALBASE}/lib/compat/libncursesw.so.8:misc/compat12x
.endif

GHC_ARCH=		${ARCH:S/amd64/x86_64/:C/armv.*/arm/}
GHC_LIBDIR=		${STAGEDIR}${PREFIX}/lib/ghc-${GHC_VERSION}
GHC_LIBDIR_REL=		lib/ghc-${GHC_VERSION}

_EXECUTABLES=	${GHC_LIBDIR}/bin/unlit \
		${GHC_LIBDIR}/bin/hpc \
		${GHC_LIBDIR}/bin/ghc-iserv \
		${GHC_LIBDIR}/bin/ghc-pkg \
		${GHC_LIBDIR}/bin/hsc2hs \
		${GHC_LIBDIR}/bin/runghc \
		${GHC_LIBDIR}/bin/ghc \
		${GHC_LIBDIR}/bin/haddock \
		${GHC_LIBDIR}/bin/hp2ps

.if ${PORT_OPTIONS:MPROFILE}
_EXECUTABLES+=	${GHC_LIBDIR}/bin/ghc-iserv-prof
.endif
.if ${PORT_OPTIONS:MDYNAMIC}
_EXECUTABLES+=	${GHC_LIBDIR}/bin/ghc-iserv-dyn
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

.if empty(PORT_OPTIONS:MBOOT)
BOOT_DIR=	${WRKDIR}/ghc-${BOOT_GHC_VERSION}-boot
BOOT_GHC=	${BOOT_DIR}/bin/ghc-${BOOT_GHC_VERSION}

CONFIGURE_ENV+=		GHC=${BOOT_GHC}
.else # MBOOT
CONFIGURE_ENV+=		GHC=${LOCALBASE}/bin/ghc
.endif # MBOOT

# TODO: remove this after rerolling all bootstraps
post-patch:
.if empty(PORT_OPTIONS:MBOOT)
	@${REINPLACE_CMD} -e '/^mandir/d' ${BOOT_DIR}/mk/build.mk
	@${REINPLACE_CMD} -e '/^infodir/d' ${BOOT_DIR}/mk/build.mk
	@${REINPLACE_CMD} -e '/^docdir/d' ${BOOT_DIR}/mk/build.mk
	@${REINPLACE_CMD} -e '/^htmldir/d' ${BOOT_DIR}/mk/build.mk
.endif

pre-configure:
	# Copy the subbed build.mk to the proper position
	${CP} ${WRKDIR}/build.mk ${WRKSRC}/mk/build.mk

# If we are using bootstrap compiler, configure and install it into ${BOOT_DIR}
.if empty(PORT_OPTIONS:MBOOT)
	cd ${BOOT_DIR} && ${CONFIGURE_ENV} ${CONFIGURE_CMD} --prefix=${BOOT_DIR}
	cd ${BOOT_DIR} && PACKAGES='' ${MAKE_CMD} install
.endif

post-install:
	(for f in ${_EXECUTABLES} $$(${FIND} ${GHC_LIBDIR} -name '*.so*'); do \
		${STRIP_CMD} $$f; done)
	${FIND} ${STAGEDIR}${DOCSDIR}/html -name .buildinfo -delete
	${RM} ${STAGEDIR}${PREFIX}/bin/haddock

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
