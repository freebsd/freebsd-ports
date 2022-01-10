PORTNAME=	capstone
PORTVERSION=	4.0.2
CATEGORIES=	devel
PKGNAMESUFFIX=	4

MAINTAINER=	oleksii.tsai@gmail.com
COMMENT=	Multi-platform, multi-architecture disassembly framework

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

CONFLICTS=	capstone

USES=		cpe gmake
CPE_VENDOR=	${PORTNAME}-engine
USE_GITHUB=	yes
GH_ACCOUNT=	aquynh
USE_LDCONFIG=	yes

MAKE_ENV+=	INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_LIB="${INSTALL_LIB}"

TEST_ENV=	${MAKE_ENV} \
		LD_LIBRARY_PATH=${STAGEDIR}${PREFIX}/lib
TEST_TARGET=	check

CONFLICTS_BUILD=	capstone3

pre-test:
# Disable broken tests.
	@${REINPLACE_CMD} -E 's|^(check:.*)fuzzallcorp|\1|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
