PORTNAME=	lightning
PORTVERSION=	2.2.2
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Generates assembly language code at run-time
WWW=		https://www.gnu.org/software/lightning/

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386 mips powerpc powerpc64 powerpc64le powerpcspe riscv64

USES=		cpe libtool pathfix
CPE_VENDOR=	gnu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-disassembler=no
INSTALL_TARGET=	install-strip
TEST_TARGET=	check
USE_LDCONFIG=	yes

PLIST_SUB=	JIT_ARCH=${ARCH:S/i386/x86/:S/amd64/x86/:S/x86_64/x86/:C/powerpc.*/ppc/:C/armv./arm/:S/riscv64/riscv/}

INFO=		lightning

OPTIONS_DEFINE=	ASSERTIONS

ASSERTIONS_DESC=Enable runtime code generation assertions
ASSERTIONS_CONFIGURE_ON=--enable-assertions=yes
ASSERTIONS_CONFIGURE_OFF=--enable-assertions=no

.include <bsd.port.pre.mk>

.if ${ARCH:Marmv?}
USE_GCC=	yes
.endif

pre-configure:
	@${REINPLACE_CMD} -e \
		's|%%CC%%|${CC:T}|' ${WRKSRC}/check/lightning.c

.include <bsd.port.post.mk>
