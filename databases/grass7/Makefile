PORTNAME=	grass
PORTVERSION=	7.8.8
PORTREVISION=	5
CATEGORIES=	databases geography
MASTER_SITES=	https://grass.osgeo.org/%SUBDIR%/ \
		http://grass.cict.fr/%SUBDIR%/ \
		http://grass.fbk.eu/%SUBDIR%/ \
		http://grass.gis-lab.info/%SUBDIR%/ \
		http://grass.meteo.uni.wroc.pl/%SUBDIR%/ \
		http://grass.polytechnic.edu.na/%SUBDIR%/ \
		http://grass.unibuc.ro/%SUBDIR%/ \
		http://mirrors.ibiblio.org/grass/%SUBDIR%/ \
		http://pinus.gntech.ac.kr/grass/%SUBDIR%/ \
		http://wgbis.ces.iisc.ernet.in/grass/%SUBDIR%/ \
		http://wgrass.media.osaka-cu.ac.jp/grassh/%SUBDIR%/
MASTER_SITE_SUBDIR=	grass${VER}/source
PKGNAMESUFFIX=	7

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	Open source Geographical Information System (GIS)
WWW=		https://grass.osgeo.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/GPL.TXT

BUILD_DEPENDS=	${PY_NUMPY} \
		${PYTHON_SITELIBDIR}/six.py:devel/py-six@${PY_FLAVOR}
LIB_DEPENDS=	libgdal.so:graphics/gdal \
		libpng.so:graphics/png \
		libproj.so:graphics/proj \
		libtiff.so:graphics/tiff \
		libfftw3.so:math/fftw3 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgeos.so:graphics/geos
RUN_DEPENDS=	${PY_NUMPY} \
		${PYTHON_SITELIBDIR}/six.py:devel/py-six@${PY_FLAVOR}

USES=		blaslapack compiler:c11 gl gmake gnome iconv \
		jpeg perl5 pkgconfig python readline shebangfix xorg
SHEBANG_GLOB=	*.py
SHEBANG_LANG=	nviz
nviz_OLD_CMD=	nviz
nviz_CMD=	${PREFIX}/${GRASS_INST_DIR}/bin/nviz
USE_XORG=	sm ice x11 xext xi xmu xrender xt
USE_GL=		gl glu
USE_GNOME=	cairo
USE_WX=		3.2
WX_COMPS=	wx python:run
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-includes=${LOCALBASE}/include \
		--with-libs=${LOCALBASE}/lib \
		--with-opengl-includes=${LOCALBASE}/include/ \
		--with-opengl-libs=${LOCALBASE}/lib/ \
		--with-freetype \
		--with-freetype-includes=${LOCALBASE}/include/freetype2 \
		--with-blas \
		--with-lapack \
		--with-cairo \
		--with-readline \
		--enable-largefile \
		--with-wxwidgets=${WX_CONFIG} \
		--with-proj-share=${LOCALBASE}/share/proj \
		--with-proj-includes=${LOCALBASE}/include \
		--with-proj-libs=${LOCALBASE}/lib \
		--with-proj=${LOCALBASE}/bin/proj \
		--with-geos=${LOCALBASE}/bin/geos-config \
		--with-gdal=${LOCALBASE}/bin/gdal-config \
		--with-pthread=yes \
		--prefix=${LOCALBASE} \
		--exec-prefix=${LOCALBASE}

CFLAGS+=	-std=c11

SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}
BINARY_ALIAS=	python3=${PYTHON_CMD}
ALL_TARGET=	default
USE_LDCONFIG=	${PREFIX}/${GRASS_INST_DIR}/lib
MAKE_ENV+=	TARGET="${CONFIGURE_TARGET}"
VER=		${PORTVERSION:R:C/\.//}

PLIST_SUB=	GRASS_INST_DIR="${GRASS_INST_DIR}" \
		VERSION="${PORTVERSION}" VERS="${PORTVERSION:C/([0-9]+).([0-9]+)(.*)/\1.\2/}" \
		VER="${VER}" MAJVER="${PKGNAMESUFFIX}"

OPTIONS_DEFINE=		NETCDF NLS PDAL ZSTD
OPTIONS_MULTI=		DB
OPTIONS_MULTI_DB=	MYSQL ODBC PGSQL SQLITE
#OPTIONS_SINGLE=		BLAS
#OPTIONS_SINGLE_BLAS=	ATLAS NETLIB GOTOBLAS OPENBLAS
OPTIONS_DEFAULT=	NETCDF NLS PDAL PGSQL SQLITE ZSTD
OPTIONS_SUB=		yes

# BLAS/LAPACK: Only netlib compile the maxmimum number of modules
#BLAS_DESC=		BLAS/LAPACK support
#GOTOBLAS_DESC=		GotoBLAS implementationS
#ATLAS_USES=		blaslapack:atlas
#NETLIB_USES=		blaslapack
#GOTOBLAS_USES=		blaslapack:gotoblas
#OPENBLAS_USES=		blaslapack:openblas
PDAL_DESC=		Enable points cloud data modules
DB_DESC=		Database support
MYSQL_USES=		mysql
MYSQL_CONFIGURE_ON=	--with-mysql \
			--with-mysql-includes=${LOCALBASE}/include/mysql \
			--with-mysql-libs=${LOCALBASE}/lib/mysql
NETCDF_CONFIGURE_ON=	--with-netcdf=${LOCALBASE}/bin/nc-config
NETCDF_LIB_DEPENDS=	libnetcdf.so:science/netcdf
NLS_CONFIGURE_WITH=	nls
NLS_USES=		gettext
ODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC
ODBC_CONFIGURE_WITH=	odbc
PDAL_CONFIGURE_ON=	--with-pdal=${LOCALBASE}/bin/pdal-config
PDAL_LIB_DEPENDS=	libpdalcpp.so:math/pdal
PGSQL_USES=		pgsql
PGSQL_CONFIGURE_WITH=	postgres
SQLITE_USES=		sqlite
SQLITE_CONFIGURE_WITH=	sqlite
SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}
ZSTD_CONFIGURE_WITH=	zstd
ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd

