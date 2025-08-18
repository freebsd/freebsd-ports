PORTNAME=	kicad
DISTVERSION=	9.0.4
CATEGORIES=	cad
PKGNAMESUFFIX=	-library-symbols

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Official KiCad schematic symbol libraries
WWW=		https://gitlab.com/kicad/libraries/kicad-symbols

LICENSE=	GPLv2

RUN_DEPENDS=	kicad:cad/kicad

USES=		cmake tar:bz2

USE_GITLAB=	yes
GL_ACCOUNT=	kicad/libraries
GL_PROJECT=	kicad-symbols

CONFLICTS_INSTALL=	kicad-library-symbols-devel # share/kicad/symbols/4xxx.kicad_sym

CMAKE_ARGS=	-DLOCALBASE="${LOCALBASE}" \
		-DCMAKE_BUILD_TYPE="Release" \
		-DKICAD_TESTING_VERSION=ON \
		-DKICAD_BUILD_VERSION=${DISTVERSION}
INSTALL_TARGET=	install

NO_ARCH=	yes

.include <bsd.port.mk>
