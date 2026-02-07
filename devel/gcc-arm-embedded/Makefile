PORTNAME=	gcc-arm-embedded
PORTVERSION=	${FULL_VERSION:S/.rel/r/}
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://developer.arm.com/-/media/Files/downloads/gnu/${FULL_VERSION}/srcrel/:src
DISTFILES=	arm-gnu-toolchain-src-snapshot-${FULL_VERSION}.tar.xz:src

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Complete GCC-based toolcahin for embedded ARM development
WWW=		https://developer.arm.com/Tools%20and%20Software/GNU%20Toolchain

LICENSE=	GPLv2 LGPL20 LGPL21 GPLv3 LGPL3
LICENSE_COMB=	multi

NOT_FOR_ARCHS=		arm armv6 armv7 mips mips64 mips64el mipsel mipsn32
NOT_FOR_ARCHS_REASON=	Very slow to build on emulator

BUILD_DEPENDS=	bash:shells/bash	\
		gfind:misc/findutils	\
		getopt>=0:misc/getopt

FLAVORS=		default aarch64
FLAVOR?=		${FLAVORS:[1]}

aarch64_PKGNAMESUFFIX=	-aarch64
aarch64_PLIST=		${PKGDIR}/pkg-plist.aarch64

USES=		compiler:c++14-lang cpe gmake libtool:keepla makeinfo \
		shebangfix tar:xz

USE_GITLAB=	nodefault
GL_SITE=	https://gitlab.arm.com:tools
GL_ACCOUNT=	tooling:tools
GL_PROJECT=	gnu-devtools-for-arm:tools
GL_TAGNAME=	v1.3.0:tools

SHEBANG_FILES=		gnu-devtools-for-arm/*.sh
USE_PYTHON=		noflavors

CPE_PRODUCT=	gcc
CPE_VENDOR=	gnu
CPE_VERSION=	${GCC_VERSION}

OPTIONS_DEFINE=	APROFILE PYGDB SYMLINK
OPTIONS_DEFAULT=APROFILE PYGDB SYMLINK
APROFILE_DESC=	Add support for Cortex-A profiles (valid only for default armv7 target)
PYGDB_DESC=	Build and install python-enabled gdb in addition to standard one
SYMLINK_DESC=	Make version-independent symlink ${LOCALBASE}/${PORTNAME}${PKGNAMESUFFX}

PYGDB_USES=	python
OPTIONS_SUB=	yes

WRKSRC=		${WRKDIR}/src
NO_WRKSUBDIR=	yes

GCC_VERSION=	14.2.1
FULL_VERSION=	14.2.rel1
DIR_NAME=	${PORTNAME}${PKGNAMESUFFIX}-${FULL_VERSION}

.if ${FLAVOR:U} != aarch64
TARGET=			arm-none-eabi
NEWLIB_NANO_BUILD_OP=	--enable-newlib-nano
MULTILIB_BUILD_OP=	--config-flags-gcc=--with-multilib-list=${MULTILIBS}
.else
TARGET=			aarch64-none-elf
NEWLIB_NANO_BUILD_OP=
MULTILIB_BUILD_OP=
.endif

PLIST_SUB+=	GCC_VERSION=${GCC_VERSION} FULL_VERSION=${FULL_VERSION} TARGET=${TARGET}

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc64*}
GMP_ABI=		ABI="mode64"
.else
GMP_ABI=
.endif

.if ${PORT_OPTIONS:MPYGDB}
PYGDB_BUILD_OPT=	--enable-gdb-with-python=${PYTHON_CMD}
.else
PYGDB_BUILD_OPT=
.endif

.if ${PORT_OPTIONS:MAPROFILE}
MULTILIBS=	aprofile,rmprofile
.else
MULTILIBS=	rmprofile
.endif

INFO_PATH=	${DIR_NAME}/share/info
INFO=		annotate as bfd binutils cpp cppinternals ctf-spec gcc gccinstall \
		gccint gdb gfortran gprof ld ldint porting sframe-spec stabs

MANDIRS=	${PREFIX}/${DIR_NAME}/share/man

.include <bsd.port.pre.mk>

post-extract:
	@${MV} ${WRKSRC}/gnu-devtools-for-arm-${GL_TAGNAME_tools} ${WRKSRC}/gnu-devtools-for-arm

do-build:
	${GMP_ABI}							\
	CC="${CC}"							\
	PATH=${WRKSRC}/gnu-devtools-for-arm:${PATH}			\
	installdir=${WRKDIR}/${DIR_NAME}				\
	LOCALBASE="${LOCALBASE}"					\
	 ${WRKSRC}/gnu-devtools-for-arm/build-baremetal-toolchain.sh 	\
		 -j ${MAKE_JOBS_NUMBER}					\
		 --builddir=${WRKDIR}/build				\
		 --target=${TARGET}					\
		 --check-gdb						\
		 --with-language=fortran				\
		 ${MULTILIB_BUILD_OP}					\
		 --srcdir=${WRKSRC}					\
		 --release						\
		 --no-package						\
		 ${NEWLIB_NANO_BUILD_OP}				\
		 ${PYGDB_BUILD_OPT}					\
		 start

# It is possible to istall by script directly ${STAGEDIR}${PREFIX}/${PKGNAME}
# and avoid this step, but then `restage` will not work.
do-install:
	@cd ${WRKDIR} && ${PAX} -l -r -w ${DIR_NAME} ${STAGEDIR}${PREFIX}

post-install-SYMLINK-on:
	@${LN} -s ${PKGNAME} ${STAGEDIR}${PREFIX}/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.post.mk>
