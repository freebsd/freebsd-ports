# New ports collection makefile for:	grass
# Date created:		15 January 2000
# Whom:			reg
#
# $FreeBSD$
#

PORTNAME=	grass
PORTVERSION=	6.0.2
PORTEPOCH=	2
CATEGORIES=	databases
MASTER_SITES=	http://grass.itc.it/grass60/source/ \
		ftp://grass.itc.it/pub/grass/grass60/source/ \
		http://grass.ibiblio.org/grass60/source/\
		ftp://www.ibiblio.org/pub/packages/gis/grass/grass60/source/\
		http://www.geog.uni-hannover.de/grass/grass60/source/\
		http://grass.meteo.uni.wroc.pl/grass60/source/ \
		http://grass.ru.ac.za/grass60/source/\
		http://wgrass.media.osaka-cu.ac.jp/grassh/grass60/source/\
		http://public.planetmirror.com/pub/grass/grass60/source/\
		ftp://ftp.planetmirror.com/pub/grass/grass60/source/\
		http://gulus.usherbrooke.ca/pub/appl/grass/grass60/source/\
		http://ludique.u-bourgogne.fr/grass/grass60/source/

MAINTAINER=	lrntct@gmail.com
COMMENT=	An open source Geographical Information System (GIS)

BUILD_DEPENDS=	proj:${PORTSDIR}/graphics/proj \
		gdal-config:${PORTSDIR}/graphics/gdal \
		wish8.4:${PORTSDIR}/x11-toolkits/tk84
RUN_DEPENDS=	proj:${PORTSDIR}/graphics/proj \
		gdal-config:${PORTSDIR}/graphics/gdal
LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		fftw.2:${PORTSDIR}/math/fftw \
		freetype.9:${PORTSDIR}/print/freetype2

USE_GMAKE=	yes
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_PERL5=	yes
USE_XLIB=	yes
USE_FREETYPE=	yes
USE_FFTW=	yes
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
		--with-readline \
		--enable-largefile

PLIST_SUB=	GRASS_INST_DIR=${GRASS_INST_DIR}
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/%%GRASS_INST_DIR%%/lib
USE_LDCONFIG=	${PREFIX}/${GRASS_INST_DIR}/lib

OPTIONS=	MYSQL "Enable MySQL support" Off \
		PGSQL "Enable PostgreSQL support" On

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
PLIST_SUB+=	FBSD4=""
.else
PLIST_SUB+=	FBSD4="@comment "
.endif

.if !defined (GRASS_INST_DIR)
GRASS_INST_DIR=	${PORTNAME}
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
.if defined(WITHOUT_PGSQL)
CONFIGURE_ARGS+=--without-postgres
PLIST_SUB+=	PGSQL="@comment "
.else
USE_PGSQL=	yes
PLIST_SUB+=	PGSQL=""
.endif

.include "${PORTSDIR}/misc/ldconfig_compat/bsd.ldconfig.mk"

post-extract:
	@${REINPLACE_CMD} -E '28s|/grass-.*|/${GRASS_INST_DIR}|g' \
	${WRKSRC}/Makefile

post-install: install-ldconfig-file

.include <bsd.port.post.mk>
