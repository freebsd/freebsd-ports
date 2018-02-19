# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyside
PORTVERSION=	1.2.2
DISTVERSIONPREFIX=	qt4.8+
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://download.qt-project.org/official_releases/pyside/
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python bindings for the Qt applications and UI framework

LICENSE=	LGPL21

LIB_DEPENDS=	libapiextractor.so:devel/apiextractor \
		libgenrunner.so:devel/generatorrunner \
		libshiboken-${PYTHON_VERSION}.so:devel/shiboken

CMAKE_ARGS+=	-DGL_H:FILEPATH="${LOCALBASE}/include/GL/gl.h" \
		-DGL_INCLUDE_DIR:FILEPATH="${LOCALBASE}/include"

USE_QT4=	declarative designer gui help qmake_build \
		moc_build multimedia network opengl \
		phonon rcc_build script scripttools \
		svg uic_build webkit

PLIST_SUB=	PORTVERSION=${PORTVERSION} \
		PYTHON_VERSION=${PYTHON_VERSION}

USES=		cmake python:2.7 tar:bzip2
USE_PYTHON=	flavors
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/devel/qt4/files/Makefile.options"

#REBUILD_QT4GUI=		"${nl} Before building ${PORTNAME},\
#please add QT4_OPTIONS+=QGTKSTYLE to ${__MAKE_CONF}${nl}\
#and then reinstall devel/qt4-corelib and x11-toolkits/qt4-gui${nl}"
#
#post-fetch:
#.if !${QT4_OPTIONS:MQGTKSTYLE}
#	@${ECHO_MSG} ${REBUILD_QT4GUI}
#	@exit 1
#.endif

.include <bsd.port.post.mk>
