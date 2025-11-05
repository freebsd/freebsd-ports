PORTNAME=	halftone
DISTVERSION=	0.7.2
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Program to apply pixel art-like style to images
WWW=		https://github.com/tfuxu/Halftone

LICENSE=	GPLv3

BUILD_DEPENDS=	desktop-file-validate:devel/desktop-file-utils \
		blueprint-compiler:devel/blueprint-compiler
LIB_DEPENDS=	libgio-2.0.so:devel/glib20
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Wand>0:graphics/py-wand@${PY_FLAVOR}

USES=		desktop-file-utils gettext-tools:build gnome meson pkgconfig python shebangfix
USE_GNOME=	glib20 gtk40 libadwaita pygobject3

USE_GITHUB=	yes
GH_ACCOUNT=	tfuxu
GH_PROJECT=	Halftone

SHEBANG_FILES=	halftone/halftone.in

BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.mk>
