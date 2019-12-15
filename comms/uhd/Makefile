# $FreeBSD$

PORTNAME=	uhd
PORTVERSION=	3.14.1.1
PORTREVISION=	1
#PORTREVISION=	1
CATEGORIES=	comms hamradio
#MASTER_SITES=	http://files.ettus.com/binaries/images/
#DISTFILES=	${IMAGE_FILE}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Ettus Research UHD driver framework

# See https://www.ettus.com/sdr-software/detail/licenses.  Dual license
# under GPLv3 and and "Alternate License" whose terms are not documented
# on the web site (contact info@ettus.com).  Mark as GPLv3 for now
# until terms of the "Alternate License" are made clear.  When that
# is understood and if appropriate, we can add that license here.
LICENSE=	GPLv3

LIB_DEPENDS=	${PY_BOOST} \
		libboost_system.so:devel/boost-libs
BUILD_DEPENDS=	cheetah-analyze:devel/py-cheetah@${PY_FLAVOR} \
		rst2html:textproc/py-docutils \
		orcc:devel/orc \
		${PYTHON_PKGNAMEPREFIX}mako>0:textproc/py-mako@${PY_FLAVOR}

USES=		compiler:c++14-lang cmake ncurses pkgconfig \
		dos2unix python:2.7 shebangfix
USE_GITHUB=     yes
GH_ACCOUNT=     EttusResearch
GH_TAGNAME=     0347a6d81fd64800422ef1ed4dc634d8c480746f

CONFLICTS=	usrp-[0-9]*

BROKEN_FreeBSD_12_aarch64=	fails to configure: Could not find standard set_new_handler function
BROKEN_FreeBSD_12_armv6=	fails to configure: Could not find standard set_new_handler function
BROKEN_FreeBSD_12_armv7=	fails to configure: Could not find standard set_new_handler function
BROKEN_FreeBSD_13_aarch64=	fails to configure: Could not find standard set_new_handler function
BROKEN_FreeBSD_13_armv6=	fails to configure: Could not find standard set_new_handler function
BROKEN_FreeBSD_13_armv7=	fails to configure: Could not find standard set_new_handler function
BROKEN_powerpc64=		fails to link: undefined reference to boost function

USE_LDCONFIG=		yes
CMAKE_SOURCE_PATH=	${WRKSRC}/host
#CXXFLAGS_amd64=	-msse2 -std=c++11
#CXXFLAGS_i386=	-msse2 -std=c++11
CXXFLAGS_amd64=	-msse2 -std=c++11
CXXFLAGS_i386=	-msse2 -std=c++98

SHEBANG_GLOB=	*.py *.py.in

CMAKE_ARGS+=	-DPKG_LIB_DIR:STRING="share/uhd" -DUHD_TXRX_DEBUG_PRINTS="yes"
# for excruciating debug use this -db
#CMAKE_ARGS+=	--debug-output --trace

IMAGE_FILE=	uhd-images_3.14.0.0-rc1.zip

OPTIONS_DEFINE= DOCS DOXYGEN
OPTIONS_DEFAULT= DOCS

OPTIONS_SUB=yes
DOXYGEN_BUILD_DEPENDS=  doxygen:devel/doxygen
DOXYGEN_CMAKE_ON=	-DENABLE_DOXYGEN:STRING="ON"
DOXYGEN_CMAKE_OFF=	-DENABLE_DOXYGEN:STRING="OFF" -DENABLE_MANUAL:STRING="OFF"

do-install:
# install host component
# hack the install prefix now
	@${REINPLACE_CMD} -e 's|"${LOCALBASE}"|"${STAGEDIR}${PREFIX}"|g' \
		${CONFIGURE_WRKSRC}/cmake_install.cmake
	cd ${CONFIGURE_WRKSRC} && ${MAKE_CMD} install
#.for subdir in images
#	${CP} -Rp ${WRKDIR}/uhd-ef1576780bc927b8611640091b15f3d051cb97ad/share/uhd/${subdir} ${STAGEDIR}${DATADIR}
#.endfor

.include <bsd.port.mk>
