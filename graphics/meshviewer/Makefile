# ex:ts=8
# Ports collection makefile for:	meshviewer
# Date created:			Jun 10, 2002
# Whom:				ijliao
#
# $FreeBSD$

PORTNAME=	meshviewer
PORTVERSION=	0.2.1.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.dai.ed.ac.uk/homes/helmutc/mesh_viewer/
DISTNAME=	mview-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mesh Viewer

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

PLIST_FILES=	bin/mview
USE_QT_VER=	3
USE_GL=		yes
MAKE_ENV=	MOC="${MOC}" \
		QTCPPFLAGS="${QTCPPFLAGS} ${PTHREAD_CFLAGS}" \
		QTCFGLIBS="${QTCFGLIBS} ${PTHREAD_LIBS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mview ${PREFIX}/bin

.include <bsd.port.mk>
