PORTNAME=	capstone
PORTVERSION=	3.0.5
CATEGORIES=	devel
PKGNAMESUFFIX=	3

MAINTAINER=	oliver.pntr@gmail.com
COMMENT=	Multi-platform, multi-architecture disassembly framework
WWW=		http://capstone-engine.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

USES=		cpe gmake
CPE_VENDOR=	${PORTNAME}-engine
USE_GITHUB=	yes
GH_ACCOUNT=	aquynh
USE_LDCONFIG=	yes

MAKE_ENV+=	INSTALL_BIN="${INSTALL_PROGRAM}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_LIB="${INSTALL_LIB}"
TEST_ENV=	${MAKE_ENV} LD_LIBRARY_PATH=${STAGEDIR}${PREFIX}/lib
TEST_TARGET=	check

CONFLICTS=	capstone capstone4

.include <bsd.port.mk>
