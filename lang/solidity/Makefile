# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	solidity
PORTVERSION=	0.4.21
CATEGORIES=	lang
MASTER_SITES=	https://github.com/ethereum/solidity/releases/download/v${PORTVERSION}/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Solidity Contract-Oriented Programming Language

LICENSE=	GPLv3

BUILD_DEPENDS=	boost-libs>=0:devel/boost-libs
LIB_DEPENDS=	libjsoncpp.so:devel/jsoncpp

OPTIONS_DEFINE=	SMT
SMT_DESC=	SMT Checker
SMT_LIB_DEPENDS=libz3.so:math/z3

USES=		cmake

CMAKE_ARGS+=	-DUSE_LD_GOLD=OFF -DTESTS=OFF \
		-DJSONCPP_INCLUDE_DIR:STRING="${LOCALBASE}/include/jsoncpp" \
		-DJSONCPP_LIB_DIR:STRING="${LOCALBASE}/lib"

PLIST_FILES=	bin/solc

pre-patch:
		@${CP} ${FILESDIR}/jsoncpp.cmake ${WRKSRC}/cmake/
		@${REINPLACE_CMD} '/jsoncpp/d' ${WRKSRC}/libdevcore/CMakeLists.txt
		@${REINPLACE_CMD} '/EthCcache/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
