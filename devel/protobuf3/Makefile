PORTNAME=	protobuf
PORTVERSION=	3.21.12
DISTVERSIONPREFIX=	cpp-
CATEGORIES=	devel
MASTER_SITES=	https://github.com/protocolbuffers/protobuf/releases/download/v${PORTVERSION:R:E}.${PORTVERSION:E}/
PKGNAMESUFFIX=	3

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Data interchange format library
WWW=		https://protobuf.dev/ \
		https://github.com/protocolbuffers/protobuf

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_sparc64=	fails to compile: no atomic ops available

TEST_DEPENDS=	googletest>=0:devel/googletest

USES=		compiler:c++11-lang cpe libtool localbase pathfix pkgconfig

CFLAGS+=	-D_THREAD_SAFE -DGOOGLE_PROTOBUF_NO_RTTI -I${WRKSRC}/src
CONFIGURE_ENV=	CC_FOR_BUILD="${CC}" \
		CFLAGS_FOR_BUILD="${CFLAGS}" \
		CPPFLAGS_FOR_BUILD="${CPPFLAGS}" \
		CXX_FOR_BUILD="${CXX}" \
		CXXFLAGS_FOR_BUILD="${CXXFLAGS}" \
		LDFLAGS_FOR_BUILD="${LDFLAGS}"
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_ARGS=	${MAKE_ARGS} ${_MAKE_JOBS}
TEST_TARGET=	check
USE_CXXSTD=	c++11
USE_LDCONFIG=	yes

PLIST_SUB=	PATCH_VERSION=${PORTVERSION:E}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

CPE_VENDOR=	google

PORTSCOUT=	limit:^3\.

.include <bsd.port.mk>
