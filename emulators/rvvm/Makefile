PORTNAME=	RVVM
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6
CATEGORIES=	emulators
MASTER_SITES=	https://github.com/LekKit/patches-misc/releases/download/rvvm-uboot-2024.7/:fw \
		https://github.com/LekKit/riscv-tests/releases/download/rvvm-tests/:tests
DISTFILES=	${FWFILES:.bin=.bin:fw} riscv-tests.tar.gz:tests
DIST_SUBDIR=	rvvm-${DISTVERSION}
EXTRACT_ONLY=	${DISTFILE_DEFAULT}

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	RISC-V Virtual Machine

LICENSE=	GPLv2 GPLv3 MPL20
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSE-GPL
LICENSE_FILE_MPL20=	${WRKSRC}/LICENSE-MPL
LICENSE_DISTFILES_GPLv2=	${FWFILES}
LICENSE_DISTFILES_GPLv3=	${DISTFILE_DEFAULT}
LICENSE_DISTFILES_MPL20=	${DISTFILE_DEFAULT}

FLAVORS=	x11 nox11
FLAVOR?=	${FLAVORS:[1]}
nox11_PKGNAMESUFFIX=	-nox11

USES=		gmake localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	LekKit
USE_LDCONFIG=	yes

BUILDDIR=	${WRKDIR}/.build
MAKE_ENV+=	BUILDDIR=${BUILDDIR}
TEST_TARGET=	test
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	FDT FPU JIT JNI SPINLOCK_DEBUG NET PCI RV64
OPTIONS_DEFAULT=	FDT FPU JIT JNI SPINLOCK_DEBUG NET PCI RV64
FDT_DESC=	enable automatic FDT generation
FPU_DESC=	enable floating point (F/D) CPU extension
JIT_DESC=	enable RVJIT accelerator
JNI_DESC=	include native JNI bindings in shared librvvm
NET_DESC=	enable unprivileged userland networking stack
PCI_DESC=	enable PCI support in ATA, etc devices
RV64_DESC=	enable riscv64 CPU support
SPINLOCK_DEBUG_DESC=	enable deadlock debugging (minimal runtime overhead)

FWFILES=	fw_jump.bin fw_payload.bin

.for o in ${OPTIONS_DEFINE}
$o_MAKE_ENV=	USE_$o=1
$o_MAKE_ENV_OFF=	USE_$o=0
.endfor

.if ${FLAVOR} == x11
MAKE_ENV+=	USE_FB=1 USE_XSHM=1
USES+=		xorg
USE_XORG+=	x11 xext
.else
MAKE_ENV+=	USE_FB=0 USE_XSHM=0
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
MAKE_ENV+=	USE_DEBUG=1
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rvvm
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librvvm.so
	${MKDIR} ${STAGEDIR}${DATADIR}
.for f in ${FWFILES}
	${INSTALL_DATA} ${_DISTDIR}/$f ${STAGEDIR}${DATADIR}/
.endfor

pre-test:
	${LN} -sf ${_DISTDIR}/riscv-tests.tar.gz ${BUILDDIR}/

.include <bsd.port.post.mk>
