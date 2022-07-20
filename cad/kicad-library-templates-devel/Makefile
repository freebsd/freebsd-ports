PORTNAME=	kicad
DISTVERSION=	r${GIT_TMPL_DATE}
PORTREVISION=	0
CATEGORIES=	cad
MASTER_SITES=	https://gitlab.com/kicad/libraries/${PORTNAME}-templates/-/archive/${GL_COMMIT}/
PKGNAMESUFFIX=	-library-tmpl-devel
DISTNAME=	${PORTNAME}-templates-${GL_COMMIT}

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Official KiCad project templates

LICENSE=	GPLv2

RUN_DEPENDS=	kicad:cad/kicad-devel

CONFLICTS_INSTALL=	kicad-library-tmpl # share/kicad/template/A2_ISO5457-1999_ISO7200-2004-compact_ASMEY1435-2014_EN.kicad_wks

USE_GITLAB=	nodefault
GL_ACCOUNT=	kicad
GL_PROJECT=	kicad/libraries
GL_COMMIT=	${GIT_TMPL_HASH}

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
