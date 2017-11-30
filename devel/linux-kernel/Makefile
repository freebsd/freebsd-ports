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

PORTNAME=	linux
DISTVERSION=	4.13.14
CATEGORIES=	devel
MASTER_SITES=	KERNEL_ORG/linux/kernel/v4.x
PKGNAMESUFFIX=	-kernel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Linux kernel

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386

BUILD_DEPENDS=	bash:shells/bash \
		gcp:sysutils/coreutils \
		gnustat:sysutils/coreutils \
		gsed:textproc/gsed \
		gnubc>0:math/gnubc

USES=		tar:xz gmake ncurses perl5 shebangfix
USE_GCC=	yes
USE_PERL5=	build

SHEBANG_FILES=	scripts/check_extable.sh \
		scripts/coccicheck \
		scripts/config \
		scripts/decode_stacktrace.sh \
		scripts/gfp-translate \
		scripts/kernel-doc \
		scripts/mkuboot.sh \
		scripts/objdiff

# Override LINUX_KCONFIG to set the Linux configuration file to use
LINUX_KCONFIG?=	${WRKDIR}/linux-config
.if !exists(${LINUX_KCONFIG})
_PRE_ALL_TARGET=	defconfig
.endif

OPTIONS_DEFINE=	FIRMWARE KVM MODULES XEN
OPTIONS_DEFAULT=	KVM

FIRMWARE_DESC=	Install firmware
KVM_DESC=	KVM guest kernel support
MODULES_DESC=	Build and install kernel modules
XEN_DESC=	Xen dom0 and guest kernel support

FIRMWARE_VARS=	_POST_INSTALL_TARGET+=firmware-install
KVM_VARS=	_PRE_ALL_TARGET+=kvmconfig
MODULES_VARS=	_POST_ALL_TARGET+=modules \
		_POST_INSTALL_TARGET+=modules_install
XEN_VARS=	_PRE_ALL_TARGET+=xenconfig

# Order is important here e.g. kvmconfig needs to always go before bzImage
ALL_TARGET=	${_PRE_ALL_TARGET} bzImage ${_POST_ALL_TARGET}
INSTALL_TARGET=	${_PRE_INSTALL_TARGET} install ${_POST_INSTALL_TARGET}

# Setup build environment
## For menuconfig, config, etc.
BINARY_ALIAS=		cp=gcp gcc=${CC} make=gmake sed=gsed stat=gnustat
HOST_EXTRACFLAGS+=	-DCURSES_LOC='<ncurses.h>' -DKBUILD_NO_NLS=1
HOST_LOADLIBES+=	-Wl,-rpath=${LOCALBASE}/lib
LINUX_ARCH?=	x86
LINUX_SUBARCH?=	x86
LINUX_INSTALL_PATH?=	${PREFIX}/linux-kernel
LINUX_MOD_INSTALL_PATH?=	${LINUX_INSTALL_PATH}
## Pretend to be Linux (for ACPI)
KCFLAGS=		-D_LINUX -D__linux__
HOST_EXTRACFLAGS=	-I${BUILD_WRKSRC}/arch/${LINUX_ARCH}/include/uapi \
			-I${WRKDIR}/build-support
## Make sure ${LOCALBASE}/bin is in the PATH for Poudriere/Synth
MAKE_ENV=	PATH="${LOCALBASE}/bin:${PATH}" \
		HOST_EXTRACFLAGS="${HOST_EXTRACFLAGS}" \
		HOST_LOADLIBES="${HOST_LOADLIBES}" \
		KCFLAGS="${KCFLAGS}" \
		BASH="${LOCALBASE}/bin/bash"
MAKE_ARGS=	ARCH="${LINUX_ARCH}" \
		SUBARCH="${LINUX_SUBARCH}" \
		KCONFIG_CONFIG="${LINUX_KCONFIG}" \
		INSTALL_PATH="${STAGEDIR}${LINUX_INSTALL_PATH}" \
		INSTALL_MOD_PATH="${STAGEDIR}${LINUX_MOD_INSTALL_PATH}" \
		V=1

post-patch:
# Create empty include files which Linux' build tools require, but
# are not needed on FreeBSD.  Saves us from patching code.
	@${MKDIR} ${WRKDIR}/build-support/bits
	@${TOUCH} ${WRKDIR}/build-support/byteswap.h \
		${WRKDIR}/build-support/endian.h \
		${WRKDIR}/build-support/features.h
	@${CP} ${FILESDIR}/elf.h ${WRKDIR}/build-support
	@${CP} ${FILESDIR}/auxv.h ${WRKDIR}/build-support/bits
# Some scripts expect the config file in /.config
	@${LN} -sf ${LINUX_KCONFIG} ${WRKSRC}/.config

	@${REINPLACE_CMD} 's/,x86_64)$$/,amd64)/' \
		${WRKSRC}/arch/x86/Makefile
	@${REINPLACE_CMD} 's/x86_64/amd64/' ${WRKSRC}/Makefile

# Run Makefile targets of Linux with e.g. make _menuconfig.  Run make
# _help to see a list of available targets.  Prefix targets with _.
# Some of Linux' targets are duplicates of the ports tree's and this
# should hopefully prevent conflicts between them.
.for target in ${.TARGETS:M_*}
${target}: patch create-binary-alias
	@cd ${BUILD_WRKSRC} && ${DO_MAKE_BUILD} ${target:S/_//}
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

.include <bsd.port.mk>

RUN_DEPENDS:=	${RUN_DEPENDS:Ngcc*}
