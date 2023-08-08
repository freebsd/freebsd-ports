PORTNAME=	pywal
DISTVERSION=	3.3.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	DtxdF@disroot.org
COMMENT=	Generate and change color-schemes on the fly
WWW=		https://github.com/dylanaraps/pywal

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=			IMAGEMAGICK
OPTIONS_DEFAULT=		IMAGEMAGICK
OPTIONS_GROUP=			BACKEND WALLPAPER
OPTIONS_GROUP_BACKEND=		COLORTHIEF COLORZ HAISHOKU
OPTIONS_GROUP_WALLPAPER=	BGS FEH HABAK HSETROOT NITROGEN

BACKEND_DESC=		Color backend to use
BGS_DESC=		Install with x11/bgs
COLORTHIEF_DESC=	Install with graphics/py-colorthief
COLORZ_DESC=		Install with graphics/py-colorz
FEH_DESC=		Install with graphics/feh
HABAK_DESC=		Install with x11/habak
HAISHOKU_DESC=		Install with graphics/py-haishoku
HSETROOT_DESC=		Install with x11/hsetroot
NITROGEN_DESC=		Install with sysutils/nitrogen
WALLPAPER_DESC=		Universal wallpaper setting

BGS_RUN_DEPENDS=	bgs>0:x11/bgs
COLORTHIEF_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorthief>0:graphics/py-colorthief@${PY_FLAVOR}
COLORZ_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorz>0:graphics/py-colorz@${PY_FLAVOR}
FEH_RUN_DEPENDS=	feh>0:graphics/feh
HABAK_RUN_DEPENDS=	habak>0:x11/habak
HAISHOKU_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}haishoku>0:graphics/py-haishoku@${PY_FLAVOR}
HSETROOT_RUN_DEPENDS=	hsetroot>0:x11/hsetroot
IMAGEMAGICK_USES=	magick:run
NITROGEN_RUN_DEPENDS=	nitrogen>0:sysutils/nitrogen

.include <bsd.port.mk>
