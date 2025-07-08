PORTNAME=	kicad
DISTVERSION=	9.0.3
CATEGORIES=	cad
PKGNAMESUFFIX=	-library-tmpl

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Official KiCad project templates
WWW=		https://gitlab.com/kicad/libraries/kicad-templates

LICENSE=	GPLv2

RUN_DEPENDS=	kicad:cad/kicad

USES=		cmake tar:bz2

USE_GITLAB=	yes
GL_ACCOUNT=	kicad/libraries
GL_PROJECT=	kicad-templates

CONFLICTS_INSTALL=	kicad-library-tmpl-devel # share/kicad/template/A2_ISO5457-1999_ISO7200-2004-compact_ASMEY1435-2014_EN.kicad_wks

CMAKE_ARGS=	-DLOCALBASE="${LOCALBASE}" \
		-DCMAKE_BUILD_TYPE="Release" \
		-DKICAD_TESTING_VERSION=ON \
		-DKICAD_BUILD_VERSION=${DISTVERSION}
INSTALL_TARGET=	install

NO_ARCH=	yes

.include <bsd.port.mk>
