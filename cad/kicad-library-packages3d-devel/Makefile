# Created by: Thierry Thomas <thierry@FreeBSD.org>

PORTNAME=	kicad
DISTVERSION=	r${GIT_P3D_DATE}
PORTREVISION=	0
CATEGORIES=	cad
MASTER_SITES=	https://gitlab.com/kicad/libraries/${PORTNAME}-packages3D/-/archive/${GL_COMMIT}/
PKGNAMESUFFIX=	-library-packages3d-devel
DISTNAME=	${PORTNAME}-packages3D-${GL_COMMIT}

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Official KiCad 3D model libraries for rendering and MCAD integration

LICENSE=	GPLv2

RUN_DEPENDS=	kicad:cad/kicad-devel

CONFLICTS_INSTALL=	kicad-library-packages3d # share/kicad/3dmodels/Battery.3dshapes/BatteryHolder_Bulgin_BX0036_1xC.step

USE_GITLAB=	nodefault
GL_ACCOUNT=	kicad
GL_PROJECT=	kicad/packages3D
GL_COMMIT=	${GIT_P3D_HASH}

USES=		cmake

CMAKE_ARGS=	-DLOCALBASE="${LOCALBASE}" \
		-DCMAKE_BUILD_TYPE="Release" \
		-DKICAD_TESTING_VERSION=ON \
		-DKICAD_BUILD_VERSION=${DISTVERSION}
INSTALL_TARGET=	install

NO_ARCH=	yes

.include "Makefile.git_rev"

# Updating to new rev:
# sh files/newVersion.sh
# make install #breaks probably due to plist differences
# make makeplist > pkg-plist #One has to edit/review the generated plist
# make generate-plist && make check-plist

.include <bsd.port.mk>
