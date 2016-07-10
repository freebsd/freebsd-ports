# $FreeBSD$

PORTNAME=	capstone
PORTVERSION=	4.0
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMESUFFIX=	4

MAINTAINER=	oleksii.tsai@gmail.com
COMMENT=	Multi-platform, multi-architecture disassembly framework

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

CONFLICTS_BUILD=	capstone3

USES=		gmake
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	aquynh
GH_TAGNAME=	d99cbc3

MAKE_ENV+=	INSTALL_LIB="${INSTALL_LIB}" \
		INSTALL_DATA="${INSTALL_DATA}"

TEST_ENV=	${MAKE_ENV} LD_LIBRARY_PATH=${STAGEDIR}${PREFIX}/lib
TEST_TARGET=	check

post-patch:
	${REINPLACE_CMD} -i '' \
		-e 's|DESTDIR ?=|DESTDIR = ${STAGEDIR}|' \
		-e 's|LIBDIR ?=.*|LIBDIR = ${PREFIX}/lib|' \
		${WRKSRC}/Makefile

post-install:
	${REINPLACE_CMD} -i '' -e 's|${STAGEDIR}||g' \
		${STAGEDIR}/${PREFIX}/libdata/pkgconfig/capstone.pc

.include <bsd.port.mk>
