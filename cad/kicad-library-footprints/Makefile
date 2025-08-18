PORTNAME=	kicad
DISTVERSION=	9.0.4
CATEGORIES=	cad
PKGNAMESUFFIX=	-library-footprints

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Official KiCad Footprint Libraries
WWW=		https://gitlab.com/kicad/libraries/kicad-footprints

LICENSE=	GPLv2

RUN_DEPENDS=	kicad:cad/kicad

USES=		cmake tar:bz2

USE_GITLAB=	yes
GL_ACCOUNT=	kicad/libraries
GL_PROJECT=	kicad-footprints

CONFLICTS_INSTALL=	kicad-library-footprints-devel # share/kicad/footprints/Audio_Module.pretty/Reverb_BTDR-1H.kicad_mod

CMAKE_ARGS=	-DLOCALBASE="${LOCALBASE}" \
		-DCMAKE_BUILD_TYPE="Release" \
		-DKICAD_TESTING_VERSION=ON \
		-DKICAD_BUILD_VERSION=${DISTVERSION}
INSTALL_TARGET=	install

NO_ARCH=	yes

.include <bsd.port.mk>
