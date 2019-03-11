# Created by: Thierry Thomas <thierry@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kicad
PORTVERSION=	5.1.0
CATEGORIES=	cad
PKGNAMESUFFIX=	-library-packages3d

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Official KiCad 3D model libraries for rendering and MCAD integration

LICENSE=	GPLv2

RUN_DEPENDS=	kicad:cad/kicad

CONFLICTS=	kicad-devel-r2*

USE_GITHUB=	yes
GH_ACCOUNT=	KiCad
GH_PROJECT=	kicad-packages3D

USES=		cmake

CMAKE_ARGS=	-DLOCALBASE="${LOCALBASE}" \
		-DCMAKE_BUILD_TYPE="Release" \
		-DKICAD_TESTING_VERSION=ON \
		-DKICAD_BUILD_VERSION=${DISTVERSION}
INSTALL_TARGET=	install

NO_ARCH=	yes

.include <bsd.port.mk>
