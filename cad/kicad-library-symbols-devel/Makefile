# Created by: Thierry Thomas <thierry@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kicad
DISTVERSION=	r${GIT_SYM_DATE}
PORTREVISION=	1
CATEGORIES=	cad
PKGNAMESUFFIX=	-library-symbols-devel

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Official KiCad schematic symbol libraries for the future Kicad 5 release

LICENSE=	GPLv2

RUN_DEPENDS=	kicad:cad/kicad-devel

CONFLICTS=	kicad-4.*

USE_GITHUB=	yes
GH_ACCOUNT=	KiCad
GH_PROJECT=	kicad-symbols
GH_TAGNAME=	${GIT_SYM_HASH}

USES=		cmake

CMAKE_ARGS=     -DLOCALBASE="${LOCALBASE}" \
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
