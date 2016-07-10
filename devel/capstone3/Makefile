# $FreeBSD$

PORTNAME=	capstone
PORTVERSION=	3.0.4
CATEGORIES=	devel

MAINTAINER=	oliver.pntr@gmail.com
COMMENT=	Multi-platform, multi-architecture disassembly framework

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

CONFLICTS=	capstone4

USES=		gmake
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	aquynh

MAKE_ENV+=	INSTALL_LIB="${INSTALL_LIB}" \
		INSTALL_DATA="${INSTALL_DATA}"

TEST_ENV=	${MAKE_ENV} LD_LIBRARY_PATH=${STAGEDIR}${PREFIX}/lib
TEST_TARGET=	check

.include <bsd.port.mk>
