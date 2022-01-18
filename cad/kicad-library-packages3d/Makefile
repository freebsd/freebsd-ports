# Created by: Thierry Thomas <thierry@FreeBSD.org>

PORTNAME=	kicad
PORTVERSION=	6.0.1
CATEGORIES=	cad
MASTER_SITES=	https://gitlab.com/kicad/libraries/${PORTNAME}-packages3D/-/archive/${DISTVERSION}/
PKGNAMESUFFIX=	-library-packages3d
DISTNAME=	${PORTNAME}-packages3D-${DISTVERSION}

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Official KiCad 3D model libraries for rendering and MCAD integration

LICENSE=	GPLv2

RUN_DEPENDS=	kicad:cad/kicad

USES=		cmake tar:bz2

CONFLICTS=	kicad-devel-r2*

CMAKE_ARGS=	-DLOCALBASE="${LOCALBASE}" \
		-DCMAKE_BUILD_TYPE="Release" \
		-DKICAD_TESTING_VERSION=ON \
		-DKICAD_BUILD_VERSION=${DISTVERSION}
INSTALL_TARGET=	install

NO_ARCH=	yes

.include <bsd.port.mk>
