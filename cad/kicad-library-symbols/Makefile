# Created by: Thierry Thomas <thierry@FreeBSD.org>

PORTNAME=	kicad
PORTVERSION=	6.0.4
CATEGORIES=	cad
MASTER_SITES=	https://gitlab.com/kicad/libraries/${PORTNAME}-symbols/-/archive/${DISTVERSION}/
PKGNAMESUFFIX=	-library-symbols
DISTNAME=	${PORTNAME}-symbols-${DISTVERSION}

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Official KiCad schematic symbol libraries

LICENSE=	GPLv2

RUN_DEPENDS=	kicad:cad/kicad

USES=		cmake tar:bz2

CONFLICTS_INSTALL=	kicad-library-symbols-devel # share/kicad/symbols/4xxx.kicad_sym

CMAKE_ARGS=	-DLOCALBASE="${LOCALBASE}" \
		-DCMAKE_BUILD_TYPE="Release" \
		-DKICAD_TESTING_VERSION=ON \
		-DKICAD_BUILD_VERSION=${DISTVERSION}
INSTALL_TARGET=	install

NO_ARCH=	yes

.include <bsd.port.mk>
