# New ports collection makefile for:	vterrain-apps
# Date created:		27 Apr 2001
# Whom:			Randall Hopper
#
# $FreeBSD$
#

PORTNAME=	vterrain-apps
PORTVERSION=	010829
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.vterrain.org/pub/vterrain/dist/
DISTNAME=	TerrainApps-${PORTVERSION}

MAINTAINER=	aa8vb@nc.rr.com

LIB_DEPENDS=    vtdata.1:${PORTSDIR}/graphics/vterrain-sdk \
		wx_gtk_gl.2:${PORTSDIR}/x11-toolkits/wxgtk \
		netcdf.1:${PORTSDIR}/math/netcdf \
		osg.1:${PORTSDIR}/graphics/osg \
		png.4:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/TerrainApps

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS+=	-a
USE_X_PREFIX=	yes
USE_MESA=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
MAKE_ENV=	CXX="${CXX}" \
		COPT="${CXXFLAGS} -fpic -DPIC" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Enviro/wxEnviro ${PREFIX}/bin

.include <bsd.port.mk>
