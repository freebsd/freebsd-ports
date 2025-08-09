PORTNAME=	solidity
PORTVERSION=	0.8.30
PORTREVISION=	1
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
Z3_DESC=	SMT Checker via Z3
CVC5_DESC=	SMT Checker via CVC5
Z3_RUN_DEPENDS=		z3:math/z3
CVC5_RUN_DEPENDS=	cvc5:math/cvc5

CMAKE_ARGS+=	-DTESTS=OFF \
		-DIGNORE_VENDORED_DEPENDENCIES=ON

PLIST_FILES=	bin/solc \
		bin/yul-phaser

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CXXFLAGS+=	-Wno-unqualified-std-cast-call
.endif

.include <bsd.port.mk>