.if exists(/usr/include/omp.h)
CONFIGURE_ARGS+=	--with-openmp
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
USE_GCC=	yes
PLIST_SUB+=	NOTONI386="@comment "
.else
PLIST_SUB+=	NOTONI386=""
.endif

.if !defined (GRASS_INST_DIR)
GRASS_INST_DIR=	${PORTNAME}${VER}
.endif

MANDIRS=	${PREFIX}/grass${VER}/docs/man/man1

post-patch:
	${REINPLACE_CMD} \
		's|= python3|= ${PYTHON_CMD:T}|' ${WRKSRC}/include/Make/Platform.make.in
	${REINPLACE_CMD} -e \
		"s|'make'|'gmake'|g; \
		 s|gcc|${CC}|" ${WRKSRC}/scripts/g.extension/g.extension.py
	${REINPLACE_CMD} \
		's|$$(ARCH)|$$(TARGET)|g' ${WRKSRC}/include/Make/Grass.make
# Replace hardcoded python interpreter to PYTHON_CMD
	${REINPLACE_CMD} "s|'GRASS_PYTHON', 'python'|'GRASS_PYTHON', \'${PYTHON_CMD}\'|g" \
		${WRKSRC}/scripts/wxpyimgview/wxpyimgview.py
	${REINPLACE_CMD} 's|GRASS_PYTHON=python|GRASS_PYTHON=${PYTHON_CMD}|g' \
		${WRKSRC}/lib/init/grass.sh
	${REINPLACE_CMD} \
		"s|environ\['GRASS_PYTHON'\] = "'"python3"'"|environ['GRASS_PYTHON'] = "'"${PYTHON_CMD}"'"|g" \
		${WRKSRC}/lib/python/script/setup.py

post-install:
# remove useless files
	${RM} -rf ${STAGEDIR}${PREFIX}/${GRASS_INST_DIR}/etc/db.test/
	${RM} -rf ${STAGEDIR}${PREFIX}/${GRASS_INST_DIR}/demolocation/PERMANENT/.tmp/
	${RM} -rf ${STAGEDIR}${PREFIX}/${GRASS_INST_DIR}/docs/html/colortables/*bak.png

# fix pkg-plist issues
# poudriere testport, poudriere bulk -t and make ports can create different pkg-plist
	for i in `${FIND} ${WRKSRC}/scripts -type f \( -name *jpg -o -name *png -o -name *gxm \)  -print`; do \
		${INSTALL_DATA} $$i ${STAGEDIR}${LOCALBASE}/${PORTNAME}${VER}/docs/html; \
	done
	for i in `${FIND} ${WRKSRC}/gui/wxpython -type f \( -name *jpg -o -name *png -o -name *gxm \) -print`; do \
		${INSTALL_DATA} $$i ${STAGEDIR}${LOCALBASE}/${PORTNAME}${VER}/docs/html; \
	done
	for i in `${FIND} ${WRKSRC}/raster -type f \( -name *jpg -o -name *png -o -name *gxm \) -print`; do \
		${INSTALL_DATA} $$i ${STAGEDIR}${LOCALBASE}/${PORTNAME}${VER}/docs/html; \
	done
	for i in `${FIND} ${WRKSRC}/imagery -type f \( -name *jpg -o -name *png -o -name *gxm \) -print`; do \
		${INSTALL_DATA} $$i ${STAGEDIR}${LOCALBASE}/${PORTNAME}${VER}/docs/html; \
	done
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/wxpyimgview/wxpyimgview_gui.py ${STAGEDIR}${PREFIX}/${GRASS_INST_DIR}/etc/wxpyimgview_gui.py
	${MKDIR} ${STAGEDIR}${PREFIX}/${GRASS_INST_DIR}/etc/d.polar
	${INSTALL_DATA} ${WRKSRC}/scripts/d.polar/ps_defs.eps ${STAGEDIR}${PREFIX}/${GRASS_INST_DIR}/etc/d.polar

# STRIP PART
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${GRASS_INST_DIR}/bin/*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${GRASS_INST_DIR}/driver/db/*
.for i in clean_temp current_time_s_ms echo i.find lock run r.watershed/seg r.watershed/ram lister/vector lister/cell
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${GRASS_INST_DIR}/etc/${i}
.endfor
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${GRASS_INST_DIR}/tools/g.echo
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${GRASS_INST_DIR}/lib/*

# symlink grass7
	${LN} -sf ${PORTNAME}${VER} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}${PKGNAMESUFFIX}
.include <bsd.port.post.mk>
