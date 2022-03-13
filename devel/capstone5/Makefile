PORTNAME=	capstone
DISTVERSION=	5.0-rc2
CATEGORIES=	devel
PKGNAMESUFFIX=	5

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Multi-platform, multi-architecture disassembly framework

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

USES=		cpe gmake
CPE_VENDOR=	${PORTNAME}-engine
USE_GITHUB=	yes
GH_ACCOUNT=	capstone-engine
USE_LDCONFIG=	yes

MAKE_ENV+=	INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_LIB="${INSTALL_LIB}"
TEST_ENV=	${MAKE_ENV} \
		LD_LIBRARY_PATH=${STAGEDIR}${PREFIX}/lib
TEST_TARGET=	check

CONFLICTS=		capstone
CONFLICTS_BUILD=	capstone[34]

pre-test:
# Disable broken tests.
	@${REINPLACE_CMD} -E 's|^(check:.*)fuzzallcorp|\1|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
