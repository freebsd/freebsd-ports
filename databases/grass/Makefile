# New ports collection makefile for:	grass
# Date created:		15 January 2000
# Whom:			reg
#
# $FreeBSD$
#

PORTNAME=	grass
PORTVERSION=	6.2.3
PORTREVISION=	6
PORTEPOCH=	2
CATEGORIES=	databases geography
MASTER_SITES=	http://grass.itc.it/grass62/source/ \
		ftp://grass.itc.it/pub/grass/grass62/source/ \
		http://grass.ibiblio.org/grass62/source/\
		ftp://www.ibiblio.org/pub/packages/gis/grass/grass62/source/\
		http://www.geog.uni-hannover.de/grass/grass62/source/\
		http://grass.meteo.uni.wroc.pl/grass62/source/ \
		http://grass.ru.ac.za/grass62/source/\
		http://wgrass.media.osaka-cu.ac.jp/grassh/grass62/source/\
		http://public.planetmirror.com/pub/grass/grass62/source/\
		ftp://ftp.planetmirror.com/pub/grass/grass62/source/\
		http://gulus.usherbrooke.ca/pub/appl/grass/grass62/source/\
		http://ludique.u-bourgogne.fr/grass/grass62/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An open source Geographical Information System (GIS)

BUILD_DEPENDS=	proj:${PORTSDIR}/graphics/proj \
		gdal-config:${PORTSDIR}/graphics/gdal
RUN_DEPENDS=	proj:${PORTSDIR}/graphics/proj \
		gdal-config:${PORTSDIR}/graphics/gdal \
		bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		fftw.2:${PORTSDIR}/math/fftw \
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
PATCH_TCL_SCRIPTS=lib/init/init.sh
PATCH_TK_SCRIPTS=lib/init/init.sh

ALL_TARGET=
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-includes=${LOCALBASE}/include \
		--with-libs=${LOCALBASE}/lib \
		--with-tcltk-includes="${TCL_INCLUDEDIR} ${TK_INCLUDEDIR}" \
		--with-opengl-includes=${LOCALBASE}/include \
		--with-opengl-libs=${LOCALBASE}/lib \
		--with-freetype \
		--with-freetype-includes=${LOCALBASE}/include/freetype2 \
		--with-nls \
		--with-cxx \
		--with-readline \
		--with-curses \
		--enable-largefile

PLIST_SUB=	GRASS_INST_DIR=${GRASS_INST_DIR} \
		VERSION=${PORTVERSION} \
		VER=${PORTVERSION:R:C/\.//}
USE_LDCONFIG=	${PREFIX}/${GRASS_INST_DIR}/lib

OPTIONS=	MYSQL	"Enable MySQL support" Off \
		ODBC	"Enable ODBC support" Off \
		PGSQL	"Enable PostgreSQL support" On \
		SQLITE	"Enable SQLite support" Off

BASH_SCRIPTS=	i.spectral r.mapcalculator r.tileset r3.mapcalculator \
		v.in.gpsbabel

.include <bsd.port.pre.mk>

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

.if defined(WITH_ODBC)
LIB_DEPENDS+=	odbc:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=--with-odbc
PLIST_SUB+=	ODBC=""
.else
PLIST_SUB+=	ODBC="@comment "
.endif

.if defined(WITHOUT_PGSQL)
CONFIGURE_ARGS+=--without-postgres
PLIST_SUB+=	PGSQL="@comment "
.else
USE_PGSQL=	yes
PLIST_SUB+=	PGSQL=""
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
