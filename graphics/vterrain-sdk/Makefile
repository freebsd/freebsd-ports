# New ports collection makefile for:	vterrain-sdk
# Date created:				27 Apr 2001
# Whom:					Randall Hopper <aa8vb@nc.rr.com>
#
# $FreeBSD$
#

PORTNAME=	vterrain-sdk
PORTVERSION=	010423
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.vterrain.org/pub/vterrain/dist/ \
		http://www.boost.org/libs/dir_it/
DISTFILES=	${EXTRACT_ONLY} \
		dir_it.zip
EXTRACT_ONLY=	TerrainSDK-${PORTVERSION}.zip

MAINTAINER=	aa8vb@nc.rr.com

LIB_DEPENDS=	netcdf.1:${PORTSDIR}/math/netcdf \
		shp.1:${PORTSDIR}/devel/shapelib \
		png.5:${PORTSDIR}/graphics/png \
		osg.1:${PORTSDIR}/graphics/osg \
		projection.1:${PORTSDIR}/misc/projectionlib

WRKSRC=		${WRKDIR}/TerrainSDK

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS+=	-a
USE_X_PREFIX=	yes
USE_MESA=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
MAKE_ENV=	CXX="${CXX}" \
		COPT="${CXXFLAGS} -fpic -DPIC"

post-extract:
	cd ${WRKSRC}/vtdata && \
		unzip -aj ${DISTDIR}/dir_it.zip boost/directory.h src/directory.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vtdata/libvtdata.so ${PREFIX}/lib/libvtdata.so.1
	${INSTALL_PROGRAM} ${WRKSRC}/vtlib/vtosg/libvtosg.so ${PREFIX}/lib/libvtosg.so.1
	${LN} -sf libvtdata.so.1 ${PREFIX}/lib/libvtdata.so
	${LN} -sf libvtosg.so.1 ${PREFIX}/lib/libvtosg.so
	${MKDIR} ${PREFIX}/include/TerrainSDK
	cd ${WRKSRC} && \
	  find . -name '*.h' -o -name '*.inl' \
	  | cpio -dumpv ${PREFIX}/include/TerrainSDK
	find ${PREFIX}/include/TerrainSDK -type d | xargs ${CHMOD} 755
	find ${PREFIX}/include/TerrainSDK -type f | xargs ${CHMOD} 644

.include <bsd.port.mk>
