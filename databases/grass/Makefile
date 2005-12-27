# New ports collection makefile for:	grass
# Date created:		15 January 2000
# Whom:			reg
#
# $FreeBSD$
#

PORTNAME=	grass
PORTVERSION=	6.0.1
PORTEPOCH=	2
CATEGORIES=	databases
MASTER_SITES=	ftp://grass.itc.it/pub/grass/grass60/source/\
		http://grass.itc.it/grass60/source/ \
		http://grass.meteo.uni.wroc.pl/grass60/source/ \
		http://grass.ru.ac.za/grass60/source/\
		ftp://ftp.planetmirror.com/pub/grass/grass60/source/\
		http://wgrass.media.osaka-cu.ac.jp/grassh/grass60/source/\
		http://public.planetmirror.com/pub/grass/grass60/source/\
		ftp://www.ibiblio.org/pub/packages/gis/grass/grass60/source/\
		http://www.geog.uni-hannover.de/grass/grass60/source/\
		http://grass.ibiblio.org/grass60/source/\
		http://gulus.usherbrooke.ca/pub/appl/grass/grass60/source/\
		http://ludique.u-bourgogne.fr/grass/grass60/source/

MAINTAINER=	lrntct@gmail.com
COMMENT=	An open source Geographical Information System (GIS)

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		fftw.2:${PORTSDIR}/math/fftw \
		freetype.9:${PORTSDIR}/print/freetype2
BUILD_DEPENDS=	proj:${PORTSDIR}/graphics/proj \
		gdal-config:${PORTSDIR}/graphics/gdal \
		wish8.4:${PORTSDIR}/x11-toolkits/tk84
RUN_DEPENDS=	proj:${PORTSDIR}/graphics/proj \
		gdal-config:${PORTSDIR}/graphics/gdal

USE_PGSQL=	yes
USE_ICONV=	yes
USE_XLIB=	yes
USE_FREETYPE=	yes
USE_FFTW=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GETTEXT=	yes
USE_TCL_BUILD=	yes
USE_TCL=	yes
USE_TK=		yes
PATCH_TCL_SCRIPTS=lib/init/init.sh
PATCH_TK_SCRIPTS=lib/init/init.sh

ALL_TARGET=
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-includes=${LOCALBASE}/include \
		--with-libs=${LOCALBASE}/lib \
		--with-tcltk-includes="${LOCALBASE}/include/tcl8.4 \
					 ${LOCALBASE}/include/tk8.4" \
		--with-opengl-includes=${X11BASE}/include \
		--with-opengl-libs=${X11BASE}/lib \
		--with-freetype \
		--with-freetype-includes=${LOCALBASE}/include/freetype2 \
		--with-nls \
		--with-cxx \
		--enable-largefile

post-extract:
	@${REINPLACE_CMD} -e 's/ make mo/ ${GMAKE} mo/g' \
	${WRKSRC}/locale/Makefile

.include <bsd.port.mk>
