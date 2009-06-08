# New ports collection makefile for:	libopensync-plugin-python-devel
# Date created:				16 June 2008
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	libopensync-plugin-python
PORTVERSION=	0.36
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	http://www.opensync.org/download/releases/${PORTVERSION}/
PKGNAMESUFFIX=	-devel

MAINTAINER=	avl@FreeBSD.org
COMMENT=	Python plugin for the OpenSync framework

LIB_DEPENDS=	opensync.1:${PORTSDIR}/devel/libopensync

CONFLICTS=	libopensync-plugin-python-0.2*

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_PYTHON=	yes
USE_GNOME=	pkgconfig
CMAKE_ARGS+=	-Wno-dev  \
		-DPYTHON_INCLUDE_PATH:PATH=${PYTHON_INCLUDEDIR} \
		-DPYTHON_LIBRARY:PATH=${PYTHON_LIBDIR}/config/lib${PYTHON_VERSION}.so

# This hack is meant to respect PREFIX, and should be
# enhanced to use pkg-config or cmake.
OS_PLUGIN_DIR=	${PREFIX}/lib/opensync-1.0/plugins
OS_PYPLUGIN_DIR=${PREFIX}/lib/opensync-1.0/python-plugins

pre-patch:
	@${REINPLACE_CMD} -e "s|MESSAGE|# MESSAGE|" \
		${WRKSRC}/cmake/modules/MacroEnsureOutOfSourceBuild.cmake

do-install:
	${MKDIR} -p ${OS_PLUGIN_DIR} ${OS_PYPLUGIN_DIR}
	${INSTALL_DATA} ${WRKSRC}/src/python-module.so ${OS_PLUGIN_DIR}
	${INSTALL_DATA} ${WRKSRC}/src/sample.py ${OS_PYPLUGIN_DIR}

.include <bsd.port.mk>
