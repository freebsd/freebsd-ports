# New ports collection makefile for:	vterrain-sdk virtual terrain development and modeling libraries
# Date created:		27 Apr 2001
# Whom:			Randall Hopper
#
# $FreeBSD$
#

PORTNAME=	vterrain-sdk
PORTVERSION=	010829
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.vterrain.org/pub/vterrain/dist/
DISTFILES=	TerrainSDK-${PORTVERSION}.zip

MAINTAINER=	aa8vb@nc.rr.com

LIB_DEPENDS=    netcdf.1:${PORTSDIR}/math/netcdf \
		osg.1:${PORTSDIR}/graphics/osg \
		png.4:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/TerrainSDK

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS+=	-a
USE_X_PREFIX=	yes
USE_MESA=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
MAKE_ENV=	CXX="${CXX}" \
		COPT="${CXXFLAGS} -fpic -DPIC" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

#PREFIX seems broken -  Uses /usr/local even if USE_X_PREFIX set
PREFIX=		${X11BASE}

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
