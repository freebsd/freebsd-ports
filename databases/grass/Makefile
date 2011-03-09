# New ports collection makefile for:	grass
# Date created:		15 January 2000
# Whom:			reg
#
# $FreeBSD$
#

PORTNAME=	grass
PORTVERSION=	6.4.0
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	databases geography
MASTER_SITES=	http://grass.itc.it/grass64/source/ \
		ftp://grass.itc.it/pub/grass/grass64/source/ \
		http://grass.ibiblio.org/grass64/source/\
		ftp://www.ibiblio.org/pub/packages/gis/grass/grass64/source/\
		http://www.geog.uni-hannover.de/grass/grass64/source/\
		http://grass.meteo.uni.wroc.pl/grass64/source/ \
		http://grass.ru.ac.za/grass64/source/\
		http://wgrass.media.osaka-cu.ac.jp/grassh/grass64/source/\
		http://public.planetmirror.com/pub/grass/grass64/source/\
		ftp://ftp.planetmirror.com/pub/grass/grass64/source/\
		http://gulus.usherbrooke.ca/pub/appl/grass/grass64/source/\
		http://ludique.u-bourgogne.fr/grass/grass64/source/
#DISTNAME=	${PORTNAME}-${PORTVERSION}RC5

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An open source Geographical Information System (GIS)

BUILD_DEPENDS=	proj:${PORTSDIR}/graphics/proj \
		gdal-config:${PORTSDIR}/graphics/gdal \
		${LOCALBASE}/bin/swig:${PORTSDIR}/devel/swig13 \
		${LOCALBASE}/bin/wxgtk2-2.8-config:${PORTSDIR}/x11-toolkits/wxgtk28
RUN_DEPENDS=	proj:${PORTSDIR}/graphics/proj \
		gdal-config:${PORTSDIR}/graphics/gdal \
		bash:${PORTSDIR}/shells/bash \
		${LOCALBASE}/bin/wxgtk2-2.8-config:${PORTSDIR}/x11-toolkits/wxgtk28
LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		png.6:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		fftw3.5:${PORTSDIR}/math/fftw3 \
		freetype.9:${PORTSDIR}/print/freetype2

USE_GMAKE=	yes
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_PERL5=	yes
USE_GL=		glut
USE_FREETYPE=	yes
USE_TCL=	yes
USE_TCL_BUILD=	yes
USE_TK=		yes
USE_TK_BUILD=	yes
USE_PYTHON=	yes
USE_WX=		2.8
WX_COMPS=	python:run
PATCH_TCL_SCRIPTS=lib/init/init.sh
PATCH_TK_SCRIPTS=lib/init/init.sh

ALL_TARGET=
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-includes=${LOCALBASE}/include \
		--with-libs=${LOCALBASE}/lib \
		--with-tcltk-includes="${TCL_INCLUDEDIR} ${TK_INCLUDEDIR}" \
		--with-opengl-includes=${LOCALBASE}/include/ \
		--with-opengl-libs=${LOCALBASE}/lib/ \
		--with-freetype \
		--with-freetype-includes=${LOCALBASE}/include/freetype2 \
		--with-nls \
		--with-cxx \
		--with-readline \
		--with-curses \
		--enable-largefile \
		--with-python=${LOCALBASE}/bin/python-config \
		--with-wxwidgets=${LOCALBASE}/bin/wxgtk2-2.8-config

PLIST_SUB=	GRASS_INST_DIR=${GRASS_INST_DIR} \
		VERSION=${PORTVERSION} \
		VER=${PORTVERSION:R:C/\.//}
USE_LDCONFIG=	${PREFIX}/${GRASS_INST_DIR}/lib

OPTIONS=	MYSQL	"Enable MySQL support" Off \
		ODBC	"Enable ODBC support" Off \
		PGSQL	"Enable PostgreSQL support" On \
		SQLITE	"Enable SQLite support" Off

BASH_SCRIPTS=	i.spectral r.tileset

.include <bsd.port.pre.mk>

.if !defined (GRASS_INST_DIR)
GRASS_INST_DIR=	${PORTNAME}-${PORTVERSION}
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-mysql \
		--with-mysql-includes=${LOCALBASE}/include/mysql \
		--with-mysql-libs=${LOCALBASE}/lib/mysql
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if defined(WITH_ODBC)
LIB_DEPENDS+=	odbc:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=--with-odbc
PLIST_SUB+=	ODBC=""
.else
PLIST_SUB+=	ODBC="@comment "
.endif

.if !defined(WITHOUT_PGSQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=--with-postgres
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if defined(WITH_SQLITE)
USE_SQLITE=	yes
CONFIGURE_ARGS+=--with-sqlite
PLIST_SUB+=	SQLITE=""
.else
PLIST_SUB+=	SQLITE="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e "/^INST_DIR=/s|grass-.*|${GRASS_INST_DIR}|" \
		${WRKSRC}/Makefile
.for s in ${BASH_SCRIPTS}
	@${REINPLACE_CMD} -e "1s|/bin/bash|${LOCALBASE}/bin/bash|" \
		 ${WRKSRC}/scripts/$s/$s
.endfor

.include <bsd.port.post.mk>
