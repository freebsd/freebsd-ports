# $FreeBSD$

PORTNAME=	sumo
DISTVERSION=	1.2.0
CATEGORIES=	cad
MASTER_SITES=	http://www.dlr.de/ts/en/Portaldata/16/Resources/projekte/sumo/
DISTFILES=	${PORTNAME}-src-${DISTVERSIONFULL}${EXTRACT_SUFX}

MAINTAINER=	enriquefynn@gmail.com
COMMENT=	Traffic simulation suite for road vehicles, public transportation, etc

BROKEN_powerpc64=	fails to configure: xerces-lib not found in /usr/local/lib

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libFOX-1.6.so:x11-toolkits/fox16 \
		libfreetype.so:print/freetype2 \
		libgdal.so:graphics/gdal \
		libpng.so:graphics/png \
		libproj.so:graphics/proj \
		libtiff.so:graphics/tiff \
		libxerces-c.so:textproc/xerces-c3

USES=		cmake gl jpeg python shebangfix zip xorg
SHEBANG_FILES=	tools/*.py tools/*/*.py \
		tools/*/*/*.py tools/*/*/*/*.py \
		tools/*/*/*/*/*/*.py \
		tools/game/A10KW/build.sh \
		tools/game/rebuild_networks.sh \
		tools/build/rebuild_cscope.sh \
		tools/build/dailyUpdateMakeGCC.sh
		
python_OLD_CMD+="/usr/bin/env python"
USE_GL=		gl glu
USE_XORG=	x11 xcursor xext xfixes xft xi xrandr xrender

.include <bsd.port.mk>
