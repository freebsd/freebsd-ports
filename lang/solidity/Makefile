PORTNAME=	solidity
PORTVERSION=	0.8.23
CATEGORIES=	lang
MASTER_SITES=	https://github.com/ethereum/solidity/releases/download/v${PORTVERSION}/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Solidity Contract-Oriented Programming Language
WWW=		https://github.com/ethereum/solidity

LICENSE=	GPLv3

NOT_FOR_ARCHS=		powerpc powerpc64 powerpcspe
NOT_FOR_ARCHS_REASON=	solidity currently does not support big endian systems

BUILD_DEPENDS=	boost-libs>=0:devel/boost-libs \
		libfmt>=0:devel/libfmt \
		range-v3>=0:devel/range-v3
LIB_DEPENDS=	libjsoncpp.so:devel/jsoncpp

USES=		cmake compiler:c++14-lang cpe
CPE_VENDOR=	${PORTNAME}lang

OPTIONS_DEFINE=	Z3 CVC4
OPTIONS_DEFAULT=Z3 #CVC4
OPTIONS_EXCLUDE_i386=	Z3
Z3_DESC=	SMT Checker via Z3
CVC4_DESC=	SMT Checker via CVC4
Z3_LIB_DEPENDS=		libz3.so:math/z3
CVC4_LIB_DEPENDS=	libcvc5.so:math/cvc5 libgmp.so:math/gmp
Z3_CMAKE_OFF=	USE_Z3
CVC4_CMAKE_OFF=	USE_CVC4
CVC4_BROKEN=	solidity uses cvc4 which has been succeeded by cvc5

CMAKE_ARGS+=	-DUSE_LD_GOLD=OFF -DTESTS=OFF \
		-DRANGE_V3_INCLUDE_DIR="${LOCALBASE}/include" \
		-DJSONCPP_INCLUDE_DIR:STRING="${LOCALBASE}/include/jsoncpp" \
		-DJSONCPP_LIB_DIR:STRING="${LOCALBASE}/lib" \
		-DSTRICT_Z3_VERSION=OFF

PLIST_FILES=	bin/solc \
		bin/yul-phaser

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CXXFLAGS+=	-Wno-unqualified-std-cast-call
.endif

pre-patch:
		@${CP} ${FILESDIR}/fmtlib.cmake ${FILESDIR}/jsoncpp.cmake ${WRKSRC}/cmake/
		@${REINPLACE_CMD} '/EthCcache/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
