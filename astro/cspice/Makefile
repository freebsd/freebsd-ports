PORTNAME=	cspice
DISTVERSION=	67
CATEGORIES=	astro
MASTER_SITES=	https://naif.jpl.nasa.gov/pub/naif/misc/toolkit_N0067/C/PC_Linux_GCC_64bit/packages/:cspice_src
DISTFILES=	cspice.tar.Z:cspice_src

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	NAIF C SPICE Toolkit
WWW=		https://naif.jpl.nasa.gov/naif/toolkit.html \
		https://github.com/AndrewAnnex/cspice-cmake-spiceypy

LICENSE=	NAIF
LICENSE_NAME=	NAIF CSPICE License
LICENSE_TEXT=	See https://naif.jpl.nasa.gov/naif/rules.html
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		cmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	AndrewAnnex
GH_PROJECT=	cspice-cmake-spiceypy
GH_TAGNAME=	658aa8b0116dc5e33a084c0aeb6eb9f9fc8fc1b3 # CMakeLists.txt has: set(CSPICE_VERSION_INT 67), otherwise the project is tagged with irrelevant version numbers

CONFIGURE_ENV=	CSPICE_SRC=${WRKDIR}/cspice
CMAKE_ARGS=	-DBUILD_TESTING=OFF \
		-DBUILD_EXECUTABLES=OFF

.include <bsd.port.mk>
