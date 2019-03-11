# Created by: Thierry Thomas <thierry@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kicad
PORTVERSION=	5.1.0
CATEGORIES=	cad
PKGNAMESUFFIX=	-library-footprints

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Official KiCad Footprint Libraries

LICENSE=	GPLv2

RUN_DEPENDS=	kicad:cad/kicad

CONFLICTS=	kicad-devel-r2*

USE_GITHUB=	yes
GH_ACCOUNT=	KiCad
GH_PROJECT=	kicad-footprints
GH_TAGNAME=	${GIT_FP_HASH}

USES=		cmake

CMAKE_ARGS=	-DLOCALBASE="${LOCALBASE}" \
		-DCMAKE_BUILD_TYPE="Release" \
		-DKICAD_TESTING_VERSION=ON \
		-DKICAD_BUILD_VERSION=${DISTVERSION}
INSTALL_TARGET=	install

NO_ARCH=	yes

.include <bsd.port.mk>
