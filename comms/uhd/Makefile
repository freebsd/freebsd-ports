# $FreeBSD$

PORTNAME=	uhd
PORTVERSION=	3.9.5
#PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	http://files.ettus.com/binaries/images/
DISTFILES=	${IMAGE_FILE}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTFILES}

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Ettus Research UHD driver framework

USE_GITHUB=     yes
GH_ACCOUNT=     EttusResearch
GH_TAGNAME=     ${UHD_COMMIT}

UHD_COMMIT=	32951af2f3e7b1ddb56486c9f15b2e1033605bd6

CONFLICTS=	usrp-[0-9]*

LIB_DEPENDS=	libboost_python.so:${PORTSDIR}/devel/boost-python-libs
BUILD_DEPENDS=	${LOCALBASE}/include/boost/tuple/tuple.hpp:${PORTSDIR}/devel/boost-libs \
		cheetah-analyze:${PORTSDIR}/devel/py-cheetah \
		rst2html:${PORTSDIR}/textproc/py-docutils \
		orcc:${PORTSDIR}/devel/orc \
		${PYTHON_PKGNAMEPREFIX}mako>0:${PORTSDIR}/textproc/py-mako

USES=			compiler:c++0x cmake:outsource gmake pkgconfig dos2unix python:2.7
COMPILER_FEATURES=	libc++
USE_LDCONFIG=		yes
CMAKE_SOURCE_PATH=	${WRKSRC}/host
MAKE_JOBS_UNSAFE=	yes

CMAKE_ARGS+=	-DPKG_LIB_DIR:STRING="share/uhd" -DUHD_TXRX_DEBUG_PRINTS="yes"
# for excruciating debug use this -db
#CMAKE_ARGS+=	--debug-output --trace
DOCSDIR=	share/doc/uhd

IMAGE_FILE=	uhd-images_003.009.005-release.zip

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
IGNORE=	needs libusb 1.0
.endif

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
CMAKE_ARGS+=	-DENABLE_DOXYGEN:STRING="ON"
HAVEDOCS=	YES
.endif

do-install:
# install host component
# hack the install prefix now
	@${REINPLACE_CMD} -e "s|/usr/local|${STAGEDIR}${PREFIX}|g" \
		${CONFIGURE_WRKSRC}/cmake_install.cmake
	cd ${CONFIGURE_WRKSRC} && ${MAKE} install
.for subdir in images
	${CP} -Rp ${WRKDIR}/${IMAGE_FILE:S|.zip||}/share/uhd/${subdir} ${STAGEDIR}${DATADIR}
.endfor

.include <bsd.port.post.mk>
