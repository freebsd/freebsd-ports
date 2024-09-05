PORTNAME=	solidity
PORTVERSION=	0.8.27
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
		nlohmann-json>=0:devel/nlohmann-json \
		range-v3>=0:devel/range-v3

USES=		cmake compiler:c++14-lang cpe
CPE_VENDOR=	${PORTNAME}lang

OPTIONS_DEFINE=	Z3 CVC5
OPTIONS_DEFAULT=Z3
OPTIONS_EXCLUDE_i386=	Z3
Z3_DESC=	SMT Checker via Z3
CVC5_DESC=	SMT Checker via CVC5
Z3_LIB_DEPENDS=		libz3.so:math/z3
CVC5_RUN_DEPENDS=	cvc5:math/cvc5
Z3_CMAKE_OFF=	USE_Z3

CMAKE_ARGS+=	-DUSE_LD_GOLD=OFF -DTESTS=OFF \
		-DIGNORE_VENDORED_DEPENDENCIES=ON \
		-DRANGE_V3_INCLUDE_DIR="${LOCALBASE}/include" \
		-DSTRICT_NLOHMANN_JSON_VERSION=OFF \
		-DSTRICT_Z3_VERSION=OFF

PLIST_FILES=	bin/solc \
		bin/yul-phaser

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CXXFLAGS+=	-Wno-unqualified-std-cast-call
.endif

.include <bsd.port.mk>
