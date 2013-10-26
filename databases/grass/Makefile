# Created by: reg
# $FreeBSD$

PORTNAME=	grass
PORTVERSION=	6.4.2
PORTREVISION=	7
PORTEPOCH=	2
CATEGORIES=	databases geography
MASTER_SITES=	http://grass.osgeo.org/%SUBDIR%/ \
		http://wgbis.ces.iisc.ernet.in/grass/%SUBDIR%/ \
		http://grass.bergenheim.net/%SUBDIR%/ \
		http://grass.cict.fr/%SUBDIR%/ \
		http://www.phygeo.uni-hannover.de/grass/%SUBDIR%/ \
		http://grass.fbk.eu/%SUBDIR%/ \
		http://grass.gis-lab.info/%SUBDIR%/ \
		http://mirrors.ibiblio.org/grass/%SUBDIR%/
MASTER_SITE_SUBDIR=	grass64/source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source Geographical Information System (GIS)

LICENSE=	GPLv2

BROKEN=		Does not build

BUILD_DEPENDS=	${LOCALBASE}/bin/swig:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	gdal:${PORTSDIR}/graphics/gdal \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		proj:${PORTSDIR}/graphics/proj \
		tiff:${PORTSDIR}/graphics/tiff \
		fftw3:${PORTSDIR}/math/fftw3 \
		freetype:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USES=		gettext gmake iconv readline perl5 tk
USE_XORG=	sm ice xi x11 xt xmu xext
USE_GL=		glut
USE_PYTHON=	yes
USE_WX=		2.8
WX_COMPS=	wx:build python:run
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
		--with-wxwidgets=${WX_CONFIG}

PLIST_SUB=	GRASS_INST_DIR=${GRASS_INST_DIR} \
		VERSION=${PORTVERSION} \
		VER=${PORTVERSION:R:C/\.//}
USE_LDCONFIG=	${PREFIX}/${GRASS_INST_DIR}/lib


OPTIONS_DEFINE=	MYSQL ODBC PGSQL SQLITE
OPTIONS_DEFAULT=	PGSQL

BASH_SCRIPTS=	i.spectral r.tileset

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not configure on sparc64
.endif

.if !defined (GRASS_INST_DIR)
GRASS_INST_DIR=	${PORTNAME}-${PORTVERSION}
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-mysql \
		--with-mysql-includes=${LOCALBASE}/include/mysql \
		--with-mysql-libs=${LOCALBASE}/lib/mysql
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MODBC}
LIB_DEPENDS+=	odbc:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=--with-odbc
PLIST_SUB+=	ODBC=""
.else
PLIST_SUB+=	ODBC="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=--with-postgres
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MSQLITE}
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
