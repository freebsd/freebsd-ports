# Created by: Thierry Thomas <thierry@FreeBSD.org>

PORTNAME=	kicad
PORTVERSION=	6.0.1
CATEGORIES=	cad
MASTER_SITES=	https://gitlab.com/kicad/libraries/${PORTNAME}-templates/-/archive/${DISTVERSION}/
PKGNAMESUFFIX=	-library-tmpl
DISTNAME=	${PORTNAME}-templates-${DISTVERSION}

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Official KiCad project templates

LICENSE=	GPLv2

RUN_DEPENDS=	kicad:cad/kicad

USES=		cmake tar:bz2

CONFLICTS_INSTALL=	kicad-library-tmpl-devel # share/kicad/template/A2_ISO5457-1999_ISO7200-2004-compact_ASMEY1435-2014_EN.kicad_wks

CMAKE_ARGS=	-DLOCALBASE="${LOCALBASE}" \
		-DCMAKE_BUILD_TYPE="Release" \
		-DKICAD_TESTING_VERSION=ON \
		-DKICAD_BUILD_VERSION=${DISTVERSION}
INSTALL_TARGET=	install

NO_ARCH=	yes

.include <bsd.port.mk>
