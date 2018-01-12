# Created by: Thierry Thomas <thierry@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kicad
DISTVERSION=	r${GIT_SRC_DATE}
CATEGORIES=	cad
PKGNAMESUFFIX=	-library

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Schematic and 3D libraries supported by KiCad team

LICENSE=	GPLv2

RUN_DEPENDS=	kicad:cad/kicad-devel

CONFLICTS=	kicad-4.*

USE_GITHUB=	yes
GH_ACCOUNT=	KiCad
GH_PROJECT=	kicad-library
GH_TAGNAME=	758be27c7697b7ce3d4e0d6c9bb32fb6ff962a32

USES=		cmake

NO_ARCH=	yes

.include "Makefile.git_rev"

# Updating to new rev:
# sh files/newVersion.sh
# make install #breaks probably due to plist differences
# make makeplist > pkg-plist #One has to edit/review the generated plist
# make generate-plist && make check-plist

.include <bsd.port.mk>
