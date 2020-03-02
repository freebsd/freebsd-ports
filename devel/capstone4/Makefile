# $FreeBSD$

PORTNAME=	capstone
PORTVERSION=	4.0.1
CATEGORIES=	devel
PKGNAMESUFFIX=	4

PATCH_SITES=	https://github.com/aquynh/capstone/pull/1589/commits/
PATCHFILES=	046846b2ea189142482754c13ee0ed54cb4f4e5b.patch:-p1

MAINTAINER=	oleksii.tsai@gmail.com
COMMENT=	Multi-platform, multi-architecture disassembly framework

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

USES=		gmake
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
