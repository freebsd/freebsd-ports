# New ports collection makefile for:	Geospatial Data Abstraction Library
# Date created:		27 Aug 2001
# Whom:			Randall Hopper
#
# $FreeBSD$
#

PORTNAME=	gdal
PORTVERSION=	1.5.0
CATEGORIES=	graphics geography
MASTER_SITES=	ftp://ftp.remotesensing.org/pub/gdal/ \
		http://www.gdal.org/dl/ \
		http://dl.maptools.org/dl/gdal/ \
		http://sunpoet.net/distfiles/

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	A translator library for geospatial data formats

BUILD_DEPENDS=	${LOCALBASE}/bin/doxygen:${PORTSDIR}/devel/doxygen \
		${PYEASYINSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
LIB_DEPENDS=	jasper.4:${PORTSDIR}/graphics/jasper \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		geotiff.1:${PORTSDIR}/graphics/libgeotiff \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff
RUN_DEPENDS=	${PYEASYINSTALL_CMD}:${PORTSDIR}/devel/py-setuptools

USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${DATADIR} \
		--with-libz=/usr \
		--with-jasper=${LOCALBASE} \
		--with-libgeotiff=${LOCALBASE} \
		--with-libgif=${LOCALBASE} \
		--with-libjpeg=${LOCALBASE} \
		--with-libtiff=${LOCALBASE} \
		--with-png=${LOCALBASE} \
		--with-python
MAKEFILE=	GNUmakefile
INSTALL_TARGET=	install install-man

MAN1=		gdal-config.1 gdal2tiles.1 gdal_contour.1 gdal_grid.1 \
		gdal_merge.1 gdal_rasterize.1 gdal_retile.1 gdal_translate.1 \
		gdal_utilities.1 gdaladdo.1 gdalinfo.1 gdaltindex.1 \
		gdaltransform.1 gdalwarp.1 nearblack.1 ogr2ogr.1 \
		ogr_utilities.1 ogrinfo.1 ogrtindex.1 pct2rgb.1 rgb2pct.1

.include <bsd.port.pre.mk>

# We can not use USE_PYDISTUTILS, so copy these from bsd.python.mk.
PYEASYINSTALL_CMD=	${LOCALBASE}/bin/easy_install-${PYTHON_VER}
PYDISTUTILS_PKGNAME=	${PORTNAME:U}
PYDISTUTILS_PKGVERSION=	${PORTVERSION}
_OSRELEASE!=		${UNAME} -r
PYEASYINSTALL_OSARCH=	-${OPSYS:L}-${_OSRELEASE}-${ARCH}
PYEASYINSTALL_EGG=	${PYDISTUTILS_PKGNAME:C/[^A-Za-z0-9.]+/_/g}-${PYDISTUTILS_PKGVERSION:C/[^A-Za-z0-9.]+/_/g}-${PYTHON_VERSION:S/thon//}${PYEASYINSTALL_OSARCH}.egg
PYEASYINSTALL_BINDIR=		${PREFIX}/bin
PYEASYINSTALL_SITELIBDIR=	${PYTHONPREFIX_SITELIBDIR}

PLIST_SUB+=	PYEASYINSTALL_EGG=${PYEASYINSTALL_EGG} \
		PYEASYINSTALL_CMD=${PYEASYINSTALL_CMD} \
		PYEASYINSTALL_BINDIR=${PYEASYINSTALL_BINDIR} \
		PYEASYINSTALL_SITELIBDIR=${PYEASYINSTALL_SITELIBDIR} \
		PYDISTUTILS_PKGNAME=${PYDISTUTILS_PKGNAME} \
		PYDISTUTILS_PKGVERSION=${PYDISTUTILS_PKGVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|lgif|lungif|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '\
		s,%%MAKE_ENV%%,${MAKE_ENV},; \
		s,%%PYTHON_SITELIBDIR%%,${PYTHON_SITELIBDIR},; \
		s,%%PYEASYINSTALL_BINDIR%%,${PYEASYINSTALL_BINDIR},; \
		s,%%PYEASYINSTALL_SITELIBDIR%%,${PYEASYINSTALL_SITELIBDIR},; \
		s,%%PYEASYINSTALL_EGG%%,${PYEASYINSTALL_EGG},; \
		s,%%WRKSRC%%,${WRKSRC},; \
		' ${WRKSRC}/swig/python/GNUmakefile

pre-build:
	@(cd ${BUILD_WRKSRC}/swig/python; \
		${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} setopt -c build -o build-platlib -s lib.${PYEASYINSTALL_OSARCH:S/^-//}; \
		${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} setopt -c build -o build-temp -s temp.${PYEASYINSTALL_OSARCH:S/^-//}-${PYTHON_VER}; \
		${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} setopt -c bdist_egg -o plat-name -s ${PYEASYINSTALL_OSARCH:S/^-//}; \
		${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} setopt -c bdist -o plat-name -s ${PYEASYINSTALL_OSARCH:S/^-//})

.include <bsd.port.post.mk>
