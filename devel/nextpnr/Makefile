# $FreeBSD$

PORTNAME=	nextpnr
PORTVERSION=	g20190529
CATEGORIES=	devel

MAINTAINER=	manu@FreeBSD.Org
COMMENT=	Portable FPGA place and route tool

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/share/trellis/database:devel/trellis \
		${LOCALBASE}/share/icebox:devel/icestorm
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libboost_filesystem.so:devel/boost-libs \
		libboost_program_options.so:devel/boost-libs \
		${PY_BOOST}

USES=		cmake qt:5 eigen:3 python:3.5+ gl

USE_QT=		buildtools_build core gui opengl qmake_build widgets
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	YosysHQ
GH_TAGNAME=	150004e3

BINARY_ALIAS=	python3=${PYTHON_CMD}

CMAKE_ARGS=	-DARCH="ice40;ecp5" -DTRELLIS_ROOT=${LOCALBASE}/share/trellis/

PLIST_FILES=	bin/nextpnr-ecp5 \
		bin/nextpnr-ice40

.include <bsd.port.mk>
