# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	libopensync-plugin-python
PORTVERSION=	0.36
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	http://www.opensync.org/download/releases/${PORTVERSION}/
PKGNAMESUFFIX=	-devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python plugin for the OpenSync framework

LIB_DEPENDS=	opensync.1:${PORTSDIR}/devel/libopensync

CONFLICTS=	libopensync-plugin-python-0.2*

DEPRECATED=	Broken for more than 6 month
EXPIRATION_DATE=	2013-12-22

BROKEN=		fails to build with recent libopensync

USE_BZIP2=	yes
USES=		cmake:outsource pkgconfig
USE_PYTHON=	yes
CMAKE_ARGS+=	-Wno-dev  \
		-DPYTHON_INCLUDE_PATH:PATH=${PYTHON_INCLUDEDIR} \
		-DPYTHON_LIBRARY:PATH=${PYTHON_LIBDIR}/config/lib${PYTHON_VERSION}.so

# This hack is meant to respect PREFIX, and should be
# enhanced to use pkg-config or cmake.
OS_PLUGIN_DIR=	${PREFIX}/lib/opensync-1.0/plugins
OS_PYPLUGIN_DIR=${PREFIX}/lib/opensync-1.0/python-plugins

NO_STAGE=	yes
post-patch:
# Help find opensync, which is apparently renamed in ports
	${REINPLACE_CMD} -e "s,opensync-1.0,libopensync,g" \
		${WRKSRC}/cmake/modules/FindOpenSync.cmake

do-install:
	${MKDIR} -p ${OS_PLUGIN_DIR} ${OS_PYPLUGIN_DIR}
	${INSTALL_DATA} ${WRKSRC}/src/python-module.so ${OS_PLUGIN_DIR}
	${INSTALL_DATA} ${WRKSRC}/src/sample.py ${OS_PYPLUGIN_DIR}

.include <bsd.port.mk>
