# $FreeBSD$

PORTNAME=	yajl
PORTVERSION=	2.1.0
CATEGORIES=	devel

MAINTAINER=	gregf@hugops.pw
COMMENT=	Portable JSON parsing and serialization library in ANSI C

LICENSE=	ISCL

USE_GITHUB=	yes
GH_ACCOUNT=	lloyd

CFLAGS+=	-g -O0

USE_LDCONFIG=	yes
USES=		cmake

PLIST_SUB=	VERSION=${PORTVERSION}

TEST_TARGET=	test test-api

post-patch:
	@${REINPLACE_CMD} -e "s,share/pkgconfig,libdata/pkgconfig,g" \
		${WRKSRC}/src/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|include/yajl|include|' \
		${WRKSRC}/src/yajl.pc.cmake

.include <bsd.port.mk>
