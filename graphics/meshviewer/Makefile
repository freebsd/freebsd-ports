# ex:ts=8
# Ports collection makefile for:	meshviewer
# Date created:			Jun 10, 2002
# Whom:				ijliao
#
# $FreeBSD$

PORTNAME=	meshviewer
PORTVERSION=	0.2.0.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.dai.ed.ac.uk/homes/helmutc/mesh_viewer/
DISTNAME=	mview-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mesh Viewer

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

USE_MESA=	yes
USE_QT_VER=	3
USE_GMAKE=	yes
MAKE_ENV=	MOC="${MOC}" QTDIR="${X11BASE}" \
		CPPFLAGS="${QTCPPFLAGS} ${PTHREAD_CFLAGS}" \
		LIBS="${QTCFGLIBS} ${PTHREAD_LIBS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mview ${PREFIX}/bin

.include <bsd.port.mk>
