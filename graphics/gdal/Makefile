# New ports collection makefile for:	Geospatial Data Abstraction Library
# Date created:		27 Aug 2001
# Whom:			Randall Hopper
#
# $FreeBSD$
#

PORTNAME=	gdal
PORTVERSION=	1.6.0
PORTREVISION=	4
CATEGORIES=	graphics geography
MASTER_SITES=	ftp://ftp.remotesensing.org/pub/gdal/ \
		http://www.gdal.org/dl/ \
		http://dl.maptools.org/dl/gdal/ \
		http://sunpoet.net/distfiles/

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	A translator library for geospatial data formats

USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${DATADIR} --with-libz=/usr
MAKEFILE=	GNUmakefile
INSTALL_TARGET=	install install-man
MAKE_JOBS_UNSAFE=	yes

MAN1=		gdal-config.1 gdal2tiles.1 gdal_contour.1 gdal_grid.1 \
		gdal_merge.1 gdal_rasterize.1 gdal_retile.1 gdal_translate.1 \
		gdal_utilities.1 gdaladdo.1 gdalinfo.1 gdaltindex.1 \
		gdaltransform.1 gdalwarp.1 nearblack.1 ogr2ogr.1 \
		ogr_utilities.1 ogrinfo.1 ogrtindex.1 pct2rgb.1 rgb2pct.1

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=		${LOCALBASE}/bin/doxygen:${PORTSDIR}/devel/doxygen
.endif

OPTIONS=	CFITSIO	"FITS support"			off \
		CURL	"Curl support"			off \
		EXPAT	"Expat support"			off \
		GEOS	"GEOS support"			off \
		GEOTIFF	"GeoTIFF support"		on \
		GIF	"GIF support"			on \
		GRASS	"GRASS support"			off \
		HDF4	"HDF4 support"			off \
		HDF5	"HDF5 support"			off \
		JASPER	"JPEG 2000 support via jasper"	on \
		JPEG	"JPEG support"			on \
		MYSQL	"MySQL support"			off \
		NETCDF	"NetCDF support"		off \
		ODBC	"ODBC support"			off \
		PERL	"Perl support"			off \
		PGSQL	"PostgreSQL support"		off \
		PHP	"PHP support"			off \
		PNG	"PNG support"			on \
		PROJ4	"Projection support via proj4"	off \
		PYTHON	"Python support"		on \
		RUBY	"Ruby support"			off \
		SQLITE	"SQLite support"		off \
		THREAD	"Thread support"		off\
		TIFF	"TIFF support"			on \
		XERCES	"Xerces support"		off

.include <bsd.port.pre.mk>

.if defined(WITH_CFITSIO)
LIB_DEPENDS+=		cfitsio.0:${PORTSDIR}/astro/cfitsio
CONFIGURE_ARGS+=	--with-cfitsio=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--with-cfitsio=no
.endif

.if defined(WITH_CURL)
LIB_DEPENDS+=		curl.5:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--with-curl=${LOCALBASE}/bin/curl-config
.else
CONFIGURE_ARGS+=	--with-curl=no
.endif

.if defined(WITH_EXPAT)
LIB_DEPENDS+=		expat.6:${PORTSDIR}/textproc/expat2
CONFIGURE_ARGS+=	--with-expat=${LOCALBASE} \
			--with-expat-inc=${LOCALBASE}/include \
			--with-expat-lib=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--with-expat=no
.endif

.if defined(WITH_GEOS)
LIB_DEPENDS+=		geos.0:${PORTSDIR}/graphics/geos
CONFIGURE_ARGS+=	--with-geos=${LOCALBASE}/bin/geos-config
.else
CONFIGURE_ARGS+=	--with-geos=no
.endif

.if !defined(WITHOUT_GEOTIFF)
LIB_DEPENDS+=		geotiff.1:${PORTSDIR}/graphics/libgeotiff
CONFIGURE_ARGS+=	--with-libgeotiff=${LOCALBASE}
.endif

