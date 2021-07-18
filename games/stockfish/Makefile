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

USES=		compiler:c++11-lang gmake perl5
USE_GITHUB=	yes
GH_ACCOUNT=	official-stockfish
GH_PROJECT=	Stockfish
USE_PERL5=	build

MAKE_ARGS=	ARCH=${MYARCH} \
		COMP=${CHOSEN_COMPILER_TYPE} \
		CXX="${CXX}" \
		PREFIX=${PREFIX}
ALL_TARGET=	build
LDFLAGS+=	-fuse-ld=lld

_NNUE_VER=	62ef826d1a6d

WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/stockfish
PORTDOCS=	README.md

OPTIONS_DEFINE=		DOCS
OPTIONS_RADIO=		MACHDEP
OPTIONS_RADIO_MACHDEP=	AVX2 BMI2 POPCNT
OPTIONS_EXCLUDE=	${${ARCH} != amd64:?${OPTIONS_RADIO_MACHDEP}:}

AVX2_DESC=	Use the AVX2 instruction set
BMI2_DESC=	Use the BMI2 instruction set
POPCNT_DESC=	Use the POPCNT instruction

.include <bsd.port.options.mk>

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
.elif ${ARCH} == aarch64
MYARCH=		armv8
.elif ${ARCH} == armv7
MYARCH=		armv7-neon
.elif ${ARCH} == powerpc
MYARCH=		ppc-32
.elif ${ARCH:Mpowerpc64*}
MYARCH=		ppc-64
.elif ${ARCH:M*64*}
MYARCH=		general-64
.else
MYARCH=		general-32
.endif

post-patch:
	@${CP} ${_DISTDIR}/nn-${_NNUE_VER}.nnue ${WRKSRC}/.

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stockfish ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
