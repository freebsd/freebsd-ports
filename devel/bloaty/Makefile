PORTNAME=	bloaty
PORTVERSION=	1.1
DISTVERSIONPREFIX=	v
PORTREVISION=	13
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Size profiler for binaries
WWW=		https://github.com/google/bloaty

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libre2.so:devel/re2 \
		libcapstone.so:devel/capstone \
		libprotobuf.so:devel/protobuf

USES=		cmake compiler:c++17-lang pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TUPLE=	nico:demumble:01098ea:demumble/third_party/demumble
CMAKE_ARGS=	-DCMAKE_CXX_STANDARD=17
CMAKE_OFF=	BLOATY_ENABLE_CMAKETARGETS BLOATY_ENABLE_BUILDID

PLIST_FILES=	bin/bloaty

.include <bsd.port.mk>
