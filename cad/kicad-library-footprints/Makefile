PORTNAME=	kicad
PORTVERSION=	6.0.6
CATEGORIES=	cad
MASTER_SITES=	https://gitlab.com/kicad/libraries/${PORTNAME}-footprints/-/archive/${DISTVERSION}/
PKGNAMESUFFIX=	-library-footprints
DISTNAME=	${PORTNAME}-footprints-${DISTVERSION}

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Official KiCad Footprint Libraries

LICENSE=	GPLv2

RUN_DEPENDS=	kicad:cad/kicad

USES=		cmake tar:bz2

CONFLICTS_INSTALL=	kicad-library-footprints-devel # share/kicad/footprints/Audio_Module.pretty/Reverb_BTDR-1H.kicad_mod

CMAKE_ARGS=	-DLOCALBASE="${LOCALBASE}" \
		-DCMAKE_BUILD_TYPE="Release" \
		-DKICAD_TESTING_VERSION=ON \
		-DKICAD_BUILD_VERSION=${DISTVERSION}
INSTALL_TARGET=	install

NO_ARCH=	yes

.include <bsd.port.mk>
