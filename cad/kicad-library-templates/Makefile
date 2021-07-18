# Created by: Thierry Thomas <thierry@FreeBSD.org>

PORTNAME=	kicad
PORTVERSION=	5.1.10
CATEGORIES=	cad
MASTER_SITES=	https://gitlab.com/kicad/libraries/${PORTNAME}-templates/-/archive/${DISTVERSION}/
PKGNAMESUFFIX=	-library-tmpl
DISTNAME=	${PORTNAME}-templates-${DISTVERSION}

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Official KiCad project templates

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
