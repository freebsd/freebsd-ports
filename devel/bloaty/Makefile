# $FreeBSD$

PORTNAME=	bloaty
PORTVERSION=	1.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Size profiler for binaries

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	go:lang/go \
		cmake:devel/cmake \
		ninja:devel/ninja
LIB_DEPENDS=	libre2.so:devel/re2 \
		libcapstone.so:devel/capstone4 \
		libprotobuf.so:devel/protobuf

USES=		cmake pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TUPLE=	google:${PORTNAME}:${DISTVERSIONPREFIX}${PORTVERSION}:DEFAULT \
		abseil:abseil-cpp:bea85b5:abseil/third_party/abseil-cpp \
		nico:demumble:01098ea:demumble/third_party/demumble
CMAKE_OFF=	BLOATY_ENABLE_CMAKETARGETS BLOATY_ENABLE_BUILDID

PLIST_FILES=	bin/bloaty

.include <bsd.port.mk>
