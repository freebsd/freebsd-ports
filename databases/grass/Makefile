# Created by: reg
# $FreeBSD$

PORTNAME=	grass
PORTVERSION=	6.4.6
PORTREVISION=	2
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

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/GPL.TXT

BUILD_DEPENDS=	${LOCALBASE}/bin/swig:devel/swig13
LIB_DEPENDS=	libgdal.so:graphics/gdal \
		libpng.so:graphics/png \
		libproj.so:graphics/proj \
		libtiff.so:graphics/tiff \
		libfftw3.so:math/fftw3 \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	bash:shells/bash

USES=		fortran gettext gmake iconv jpeg ncurses perl5 pkgconfig \
		python:2 readline shebangfix tk
SHEBANG_FILES=	scripts/i.spectral/i.spectral \
		scripts/r.tileset/r.tileset \
		visualization/nviz/scripts/nviz2.2_script \
		visualization/nviz/scripts/script_file_tools \
		visualization/nviz/scripts/script_get_line \
		visualization/nviz/scripts/script_play \
		visualization/nviz/scripts/script_tools
SHEBANG_LANG=	nviz
nviz_OLD_CMD=	nviz
nviz_CMD=	${PREFIX}/${GRASS_INST_DIR}/bin/nviz
PATCH_TCL_SCRIPTS=lib/init/init.sh
PATCH_TK_SCRIPTS=lib/init/init.sh
USE_XORG=	sm ice x11 xext xi xmu xt
USE_GL=		glu
USE_GNOME=	cairo
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
CPPFLAGS+=	-I${NCURSESINC}

MAKE_JOBS_UNSAFE=	yes

PLIST_SUB=	GRASS_INST_DIR="${GRASS_INST_DIR}" \
		VERSION="${PORTVERSION}" \
		VER="${PORTVERSION:R:C/\.//}"

BROKEN_sparc64=		Does not configure on sparc64

OPTIONS_DEFINE=		ATLAS FFMPEG MOTIF
OPTIONS_MULTI=		DB
OPTIONS_MULTI_DB=	MYSQL ODBC PGSQL SQLITE
OPTIONS_DEFAULT=	PGSQL
OPTIONS_SUB=		yes

ATLAS_DESC=		Use ATLAS for BLAS and LAPACK
ATLAS_USES=		blaslapack:atlas
ATLAS_USES_OFF=		blaslapack
DB_DESC=		Database support
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
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
ODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC
ODBC_CONFIGURE_ON=	--with-odbc
PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ON=	--with-postgres
SQLITE_USES=		sqlite
SQLITE_CONFIGURE_ON=	--with-sqlite

.include <bsd.port.options.mk>

.if !defined (GRASS_INST_DIR)
GRASS_INST_DIR=	${PORTNAME}-${PORTVERSION}
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lblas|${BLASLIB}|g ; \
		 s|-llapack|${LAPACKLIB}|g ; \
		 s|g2c|f2c|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|make -C|$$(MAKE) -C| ; \
		 /^BINDIR/s|=.*|=	$${DESTDIR}$${UNIX_BIN}| ; \
		 /test /s| $${INST_DIR}| $${DESTDIR}$${INST_DIR}|g ; \
		 /tar /s| $${INST_DIR}| $${DESTDIR}$${INST_DIR}|g ; \
		 /chmod /s| $${INST_DIR}| $${DESTDIR}$${INST_DIR}|g ; \
		 /tar /s| $${INST_DIR}| $${DESTDIR}$${INST_DIR}|g ; \
		 s|> $${INST_DIR}|> $${DESTDIR}$${INST_DIR}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|^CC=.*|CC?=cc| ; \
		 s|^CFLAGS=.*|CFLAGS+=-fno-common|' ${WRKSRC}/gem/Makefile
	@${REINPLACE_CMD} -e \
		's|= python|= ${PYTHON_CMD:T}|' ${WRKSRC}/include/Make/Platform.make.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gem64
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${GRASS_INST_DIR}/bin/*.*
.for i in HTMLMAP PNG PS XDRIVER cairo
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${GRASS_INST_DIR}/driver/${i}
.endfor
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${GRASS_INST_DIR}/driver/db/*
.for i in bmif_to_cell clean_temp current_time_s_ms echo frame.* grocat \
	i.ask i.find i.photo.* lock mod* mon.* poly_to_bmif r.watershed.* \
	run set_data
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${GRASS_INST_DIR}/etc/${i}
.endfor
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${GRASS_INST_DIR}/etc/form/form
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${GRASS_INST_DIR}/etc/lister/*
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${GRASS_INST_DIR}/etc/nviz2.2/nviz
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${GRASS_INST_DIR}/lib/libgrass_*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${GRASS_INST_DIR}/tools/g.echo

post-install-MOTIF-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${GRASS_INST_DIR}/bin/xganim

.include <bsd.port.mk>
