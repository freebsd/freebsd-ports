# Created by: reg
# $FreeBSD$

PORTNAME=	grass
PORTVERSION=	6.4.3
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	databases geography
MASTER_SITES=	http://grass.osgeo.org/%SUBDIR%/ \
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
MASTER_SITE_SUBDIR=	grass64/source

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source Geographical Information System (GIS)

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/bin/swig:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	libgdal.so:${PORTSDIR}/graphics/gdal \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libproj.so:${PORTSDIR}/graphics/proj \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libfftw3.so:${PORTSDIR}/math/fftw3 \
		libfreetype.so:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USES=		fortran gettext gmake iconv perl5 pkgconfig readline \
		shebangfix tk
SHEBANG_FILES=	scripts/i.spectral/i.spectral \
		scripts/r.tileset/r.tileset
PATCH_TCL_SCRIPTS=lib/init/init.sh
PATCH_TK_SCRIPTS=lib/init/init.sh
USE_XORG=	sm ice x11 xext xi xmu xt
USE_GL=		glu
USE_GNOME=	cairo
USE_PYTHON=	2
USE_WX=		2.8
WX_COMPS=	wx:build python:run
USE_GCC=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PERL="${PERL}"
CONFIGURE_ARGS=	--with-includes=${LOCALBASE}/include \
		--with-libs=${LOCALBASE}/lib \
		--with-tcltk-includes="${TCL_INCLUDEDIR} ${TK_INCLUDEDIR}" \
		--with-opengl-includes=${LOCALBASE}/include/ \
		--with-opengl-libs=${LOCALBASE}/lib/ \
		--with-freetype \
		--with-freetype-includes=${LOCALBASE}/include/freetype2 \
		--with-blas \
		--with-lapack \
		--with-cairo \
		--with-nls \
		--with-cxx \
		--with-readline \
		--with-curses \
		--enable-largefile \
		--with-python=${PYTHON_CMD}-config \
		--with-wxwidgets=${WX_CONFIG}
ALL_TARGET=	default
USE_LDCONFIG=	${PREFIX}/${GRASS_INST_DIR}/lib
MAKE_JOBS_UNSAFE=yes

PLIST_SUB=	GRASS_INST_DIR="${GRASS_INST_DIR}" \
		VERSION="${PORTVERSION}" \
		VER="${PORTVERSION:R:C/\.//}"

OPTIONS_DEFINE=		ATLAS FFMPEG MOTIF MYSQL ODBC PGSQL SQLITE
OPTIONS_DEFAULT=	PGSQL
OPTIONS_SUB=		yes

ATLAS_DESC=		Use ATLAS for BLAS and LAPACK
ALTAS_LIB_DEPENDS=	libalapack.so:${PORTSDIR}/math/atlas
ATLAS_LIB_DEPENDS_OFF=	libblas.so:${PORTSDIR}/math/blas \
			liblapack.so:${PORTSDIR}/math/lapack
FFMPEG_LIB_DEPENDS=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg
FFMPEG_CONFIGURE_ON=	--with-ffmpeg \
			--with-ffmpeg-includes="${LOCALBASE}/include/libavcodec \
			 ${LOCALBASE}/include/libavformat \
			 ${LOCALBASE}/include/libavutil \
			 ${LOCALBASE}/include/libswscale" \
			--with-ffmpeglibs=${LOCALBASE}/lib
MOTIF_USES=		motif
MOTIF_USE=		GL=glw
MOTIF_CONFIGURE_ON=	--with-motif --with-glw
MYSQL_USE=		MYSQL=yes
MYSQL_CONFIGURE_ON=	--with-mysql \
			--with-mysql-includes=${LOCALBASE}/include/mysql \
			--with-mysql-libs=${LOCALBASE}/lib/mysql
ODBC_LIB_DEPENDS=	libodbc.so:${PORTSDIR}/databases/unixODBC
ODBC_CONFIGURE_ON=	--with-odbc
PGSQL_USE=		PGSQL=yes
PGSQL_CONFIGURE_ON=	--with-postgres
SQLITE_USE=		SQLITE=yes
SQLITE_CONFIGURE_ON=	--with-sqlite

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MATLAS}
BLASLIB=	f77blas
LAPACKLIB=	alapack
.else
BLASLIB=	blas
LAPACKLIB=	lapack
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not configure on sparc64
.endif

.if !defined (GRASS_INST_DIR)
GRASS_INST_DIR=	${PORTNAME}-${PORTVERSION}
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lblas|-l${BLASLIB}| ; \
		 s|echo blas|echo ${BLASLIB}| ; \
		 s|-llapack|-l${LAPACKLIB}| ; \
		 s|echo lapack|echo ${LAPACKLIB}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|make -C|$$(MAKE) -C| ; \
		 /^BINDIR/s|=.*|=	$${DESTDIR}$${UNIX_BIN}| ; \
		 /test /s| $${INST_DIR}| $${DESTDIR}$${INST_DIR}|g ; \
		 /tar /s| $${INST_DIR}| $${DESTDIR}$${INST_DIR}|g ; \
		 /chmod /s| $${INST_DIR}| $${DESTDIR}$${INST_DIR}|g ; \
		 /GISBASE/s| $${INST_DIR}| $${DESTDIR}$${INST_DIR}|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|^CC=.*|CC?=cc| ; \
		 s|^CFLAGS=.*|CFLAGS+=-fno-common|' ${WRKSRC}/gem/Makefile
	@${REINPLACE_CMD} -e \
		's|= python|= ${PYTHON_CMD:T}|' ${WRKSRC}/include/Make/Platform.make.in

.include <bsd.port.mk>
