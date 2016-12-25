# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

# To configure the Linux kernel yourself run
#
#   make _menuconfig
#
# first, afterwards proceed with the normal port installation.  This
# is optional.
#
# By default the Linux config file is saved in work/linux-config.  You
# can override it by setting LINUX_KCONFIG. If you need it later copy
# it somewhere else before running make clean, or it's gone!
#
# To use an existing Linux config file pass the absolute path with
# LINUX_KCONFIG=/path/to/linux/config to the port (on the command line
# or via /etc/make.conf).  Enabling either the XEN or KVM option will
# merge the KVM/XEN-specific default config with your own.
#
# You can run any Makefile targets of Linux by prefixing it with an
# underscore (_).  This setups a build environment for you so has
# benefits over going to ${WRKSRC} yourself.
#
# You won't be able to build 64-bit kernels on FreeBSD/i386.  gcc is
# missing support for this.
#
# By default the kernel is installed into ${PREFIX}/linux-kernel.
# Override by setting LINUX_INSTALL_PATH.  Same for kernel modules and
# LINUX_MOD_INSTALL_PATH.

PORTNAME=	linux-kernel
PORTVERSION=	4.9
CATEGORIES=	devel
MASTER_SITES=	KERNEL_ORG/linux/kernel/v4.x
DISTNAME=	linux-${DISTVERSION}

MAINTAINER=	t@tobik.me
COMMENT=	Linux kernel

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash \
		gcp:sysutils/coreutils \
		gsed:textproc/gsed \
		gnubc>0:math/gnubc

# USE_GCC adds a run dependency on gcc, which is nonsense for this
# port so we add a binutils and gcc build dependency ourselves.  Using
# 'gcc>0' to always install gcc even on FreeBSD 9.3, where base's gcc
# is too old.
BUILD_DEPENDS+=	gcc>0:lang/gcc \
		binutils>0:devel/binutils

USES=		tar:xz gmake ncurses perl5 shebangfix

SHEBANG_FILES=	scripts/check_extable.sh \
		scripts/coccicheck \
		scripts/config \
		scripts/decode_stacktrace.sh \
		scripts/gfp-translate \
		scripts/kernel-doc \
		scripts/mkuboot.sh \
		scripts/objdiff

ONLY_FOR_ARCHS=	i386 amd64

# Override LINUX_KCONFIG to set the Linux configuration file to use
LINUX_KCONFIG?=	${WRKDIR}/linux-config
.if !exists(${LINUX_KCONFIG})
ALL_TARGET=	defconfig
.endif

OPTIONS_DEFINE=	FIRMWARE KVM MODULES XEN
OPTIONS_DEFAULT=	KVM

FIRMWARE_DESC=	Install firmware
KVM_DESC=	KVM guest kernel support
MODULES_DESC=	Build and install kernel modules
XEN_DESC=	Xen dom0 and guest kernel support

.include <bsd.port.pre.mk>

# Unfortunately options helpers can't be used here.  KVM_ALL_TARGET
# would append 'kvmconfig' to the end of ALL_TARGET but it needs to go
# before 'bzImage'.

.if ${PORT_OPTIONS:MKVM}
ALL_TARGET+=	kvmconfig
.endif

.if ${PORT_OPTIONS:MXEN}
ALL_TARGET+=	xenconfig
.endif

ALL_TARGET+=	bzImage
INSTALL_TARGET=	install

.if ${PORT_OPTIONS:MMODULES}
ALL_TARGET+=	modules
INSTALL_TARGET+=	modules_install
.endif

.if ${PORT_OPTIONS:MFIRMWARE}
INSTALL_TARGET+=	firmware_install
.endif

# Setup build environment
## For menuconfig, config, etc.
HOST_EXTRACFLAGS+=	-DCURSES_LOC='<ncurses.h>' -DKBUILD_NO_NLS=1
HOST_LOADLIBES+=	-Wl,-rpath=${LOCALBASE}/lib
LINUX_ARCH?=	x86
LINUX_SUBARCH?=	x86
LINUX_INSTALL_PATH?=	${PREFIX}/linux-kernel
LINUX_MOD_INSTALL_PATH?=	${LINUX_INSTALL_PATH}
## Pretend to be Linux (for ACPI)
KCFLAGS+=		-D_LINUX -D__linux__
HOST_EXTRACFLAGS+=	-I${BUILD_WRKSRC}/freebsd-build-support/include
## Make sure ${LOCALBASE}/bin is in the PATH for Poudriere/Synth
MAKE_ENV+=	PATH="${BUILD_WRKSRC}/freebsd-build-support/bin:${LOCALBASE}/bin:${PATH}" \
		HOST_EXTRACFLAGS="${HOST_EXTRACFLAGS}" \
		HOST_LOADLIBES="${HOST_LOADLIBES}" \
		KCFLAGS="${KCFLAGS}" \
		BASH="${LOCALBASE}/bin/bash"
MAKE_ARGS+=	ARCH="${LINUX_ARCH}" \
		SUBARCH="${LINUX_SUBARCH}" \
		KCONFIG_CONFIG="${LINUX_KCONFIG}" \
		INSTALL_PATH="${STAGEDIR}${LINUX_INSTALL_PATH}" \
		INSTALL_MOD_PATH="${STAGEDIR}${LINUX_MOD_INSTALL_PATH}" \
		V=1

post-patch:
# Create empty include files which Linux' build tools require, but
# are not needed on FreeBSD.  Saves us from patching code.
	@${MKDIR} ${WRKSRC}/freebsd-build-support/include
	@${TOUCH} ${WRKSRC}/freebsd-build-support/include/byteswap.h
	@${TOUCH} ${WRKSRC}/freebsd-build-support/include/endian.h
	@${TOUCH} ${WRKSRC}/freebsd-build-support/include/features.h
# Setup some tools that Linux' build system uses where FreeBSD's
# versions are not compatible enough with GNU's.
	@${MKDIR} ${WRKSRC}/freebsd-build-support/bin
	@${LN} -s ${LOCALBASE}/bin/gcp ${WRKSRC}/freebsd-build-support/bin/cp
	@${LN} -s ${LOCALBASE}/bin/gsed ${WRKSRC}/freebsd-build-support/bin/sed
# Some scripts expect the config file in /.config
	@${LN} -sf ${LINUX_KCONFIG} ${WRKSRC}/.config

# Run Makefile targets of Linux with e.g. make _menuconfig.  Run make
# _help to see a list of available targets.  Prefix targets with _.
# Some of Linux' targets are duplicates of the ports tree's and this
# should hopefully prevent conflicts between them.
.for target in ${.TARGETS:M_*}
${target}: patch
	@(cd ${BUILD_WRKSRC} && ${DO_MAKE_BUILD} ${target:S/_//})
	@${ECHO} "Linux configuration file: ${LINUX_KCONFIG}"
.endfor

pre-build:
	@${ECHO} "using ${LINUX_KCONFIG}"

pre-install:
	@${MKDIR} ${STAGEDIR}${LINUX_INSTALL_PATH}
	@${MKDIR} ${STAGEDIR}${LINUX_MOD_INSTALL_PATH}

post-install:
# With the multitude of options available in the Linux kernel
# maintaining a proper plist is going to be near impossible, so we
# generate it on the fly here.
	@(cd ${STAGEDIR}${PREFIX} && \
		${FIND} -s linux-kernel -type f -o -type l >> ${TMPPLIST})

.include <bsd.port.post.mk>
