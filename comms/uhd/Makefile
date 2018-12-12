# $FreeBSD$

PORTNAME=	uhd
PORTVERSION=	3.10.3.0
PORTREVISION=	8
CATEGORIES=	comms hamradio
MASTER_SITES=	http://files.ettus.com/binaries/images/
DISTFILES=	${IMAGE_FILE}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Ettus Research UHD driver framework

LIB_DEPENDS=	${PY_BOOST} \
		libboost_system.so:devel/boost-libs
BUILD_DEPENDS=	${LOCALBASE}/include/boost/tuple/tuple.hpp:devel/boost-libs \
		cheetah-analyze:devel/py-cheetah@${PY_FLAVOR} \
		rst2html:textproc/py-docutils \
		orcc:devel/orc \
		${PYTHON_PKGNAMEPREFIX}mako>0:textproc/py-mako@${PY_FLAVOR}

USE_GITHUB=     yes
GH_ACCOUNT=     EttusResearch
GH_TAGNAME=     ef1576780bc927b8611640091b15f3d051cb97ad

CONFLICTS=	usrp-[0-9]*

BROKEN_FreeBSD_12_aarch64=	fails to configure: Could not find standard set_new_handler function
BROKEN_FreeBSD_12_armv6=	fails to configure: Could not find standard set_new_handler function
BROKEN_FreeBSD_12_armv7=	fails to configure: Could not find standard set_new_handler function
BROKEN_FreeBSD_13_aarch64=	fails to configure: Could not find standard set_new_handler function
BROKEN_FreeBSD_13_armv6=	fails to configure: Could not find standard set_new_handler function
BROKEN_FreeBSD_13_armv7=	fails to configure: Could not find standard set_new_handler function
BROKEN_powerpc64=		fails to link: undefined reference to boost function

USES=		compiler:c++11-lib cmake:outsource ncurses pkgconfig \
		dos2unix python:2.7 shebangfix
USE_LDCONFIG=		yes
CMAKE_SOURCE_PATH=	${WRKSRC}/host
#MAKE_JOBS_UNSAFE=	yes
#CXXFLAGS_amd64=	-msse2 -std=c++11
#CXXFLAGS_i386=	-msse2 -std=c++11
CXXFLAGS_amd64=	-msse2 -std=c++98
CXXFLAGS_i386=	-msse2 -std=c++98

SHEBANG_GLOB=	*.py *.py.in

CMAKE_ARGS+=	-DPKG_LIB_DIR:STRING="share/uhd" -DUHD_TXRX_DEBUG_PRINTS="yes"
# for excruciating debug use this -db
#CMAKE_ARGS+=	--debug-output --trace

IMAGE_FILE=	uhd-images_003.010.003.000-release.zip

OPTIONS_DEFINE= DOXYGEN DOCS
#OPTIONS_DEFAULT= DOXYGEN

OPTIONS_SUB=yes
DOXYGEN_BUILD_DEPENDS=  doxygen:devel/doxygen

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOXYGEN}
BUILD_DEPENDS+=	doxygen:devel/doxygen
CMAKE_ARGS+=	-DENABLE_DOXYGEN:STRING="ON"
HAVEDOCS=	YES
.endif

post-patch:
# USES=pathfix handles LIBRARY_INSTALL_DIR but not LIBRARY_DIR
	@${REINPLACE_CMD} '/pkgconfig/s|LIBRARY_DIR}|CMAKE_INSTALL_PREFIX}/libdata|' \
		${PATCH_WRKSRC}/host/CMakeLists.txt

do-install:
# install host component
# hack the install prefix now
	@${REINPLACE_CMD} -e "s|/usr/local|${STAGEDIR}${PREFIX}|g" \
		${CONFIGURE_WRKSRC}/cmake_install.cmake
	cd ${CONFIGURE_WRKSRC} && ${MAKE_CMD} install
.for subdir in images
	${CP} -Rp ${WRKDIR}/${IMAGE_FILE:S|.zip||}/share/uhd/${subdir} ${STAGEDIR}${DATADIR}
.endfor

.include <bsd.port.post.mk>
