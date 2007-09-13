# New ports collection makefile for:	py-qt4-dbus
# Date created:				2007-02-20
# Whom:					Danny Pansters <danny@ricin.com>
#
# $FreeBSD$

PORTNAME=	dbus
PORTVERSION=	4.3
PORTREVISION=	# zero
CATEGORIES=	devel python
MASTER_SITES=	http://www.riverbankcomputing.com/Downloads/PyQt4/GPL/ \
		http://freebsd.ricin.com/ports/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}qt4-
DISTNAME=	PyQt-x11-gpl-${PORTVERSION}

MAINTAINER=	danny@ricin.com
COMMENT=	Python bindings for the Qt4 toolkit, D-BUS module

BUILD_DEPENDS=	${LOCALBASE}/bin/sip:${PORTSDIR}/devel/py-sip \
		${PYTHON_PKGNAMEPREFIX}dbus>=0.8:${PORTSDIR}/devel/py-dbus \
		${PYTHON_SITELIBDIR}/PyQt4/QtCore.so:${PORTSDIR}/devel/py-qt4-core
RUN_DEPENDS=	${BUILD_DEPENDS}

HAS_CONFIGURE=	yes
USE_PYTHON=	2.5+
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake moc

OPTIONS=	DEBUG	"Enable debugging in generated code" off \
		TRACING	"Enable tracing in generated code" off

PATCHDIR=	${PORTSDIR}/devel/py-qt4-core/files
OPTIONSFILE=	${PORT_DBDIR}/py-qt4-${PORTNAME}/options
CONFIGURE_ENV+=	PYQT4_COMPONENT="${PORTNAME}"
ARGS=		-b ${PREFIX}/bin\
		-d ${PYTHON_SITELIBDIR}\
		-q ${QT_PREFIX}/bin/qmake-qt4

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
ARGS+=		--debug
.endif
.if defined(WITH_TRACING)
ARGS+=		--trace
.endif
ARGS+=		--enable QtCore

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV}\
		${PYTHON_CMD} configure.py ${ARGS}

post-configure:
	${REINPLACE_CMD} -e 's|mkspecs/freebsd-g++|share/qt4/mkspecs/freebsd-g++|'\
		-e 's|CC = cc|CC = ${CC}|'\
		-e 's|CXX = c++|CXX = ${CXX}|'\
		-e 's|LINK = c++|LINK = ${CXX}|'\
		${WRKSRC}/dbus/Makefile

.include <bsd.port.post.mk>
