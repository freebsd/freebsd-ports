# Created by: Gautam Mani <execve@gmail.com>

PORTNAME=	stockfish
DISTVERSIONPREFIX=	sf_
DISTVERSION=	13
CATEGORIES=	games
MASTER_SITES=	https://tests.stockfishchess.org/api/nn/:nnue
DISTFILES=	nn-${_NNUE_VER}.nnue:nnue
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	execve@gmail.com
COMMENT=	Open source chess engine

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../Copying.txt

BROKEN_aarch64=	Fails to build: cannot detect architecture
BROKEN_armv6=	Fails to configure: config-sanity: Error 1
BROKEN_armv7=	Fails to configure: config-sanity: Error 1
BROKEN_mips64=	Fails to build: cannot detect architecture
BROKEN_riscv64=	Fails to configure: config-sanity: Error 1
NOT_FOR_ARCHS=	sparc64

USES=		compiler:c++11-lang gmake perl5
USE_GITHUB=	yes
GH_ACCOUNT=	official-stockfish
GH_PROJECT=	Stockfish
USE_PERL5=	build

LDFLAGS+=	-fuse-ld=lld

_NNUE_VER=	62ef826d1a6d

WRKSRC_SUBDIR=	src
MYARCH=		${ARCH}
MYCC=		${CHOSEN_COMPILER_TYPE}
TGTBLD=		build

PLIST_FILES=	bin/stockfish
PORTDOCS=	README.md

#POPCNT AVX2 BMI2
OPTIONS_DEFINE=		DOCS
OPTIONS_RADIO=		MACHDEP
OPTIONS_RADIO_MACHDEP=	AVX2 BMI2 POPCNT

AVX2_DESC=	Use the AVX2 instruction set
BMI2_DESC=	Use the BMI2 instruction set
POPCNT_DESC=	Use the POPCNT instruction

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPOPCNT} && ${ARCH} != amd64
BROKEN=		POPCNT compiles only on amd64
.endif

.if ${PORT_OPTIONS:MAVX2} && ${ARCH} != amd64
BROKEN=		AVX compiles only on amd64
.endif

.if ${PORT_OPTIONS:MBMI2} && ${ARCH} != amd64
BROKEN=		BMI compiles only on amd64
.endif

# workaround the ARCH usage in the stockfish Makefile
.if ${ARCH} == "i386"
MYARCH=		x86-32
.elif ${ARCH} == "amd64"
.  if ${PORT_OPTIONS:MBMI2}
MYARCH=		x86-64-bmi2
.  elif ${PORT_OPTIONS:MAVX2}
MYARCH=		x86-64-avx2
.  elif ${PORT_OPTIONS:MPOPCNT}
MYARCH=		x86-64-modern
.  else
MYARCH=		x86-64
.  endif
.elif ${ARCH} == powerpc
MYARCH=		ppc-32
.elif ${ARCH:Mpowerpc64*}
MYARCH=		ppc-64
.endif

ALL_TARGET=	${TGTBLD} ARCH=${MYARCH} COMP=${MYCC}

post-patch:
	@${CP} ${_DISTDIR}/nn-${_NNUE_VER}.nnue ${WRKSRC}/.
	@${REINPLACE_CMD} -e "s/^PREFIX =/PREFIX ?=/" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s/CXX=g++/CXX=g++${GCC_DEFAULT}/" \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stockfish ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