.if !defined(WITHOUT_GIF)
LIB_DEPENDS+=		ungif.5:${PORTSDIR}/graphics/libungif
CONFIGURE_ARGS+=	--with-libgif=${LOCALBASE}
.endif

.if defined(WITH_GRASS)
GRASS_INST_DIR=		grass
CONFIGURE_ARGS+=	--with-grass=${LOCALBASE}/${GRASS_INST_DIR} \
			--with-grasslib=${LOCALBASE}/${GRASS_INST_DIR}/lib
.else
CONFIGURE_ARGS+=	--with-grass=no
.endif

.if defined(WITH_HDF4)
LIB_DEPENDS+=		mfhdf.3:${PORTSDIR}/science/hdf
CONFIGURE_ARGS+=	--with-hdf4=${LOCALBASE}
.endif

.if defined(WITH_HDF5)
LIB_DEPENDS+=		hdf5.0:${PORTSDIR}/science/hdf5
CONFIGURE_ARGS+=	--with-hdf5=${LOCALBASE}
.endif

.if !defined(WITHOUT_JASPER)
LIB_DEPENDS+=		jasper.4:${PORTSDIR}/graphics/jasper
CONFIGURE_ARGS+=	--with-jasper=${LOCALBASE}
.endif

.if !defined(WITHOUT_JPEG)
LIB_DEPENDS+=		jpeg.10:${PORTSDIR}/graphics/jpeg
CONFIGURE_ARGS+=	--with-jpeg=${LOCALBASE}
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}/bin/mysql_config
.else
CONFIGURE_ARGS+=	--with-mysql=no
.endif

.if defined(WITH_NETCDF)
LIB_DEPENDS+=		netcdf.4:${PORTSDIR}/science/netcdf
CONFIGURE_ARGS+=	--with-netcdf=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--with-netcdf=no
.endif

.if defined(WITH_ODBC)
LIB_DEPENDS+=		odbc.1:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-odbc=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--with-odbc=no
.endif

.if defined(WITH_PERL)
USE_PERL=		yes
CONFIGURE_ARGS+=	--with-perl
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=		yes
CONFIGURE_ARGS+=	--with-pg=${LOCALBASE}/bin/pg_config
.else
CONFIGURE_ARGS+=	--with-pg=no
.endif

.if defined(WITH_PHP)
USE_PHP=		yes
CONFIGURE_ARGS+=	--with-php
.endif

.if defined(WITH_PROJ4)
LIB_DEPENDS+=		proj.5:${PORTSDIR}/graphics/proj
CONFIGURE_ARGS+=	--with-static-proj4=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--with-static-proj4=no
.endif

.if !defined(WITHOUT_PYTHON)
USE_PYTHON=		yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
CONFIGURE_ARGS+=	--with-python

