# Created by: vanilla
# $FreeBSD$

PORTNAME=	protobuf
PORTVERSION=	3.6.1
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Data interchange format library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_sparc64=	fails to compile: no atomic ops available

TEST_DEPENDS=	googlemock>=0:devel/googlemock \
		googletest>=0:devel/googletest

USES=		autoreconf compiler:c++11-lang gmake libtool localbase pathfix pkgconfig

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

GH_ACCOUNT=	protocolbuffers
USE_GITHUB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|^check-local:|disabled-&|' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -Ee '/gtest|mock/ s|[^ ]*lib(.*)\.la|-l\1|' ${WRKSRC}/src/Makefile.am

.include <bsd.port.mk>
