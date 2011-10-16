# New ports collection makefile for:	py-qt4-dbus
# Date created:				2007-02-20
# Whom:					Danny Pansters <danny@ricin.com>
#
# $FreeBSD$

PORTNAME=	dbus
PORTVERSION=	${PYQT4_VERSION}
PORTEPOCH=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITES_PYQT4}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt4-
DISTNAME=	${PYQT4_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt4 toolkit, D-BUS module

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sip>=${SIP_VERSION}:${PORTSDIR}/devel/py-sip \
		${PYTHON_PKGNAMEPREFIX}dbus>=0.8:${PORTSDIR}/devel/py-dbus
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>=0.8:${PORTSDIR}/devel/py-dbus \
		${PKGNAMEPREFIX}core>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-core

DISTINFO_FILE=	${PYQT4_DISTINFO_FILE}
HAS_CONFIGURE=	yes
USE_PYTHON=	2.5+
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake_build moc_build
USE_XORG=	x11 xext

BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}
INSTALL_WRKSRC=	${WRKSRC}/${PORTNAME}

OPTIONS=	DEBUG	"Enable debugging in generated code" off \
		TRACING	"Enable tracing in generated code" off

PATCHDIR=	${PORTSDIR}/devel/py-qt4-core/files
OPTIONSFILE=	${PORT_DBDIR}/py-qt4-${PORTNAME}/options
CONFIGURE_ENV+=	PYQT4_COMPONENT="${PORTNAME}"
ARGS=		-b ${PREFIX}/bin\
		-d ${PYTHONPREFIX_SITELIBDIR}\
		-p ${PREFIX}/${QT_PLUGINDIR_REL}\
		-q ${QMAKE}\
		--confirm-license\
		--enable QtCore

.include "../py-sip/files/bsd.pyqt.mk"
.include <bsd.port.options.mk>

.if defined(WITH_DEBUG)
ARGS+=		--debug
.endif
.if defined(WITH_TRACING)
ARGS+=		--trace
.endif

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV}\
		${PYTHON_CMD} configure.py ${ARGS}

post-configure:
	${REINPLACE_CMD} -e 's|mkspecs/freebsd-g++|share/qt4/mkspecs/freebsd-g++|'\
		-e 's|CC = cc|CC = ${CC}|'\
		-e 's|CXX = c++|CXX = ${CXX}|'\
		-e 's|LINK = c++|LINK = ${CXX}|'\
		${WRKSRC}/dbus/Makefile

.include <bsd.port.mk>