BUILD_DEPENDS+=	${PYEASYINSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS+=	${PYEASYINSTALL_CMD}:${PORTSDIR}/devel/py-setuptools

# We can not use USE_PYDISTUTILS, so copy these from bsd.python.mk.
PYEASYINSTALL_CMD=	${LOCALBASE}/bin/easy_install-${PYTHON_VER}
PYDISTUTILS_PKGNAME=	${PORTNAME:U}
PYDISTUTILS_PKGVERSION=	${PORTVERSION}
PORTREVISION=	1
_OSRELEASE!=		${UNAME} -r
PYEASYINSTALL_OSARCH=	-${OPSYS:L}-${_OSRELEASE}-${ARCH}
PYEASYINSTALL_EGG=	${PYDISTUTILS_PKGNAME:C/[^A-Za-z0-9.]+/_/g}-${PYDISTUTILS_PKGVERSION:C/[^A-Za-z0-9.]+/_/g}-${PYTHON_VERSION:S/thon//}${PYEASYINSTALL_OSARCH}.egg
PYEASYINSTALL_BINDIR=	${PREFIX}/bin
PYEASYINSTALL_SITELIBDIR=	${PYTHONPREFIX_SITELIBDIR}

PLIST_SUB+=		PYEASYINSTALL_EGG=${PYEASYINSTALL_EGG} \
			PYEASYINSTALL_CMD=${PYEASYINSTALL_CMD} \
			PYEASYINSTALL_BINDIR=${PYEASYINSTALL_BINDIR} \
			PYEASYINSTALL_SITELIBDIR=${PYEASYINSTALL_SITELIBDIR} \
			PYDISTUTILS_PKGNAME=${PYDISTUTILS_PKGNAME} \
			PYDISTUTILS_PKGVERSION=${PYDISTUTILS_PKGVERSION}
.endif

.if !defined(WITHOUT_PNG)
LIB_DEPENDS+=		png.5:${PORTSDIR}/graphics/png
CONFIGURE_ARGS+=	--with-png=${LOCALBASE}
.endif

.if defined(WITH_RUBY)
USE_RUBY=		yes
.include "${PORTSDIR}/Mk/bsd.ruby.mk"
CONFIGURE_ARGS+=	--with-ruby
.endif

.if defined(WITH_SQLITE)
USE_SQLITE=		yes
CONFIGURE_ARGS+=	--with-sqlite=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--with-sqlite=no
.endif

.if !defined(WITHOUT_THREAD)
CONFIGURE_ARGS+=	--with-threads=${PTHREAD_LIBS}
CONFIGURE_ENV+=		CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}"
.endif

.if !defined(WITHOUT_TIFF)
LIB_DEPENDS+=		tiff.4:${PORTSDIR}/graphics/tiff
CONFIGURE_ARGS+=	--with-libtiff=${LOCALBASE}
.endif

.if defined(WITH_XERCES)
XERCESC_VER?=		27
LIB_DEPENDS+=		xerces-c.${XERCESC_VER}:${PORTSDIR}/textproc/xerces-c2
#LIB_DEPENDS+=		xalan-c.19:${PORTSDIR}/textproc/xalan-c
CONFIGURE_ARGS+=	--with-xerces=${LOCALBASE} \
			--with-xerces-inc=${LOCALBASE}/include \
			--with-xerces-lib=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--with-xerces=no
.endif

.if defined(WITH_HDF4) && defined(WITH_HDF5)
IGNORE=			"You can't use HDF4 with HDF5."
.endif

pre-build:
.if defined(WITH_PYTHON)
	@(cd ${BUILD_WRKSRC}/swig/python; \
		${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} setopt -c build -o build-platlib -s lib.${PYEASYINSTALL_OSARCH:S/^-//}; \
		${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} setopt -c build -o build-temp -s temp.${PYEASYINSTALL_OSARCH:S/^-//}-${PYTHON_VER}; \
		${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} setopt -c bdist_egg -o plat-name -s ${PYEASYINSTALL_OSARCH:S/^-//}; \
		${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} setopt -c bdist -o plat-name -s ${PYEASYINSTALL_OSARCH:S/^-//})
.endif

post-patch:
.if !defined(WITHOUT_GIF)
	@${REINPLACE_CMD} -e 's|lgif|lungif|' ${WRKSRC}/configure
.endif
.if defined(WITH_PYTHON)
	@${REINPLACE_CMD} -e '\
		s,%%MAKE_ENV%%,${MAKE_ENV},; \
		s,%%PYTHON_SITELIBDIR%%,${PYTHON_SITELIBDIR},; \
		s,%%PYEASYINSTALL_BINDIR%%,${PYEASYINSTALL_BINDIR},; \
		s,%%PYEASYINSTALL_SITELIBDIR%%,${PYEASYINSTALL_SITELIBDIR},; \
		s,%%PYEASYINSTALL_EGG%%,${PYEASYINSTALL_EGG},; \
		s,%%WRKSRC%%,${WRKSRC},; \
		' ${WRKSRC}/swig/python/GNUmakefile
.endif

post-install:
	${INSTALL_MAN} ${FILESDIR}/gdalwarp.1 ${PREFIX}/man/man1/

.include <bsd.port.post.mk>
