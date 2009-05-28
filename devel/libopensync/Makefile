# New ports collection makefile for:	libopensync
# Date created:		2005-06-19
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libopensync
PORTVERSION=	0.36
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.opensync.org/download/releases/${PORTVERSION}/

MAINTAINER=	avl@FreeBSD.org
COMMENT=	A PIM data synchronization framework

BUILD_DEPENDS=	swig1.3:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3
RUN_DEPENDS=	swig1.3:${PORTSDIR}/devel/swig13

CONFLICTS=	libopensync-0.22*

USE_BZIP2=	yes
USE_CMAKE=	yes
CMAKE_ARGS+=	-Wno-dev
CMAKE_USE_PTHREAD=	yes
USE_GNOME=	glib20 libxml2
USE_PYTHON=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

SWIG_VER!=	cd ${PORTSDIR}/devel/swig13 && ${MAKE} -V PORTVERSION
SWIG_DATADIR!=	cd ${PORTSDIR}/devel/swig13 && ${MAKE} -V DATADIR

post-patch:
	@${REINPLACE_CMD} -e "s|\$${LIB_INSTALL_DIR}/pkgconfig|${PREFIX}/libdata/pkgconfig|" \
		-e "s|FIND_PACKAGE( SWIG|FIND_PACKAGE( SWIG REQUIRED|" \
		-e "/FIND_PACKAGE( Check )/d" ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e "s|/usr/local/share/swig1.3|${SWIG_DATADIR}/${SWIG_VER}|g" \
		${WRKSRC}/cmake/modules/FindSWIG.cmake

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
