# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyside
PORTVERSION=	1.1.1
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	http://nivit.altervista.org/FreeBSD/ports/distfiles/
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}
DISTNAME=	${PORTNAME}-qt${QT4_VERSION:R}+${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python bindings for the Qt applications and UI framework

LICENSE=	LGPL21

LIB_DEPENDS=	libapiextractor.so:${PORTSDIR}/devel/apiextractor \
		libgenrunner.so:${PORTSDIR}/devel/generatorrunner \
		libshiboken-${PYTHON_VERSION}.so:${PORTSDIR}/devel/shiboken

MANUAL_PACKAGE_BUILD=	requires x11-toolkits/qt4-gui with QGTKSTYLE enabled

CMAKE_ARGS+=	-DGL_H:FILEPATH="${LOCALBASE}/include/GL/gl.h" \
		-DGL_INCLUDE_DIR:FILEPATH="${LOCALBASE}/include"

USE_QT4=	declarative designer gui help qmake_build \
		moc_build multimedia network opengl \
		phonon rcc_build script scripttools \
		svg uic_build webkit

PLIST_SUB=	PORTVERSION=${PORTVERSION} \
		PYTHON_VERSION=${PYTHON_VERSION}

USE_BZIP2=	yes
USES=		cmake
USE_LDCONFIG=	yes
USE_PYTHON=	-2.7

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.include "${PORTSDIR}/devel/qt4/files/Makefile.options"

nl=	${.newline}

REBUILD_QT4GUI=		"${nl} Before building ${PORTNAME},\
please add QT4_OPTIONS+=QGTKSTYLE to ${__MAKE_CONF}${nl}\
and then reinstall devel/qt4-corelib and x11-toolkits/qt4-gui${nl}"

#QGTKSTYLE_MSG=	"${nl}\# ${PORTNAME} requires\
#x11-toolkits/qt4-gui built with QGTKSTYLE\
#${nl}QT4_OPTIONS+=QGTKSTYLE${nl}"

post-fetch:
.if !${QT4_OPTIONS:MQGTKSTYLE}
	@${ECHO_MSG} ${REBUILD_QT4GUI}
	@exit 1
# a non canonical way...
#	@${ECHO_CMD} ${QGTKSTYLE_MSG} >> ${__MAKE_CONF}
#.	if exists(${LOCALBASE}/include/qt4/Qt/QtGui)
#.		for p in devel/qt4-corelib x11-toolkits/qt4-gui
#		    @(cd ${PORTSDIR}/${p} && \
#		    ${MAKE} clean install -DFORCE_PKG_REGISTER)
#.		endfor
#.	endif
.endif

.include <bsd.port.post.mk>
