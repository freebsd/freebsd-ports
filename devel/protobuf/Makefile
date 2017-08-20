# Created by: vanilla
# $FreeBSD$

PORTNAME=	protobuf
PORTVERSION=	3.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Data interchange format library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_sparc64=	fails to compile: no atomic ops available

TEST_DEPENDS=	googlemock>=0:devel/googlemock \
		googletest>=0:devel/googletest

CFLAGS+=	-DGOOGLE_PROTOBUF_NO_RTTI -I${WRKSRC}/src
CONFIGURE_ENV=	CXX_FOR_BUILD=c++
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
TEST_ARGS=	${MAKE_ARGS} ${_MAKE_JOBS}
TEST_TARGET=	check
USE_LDCONFIG=	yes
USES=		autoreconf compiler:c++11-lang gmake libtool localbase pathfix pkgconfig

GH_ACCOUNT=	google
USE_GITHUB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|^check-local:|disabled-&|' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -Ee '/gtest|mock/ s|[^ ]*lib(.*)\.la|-l\1|' ${WRKSRC}/src/Makefile.am

.include <bsd.port.mk>
