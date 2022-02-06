# Created by: Thierry Thomas <thierry@FreeBSD.org>

PORTNAME=	kicad
DISTVERSION=	r${GIT_FP_DATE}
PORTREVISION=	0
CATEGORIES=	cad
MASTER_SITES=	https://gitlab.com/kicad/libraries/${PORTNAME}-footprints/-/archive/${GL_COMMIT}/
PKGNAMESUFFIX=	-library-footprints-devel
DISTNAME=	${PORTNAME}-footprints-${GL_COMMIT}

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Official KiCad Footprint Libraries for the future Kicad version 5

LICENSE=	GPLv2

RUN_DEPENDS=	kicad:cad/kicad-devel

CONFLICTS_INSTALL=	kicad-library-footprints # share/kicad/footprints/Audio_Module.pretty/Reverb_BTDR-1H.kicad_mod

USE_GITLAB=	nodefault
GL_ACCOUNT=	kicad
GL_PROJECT=	kicad/libraries
GL_COMMIT=	${GIT_FP_HASH}
# WRKSRC=	${WRKDIR}/${PORTNAME}-${GL_COMMIT}-${GL_COMMIT}

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
